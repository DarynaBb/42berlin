#include "push_swap.h"

int	arguments_are_integers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack_node *a, int value)
{
	while (a)
	{
		if (a->data == value)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack_node	*create_stack_node(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		free_stack(stack);
		print_error_and_exit();
	}
	new_node->data = value;
	new_node->next = NULL;
	return (new_node);
}

void	append_to_stack(t_stack_node **stack, t_stack_node *new_node)
{
	t_stack_node	*current;

	if (!new_node)
	{
		free_stack(*stack);
		print_error_and_exit();
	}
	if (!*stack)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

t_stack_node	*validate_arguments(int argc, char **argv)
{
	t_stack_node	*a;
	int				i;
	int				value;

	a = NULL;
	i = 0;
	if (argc < 2)
		print_error_and_exit();
	if (!arguments_are_integers(argv))
	{
		free_stack(a);
		print_error_and_exit();
	}
	while (i < argc)
	{
		value = (int)ft_atol(argv[i]);
		if (is_duplicate(a, value))
		{
			free_stack(a);
			print_error_and_exit();
		}
		append_to_stack(&a, create_stack_node(a, value));
		i++;
	}
	return (a);
}
