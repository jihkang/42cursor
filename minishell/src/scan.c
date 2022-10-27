/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:07:54 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 19:57:44 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

t_token	*lexcial_syntax(char *str)
{
	char	**spt;
	t_token	*tkn;
	int		i;
	char	type;

	tkn = NULL;
	spt = ft_split(str, ' ');
	i = 0;
	while (spt[i])
	{
		add_last(&tkn, spt[i]);
		i++;
	}
	return (tkn);
}
