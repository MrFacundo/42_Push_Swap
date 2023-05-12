/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:59:12 by facundo           #+#    #+#             */
/*   Updated: 2023/05/12 14:00:27 by facundo          ###   ########.fr       */
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