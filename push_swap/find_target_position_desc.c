#include "push_swap.h"

int	find_boundary_position(t_stack_node *b, int number, 
	int smallest, int largest)
{
	int	p;

	if (number > largest || number < smallest)
	{
		p = find_position(b, smallest);
		if (p + 1 == stack_len(b))
			return (0);
		else
			return (p + 1);
	}
	return (-1);
}

int	find_position_with_min_diff(t_stack_node *b, int number)
{
	t_stack_node	*current;
	int				position;
	int				min_diff;
	int				best_position;

	position = 0;
	min_diff = INT_MAX;
	best_position = 0;
	current = b;
	while (current)
	{
		if (number > current->data && (number - current->data) < min_diff)
		{
			min_diff = number - current->data;
			best_position = position;
		}
		current = current->next;
		position++;
	}
	return (best_position);
}

int	find_target_position(t_stack_node *b, int number)
{
	int	smallest;
	int	largest;
	int	boundary_position;
	int	best_position;

	if (!b)
		return (-1);
	smallest = find_smallest(b);
	largest = find_largest(b);
	boundary_position = find_boundary_position(b, number, smallest, largest);
	if (boundary_position != -1)
		return (boundary_position);
	best_position = find_position_with_min_diff(b, number);
	return (best_position);
}
