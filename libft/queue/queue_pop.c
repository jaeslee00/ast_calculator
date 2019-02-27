/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:55:01 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 19:03:33 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_list	*queue_pop(t_queue *queue)
{
	t_list	*pop;

	pop = list_pop(&queue->front);
	queue->size--;
	if (queue->size == 0)
		queue->back = NULL;
	return (pop);
}
