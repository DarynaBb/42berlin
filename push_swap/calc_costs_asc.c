#include "push_swap.h"

int calculate_rotations_a_asc(t_stack_node *stack, int target_position)
{
	int	size;
	int	rotations;

	size = stack_len(stack);
	if (target_position < 0 || target_position >= size)
	{
		return (-1);
	}
	if (target_position <= (size) / 2)
		rotations = target_position;
	else
		rotations = -(size - target_position);
	return (rotations);
}

int	calculate_rotations_b_asc(t_stack_node *stack, int number)
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

void	calculate_cost_asc(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_b;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	target_position;

	if (!a || !b)
		return ;
	current_b = b;
	while (current_b)
	{
		target_position = find_target_position_asc(a, current_b->data);
		if (target_position == -1)
		{
			// printf("Error: No valid target position for number %d\n", current_a->data);
			current_b->push_cost = INT_MAX;
			current_b = current_b->next;
			continue;
		}
		cost_a = calculate_rotations_a_asc(a, target_position);
		cost_b = calculate_rotations_b_asc(b, current_b->data);
		// printf("cost A: %d\n", cost_a);
		// printf("cost B: %d\n", cost_b);

		if (cost_a != INT_MAX && cost_b != INT_MAX)
		{
			if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
			{
				if (cost_a < 0 && cost_b < 0) {
					cost_a = -cost_a;
					cost_b = -cost_b;
				}
				if (cost_a > cost_b)
					total_cost = cost_a;
				else
					total_cost = cost_b;
				// printf("Simultaneous rotation, total cost: %d\n", total_cost);	
			}
			else
			{
				if (cost_a < 0)
					cost_a = -cost_a;
				if (cost_b < 0)
					cost_b = -cost_b;
				total_cost = cost_a + cost_b;
				// printf("Separate rotations, total cost: %d\n", total_cost);
			}
			// printf("total cost: %d\n", total_cost);
			current_b->push_cost = total_cost;
		}
		else
		{
			// printf("Error: Invalid cost for number %d\n", current_a->data);
			current_b->push_cost = INT_MAX;
		}
		current_b = current_b->next;
	}
}