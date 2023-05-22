/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:15:59 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/22 21:49:44 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

// direction 1 = ra/rb = stack moves up 1 2 3 => 2 3 1
// direction -1 = rra/rrb = stack moves down 1 2 3 => 3 1 2
void	rotate_direction(t_stack_node **stack, int direction)
{
	t_stack_node	*last_node;

	last_node = get_last_node(*stack);
	if (!stack || !*stack)
		return ;
	if (direction == 1)
	{
		last_node->next = *stack;
		last_node->next->prev = last_node;
		*stack = (*stack)->next;
		(*stack)->prev = 0;
		last_node->next->next = 0;
	}
	else if (direction == -1)
	{
		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = last_node;
		last_node->prev->next = 0;
		last_node->prev = 0;
	}
}
