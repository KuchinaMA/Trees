#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "Tree.h"

Node* node_ctor(int data, Node* left, Node* right) {

    Node* node = (Node*)calloc(1, sizeof(Node));

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}

int node_dtor(Node* node) {

    if (node->left != 0 && node->right != 0) {
        node_dtor(node->left);
        node_dtor(node->right);
    }

    node->left = 0;
    node->right = 0;
    node->data = TREEPOISON;

    free(node);

    return 0;
}

void print_node_pre(Node* node) {

    if (node == 0) {
        printf(" nil ");
        return;
    }
    printf(" ( ");
    printf(" %d ", node->data);
    print_node_pre(node->left);
    print_node_pre(node->right);
    printf(" ) ");
}

void print_node_post(Node* node) {

    if (node == 0) {
        printf(" nil ");
        return;
    }
    printf(" ( ");
    print_node_post(node->left);
    print_node_post(node->right);
    printf(" %d ", node->data);
    printf(" ) ");
}

void print_node_in(Node* node) {

    if (node == 0) {
        printf(" nil ");
        return;
    }
    printf(" ( ");
    print_node_in(node->left);
    printf(" %d ", node->data);
    print_node_in(node->right);
    printf(" ) ");
}


Tree* tree_ctor(Node* root, size_t size) {

    assert(root);

    Tree* tree = (Tree*)calloc(1, sizeof(Tree));

    tree->root = root;
    tree->size = size;

    return tree;
}

int tree_dtor(Tree* tree) {

    node_dtor(tree->root);
    tree->root = 0;
    tree->size = 0;

    free(tree);

    return 0;
}

int add_node(Tree* tree, Node* node, int data) {

    if (data <= node->data) {

        if (node->left != 0)

            add_node(tree, node->left, data);

        else {

            Node* new_node = node_ctor(data, 0, 0);
            node->left = new_node;
        }
    }

    else {

        if (node->right != 0)

            add_node(tree, node->right, data);

        else {

            Node* new_node = node_ctor(data, 0, 0);
            node->right = new_node;
        }
    }

    return 0;
}


int graph_dump(const Tree* tree) {

    FILE* dotfile = fopen("TreePicture.dot", "w");

    fprintf(dotfile, "digraph {\n");
    fprintf(dotfile, "  rankdir = HR;\n");
    fprintf(dotfile, "  node [shape = Mrecord, color = \"#800000\", style = filled, fillcolor = \"#FFD5D5\"];\n");

    node_graph_dump(tree->root, dotfile);
    edge_graph_dump(tree->root, dotfile);

    fprintf(dotfile, "}");

    system("dot TreePicture.dot -T png -o TreePicture.png");

    fclose(dotfile);

    return 0;
}


void node_graph_dump(Node* node, FILE* dotfile) {

    if (node == 0)
        return;
    fprintf(dotfile, "  node_%p[label = \" %d \"]; \n", node, node->data);
    node_graph_dump(node->left, dotfile);
    node_graph_dump(node->right, dotfile);

}

void edge_graph_dump(Node* node, FILE* dotfile) {

    if (node->left != 0) {
        fprintf(dotfile, "  node_%p -> node_%p [weight = 1, color = \"#800000\"];\n", node, node->left);
        edge_graph_dump(node->left, dotfile);
    }

    if (node->right != 0) {
        fprintf(dotfile, "  node_%p -> node_%p [weight = 1, color = \"#800000\"];\n", node, node->right);
        edge_graph_dump(node->right, dotfile);
    }
}








