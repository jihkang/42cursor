#include "list.h"
#include "utils.h"
#include <stdio.h>

void	add_list(t_list **lst, char *key, char *value)
{
	t_list	*hash;

	hash = add_hash(key, value);
	if (hash == NULL)
		return ;
	find_key(lst, hash);
}

void	print_hash(t_list *lst)
{
	printf("[key : %s], [value : %s], [next : %p]\n", (char *)lst->key, (char *)lst->value, lst->next);
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		print_hash(lst);
		lst = lst->next;
	}
	printf("\n\n");
}

void	clear_lst(t_list **lst)
{
	t_list	*hash;
	t_list	*temp;

	hash = *lst;
	while (hash)
	{
		temp = hash->next;
		delete_hash(hash);
		hash = NULL;
		hash = temp;
	}
}

void	test()
{
	t_list	*lst;

	lst = NULL;
	add_list(&lst, "a", ".");
	add_list(&lst, "b", "..3.");
	add_list(&lst, "c", "..3");
	add_list(&lst, "d", ".");
	add_list(&lst, "e", "gg`");
	add_list(&lst, "a", "test");
	print_lst(lst);
	clear_lst(&lst);
}
