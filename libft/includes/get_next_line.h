/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:12:50 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:48:04 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 16384
# define NODE_BUFF(n) ((t_filebuffer*)((n)->content))
# define CURR_PTR(n) (NODE_BUFF(n)->text_buffer + NODE_BUFF(n)->index)

# include <sys/types.h>

typedef struct	s_filebuffer
{
	int		fd;
	char	*text_buffer;
	ssize_t	index;
	ssize_t	size;
}				t_filebuffer;

int				get_next_line(const int fd, char **line);
int				fd_match(const void *ref, const void *buff);
void			free_buffer(void *buffer, size_t stub);

#endif
