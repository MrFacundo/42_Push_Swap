/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:37 by facundo           #+#    #+#             */
/*   Updated: 2023/05/19 11:13:04 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*highest_value_node;

	highest_value_node = get_highest_value_node(*stack);
	if (*stack == highest_value_node)
		rotate_stack(stack, "ra");
	else if ((*stack)->next == highest_value_node)
		rotate_stack(stack, "rra");
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_to_push;

	node_to_push = get_lowest_cost_node(*b);
	if (node_to_push->above_median
		&& node_to_push->target_node->above_median)
		rotate_both(a, b, node_to_push, "rr");
	if (!(node_to_push->above_median)
		&& !(node_to_push->target_node->above_median))
		rotate_both(a, b, node_to_push, "rrr");
	rotate_one(b, node_to_push, 'b');
	rotate_one(a, node_to_push->target_node, 'a');
	push_direction(a, b, "pa");
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int				stack_length;
	int				i;
	t_stack_node	*smallest_value_node;

	stack_length = stack_size(*a);
	while (stack_length-- > 3)
		push_direction(a, b, "pb");
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest_value_node = get_lowest_value_node(*a);
	if (smallest_value_node->above_median)
		while (*a != smallest_value_node)
			rotate_stack(a, "ra");
	else
		while (*a != smallest_value_node)
			rotate_stack(a, "rra");
}

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

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_length;

	if (argc < 2)
		return (0);
	a = 0;
	b = 0;
	stack_init(&a, ++argv, --argc);
	stack_length = stack_size(a);
	if (stack_is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	if (stack_length == 3)
		sort_three(&a);
	else if (stack_length == 2)
		sa(&a);
	else
		sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
