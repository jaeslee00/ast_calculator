/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:48:24 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/28 15:50:11 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*list_pop(t_list **begin)
{
	t_list	*ret;

	if (!begin || !(*begin))
		return (NULL);
	ret = *begin;
	*begin = (*begin)->next;
	ret->next = NULL;
	return (ret);
}
