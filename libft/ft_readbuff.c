/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readbuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:13:23 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:37 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_readbuff(int fd, char *buff, size_t len)
{
	ssize_t	bytes;
	size_t	index;

	index = 0;
	while (index < len
		&& (bytes = read(fd, buff + index, len - index)) > 0)
	{
		index += bytes;
	}
	if (bytes < 0)
		return (bytes);
	return (index);
}
