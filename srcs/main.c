#include "../includes/push_swap.h"
#include "../libft/libft.h"


void	print_int(void *content)
{
	int value = *(int *)content;
	printf("%d\n", *(int *)content);
}

// Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty
void	pa(t_list **a, t_list **b)
{

	t_list *b_last;
	t_list *b_last_alloc;


	b_last = ft_lstlast(*b);
	printf("b_last->content: %d\n", *(int *)b_last->content);
	b_last_alloc = ft_lstnew(b_last->content);
	ft_lstadd_back(a, b_last_alloc);
	ft_lstdelone(b_last, free);
}


int	main(int argc, char *argv[])
{
	int i;
	t_list *a = 0;
	t_list *b = 0;
	int *content;
	i = 1;

	while (i < argc)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i]);
		ft_lstadd_back(&a, ft_lstnew(content));
		ft_lstadd_back(&b, ft_lstnew(content));
		i++;
	}
	printf("the items in list a:\n");
	ft_lstiter(a, print_int);
	printf("the items in list b:\n");
	ft_lstiter(b, print_int);
	pa(&a, &b);
	printf("the items in list a:\n");
	ft_lstiter(a, print_int);
	printf("the items in list b:\n");
	ft_lstiter(b, print_int);
	
	return (0);
}
