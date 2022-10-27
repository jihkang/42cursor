/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:19:16 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 20:20:19 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, int s, int e)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len < s)
		return (NULL);
	if (len < e)
		e = len;
	ret = (char *)ft_malloc(e - s + 1);
	i = 0;
	while (str[i + s] && i + s < e)
	{
		ret[i] = str[i + s];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

size_t	ft_strichr(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (i == 0)
		return (-1);
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	i = ft_strichr(str, c);
	if (i == -1)
		return (NULL);
	while (str[i] == c)
		i++;
	return (str + i);
}

char	*ft_strdup(char *str)
{
	if (str == NULL)
		return (NULL);
	return (ft_substr(str, 0, ft_strlen(str)));
}
