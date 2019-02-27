/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:06:13 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:17:48 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index_1;
	size_t index_2;

	index_1 = 0;
	index_2 = 0;
	while (s1[index_1])
		index_1++;
	while (index_2 < n && s2[index_2])
	{
		s1[index_1] = s2[index_2];
		index_1++;
		index_2++;
	}
	s1[index_1] = '\0';
	return (s1);
}
