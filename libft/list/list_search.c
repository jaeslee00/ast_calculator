/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:31:59 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:45:20 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"

t_list	*list_search(t_list *lst, const void *ref, t_comparison cmp)
{
	while (lst)
	{
		if (!cmp(lst->content, ref))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
