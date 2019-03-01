/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 03:50:38 by jaelee            #+#    #+#             */
/*   Updated: 2019/03/01 17:58:33 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_calc.h"
#include <stdio.h>

static void	interpret_error(t_ast *ast)
{
	free_program(ast);
	exit(0);
}

static void	division_by_zero(t_ast *ast)
{
	free_program(ast);
	printf("division by zero is undefined\n");
	exit(0);
}

ssize_t		interpreter(t_ast *ptr_ast)
{
	if (!ptr_ast)
		interpret_error(ptr_ast);
	if (ptr_ast->token->type == _UNARY_ADD)
		return (1 * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == _UNARY_SUB)
		return ((-1) * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == _ADD)
		return (interpreter(ptr_ast->left) + interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == _SUB)
		return (interpreter(ptr_ast->left) - interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == _MUL)
		return (interpreter(ptr_ast->left) * interpreter(ptr_ast->right));
	else if (ptr_ast->token->type == _DIV)
	{
		if (interpreter(ptr_ast->right) == 0)
			division_by_zero(ptr_ast);
		else
			return (interpreter(ptr_ast->left) / interpreter(ptr_ast->right));
	}
	else if (ptr_ast->token->type == _INTEGER)
		return (ptr_ast->token->value);
	return (0);
}
