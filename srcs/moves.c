/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:03 by facundo           #+#    #+#             */
/*   Updated: 2023/05/12 15:27:47 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *node_to_move,
					char *instruction)
{
	while (*a != node_to_move->target_node && *b != node_to_move)
		rotate_stacks(a, b, instruction);
	set_position(*a);
	set_position(*b);
}

void	rotate_one(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				rotate_stack(stack, "ra");
			else
				rotate_stack(stack, "rra");
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rotate_stack(stack, "rb");
			else
				rotate_stack(stack, "rrb");
		}
	}
}
