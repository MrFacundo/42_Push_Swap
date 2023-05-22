/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:50:58 by facundo           #+#    #+#             */
/*   Updated: 2023/05/22 17:24:53 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

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

void	stack_init(t_stack_node **stack, char **argv, int argc, int *error)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_int(argv[i]))
		{
			*error = 1;
			return ;
		}
		nbr = ft_atoi(argv[i]);
		if (!value_is_unique(*stack, nbr))
		{
			*error = 1;
			return ;
		}
		append_node(stack, nbr);
		i++;
	}
}
