/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_calc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 03:27:07 by jaelee            #+#    #+#             */
/*   Updated: 2019/03/01 16:55:07 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_CALC_H
# define AST_CALC_H
# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define FT_FAIL -1

typedef enum	e_type
{
	_INTEGER,
	_UNARY_ADD,
	_UNARY_SUB,
	_ADD,
	_SUB,
	_MUL,
	_DIV,
	_LPAREN,
	_RPAREN,
	_EOF
}				e_type;

typedef struct	s_token
{
	int		type;
	ssize_t	value;
}				t_token;

typedef struct	s_ast
{
	struct s_ast	*left;
	struct s_ast	*right;
	t_token			*token;
}				t_ast;

typedef struct	s_parser
{
	char		*input;
	size_t		pos;
	char		curr_char;
	t_token		*curr_token;
	t_ast		*ptr_ast;
}				t_parser;

void	free_program(t_ast *ptr_ast);
void	ft_exit(t_parser *parser);
void	eat(t_parser *parser, int type);
t_ast	*ast_create(t_ast *left, t_ast *right, t_token *token, t_parser *parser);
t_ast	*factor(t_parser *parser);
t_ast	*term(t_parser *parser);
t_ast	*expr(t_parser *parser);
void	init_program(t_parser *parser, char *str);
t_token	*get_next_token(t_parser *parser);
void	store_tokens(t_parser *parser,
			t_token *token, int token_type, char token_value);
void	store_integer(t_parser *parser, t_token *token);
ssize_t	interpreter(t_ast *ptr_ast);
#endif
