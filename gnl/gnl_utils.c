/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:41:22 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/06 19:35:06 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	ret = malloc(len + 1);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	char	*ret;

	if (dst == NULL)
		return (ft_strdup(src));
	if (src == NULL)
		return (ft_strdup(dst));
	ret = malloc(ft_strlen(dst) + ft_strlen(src) + 1);
	i = 0;
	while (dst && dst[i])
	{
		ret[i] = dst[i];
		i++;
	}
	j = 0;
	while (src && src[j])
	{
		ret[i + j] = src[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}

int	ft_strichr(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-2);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

t_bool	in_value(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
