/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:50:08 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:48:14 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_list	*node_init(const int fd)
{
	t_filebuffer	buffer;
	t_list			*node;

	if (!(buffer.text_buffer = ft_memalloc(BUFF_SIZE + 1)))
		return (NULL);
	buffer.fd = fd;
	buffer.index = 0;
	buffer.size = 0;
	if (!(node = list_new(&buffer, sizeof(t_filebuffer))))
		return (NULL);
	return (node);
}

static size_t	fill_buffer(t_filebuffer *buff)
{
	buff->index = 0;
	buff->size = read(buff->fd, buff->text_buffer, BUFF_SIZE);
	if (buff->size < 0)
		return (buff->size);
	buff->text_buffer[buff->size] = '\0';
	return (buff->size);
}

static ssize_t	read_line(t_filebuffer *buff, char **line)
{
	char	*end;
	char	*tmp;
	ssize_t	bytes;

	if (!((*line) = ft_strnew(0)))
		return (-1);
	end = NULL;
	while (!end)
	{
		if ((buff->size <= 0 || buff->index >= buff->size)
			&& (bytes = fill_buffer(buff)) <= 0)
			return (bytes);
		end = ft_strnstr(buff->text_buffer + buff->index, "\n",
				buff->size - buff->index);
		if (end)
			*end = '\0';
		tmp = (*line);
		(*line) = ft_strjoin(tmp, buff->text_buffer + buff->index);
		free(tmp);
		if (!(*line))
			return (-1);
		buff->index = end ? (end - buff->text_buffer + 1) : buff->size;
	}
	return (buff->size);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*buffer_list;
	t_list			*match;
	t_filebuffer	*buff;

	if (!line)
		return (-1);
	match = list_search(buffer_list, (void*)&fd, &fd_match);
	if (!match)
	{
		match = node_init(fd);
		if (!match)
			return (-1);
		list_add(&buffer_list, match);
	}
	buff = (t_filebuffer*)match->content;
	if (read_line(buff, line) < 0)
		return (-1);
	if (!buff->size && !ft_strlen(*line))
	{
		match = list_rem(&buffer_list, &fd, fd_match);
		list_delone(&match, free_buffer);
		return (0);
	}
	return (1);
}
