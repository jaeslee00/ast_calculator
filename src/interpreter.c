/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:50:38 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/27 04:31:56 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_calc.h"
#include <stdio.h>



ssize_t		interpreter(t_ast *ptr_ast)
{
	if (ptr_ast->token->type == FT_UNARY_ADD)
		return (1 * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_UNARY_SUB)
		return ((-1) * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_ADD)
		return (interpreter(ptr_ast->left) + interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_SUB)
		return (interpreter(ptr_ast->left) - interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_MUL)
		return (interpreter(ptr_ast->left) * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_DIV)
		return (interpreter(ptr_ast->left) / interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == FT_INTEGER)
		return (ptr_ast->token->value);
	return (0);
}
