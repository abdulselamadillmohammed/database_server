/* tree.h */

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <assert.h>
#include <errno.h>

// Node structure
struct s_node {
    struct s_node *north; // upward link, ie linked list
    struct s_node *west;
    struct s_leaf *east; // Notice datatype difference 
}
