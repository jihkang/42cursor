/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihkang <jihkang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:16:54 by jihkang           #+#    #+#             */
/*   Updated: 2022/10/06 20:12:38 by jihkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/gnl.h"
#include <stdio.h>

int	read_line_fd(int fd, char **buf)
{
	char	read_buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		r;

	while (TRUE)
	{
		r = read(fd, read_buf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		read_buf[r] = 0;
		tmp = *buf;
		*buf = ft_strjoin(tmp, read_buf);
		if (tmp != NULL)
			free(tmp);
		if (in_value(read_buf, '\n'))
			break ;
	}
	return (r);
}

int	get_line(char **line, char *buf)
{
	int	ind;

	ind = ft_strichr(buf, '\n');
	if (ind < 0)
		return (-1);
	if (buf[0] == 0)
		return (-1);
	buf[ind] = 0;
	*line = ft_strdup(buf);
	buf[ind] = '\n';
	return (ind + 1);
}

void	remain_buf(char **buf, int ind)
{
	char	*remain;

	remain = *buf;
	*buf = ft_strdup(remain + ind);
	free(remain);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	int			ind;
	char		*line;

	if (fd < 0 || fd > 65536)
		return (NULL);
	line = NULL;
	if (read_line_fd(fd, &buf) < 0)
		return (NULL);
	ind = get_line(&line, buf);
	if (ind == -1)
		return (line);
	remain_buf(&buf, ind);
	return (line);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (0);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
}