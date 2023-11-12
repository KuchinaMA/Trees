#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

const int TREE_POISON = -555;
const size_t MAX_LINE_LEN = 1000;

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

Tree* tree_ctor(Node* root, size_t size);
int tree_dtor(Tree* tree);

int add_node(Tree* tree, Node* node, int data);

void print_node_pre(Node* node, FILE* output);
void print_node_post(Node* node, FILE* output);
void print_node_in(Node* node, FILE* output);

Node* read_node(FILE* file);
Node* read_data(FILE* file);


#endif // TREE_H_INCLUDED
