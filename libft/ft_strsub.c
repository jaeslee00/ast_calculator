/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:09:10 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:53 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	substr = NULL;
	if (s)
	{
		substr = malloc(len + 1);
		if (substr)
		{
			ft_memcpy(substr, s + start, len);
			substr[len] = '\0';
		}
	}
	return (substr);
}
