/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <jaelee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 03:25:39 by jaelee            #+#    #+#             */
/*   Updated: 2019/03/01 17:55:54 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast_calc.h"

void	free_program(t_ast *ptr_ast)
{
	if (!ptr_ast)
		return ;
	if (ptr_ast->left)
		free_program(ptr_ast->left);
	if (ptr_ast->right)
		free_program(ptr_ast->right);
	if (ptr_ast->token)
		free(ptr_ast->token);
	free(ptr_ast);
}

void	ft_exit(t_parser *parser)
{
	free_program(parser->ptr_ast);
	exit(0);
}

void	init_program(t_parser *parser, char *str)
{
	ft_bzero(parser, sizeof(t_parser));
	if (str)
		parser->input = str;
	parser->curr_char = parser->input[parser->pos];
	parser->curr_token = get_next_token(parser);
}

void	print_all(t_ast *ptr_ast)
{
	if (ptr_ast->left)
		print_all(ptr_ast->left);
	if (ptr_ast->right)
		print_all(ptr_ast->right);
	printf("%ld\n", ptr_ast->token->value);
}

int		main(int argc, char **argv)
{
	t_parser	parser;
	ssize_t		result;

	result = 0;
	if (argc == 2)
	{
		init_program(&parser, argv[1]);
		parser.ptr_ast = expr(&parser);
		eat(&parser, _EOF);
		print_all(parser.ptr_ast);
		if (parser.ptr_ast)
			printf("result = %ld\n", interpreter(parser.ptr_ast));
		free_program(parser.ptr_ast);
	}
	else
	{
		if (argc < 2)
			printf("No input\n");
		else
			printf("Too many input\n");
	}
	return (0);
}
