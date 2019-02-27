/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 04:59:22 by jaelee            #+#    #+#             */
/*   Updated: 2019/02/25 05:15:36 by jaelee           ###   ########.fr       */
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
		if (type == FT_LPAREN || type == FT_RPAREN || type == FT_EOF)
			free(parser->curr_token);
		if (type != FT_EOF)
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
	if (token->type == FT_INTEGER)
	{
		eat(parser, FT_INTEGER);
		return (ast_create(NULL, NULL, token, parser));
	}
	else if (token->type == FT_LPAREN)
	{
		eat(parser, FT_LPAREN);
		node = expr(parser);
		eat(parser, FT_RPAREN);
		return (node);
	}
	return (NULL);
}

t_ast	*term(t_parser *parser)
{
	t_token *token;
	t_ast	*node;

	node = factor(parser);
	if (parser->curr_token->type == FT_MUL)
	{
		token = parser->curr_token;
		eat(parser, FT_MUL);
		return (ast_create(node, factor(parser), token, parser));
	}
	if (parser->curr_token->type == FT_DIV)
	{
		token = parser->curr_token;
		eat(parser, FT_DIV);
		return (ast_create(node, factor(parser), token, parser));
	}
	return (node);
}

t_ast	*expr(t_parser *parser)
{
	t_token *token;
	t_ast	*node;

	node = term(parser);
	if (parser->curr_token->type == FT_ADD)
	{
		token = parser->curr_token;
		eat(parser, FT_ADD);
		return (ast_create(node, term(parser), token, parser));
	}
	if (parser->curr_token->type == FT_SUB)
	{
		token = parser->curr_token;
		eat(parser, FT_SUB);
		return (ast_create(node, term(parser), token, parser));
	}
	return (node);
}
