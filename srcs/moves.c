/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:23:03 by facundo           #+#    #+#             */
/*   Updated: 2023/05/09 10:23:57 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node_to_move)
{
	while (*a != node_to_move->target_node && *b != node_to_move)
	{
		rr(a, b);
		set_position(*a);
		set_position(*b);
	}
}


void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node_to_move)
{
	while (*a != node_to_move->target_node && *b != node_to_move)
	{
		rrr(a, b);
		set_position(*a);
		set_position(*b);
	}
}

void		rotate_one(t_stack_node **stack, t_stack_node *node, char stack_name)
{
	while (*stack != node)
	{
		if (stack_name == 'a')
		{
			if (node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
