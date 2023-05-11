/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:37 by facundo           #+#    #+#             */
/*   Updated: 2023/05/11 21:27:07 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->value = nbr;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = 0;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	stack_init(t_stack_node **stack, char **argv, int argc)
{
	int nbr;
	int	i;

	i = 0;
	while(argv[i])
	{
		if (!is_int(argv[i]))
			handle_error(stack, NOT_INT);
		nbr = ft_atoi(argv[i]);
		if (!value_is_unique(*stack, nbr))
			handle_error(stack, UNIQUE_VALUES);
		append_node(stack, nbr);
		i++;
	}
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*highest_value_node;

	highest_value_node = get_highest_value_node(*stack);
	if (*stack == highest_value_node)
		ra(stack);
	else if ((*stack)->next == highest_value_node)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_to_push;

	node_to_push = get_lowest_cost_node(*b);
	if (node_to_push->above_median && node_to_push->target_node->above_median)
		rotate_both(a, b, node_to_push);
	if (!(node_to_push->above_median) && !(node_to_push->target_node->above_median))
		reverse_rotate_both(a, b, node_to_push);
	rotate_one(b, node_to_push,'b');
	rotate_one(a, node_to_push->target_node,'a');
	pa(a, b);	
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	stack_length;
	int	i;
	t_stack_node	*smallest_value_node;

	stack_length = stack_size(*a);
	while (stack_length-- > 3)
		push(b, a);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
		print_node(*a);
	}
	set_position(*a);
	smallest_value_node = get_lowest_value_node(*a);	
	if (smallest_value_node->above_median)
		while (*a != smallest_value_node)
			ra(a);
	else
		while (*a != smallest_value_node)
			rra(a);
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

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	char *test;
	int	stack_length;

	
	test == argv[1];
	printf("%s\n", argv[1]);
	if (argc < 2)
		return (0);
	a = 0;
	b = 0;
	stack_init(&a, argv++, argc--);
	print_node(a);
	stack_length = stack_size(a);
	if (stack_is_sorted(a))
		return (0);
	if (stack_length == 3)
		sort_three(&a);
	else if (stack_length == 2)
		sa(&a);
	else
		sort(&a, &b);
	print_node(a);
	return (0);
}