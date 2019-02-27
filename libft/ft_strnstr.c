/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:23 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:17:03 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t offset;

	offset = 0;
	while (haystack[offset] && offset + ft_strlen(needle) <= len)
	{
		if (!ft_strncmp(&haystack[offset], needle, ft_strlen(needle)))
			return ((char*)&haystack[offset]);
		offset++;
	}
	if (!haystack[0] && !needle[0] && len > 0)
		return ((char*)haystack);
	return (NULL);
}
