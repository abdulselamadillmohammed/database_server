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

// Node structure
struct s_node {
    struct s_node *north; // upward link, ie linked list
    struct s_node *west;
    struct s_leaf *east; // Notice datatype difference 
};
