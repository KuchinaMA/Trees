#include <stdio.h>

#include "Tree.h"

int main () {

    FILE* output = fopen("TreeDump.txt", "w");

    /*Node* node15 = node_ctor(15, 0, 0);
    Node* node20 = node_ctor(20, 0, 0);

    Node* node17 = node_ctor(17, node15, node20);
    Node* node5 = node_ctor(5, 0, 0);

    Node* node10 = node_ctor(10, node5, node17);

    Tree* tree0 = tree_ctor(node10, 5);

    print_node_pre(tree0->root, output);
    fprintf(output, "\n");

    add_node(tree0, tree0->root, 12);
    //add_node(tree0, tree0->root, 18);
    add_node(tree0, tree0->root, 3);
    add_node(tree0, tree0->root, 23);

    print_node_pre(tree0->root, output);
    fprintf(output, "\n\n");
    //print_node_post(tree0->root, output);
    //fprintf(output, "\n");
    //print_node_in(tree0->root, output);
    //fprintf(output, "\n");

    graph_dump(tree0);

    //txt_dump(tree0->root, output);

    tree_dtor(tree0);*/


    /*Tree* tree1 = {};
    FILE* input = fopen("TestData4.txt", "r");
    read_data(input, tree1);
    print_node_pre(tree1->root, output);
    tree_dtor(tree1);
    fclose(input);*/

    FILE* input1 = fopen("TestData7.txt", "r");
    Node* node2 = read_data(input1);
    Tree* tree2 = tree_ctor(node2, 5);
    print_node_pre(tree2->root, output);
    graph_dump(tree2);
    tree_dtor(tree2);

    //fclose(input1);
    fclose(output);

    return 0;
}
