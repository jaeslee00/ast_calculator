/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:59:19 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/03 18:05:45 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree	*tree_search(t_tree *root, const void *content, t_comparison cmp)
{
	int	last_comparison;

	while (root)
	{
		last_comparison = cmp(root->content, content);
		if (!last_comparison)
			return (root);
		else if (last_comparison > 0)
			root = root->left;
		else
			root = root->right;
	}
	return (NULL);
}
