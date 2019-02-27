/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:06:36 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 12:40:26 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_clear(t_array *array, void (*destroy_func)(void*))
{
	size_t	index;

	index = 0;
	while (index < array->length)
	{
		if (destroy_func != NULL)
			destroy_func(array->ptr + (index * array->elem_size));
		index++;
	}
	free(array->ptr);
	array->ptr = 0;
	array->length = 0;
	array->reserved = 0;
}
