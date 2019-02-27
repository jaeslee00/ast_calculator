/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_recolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 23:40:48 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/08 23:06:51 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

void	tree_recolor_handler(t_tree **root, t_tree *balance)
{
	t_tree	*parent;
	t_tree	*grandparent;

	parent = balance->parent;
	parent->type = BLACK;
	tree_uncle(balance)->type = BLACK;
	grandparent = parent->parent;
	grandparent->type = RED;
	if (grandparent->parent == NULL)
		grandparent->type = BLACK;
	else if (grandparent->parent->type == RED)
		tree_rebalance(root, grandparent);
}
