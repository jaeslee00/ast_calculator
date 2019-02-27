/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:20:24 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/11 22:21:50 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_swap(t_list *a, t_list *b)
{
    void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}