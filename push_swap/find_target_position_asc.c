#include "push_swap.h"

int	find_boundary_position_smaller(t_stack_node *stack, int smallest)
{
	int	p;

	p = find_position(stack, smallest);
	if (p != 0)
		return (p);
	else
		return (0);
}

int	find_boundary_position_larger(t_stack_node *stack, int largest)
{
	int	p;

	p = find_position(stack, largest);
	if (p + 1 == stack_len(stack))
		return (0);
	else
		return (p + 1);
}

int	find_position_with_min_diff_asc(t_stack_node *stack, int number)
{
	t_stack_node	*current;
	int				position;
	int				min_diff;
	int				best_position;

	position = 0;
	min_diff = INT_MAX;
	best_position = 0;
	current = stack;
	while (current)
	{
		if (number < current->data && (current->data - number) < min_diff)
		{
			min_diff = current->data - number;
			best_position = position;
		}
		current = current->next;
		position++;
	}
	return (best_position);
}

int	find_target_position_asc(t_stack_node *stack, int number)
{
	int	smallest;
	int	largest;

	if (!stack)
		return (-1);
	smallest = find_smallest(stack);
	largest = find_largest(stack);
	if (number < smallest)
		return (find_boundary_position_smaller(stack, smallest));
	if (number > largest)
		return (find_boundary_position_larger(stack, largest));
	return (find_position_with_min_diff_asc(stack, number));
}
