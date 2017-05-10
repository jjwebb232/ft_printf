/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 07:20:39 by jwebb             #+#    #+#             */
/*   Updated: 2017/01/27 05:05:44 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(t_gnl *gnl, void *line)
{
	int		offset;
	char	*temp;

	if (!line)
	{
		if (FD.buff && ft_strlen(FD.buff))
		{
			temp = ft_strsub(FD.buff, 0, FD.read_total);
			FD.buff = NULL;
			FD.status = 1;
			return (temp);
		}
		FD.fd = -1;
		return (ft_strdup(""));
	}
	offset = line - (void *)FD.buff;
	temp = ft_strsub(FD.buff, 0, offset);
	ft_memmove(FD.buff, FD.buff + offset + 1, FD.size - offset);
	FD.read_total -= offset + 1;
	ft_bzero(FD.buff + FD.read_total, FD.size - FD.read_total);
	FD.status = 1;
	return (temp);
}

static char	*find_next_line(t_gnl *gnl)
{
	int		read_count;
	void	*line;

	line = NULL;
	if (FD.read_total && FD.buff)
		line = ft_memchr(FD.buff, '\n', FD.read_total);
	while (!line)
	{
		if (FD.read_total + BUFF_SIZE > FD.size)
		{
			FD.size = FD.read_total + BUFF_SIZE;
			FD.buff = (char *)ft_realloc((void *)FD.buff, FD.size);
		}
		if ((read_count = read(FD.fd, FD.buff + FD.read_total, BUFF_SIZE)) < 1)
		{
			FD.status = read_count;
			if (!read_count)
				return (next_line(gnl, NULL));
			return (NULL);
		}
		FD.read_total += read_count;
		line = ft_memchr(FD.buff, '\n', FD.read_total);
	}
	return (next_line(gnl, line));
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;

	if (fd < 0 || !line)
		return (-1);
	gnl.i = 0;
	if (!gnl.files_open)
	{
		gnl.files_open = 1;
		GNL.fd = fd;
		GNL.size = BUFF_SIZE;
		GNL.buff = (char *)malloc(BUFF_SIZE);
	}
	else
		while (gnl.i < gnl.files_open && GNL.fd != fd)
			if (++gnl.i == gnl.files_open)
			{
				++gnl.files_open;
				GNL.fd = fd;
				GNL.size = BUFF_SIZE;
				GNL.buff = (char *)malloc(BUFF_SIZE);
			}
	*line = find_next_line(&gnl);
	return (GNL.status);
}
