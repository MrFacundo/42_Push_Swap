/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:04:08 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/19 11:20:26 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack_node	*get_last_node(t_stack_node *head)
{
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack_node	*get_highest_value_node(t_stack_node *stack)
{
	t_stack_node	*node;
	t_stack_node	*highest_value_node;

	node = stack;
	highest_value_node = node;
	while (node)
	{
		if (node->value > highest_value_node->value)
			highest_value_node = node;
		node = node->next;
	}
	return (highest_value_node);
}

t_stack_node	*get_lowest_value_node(t_stack_node *stack)
{
	t_stack_node	*node;
	t_stack_node	*lowest_value_node;

	node = stack;
	lowest_value_node = node;
	while (node)
	{
		if (node->value < lowest_value_node->value)
			lowest_value_node = node;
		node = node->next;
	}
	return (lowest_value_node);
}

t_stack_node	*get_lowest_cost_node(t_stack_node *node)
{
	t_stack_node	*lowest_cost_node;

	lowest_cost_node = node;
	while (node)
	{
		if (node->push_cost < lowest_cost_node->push_cost)
			lowest_cost_node = node;
		node = node->next;
	}
	return (lowest_cost_node);
}

int	stack_size(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack && ++count)
		stack = stack->next;
	return (count);
}
