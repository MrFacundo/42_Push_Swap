#include "../includes/push_swap.h"
#include "../libft/libft.h"


static void	swap(t_stack_node **head)
{
	if (!*head || !head)
		return ;
    // Update the head pointer to point to the second node in the list
	*head = (*head)->next;
    // Update the previous and next pointers of the former head node
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
    // Update the prev pointer of the last (3rd) node 
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
    // Update the new head node 
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

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

void	stack_init(t_stack_node **stack, char **argv)
{
	int nbr;
	int	i;

	i = 0;
	while(argv[i])
	{
		nbr = ft_atoi(argv[i]);
		append_node(stack, nbr);
		i++;
	}
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*highest_value_node;

	highest_value_node = get_highest_value_node(*stack);
	if (*stack == highest_value_node)
		rotate(stack);
	else if ((*stack)->next == highest_value_node)
		r_rotate(stack);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack);
}

void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_to_push;

	node_to_push = get_lowest_cost_node(*b);
	if (node_to_push->above_median && node_to_push->target_node->above_median)
		rotate_both(a, b);
	if (!(node_to_push->above_median) && !(node_to_push->target_node->above_median))
		reverse_rotate_both(a, b);
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
	}
	set_position(*a);
	smallest_value_node = get_smallest_value_node(*a);	
	if (smallest_value_node->above_median)
		while (*a != smallest_value_node)
			ra(a);
	else
		while (*a != smallest_value_node)
			rra(a);
}

int main()
{
	t_stack_node *a;
	t_stack_node *b;
	int	stack_length;
	
	char *values[7] = {
		values[0] = "\0",
		values[1] = "1",
		values[2] = "2",
		values[3] = "3",
		values[4] = 0,
		values[5] = "99",
		values[6] = 0
		};
	a = 0;
	b = 0;
	stack_init(&a, values + 1);
	stack_length = stack_size(a);
	if (stack_length == 3)
		sort_three(&a);
	else if (stack_length == 2)
		swap(&a);
	else
		sort(&a, &b);
	return (0);
}