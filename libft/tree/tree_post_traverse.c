/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_post_traverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:41:46 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/03 18:41:57 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_post_traverse(const t_tree *tree, void (*op)(const void *content))
{
	if (!tree)
		return ;
	if (tree->left)
		tree_post_traverse(tree->left, op);
	op(tree->content);
	if (tree->right)
		tree_post_traverse(tree->right, op);
}
