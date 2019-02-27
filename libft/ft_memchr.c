/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:53:59 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:15:52 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char*)s)[index] == (unsigned char)c)
			return ((char*)s + index);
		index++;
	}
	return (NULL);
}
