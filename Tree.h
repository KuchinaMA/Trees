#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

const int TREEPOISON = -555;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct Tree {
    Node* root;
    size_t size;
};

Node* node_ctor(int data, Node* left, Node* right);
int node_dtor(Node* node);
void print_node_pre(Node* node, FILE* output);
void print_node_post(Node* node, FILE* output);
void print_node_in(Node* node, FILE* output);

int graph_dump(const Tree* tree);
void node_graph_dump(Node* node, FILE* dotfile);
void edge_graph_dump(Node* node, FILE* dotfile);

Tree* tree_ctor(Node* root, size_t size);
int tree_dtor(Tree* tree);

int add_node(Tree* tree, Node* node, int data);

#endif // TREE_H_INCLUDED
