/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:34:42 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:51 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		is_space_nline_tab(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static size_t	length_last_char(char const *s)
{
	size_t index;
	size_t length;

	index = 0;
	length = 0;
	while (s[index])
	{
		if (!is_space_nline_tab(s[index]))
			length = index + 1;
		index++;
	}
	return (length);
}

char			*ft_strtrim(char const *s)
{
	size_t	index;
	size_t	length;
	char	*copy;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index] && is_space_nline_tab(s[index]))
		index++;
	length = length_last_char(s + index);
	copy = ft_strnew(length);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s + index, length);
	return (copy);
}
