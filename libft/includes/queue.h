/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:52:32 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/08 22:51:44 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _QUEUE_H
# define _QUEUE_H

# include "libft.h"
# include "list.h"

typedef struct	s_queue
{
	t_list	*front;
	t_list	*back;
	size_t	size;
}				t_queue;

void			queue_init(t_queue *queue);
void			queue_destroy(t_queue *queue,
					void (*free_func)(void *, size_t size));
t_list			*queue_pop(t_queue *queue);
void			queue_push(t_queue *queue, t_list *node);

#endif
