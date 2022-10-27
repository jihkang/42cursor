/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:26:56 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 19:53:16 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "utils.h"
#include <stdio.h>

t_token	*add_tkn(char *value)
{
	t_token	*tkn;

	tkn = (t_token *)ft_malloc(sizeof(t_token));
	ft_memset(tkn, 0, sizeof(t_token));
	tkn->value = ft_strdup(value);
	return (tkn);
}

void	add_first(t_token **tkn, char *value)
{
	t_token	*add;

	add = add_tkn(value);
	if (*tkn == NULL)
	{
		*tkn = add;
		return ;
	}
	add->next = (*tkn);
	(*tkn) = add;
}

void	add_last(t_token **tkn, char *value)
{
	t_token	*add;
	t_token	*cur;

	cur = (*tkn);
	add = add_tkn(value);
	if (cur == NULL)
	{
		*tkn = add;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = add;
}

void	clear_list(t_token **tkn)
{
	t_token	*temp;

	while (*tkn)
	{
		temp = (*tkn)->next;
		free((*tkn)->value);
		free((*tkn));
		*tkn = temp;
		temp = NULL;
	}
}

void	print_list(t_token *tkn)
{
	while (tkn)
	{
		printf("value: %s\n", tkn->value);
		tkn = tkn->next;
	}
}
/**
 * test list
 * 

void	test()
{
	t_token	*test;

	test = NULL;
	add_last(&test, TYPE_STR, "hi");
	add_last(&test, TYPE_STR, "bye");
	add_first(&test, TYPE_STR, "b..");
	print_list(test);
	clear_list(&test);
}
int	main()
{
	test();
	// system("leaks a.out");
}
*/