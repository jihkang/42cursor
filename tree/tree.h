#ifndef	TREE_H
# define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}t_bool;

typedef struct s_tree
{
	struct s_tree	*parent;
	struct s_tree	*left;
	struct s_tree	*right;
	int				key;
	int				depth;
}t_tree;

#endif
