/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:34:10 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/11 22:22:01 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIST_H
# define _LIST_H

# include "libft.h"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

# define LST_CONT(list, type) (*(type*)(list)->content)

size_t			list_length(t_list *list);
t_list			*list_new(void const *content, size_t content_size);
void			list_swap(t_list *a, t_list *b);
void			list_delone(t_list **alst, void (*del)(void *, size_t));
void			list_del(t_list **alst, void (*del)(void *, size_t));
void			list_add(t_list **alst, t_list *new);
t_list			*list_pop(t_list **begin);
void			list_iter(t_list *lst, void (*f)(t_list *elem));
t_list			*list_map(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*list_search(t_list *lst, const void *ref, t_comparison cmp);
t_list			*list_rem(t_list **lst, const void *ref, t_comparison cmp);
void			list_append(t_list **lst, t_list *node);
void			list_rollback(t_list **lst);

#endif
