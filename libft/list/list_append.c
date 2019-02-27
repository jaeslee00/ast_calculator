/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 23:25:24 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:46:55 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"

void	list_append(t_list **lst, t_list *node)
{
	t_list	*traverse;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = node;
		return ;
	}
	traverse = *lst;
	while (traverse->next)
		traverse = traverse->next;
	traverse->next = node;
	node->prev = traverse;
}
