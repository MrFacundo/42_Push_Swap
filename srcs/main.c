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


int main()
{
	t_stack_node *a;
	t_stack_node *test_stack;
	char *values[5] = {values[0] = "\0", values[1] = "100", values[2] = "200", values[3] = "300", values[4] = 0};
	a = 0;
	stack_init(&a, values + 1);
	test_stack = a;
	print_node(test_stack);
	r_rotate(&test_stack);
	print_node(test_stack);
	r_rotate(&test_stack);
	print_node(test_stack);
	rotate(&test_stack);
	print_node(test_stack);
	rotate(&test_stack);
	print_node(test_stack);
	return (0);
}