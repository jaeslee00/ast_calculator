/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 00:35:16 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:46:55 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdlib.h>

static t_list	*tack_element(t_list *old, t_list *tmp)
{
	t_list *ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (tmp && tmp->content && tmp->content_size > 0)
	{
		ret->content = malloc(tmp->content_size);
		if (!ret->content)
			return (NULL);
		ft_memcpy(ret->content, tmp->content, tmp->content_size);
		ret->content_size = tmp->content_size;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = NULL;
	ret->prev = old;
	if (old)
		old->next = ret;
	return (ret);
}

static void		fail_free(void *mem, size_t stub)
{
	(void)stub;
	free(mem);
}

t_list			*list_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*ret;
	t_list	*tmp;

	ret = NULL;
	start = NULL;
	while (lst)
	{
		tmp = f(lst);
		ret = tack_element(ret, tmp);
		if (!ret)
		{
			if (start)
				list_del(&start, &fail_free);
			return (NULL);
		}
		if (!start)
			start = ret;
		lst = lst->next;
	}
	return (start);
}
