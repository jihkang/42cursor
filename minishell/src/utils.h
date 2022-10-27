/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:19:52 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/27 18:36:01 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define STDERR 2

# include <stdlib.h>

/**	m_utils.c	*/
void	*ft_memset(void *data, int c, size_t size);
void	*ft_malloc(size_t size);
void	*ft_memmove(void *dst, void *src, size_t size);
/**	p_utils.c	*/
void	ft_perror(char *str);
/**	s_utils.c	*/
size_t	ft_strlen(char *str);
char	*ft_substr(char *str, int s, int e);
char	*ft_strchr(char *str, char c);
size_t	ft_strichr(char *str, char c);
char	*ft_strdup(char *str);
/** split.c	 	*/
char	**ft_split(char *str, char c);

#endif