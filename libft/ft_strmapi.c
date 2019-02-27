/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:51:49 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:17:43 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*new;

	new = NULL;
	if (s)
	{
		index = 0;
		new = (char*)malloc(ft_strlen(s) + 1);
		while (new && s[index])
		{
			new[index] = f(index, s[index]);
			index++;
		}
		if (new)
			new[index] = '\0';
	}
	return (new);
}
