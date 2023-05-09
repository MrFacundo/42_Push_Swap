/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:15:59 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/09 10:23:57 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void rotate(t_stack_node **stack)
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

// stack moves down
void	r_rotate(t_stack_node **stack)
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
}

void	ra(t_stack_node **a)
{
	rotate(a);
	printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	printf("rb\n");
}

void	rra(t_stack_node **a)
{
	r_rotate(a);
	printf("rra\n");
}

void	rrb(t_stack_node **b)
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
