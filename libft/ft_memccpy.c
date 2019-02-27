/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:19:04 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:15:49 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	index;
	char	found;

	index = 0;
	found = 0;
	while (!found && index < n)
	{
		((unsigned char*)dst)[index] = ((unsigned char*)src)[index];
		if (((unsigned char*)src)[index] == (unsigned char)c)
			found = 1;
		index++;
	}
	if (found)
		return ((unsigned char*)dst + index);
	return (NULL);
}
