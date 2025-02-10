#include "push_swap.h"

int	calculate_rotations_a_desc(t_stack_node *stack, int number)
{
	int	position;
	int	size;
	int	rotations;

	position = find_position(stack, number);
	if (position == -1)
		return (-1);
	size = stack_len(stack);
	if (position <= (size) / 2)
		rotations = position;
	else
		rotations = -(size - position);
	return (rotations);
}

int	calculate_rotations_b_desc(t_stack_node *stack, int target_position)
{
	int	size;
	int	rotations;

	size = stack_len(stack);
	if (target_position < 0 || target_position >= size)
		return (-1);
	if (target_position <= (size) / 2)
		rotations = target_position;
	else
		rotations = -(size - target_position);
	return (rotations);
}

void	calculate_cost_desc(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				target_position;

	if (!a || !b)
		return ;
	current_a = a;
	while (current_a)
	{
		target_position = find_target_position(b, current_a->data);
		if (target_position == -1)
		{
			current_a->push_cost = INT_MAX;
			current_a = current_a->next;
			continue ;
		}
		cost_a = calculate_rotations_a_desc(a, current_a->data);
		cost_b = calculate_rotations_b_desc(b, target_position);
		total_cost = calculate_push_cost(cost_a, cost_b);
		current_a->push_cost = total_cost;
		current_a = current_a->next;
	}
}
