/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:58:46 by jaelee            #+#    #+#             */
/*   Updated: 2019/03/01 17:55:55 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_calc.h"

void	store_integer(t_parser *parser, t_token *token)
{
	char	buf[200];
	int		index;

	ft_bzero(buf, 200);
	index = 0;
	while (ft_isdigit(parser->curr_char))
	{
		buf[index++] = parser->curr_char;
		parser->pos++;
		parser->curr_char = parser->input[parser->pos];
	}
	if (parser->curr_char != ' ' && parser->curr_char != '+' &&
		parser->curr_char != '-' && parser->curr_char != '*' &&
			parser->curr_char != '/' && parser->curr_char != ')' &&
				parser->curr_char != '\0')
	{
		printf("Invalid input : %c\n", parser->curr_char);
		ft_exit(parser);
	}
	token->value = ft_atoi(buf);
	token->type = _INTEGER;
}

void	store_tokens(t_parser *parser,
			t_token *token, int token_type, char token_value)
{
	(void)parser;
	token->type = token_type;
	token->value = token_value;
}

void	store_others(t_parser *parser, t_token *token)
{
	if (parser->curr_char == '+')
		store_tokens(parser, token, _ADD, '+');
	else if (parser->curr_char == '-')
		store_tokens(parser, token, _SUB, '-');
	else if (parser->curr_char == '*')
		store_tokens(parser, token, _MUL, '*');
	else if (parser->curr_char == '/')
		store_tokens(parser, token, _DIV, '/');
	else if (parser->curr_char == '(')
		store_tokens(parser, token, _LPAREN, '(');
	else if (parser->curr_char == ')')
		store_tokens(parser, token, _RPAREN, ')');
	else
	{
		printf("Invalid character: %c\n", parser->curr_char);
		ft_exit(parser);
	}
}

void	skip_whitespaces(t_parser *parser)
{
	while (parser->curr_char == ' ')
	{
		parser->pos++;
		parser->curr_char = parser->input[parser->pos];
	}
}

t_token	*get_next_token(t_parser *parser)
{
	t_token	*token;

	if (!(token = (t_token*)malloc(sizeof(t_token))))
		ft_exit(parser);
	while (parser->pos < ft_strlen(parser->input))
	{
		if (parser->curr_char == ' ')
		{
			skip_whitespaces(parser);
			continue;
		}
		else if (parser->curr_char >= '0' && parser->curr_char <= '9')
		{
			store_integer(parser, token);
			return (token);
		}
		else
			store_others(parser, token);
		parser->pos++;
		parser->curr_char = parser->input[parser->pos];
		return (token);
	}
	store_tokens(parser, token, _EOF, 0);
	return (token);
}
