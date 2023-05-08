/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:15:59 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/08 19:45:18 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static	void rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	
	if (NULL == stack || NULL == *stack)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	last_node->next->prev = last_node;
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	last_node->next->next= 0;
	printf("rotate\n");
}

static void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (NULL == stack || NULL == *stack)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
	last_node->prev->next = 0;
	last_node->prev = NULL;
	printf("r_rotate\n"); 
}

void	ra(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack_node **a, t_stack_node **b)
{
	rotate(b);
	printf("rb\n");
}

void	rra(t_stack_node **a, t_stack_node **b)
{
	r_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **a, t_stack_node **b)
{
	r_rotate(b);
	printf("rrb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	printf("rr\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	r_rotate(a);
	r_rotate(b);
	printf("rrr\n");
}


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
