/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:59:25 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/26 18:00:12 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	array_init(t_array *array, size_t elem_size)
{
	array->ptr = NULL;
	array->reserved = 0;
	array->length = 0;
	array->elem_size = elem_size;
}
