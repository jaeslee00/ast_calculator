/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:32:51 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:38 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char*)&s[index]);
		index++;
	}
	if (s[index] == (char)c)
		return ((char*)&s[index]);
	return (NULL);
}
