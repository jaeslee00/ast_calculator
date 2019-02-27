/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rollback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:47:05 by aamadori          #+#    #+#             */
/*   Updated: 2019/01/20 12:45:18 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"

void	list_rollback(t_list **lst)
{
	while (lst && (*lst) && (*lst)->prev)
		(*lst) = (*lst)->prev;
}
