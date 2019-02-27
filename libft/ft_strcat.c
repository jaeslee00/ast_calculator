/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:50:16 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:40 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t index_1;
	size_t index_2;

	index_1 = 0;
	index_2 = 0;
	while (s1[index_1])
		index_1++;
	while (s2[index_2])
	{
		s1[index_1] = s2[index_2];
		index_1++;
		index_2++;
	}
	s1[index_1] = '\0';
	return (s1);
}
