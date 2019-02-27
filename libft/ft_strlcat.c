/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:09:49 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:17:39 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;
	size_t src_index;

	index = 0;
	src_index = 0;
	while (index < size && dst[index])
		index++;
	while (index + 1 < size && src[src_index])
	{
		dst[index] = src[src_index];
		index++;
		src_index++;
	}
	if (index < size)
		dst[index] = '\0';
	return (index + ft_strlen(&src[src_index]));
}
