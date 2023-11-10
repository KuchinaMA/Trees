#include <stdio.h>

#include "Tree.h"

int main () {

    Node* node15 = node_ctor(15, 0, 0);
    Node* node20 = node_ctor(20, 0, 0);

    Node* node17 = node_ctor(17, node15, node20);
    Node* node5 = node_ctor(5, 0, 0);

    Node* node10 = node_ctor(10, node5, node17);

    Tree* tree0 = tree_ctor(node10, 5);

    //print_node_pre(tree0->root);
    //printf("\n\n");
    //print_node_post(tree0->root);
    //printf("\n\n");
    print_node_in(tree0->root);
    printf("\n\n");

    add_node(tree0, tree0->root, 12);

    //print_node_pre(tree0->root);
    //printf("\n\n");
    //print_node_post(tree0->root);
    //printf("\n\n");
    print_node_in(tree0->root);
    printf("\n\n");

    tree_dtor(tree0);

    return 0;
}
