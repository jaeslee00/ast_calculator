/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:12:30 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/29 16:13:19 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

size_t	list_length(t_list *list)
{
	size_t	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
