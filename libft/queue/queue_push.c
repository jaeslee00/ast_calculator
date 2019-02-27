/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:58:36 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 19:03:11 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_push(t_queue *queue, t_list *node)
{
	list_append(&queue->back, node);
	if (queue->size == 0)
		queue->front = queue->back;
	else
		queue->back = queue->back->next;
	queue->size++;
}
