/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:19:19 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 16:52:08 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_malloc(size_t size)
{
	void	*data;

	data = malloc(size);
	if (data == NULL)
	{
		ft_perror("malloc error\n");
		exit(1);
	}
	return (data);
}

void	*ft_memset(void *data, int c, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char *)data;
	while (i < size)
	{
		tmp[i] = c;
		i++;
	}
	return (tmp);
}

void	*ft_memmove(void *dst, void *src, size_t size)
{
	unsigned char	*src_tmp;
	unsigned char	*dst_tmp;
	size_t			i;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	i = 0;
	while (i <= size)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst_tmp);
}
