/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:30:32 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/06 11:16:25 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		divisor;
	char	first_digit;

	if (n < 0)
		ft_putchar('-');
	divisor = 1000000000;
	first_digit = 0;
	while (divisor > 0)
	{
		if (first_digit || ABS(n / divisor) > 0)
		{
			ft_putchar(ABS(n / divisor) + '0');
			n -= (n / divisor) * divisor;
			first_digit = 1;
		}
		divisor /= 10;
	}
	if (!first_digit)
		ft_putchar('0');
}
