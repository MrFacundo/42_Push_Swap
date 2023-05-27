/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:21:43 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/27 18:13:51 by ftroiter         ###   ########.fr       */
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

int	process_instruction(char *instruction,
							t_stack_node **a,
								t_stack_node **b)
{
	if (!ft_strncmp(instruction, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(instruction, "sb\n", 4))
		swap(b);
	else if (!ft_strncmp(instruction, "ss\n", 4))
		swap_both(a, b);
	else if (!ft_strncmp(instruction, "pa\n", 4))
		push(b, a);
	else if (!ft_strncmp(instruction, "pb\n", 4))
		push(a, b);
	else if (!ft_strncmp(instruction, "ra\n", 4))
		rotate_direction(a, 1);
	else if (!ft_strncmp(instruction, "rb\n", 4))
		rotate_direction(b, 1);
	else if (!ft_strncmp(instruction, "rr\n", 4))
		rotate_both(a, b, 1);
	else if (!ft_strncmp(instruction, "rra\n", 5))
		rotate_direction(a, -1);
	else if (!ft_strncmp(instruction, "rrb\n", 5))
		rotate_direction(b, -1);
	else if (!ft_strncmp(instruction, "rrr\n", 5))
		rotate_both(a, b, -1);
	else
		return (1);
	return (0);
}
