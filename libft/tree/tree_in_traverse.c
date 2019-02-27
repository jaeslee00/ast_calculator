/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_in_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:26:34 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/03 18:40:44 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_in_traverse(const t_tree *tree, void (*op)(const void *content))
{
	if (!tree)
		return ;
	if (tree->left)
		tree_in_traverse(tree->left, op);
	op(tree->content);
	if (tree->right)
		tree_in_traverse(tree->right, op);
}
