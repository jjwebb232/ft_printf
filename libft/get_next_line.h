/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwebb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 07:21:38 by jwebb             #+#    #+#             */
/*   Updated: 2017/02/13 06:55:38 by jwebb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# define MAX_FD	1024
# define GNL gnl.list[gnl.i]
# define FD	gnl->list[gnl->i]
# include "libft.h"

typedef	struct		s_fd
{
	int				fd;
	int				read_total;
	char			*buff;
	int				size;
	int				status;
}					t_fd;

typedef struct		s_gnl
{
	int				i;
	int				files_open;
	t_fd			list[MAX_FD];
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
