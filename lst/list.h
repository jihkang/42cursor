#ifndef LIST_H
# define LIST_H

typedef struct	s_list
{
	void			*key;
	void			*value;
	struct s_list	*next;
}t_list;

t_list	*add_hash(char *key, char *value);
void	delete_hash(t_list *hash);
void	change_list(t_list **lst, t_list *new_hash);
void	find_key(t_list **lst, t_list *new_hash);
char	*get_value(t_list *lst, char *key);

#endif
