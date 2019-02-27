/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:21:37 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/30 12:40:00 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_pop_back(t_array *array, void (*destroy_func)(void*))
{
	if (destroy_func != NULL)
		destroy_func(array->ptr + (array->length - 1) * array->elem_size);
	array->length--;
}
