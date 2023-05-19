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

void	process_instructions(char **table, t_stack_node a, t_stack_node b)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (ft_strcmp(table[i], "sa") == 0)
			swap(&a);
		else if (ft_strcmp(table[i], "sb") == 0)
			swap(&b);
		else if (ft_strcmp(table[i], "ss") == 0)
		{
			swap(&a);
			swap(&b);
		}
		else if (ft_strcmp(table[i], "pa") == 0)
			push(&a, &b);
		else if (ft_strcmp(table[i], "pb") == 0)
			push(&b, &a);
		else if (ft_strcmp(table[i], "ra") == 0)
			rotate(&a);
		else if (ft_strcmp(table[i], "rb") == 0)
			rotate(&b);
		else if (ft_strcmp(table[i], "rr") == 0)
		{
			rotate(&a);
			rotate(&b);
		}
		else if (ft_strcmp(table[i], "rra") == 0)
			reverse_rotate(&a);
		else if (ft_strcmp(table[i], "rrb") == 0)
			reverse_rotate(&b);
		else if (ft_strcmp(table[i], "rrr") == 0)
		{
			reverse_rotate(&a);
			reverse_rotate(&b);
		}
		else
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		i++;
	}
	if (is_sorted(a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}



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
	process_instructions(table, &a, &b);
	return (0);
}