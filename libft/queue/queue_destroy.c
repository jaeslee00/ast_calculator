/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:06:02 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 19:07:49 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_destroy(t_queue *queue, void (*free_func)(void *, size_t size))
{
	list_del(&queue->front, free_func);
	queue->back = NULL;
	queue->size = 0;
}
