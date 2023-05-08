/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:54:28 by facundo           #+#    #+#             */
/*   Updated: 2023/05/08 17:38:12 by facundo          ###   ########.fr       */
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
			b->target_node = get_smallest_node(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

set_push_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*node;
	int				push_cost;

	while (b)
	{
		b->push_cost = b->position;
		if(!(b->above_median))
			b->push_cost = stack_size(b) - b->position;
		if (b->above_median)
			b->push_cost += b->target_node->position;
		else
			b->push_cost += stack_size(a) - b->target_node->position;
		b = b->next;
	}
}


void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target_node(a, b);
}
