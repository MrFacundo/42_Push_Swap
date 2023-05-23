/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:21:43 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/23 20:26:12 by ftroiter         ###   ########.fr       */
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

void	rotate_both(t_stack_node **a, t_stack_node **b, int direction)
{
	rotate_direction(a, direction);
	rotate_direction(b, direction);
}

void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}

void	process_instruction(char *instruction,
							t_stack_node **a,
								t_stack_node **b)
{
	if (!ft_strncmp(instruction, "sa", 3))
		swap(a);
	else if (!ft_strncmp(instruction, "sb", 3))
		swap(b);
	else if (!ft_strncmp(instruction, "ss", 3))
		swap_both(a, b);
	else if (!ft_strncmp(instruction, "pa", 3))
		push(b, a);
	else if (!ft_strncmp(instruction, "pb", 3))
		push(a, b);
	else if (!ft_strncmp(instruction, "ra", 3))
		rotate_direction(a, 1);
	else if (!ft_strncmp(instruction, "rb", 3))
		rotate_direction(b, 1);
	else if (!ft_strncmp(instruction, "rr", 3))
		rotate_both(a, b, 1);
	else if (!ft_strncmp(instruction, "rra", 4))
		rotate_direction(a, -1);
	else if (!ft_strncmp(instruction, "rrb", 4))
		rotate_direction(b, -1);
	else if (!ft_strncmp(instruction, "rrr", 4))
		rotate_both(a, b, -1);
}

void	process_instructions(char **table, t_stack_node **a, t_stack_node **b)
{
	int	i;

	i = 0;
	while (table[i])
	{
		process_instruction(table[i], a, b);
		i++;
	}
	if (stack_is_sorted(*a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}
