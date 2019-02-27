/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:20:22 by aamadori          #+#    #+#             */
/*   Updated: 2019/02/08 23:00:50 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H
# include "libft.h"

# define UNBALANCED 0
# define BLACK 1
# define RED 2
# define LEFT 0
# define RIGHT 1
# define ROOT -1

typedef struct	s_tree
{
	struct s_tree		*parent;
	struct s_tree		*left;
	struct s_tree		*right;
	int					type;
	int					pos;
	void				*content;
	size_t				content_size;
}				t_tree;

typedef void	(*t_tree_handler)(t_tree **root, t_tree* balance);

extern const t_tree_handler	g_insert_handlers[];

t_tree			*node_create(void *content, size_t content_size);
t_tree			*tree_grandparent(const t_tree *tree);
t_tree			*tree_uncle(const t_tree *tree);

void			tree_rotate_left(t_tree **root, t_tree *tree);
void			tree_rotate_right(t_tree **root, t_tree *tree);
void			tree_recolor_handler(t_tree **root, t_tree *balance);
void			tree_llb_handler(t_tree **root, t_tree *balance);
void			tree_lrb_handler(t_tree **root, t_tree *balance);
void			tree_rlb_handler(t_tree **root, t_tree *balance);
void			tree_rrb_handler(t_tree **root, t_tree *balance);
void			tree_rebalance(t_tree **root, t_tree *leaf);
int				tree_insert(t_tree **root, t_tree *leaf, t_comparison cmp);
void			tree_delete(t_tree **root, t_tree *leaf);
void			tree_clear(t_tree **root,
					void (*free_func)(void *ptr, size_t size));
t_tree			*tree_search(t_tree *root, const void *content,
					t_comparison cmp);
void			tree_pre_traverse(const t_tree *tree,
					void (*op)(const void *content));
void			tree_in_traverse(const t_tree *tree,
					void (*op)(const void *content));
void			tree_post_traverse(const t_tree *tree,
					void (*op)(const void *content));

#endif
