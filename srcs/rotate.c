/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:15:59 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/22 17:07:04 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

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

void	rotate_stack(t_stack_node **stack, char *instruction)
{
	if (!stack || !*stack)
		return ;
	if (!ft_strncmp("ra", instruction, 3)
		|| !ft_strncmp("rb", instruction, 3))
		rotate_direction(stack, 1);
	else if (!ft_strncmp("rra", instruction, 4)
		|| !ft_strncmp("rrb", instruction, 4))
		rotate_direction(stack, -1);
	ft_putstr_fd(instruction, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate_stacks(t_stack_node **a, t_stack_node **b, char *instruction)
{
	if (!a || !*a || !b || !*b)
		return ;
	if (!ft_strncmp("rr", instruction, 3))
	{
		rotate_direction(a, 1);
		rotate_direction(b, 1);
	}
	else if (!ft_strncmp("rrr", instruction, 4))
	{
		rotate_direction(a, -1);
		rotate_direction(b, -1);
	}
	ft_putstr_fd(instruction, 1);
	ft_putchar_fd('\n', 1);
}
