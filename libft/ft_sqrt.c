/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:55:51 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/07 18:53:37 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(double num)
{
	double x;
	double old_x;

	old_x = 0;
	x = num;
	while (x - old_x > 1.0e-8 || x - old_x < -1.0e-8)
	{
		old_x = x;
		x -= ((x * x) - num) / (2 * x);
	}
	return (x);
}
