/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 04:54:46 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/08 23:07:31 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

void	tree_rotate_left(t_tree **root, t_tree *tree)
{
	t_tree	*tmp;

	tmp = tree->right;
	tree->right = tmp->left;
	if (tmp->left != NULL)
	{
		tmp->left->parent = tree;
		tmp->left->pos = RIGHT;
	}
	tmp->parent = tree->parent;
	if (tree->parent == NULL)
		*root = tmp;
	else if (tree->pos == LEFT)
		tree->parent->left = tmp;
	else
		tree->parent->right = tmp;
	tmp->left = tree;
	tree->parent = tmp;
	tmp->pos = tree->pos;
	tree->pos = LEFT;
}

void	tree_rotate_right(t_tree **root, t_tree *tree)
{
	t_tree *tmp;

	tmp = tree->left;
	tree->left = tmp->right;
	if (tmp->right != NULL)
	{
		tmp->right->parent = tree;
		tmp->right->pos = LEFT;
	}
	tmp->parent = tree->parent;
	if (tree->parent == NULL)
		*root = tmp;
	else if (tree->pos == LEFT)
		tree->parent->left = tmp;
	else
		tree->parent->right = tmp;
	tmp->right = tree;
	tree->parent = tmp;
	tmp->pos = tree->pos;
	tree->pos = RIGHT;
}
