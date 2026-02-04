/* tree.h */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <errno.h>


typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;

typedef struct s_node Node;


// Node structure
struct s_node {
    struct u_tree *north; // upward link, ie linked list
    struct s_node *west;
    struct s_leaf *east; // Notice datatype difference 

    int8 path[256];


};



