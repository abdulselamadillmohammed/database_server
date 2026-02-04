/* tree.h */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <errno.h>


#define TagRoot 
#define TagNode
#define TagLeaf

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;
typedef unsigned char Tag;



// Node structure
struct s_node {
    struct s_node *north; // upward link, ie linked list
    struct s_node *west;
    struct s_leaf *east; // Notice datatype difference 

    int8 path[256];


};

typedef struct s_node Node;

struct s_leaf {
    Tag tag; 
    union u_tree *west;
    struct s_leaf *east;
    int8 key[128];
    int8 *value;
    int16 size;
};
 
typedef struct s_leaf Leaf;

union u_tree { 
    Node n;
    Leaf l;
};

typedef union u_tree Tree;