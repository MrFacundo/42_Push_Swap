/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:48:33 by facundo           #+#    #+#             */
/*   Updated: 2023/05/19 16:06:39 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

int	main(int argc, char **argv)
{
	char	**table;
	int		i;

	// take care of args
	t_stack_node	*a;
	t_stack_node	*b;
	a = 0;
	b = 0;
	stack_init(&a, ++argv, --argc);
	print_stack(a);

	// take care of stdin
	table = ft_calloc(100, sizeof(char *));
	i = 0;
	table[i] = ft_get_next_line(STDIN_FILENO);
	while (table[i])
		table[++i] = ft_get_next_line(STDIN_FILENO);
	i = 0;
	while (table[i])
		table[i++] = ft_strtrim(table[i], "\n");
	i = 0;
	while (table[i])
		printf("%s\n", table[i++]);
	return (0);
}