/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 04:59:22 by jaelee            #+#    #+#             */
/*   Updated: 2019/03/01 17:55:55 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_calc.h"

/*
**	expr = term((ADD | SUB)term)*
**	term = factor((MUL | DIV)term)*
**	factor = INTEGER | LPAREN expr RPAREN
*/

void	eat(t_parser *parser, int type)
{
	if (parser->curr_token->type == type)
	{
		if (type == _LPAREN || type == _RPAREN || type == _EOF)
			free(parser->curr_token);
		if (type != _EOF)
			parser->curr_token = get_next_token(parser);
	}
	else
	{
		printf("Eat failed\n");
		ft_exit(parser);
	}
}

t_ast	*ast_create(t_ast *left, t_ast *right, t_token *token, t_parser *parser)
{
	t_ast	*new;

	if (!(new = (t_ast*)malloc(sizeof(t_ast))))
		ft_exit(parser);
	new->left = left;
	new->right = right;
	new->token = token;
	return (new);
}

t_ast	*factor(t_parser *parser)
{
	t_token	*token;
	t_ast	*node;

	token = parser->curr_token;
	if (token->type == _ADD)
	{
		eat(parser, _ADD);
		token->type = _UNARY_ADD;
		return (ast_create(NULL, factor(parser), token, parser));
	}
	else if (token->type == _SUB)
	{
		eat(parser, _SUB);
		token->type = _UNARY_SUB;
		return (ast_create(NULL, factor(parser), token, parser));
	}
	else if (token->type == _INTEGER)
	{
		eat(parser, _INTEGER);
		return (ast_create(NULL, NULL, token, parser));
	}
	else if (token->type == _LPAREN)
	{
		eat(parser, _LPAREN);
		node = expr(parser);
		eat(parser, _RPAREN);
		return (node);
	}
	return (NULL);
}

t_ast	*term(t_parser *parser)
{
	t_token *token;
	t_ast	*node;

	node = factor(parser);
	while (parser->curr_token->type == _MUL ||
			parser->curr_token->type == _DIV)
	{
		if (parser->curr_token->type == _MUL)
		{
			token = parser->curr_token;
			eat(parser, _MUL);
			node = ast_create(node, factor(parser), token, parser);
		}
		else if (parser->curr_token->type == _DIV)
		{
			token = parser->curr_token;
			eat(parser, _DIV);
			node = ast_create(node, factor(parser), token, parser);
		}
	}
	return (node);
}

t_ast	*expr(t_parser *parser)
{
	t_token *token;
	t_ast	*node;

	node = term(parser);
	while (parser->curr_token->type == _ADD ||
			parser->curr_token->type == _SUB)
	{
		if (parser->curr_token->type == _ADD)
		{
			token = parser->curr_token;
			eat(parser, _ADD);
			node = ast_create(node, term(parser), token, parser);
		}
		else if (parser->curr_token->type == _SUB)
		{
			token = parser->curr_token;
			eat(parser, _SUB);
			node = ast_create(node, term(parser), token, parser);
		}
	}
	return (node);
}
