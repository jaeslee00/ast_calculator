/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:17:45 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/22 18:24:33 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_push_back(t_array *array, const void *elem)
{
	if (array->reserved == 0)
		array_reserve(array, array->elem_size);
	else if (array->reserved <= array->length * array->elem_size)
		array_reserve(array, array->reserved * 2);
	fast_copy(array->ptr + array->length * array->elem_size,
		elem, array->elem_size);
	array->length++;
}
