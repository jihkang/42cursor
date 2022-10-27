/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:24:18 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 20:20:06 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

static int	word_count(char *str, char c)
{
	int	chk;
	int	cnt;

	while (*str == c)
		str++;
	cnt = 0;
	chk = 1;
	while (*str)
	{
		if (*str == c)
			chk = 1;
		if (chk == 1 && *str != c)
		{
			cnt++;
			chk = 0;
		}
		str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char c)
{
	char	**ret;
	int		i;
	int		len;

	len = word_count(str, c);
	ret = ft_malloc(sizeof(char *) * (len + 2));
	while (*str == c)
		str++;
	i = 0;
	while (i < len)
	{
		ret[i] = ft_substr(str, 0, ft_strichr(str, c));
		str = ft_strchr(str, c);
		i++;
	}
	ret[len] = NULL;
	return (ret);
}

int	main()
{
	char	**ret;
	int		i;

	ret = ft_split("asdfqwer    '  asdfqe ' asdf", ' ');
	i = 0;
	while (ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
}