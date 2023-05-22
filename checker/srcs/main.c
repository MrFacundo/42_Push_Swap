/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:48:33 by facundo           #+#    #+#             */
/*   Updated: 2023/05/22 17:40:23 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"


int	stack_is_sorted(t_stack_node *stack)
{
	t_stack_node	*node;

	node = stack;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	process_instructions(char **table, t_stack_node **a, t_stack_node **b, int error)
{
	int	i;

	i = 0;
	while (table[i])
	{
		if (ft_strncmp(table[i], "sa", 3), 4 == 0)
			swap(a);
		else if (ft_strncmp(table[i], "sb", 3) == 0)
			swap(b);
		else if (ft_strncmp(table[i], "ss", 3) == 0)
		{
			swap(a);
			swap(b);
		}
		else if (ft_strncmp(table[i], "pa", 3) == 0)
			push(b, a);
		else if (ft_strncmp(table[i], "pb", 3) == 0)
			push(a, b);
		else if (ft_strncmp(table[i], "ra", 3) == 0)
			rotate_direction(a, 1);
		else if (ft_strncmp(table[i], "rb", 3) == 0)
			rotate_direction(b, 1);
		else if (ft_strncmp(table[i], "rr", 3) == 0)
		{
			rotate_direction(a, 1);
			rotate_direction(b, 1);
		}
		else if (ft_strncmp(table[i], "rra", 4) == 0)
			rotate_direction(a, -1);
		else if (ft_strncmp(table[i], "rrb", 4) == 0)
			rotate_direction(b, -1);
		else if (ft_strncmp(table[i], "rrr", 4) == 0)
		{
			rotate_direction(a, -1);
			rotate_direction(b, -1);
		}
		else if (ft_strncmp(table[i], "Error", 6) == 0)
		{
			if (error)
				ft_putstr_fd("OK\n", STDOUT_FILENO);
			else
				ft_putstr_fd("KO\n", STDOUT_FILENO);
		}
		i++;
	}
	if (stack_is_sorted(*a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}



int	main(int argc, char **argv)
{
	char	**table;
	int		i;
	int		error;
	char	*error_msg;

	// take care of args
	t_stack_node	*a;
	t_stack_node	*b;
	a = 0;
	b = 0;
	stack_init(&a, ++argv, --argc, &error);
	// print_stack(a);

	// take care of stdin
	error_msg = ft_get_next_line(STDERR_FILENO);
	
	
	table = ft_calloc(100, sizeof(char *));
	i = 0;
	table[i] = ft_get_next_line(STDIN_FILENO);
	while (table[i])
		table[++i] = ft_get_next_line(STDIN_FILENO);
	i = 0;
	while (table[i])
		table[i++] = ft_strtrim(table[i], "\n");
	i = 0;
	// while (table[i])
	// 	printf("%s\n", table[i++]);
	process_instructions(table, &a, &b, error);
	// print_stack(a);
	return (0);
}