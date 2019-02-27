/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:02:07 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 19:02:52 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_init(t_queue *queue)
{
	queue->front = NULL;
	queue->back = NULL;
	queue->size = 0;
}
