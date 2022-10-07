#include "tree.h"
#include <stdlib.h>

t_tree	*add_node(t_tree *parent, int key)
{
	t_tree *node;

	node = malloc(sizeof(t_tree));
	node->parent = parent;
	node->key = key;
	if (parent)
		node->depth = parent->depth + 1;
	else
		node->depth = 0;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_tree	*add_tree(t_tree *root, int key)
{
	if (root == NULL)
		return (add_node(NULL, key));
	if (root->key < key)
	{
		if (root->right == NULL)
		{
			root->right = add_node(root, key);
		}
		else
		{
			add_tree(root->right, key);
		}
	}
	if (root->key > key)
	{
		if (root->left == NULL)
			root->left = add_node(root, key);
		else
			add_tree(root->left, key);
	}	
	return (root);
}

void	print_tree(t_tree *root)
{
	printf("depth : %d value : %d\n",root->depth, root->key);
	if (root->left)
	{
		print_tree(root->left);
	}
	if (root->right)
	{
		print_tree(root->right);
	}
}

int	print_tree_depth(t_tree *root, int dep)
{
	int	flag;

	flag = 0;
	if (root->depth == dep)
	{
		printf("value : %d\t", root->key);
		flag = 1;
		return flag;
	}
	if (root->depth < dep)
	{
		if (root->right)
			flag = print_tree_depth(root->right, dep);
		if (root->left)
			flag = print_tree_depth(root->left, dep);
	}
	return (flag);
}

t_tree	*find_tree(t_tree *root, int key)
{
	if (root == NULL)
		return (NULL);
	if (root->key == key)
		return (root);
	else if (root->key < key)
		return find_tree(root->right, key);
	else
		return (find_tree(root->left, key));
}

void	remove_tree(t_tree *root)
{
	t_tree	*temp;
	
	if (root == NULL)
		return ;
	temp = root;
	remove_tree(root->left);
	remove_tree(root->right);
	free(root);
}

void	test()
{
	t_tree	*tree;
	int		num;
	int 	i;

	i = 0;
	while (i < 10)
	{
		num = rand() % 100;
		tree = add_tree(tree, num);
		i++;
	}
	print_tree(tree);
	remove_tree(tree);
}

int main()
{
	test();
	system("leaks a.out");
}
