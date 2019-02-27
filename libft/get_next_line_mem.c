/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_mem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 23:22:45 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/12 23:31:47 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		fd_match(const void *ref, const void *buff)
{
	if (*((int*)ref) == ((t_filebuffer*)buff)->fd)
		return (0);
	return (1);
}

void	free_buffer(void *buffer, size_t stub)
{
	(void)stub;
	free(((t_filebuffer*)buffer)->text_buffer);
	free(buffer);
}
