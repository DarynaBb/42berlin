#include "push_swap.h"

int	find_smallest(t_stack_node *stack)
{
	t_stack_node	*current;
	int				smallest;

	current = stack;
	smallest = current->data;
	if (!stack)
		return (0);
	while(current)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	// printf("smallest number: %d\n", smallest);
	return (smallest);
}

int	find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*current;

	if (!stack)
		return (0);
	current = stack;
	largest = current->data;
	while(current)
	{
		if (current->data > largest)
			largest = current->data;
		current = current->next;
	}
	// printf("largest number: %d\n", largest);
	return (largest);
}

int	find_position(t_stack_node *b, int number)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = b;
	while (current)
	{
		if (current->data == number)
		{
			// printf("position is: %d", position);
			return (position);
		}
			
		current = current->next;
		position++;
	}
	return (-1);
}

int	find_target_position(t_stack_node *b, int number)
{
	t_stack_node	*current;
	int	smallest;
	int	largest;
	int	position;

	position = 0;
	smallest = find_smallest(b);
	largest = find_largest(b);
	if (number < smallest || number > largest)
	{
		printf("target position: %d\n", (find_position(b, smallest)));
		return (find_position(b, smallest));
	}
		
	current = b;
	while (current && current->next)
	{
		if (number > current->data && number < current->next->data)
		{
			printf("target position: %d\n", (position + 1));
			return (position + 1);
		}
		current = current->next;
		position++;
	}
	printf("target position 0");
	return (0);
}