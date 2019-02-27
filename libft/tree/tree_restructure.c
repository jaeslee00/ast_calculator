/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_restructure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:19:35 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/03 18:16:47 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

void	tree_llb_handler(t_tree **root, t_tree *balance)
{
	t_tree	*grandparent;

	grandparent = balance->parent->parent;
	balance->parent->type = BLACK;
	grandparent->type = RED;
	tree_rotate_right(root, grandparent);
}

void	tree_rrb_handler(t_tree **root, t_tree *balance)
{
	t_tree	*grandparent;

	grandparent = balance->parent->parent;
	balance->parent->type = BLACK;
	grandparent->type = RED;
	tree_rotate_left(root, grandparent);
}

void	tree_rlb_handler(t_tree **root, t_tree *balance)
{
	tree_rotate_left(root, balance->parent);
	tree_llb_handler(root, balance->left);
}

void	tree_lrb_handler(t_tree **root, t_tree *balance)
{
	tree_rotate_right(root, balance->parent);
	tree_rrb_handler(root, balance->right);
}
