/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:45:32 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/08 22:59:25 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree.h"

t_tree		*node_create(void *content, size_t content_size)
{
	t_tree	*new_node;

	if (!(new_node = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->type = RED;
	new_node->pos = 0;
	if (!(new_node->content = malloc(content_size)))
		return (NULL);
	ft_memcpy(new_node->content, content, content_size);
	new_node->content_size = content_size;
	return (new_node);
}

static int	insert_search(t_tree *root, t_tree *leaf, t_comparison cmp)
{
	t_tree	*traverse;
	t_tree	*curr;
	int		last_comparison;

	last_comparison = 1;
	curr = NULL;
	traverse = root;
	while (traverse)
	{
		curr = traverse;
		last_comparison = cmp(traverse->content, leaf->content);
		if (!last_comparison)
			return (0);
		traverse = last_comparison > 0 ? traverse->left : traverse->right;
	}
	leaf->pos = (last_comparison > 0) ? LEFT : RIGHT;
	if (last_comparison > 0)
		curr->left = leaf;
	else if (last_comparison < 0)
		curr->right = leaf;
	leaf->parent = curr;
	return (last_comparison);
}

int			tree_insert(t_tree **root, t_tree *leaf, t_comparison cmp)
{
	int			last_comparison;

	last_comparison = 1;
	if (!root)
		return (0);
	else if (*root == NULL)
		*root = leaf;
	else
		last_comparison = insert_search(*root, leaf, cmp);
	if (last_comparison)
		tree_rebalance(root, leaf);
	return (last_comparison);
}
