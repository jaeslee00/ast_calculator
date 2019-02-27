/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_pre_traverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:19:38 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/03 18:26:52 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_pre_traverse(const t_tree *tree, void (*op)(const void *content))
{
	if (!tree)
		return ;
	op(tree->content);
	if (tree->left)
		tree_pre_traverse(tree->left, op);
	if (tree->right)
		tree_pre_traverse(tree->right, op);
}
