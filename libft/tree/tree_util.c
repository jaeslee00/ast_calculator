/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 23:00:16 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/08 23:07:45 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

t_tree	*tree_grandparent(const t_tree *tree)
{
	if (tree != NULL && tree->parent != NULL)
		return (tree->parent->parent);
	else
		return (NULL);
}

t_tree	*tree_uncle(const t_tree *tree)
{
	t_tree	*grandparent;

	if (!(grandparent = tree_grandparent(tree)))
		return (NULL);
	if (tree->parent == grandparent->left)
		return (grandparent->right);
	else
		return (grandparent->left);
}
