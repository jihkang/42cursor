#include "list.h"
#include "utils.h"

t_list	*add_hash(char *key, char *value)
{
	t_list	*hash;

	hash = ft_calloc(sizeof(t_list));
	hash->key = ft_strdup(key);
	hash->value = ft_strdup(value);
	return (hash);
}

void	delete_hash(t_list *hash)
{
	free(hash->key);
	free(hash->value);
	free(hash);
}

void	change_list(t_list **lst, t_list *new_hash)
{
	new_hash->next = (*lst)->next;
	delete_hash(*lst);
	*lst = new_hash;
}

void	find_key(t_list **lst, t_list *new_hash)
{
	t_list	*cur;

	cur = *lst;
	if (cur == NULL && (*lst = new_hash))
		return ;
	if (!ft_strcmp(cur->key, new_hash->key))
	{
		new_hash->next = cur->next;
		delete_hash(cur);
		*lst = new_hash;
		return ;
	}
	while (cur->next)
	{
		if (!ft_strcmp(cur->next->key, new_hash->key))
		{
			change_list(&(cur->next), new_hash);
			return ;
		}
		cur = cur->next;
	}
	cur->next = new_hash;
}

char	*get_value(t_list *lst, char *key)
{
	while (lst)
	{
		if (!(ft_strcmp(lst->key, key)))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}
