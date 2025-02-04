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

int	find_position(t_stack_node *stack, int number)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = stack;
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
	if (number > largest || number < smallest)
	{
		printf("target position: %d\n", (position));
		return (position);
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
    if (current && number < current->data && number > current->data)
    {
        printf("target position: %d (wrap-around between %d and %d)\n", position + 1, current->data, b->data);
        return (position + 1);
    }
	printf("target position 0");
	return (position);
}

// int find_target_position(t_stack_node *b, int data)
// {
//     int position = 0;
//     int target_position = 0;
//     t_stack_node *current = b;

//     if (!b) // If stack B is empty
//         return 0;

//     while (current)
//     {
//         // Check if `data` fits between `current` and `current->next` in descending order
//         if ((current->data > data && (!current->next || current->next->data < data)) ||
//             (current->next == b && data > b->data)) // Circular case
//         {
//             return position + 1;
//         }
//         current = current->next;
//         position++;
//     }

//     return target_position; // Default is the last position
// }
