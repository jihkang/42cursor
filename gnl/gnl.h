/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:40:59 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/06 19:41:28 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}t_bool;
/*
	BUFFER_SIZE income 
	change buffer size 32
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# elif BUFFER_SIZE > 1024 && BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *dst, char *src);
int		ft_strichr(char *str, char c);
t_bool	in_value(char *str, char c);

char	*get_next_line(int fd);

#endif