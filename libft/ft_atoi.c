/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:13:48 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:14:12 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_whitespaces(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] && ft_isspace(str[index]))
		index++;
	return (index);
}

int				ft_atoi(const char *str)
{
	size_t	index;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	index = skip_whitespaces(str);
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] && ft_isdigit(str[index]))
	{
		result *= 10;
		result = result + (str[index] - '0') * sign;
		index++;
	}
	return (result);
}
