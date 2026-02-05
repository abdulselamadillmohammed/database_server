/* tree.h */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <errno.h>

typedef void* Nullptr;
Nullptr nullptr = 0 ;


#define TagRoot  1
#define TagNode  2
#define TagLeaf  4

#define find_last(x)     find_last_linear(x)
#define reterr(x) \
    errno = (x);
    return nullptr;



typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;

typedef unsigned char Tag;



// Node structure
struct s_node {
    Tag tag; 
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