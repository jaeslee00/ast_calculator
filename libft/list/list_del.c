/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:26:19 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:44:37 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

void	list_del(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*tmp_node;

	if (alst)
	{
		node = *alst;
		while (node)
		{
			del(node->content, node->content_size);
			tmp_node = node;
			node = node->next;
			free(tmp_node);
		}
		*alst = NULL;
	}
}
