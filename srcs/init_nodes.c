/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:54:28 by facundo           #+#    #+#             */
/*   Updated: 2023/05/09 09:35:23 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"


void	set_position(t_stack_node *node)
{
	int		i;
	int stack_center;
	
	if (!node)
		return ;
	stack_center = stack_size(node) / 2;
	i = 0;
	while (node)
	{
		if (i < stack_center)
			node->above_median = 1;
		else
			node->above_median = 0;
		node->position = i;
		node = node->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*node;
	long			best_match_value;

	while (b)
	{
		node = a;
		best_match_value = LONG_MAX;
		while (node)
		{
			if (node->value > b->value && node->value < best_match_value)
			{
				best_match_value = node->value;
				target_node = node;
			}
			node = node->next;
		}
		if (best_match_value == LONG_MAX)
			b->target_node = get_lowest_value_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_push_cost(t_stack_node *a, t_stack_node *b)
{
	while (b)
	{
		if (b->above_median)
			b->push_cost = b->position;
		else
			b->push_cost = stack_size(b) - b->position;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->position;
		else
			b->push_cost += stack_size(a) - b->target_node->position;
		b = b->next;
	}
}

void	set_lowest_cost_node(t_stack_node *b)
{
	t_stack_node	*lowest_cost_node;
	t_stack_node	*node;
	long			lowest_cost;

	lowest_cost = LONG_MAX;
	while (b)
	{
		if (b->push_cost < lowest_cost)
		{
			lowest_cost = b->push_cost;
			lowest_cost_node = b;
		}
		b = b->next;
	}
	lowest_cost_node->has_lowest_cost = 1;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
	set_push_cost(a, b);
	set_lowest_cost_node(b);
}
