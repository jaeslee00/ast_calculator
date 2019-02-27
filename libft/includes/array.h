/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:41:30 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/10 17:35:38 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARRAY_H
# define _ARRAY_H

# include "libft.h"

# define ARRAY_PTR(arr, type) ((type*)(arr).ptr)

typedef struct		s_array
{
	char	*ptr;
	size_t	elem_size;
	size_t	length;
	size_t	reserved;
}					t_array;

void				fast_copy(void *dst, const void *src, size_t size);
void				array_init(t_array *array, size_t elem_size);
void				array_reserve(t_array *array, size_t size);
void				array_shrink(t_array *array);
void				array_clear(t_array *array, void (*destroy_func)(void*));
void				array_push_back(t_array *array, const void *elem);
void				array_pop_back(t_array *array, void (*destroy_func)(void*));

#endif
