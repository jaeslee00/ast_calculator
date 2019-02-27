/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_shrink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:07:13 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/20 15:46:47 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_shrink(t_array *array)
{
	void	*new_ptr;
	size_t	malloc_size;

	malloc_size = array->elem_size * array->length;
	if (array->reserved <= malloc_size)
		return ;
	new_ptr = malloc(malloc_size);
	if (new_ptr && array->ptr)
		fast_copy(new_ptr, array->ptr, malloc_size);
	free(array->ptr);
	array->ptr = new_ptr;
	array->reserved = malloc_size;
}
