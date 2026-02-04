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


int main(){
    printf("%p\n", (void *)&root);
    return 0;
}