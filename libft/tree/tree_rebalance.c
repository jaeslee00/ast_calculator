/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_rebalance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 20:41:01 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/02 02:47:34 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

const t_tree_handler	g_insert_handlers[] = {
	tree_llb_handler,
	tree_recolor_handler,
	tree_lrb_handler,
	tree_recolor_handler,
	tree_rlb_handler,
	tree_recolor_handler,
	tree_rrb_handler,
	tree_recolor_handler
};

void	tree_rebalance(t_tree **root, t_tree *leaf)
{
	size_t	function_index;

	if (leaf->parent == NULL)
	{
		leaf->type = BLACK;
		leaf->pos = ROOT;
		return ;
	}
	if (leaf->parent->type == BLACK || leaf->parent->parent == NULL)
		return ;
	function_index = 0;
	function_index |= ((size_t)leaf->pos << 2);
	function_index |= ((size_t)leaf->parent->pos << 1);
	if (tree_uncle(leaf))
		function_index |= (size_t)tree_uncle(leaf)->type - BLACK;
	g_insert_handlers[function_index](root, leaf);
}
