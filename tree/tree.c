/* tree.c */

#include "tree.h"

Tree root = {
    .n = {
        .tag = (TagRoot |TagNode),
        .north = (Node *)&root,
        .west  = 0,
        .east  = 0,
        .path  = "/"
    }
};


/*

struct s_node {
    struct s_node *north; // upward link, ie linked list
    struct s_node *west;
    struct s_leaf *east; // Notice datatype difference 

    int8 path[256];


};

*/

void zero(int8 *str, int16 size){
    int8 *p;
    int16 n;

    for (n=0, p=str; n < size; p++, n++)
        *p = 0;

    return;
}

Node *create_node(Node *parent, int8 *path){
    Node *n;
    int16 size;

    assert(parent);
    size = sizeof(struct s_node);
    n = (Node *)malloc(size);
    zero((int8 *)n, size);

    parent->west = n;
    n->tag = TagNode;
    n->north = parent;
    strncpy((char *)n->path, (char *)path,255);
        
    return n;
}


int main(){
    Node *n, *n2;
    n = create_node(&root, "/Users");
    assert(n);
    n2 = create_node(n, "/Users/login");
    assert(n2);

    printf("%p %p\n", n, n2);
    free(n2);
    free(n);
    return 0;
}