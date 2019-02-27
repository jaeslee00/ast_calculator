/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:10:19 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:00 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (src < dst && src + len > dst)
	{
		while (len-- > 0)
			((char*)dst)[len] = ((char*)src)[len];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char*)dst)[index] = ((char*)src)[index];
			index++;
		}
	}
	return (dst);
}
