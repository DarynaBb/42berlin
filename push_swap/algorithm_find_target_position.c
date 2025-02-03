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
			printf("find_position: number %d found at position %d\n", number, position);
			return (position);
		}
			
		current = current->next;
		position++;
	}
	printf("find_position: number %d not found, returning -1\n", number);
	return (-1);
}

int	find_target_position(t_stack_node *b, int number)
{
	t_stack_node	*current;
	int	smallest;
	int	largest;
	int	position;

	if (!b)
		return (-1);
	smallest = find_smallest(b);
	largest = find_largest(b);
	position = 0;
	if (number > largest)
	{
		printf("target position: %d\n", (position));
		return (position);
	}
	// Case 2: Number is smaller than the smallest
	if (number < smallest)
	{
		position = find_position(b, smallest); // Place after the smallest
		printf("target position: %d (after smallest %d)\n", position + 1, smallest);
		return (position + 1); // Bottom of the stack
	}
	current = b;
	while (current && current->next)
	{
		if (number < current->data && number > current->next->data)
		{
			printf("target position: %d\n", (position + 1));
			return (position + 1);
		}
		current = current->next;
		position++;
	}
	// Case 4: Wrap-around (number fits between last and first nodes)
    if (current && number < current->data && number > b->data)
    {
        printf("target position: %d (wrap-around between %d and %d)\n", position + 1, current->data, b->data);
        return (position + 1);
    }
	printf("target position 0");
	return (position);
}

