/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:58:51 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/03 18:03:02 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	tree_clear(t_tree **root, void (*free_func)(void *ptr, size_t size))
{
	if (!root || !(*root))
		return ;
	if ((*root)->left)
		tree_clear(&(*root)->left, free_func);
	if ((*root)->right)
		tree_clear(&(*root)->right, free_func);
	free_func((*root)->content, (*root)->content_size);
	free(*root);
	*root = NULL;
}
