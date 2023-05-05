#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack_node	*get_last_node(t_stack_node *head)
{
	if (!head)
		return 0;
	while (head->next)
		head = head->next;
	return (head);
}

t_stack_node *get_highest_value_node(t_stack_node *stack)
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

static	void push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = 0;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = 0;
	}
	else
	{
		node_to_push->next = *dst;
		(*dst)->prev = node_to_push;
		*dst = node_to_push;
	}
	printf("push\n");
}

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

void	print_node(t_stack_node *stack)
{
	printf("Node address\t value\t prev\t prev address\t next\t next address\n");
	while (stack)
	{
		printf(
			"%p\t %d\t %d\t %p\t %d\t %p\n",
			stack,
			stack->value,
			stack->prev ? stack->prev->value : 0,
			stack->prev ? stack->prev : 0,
			stack->next ? stack->next->value : 0,
			stack->next ? stack->next : 0
			);
		stack = stack->next;
	}
	printf("*********************************\n");
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

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	stack_length;
	int	i;

	stack_length = stack_size(*a);
	while (stack_length-- > 3)
		push(b, a);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
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
		values[4] = "-10",
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