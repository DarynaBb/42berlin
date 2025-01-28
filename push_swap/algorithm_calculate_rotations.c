#include "push_swap.h"

int	calculate_rotations(t_stack_node *stack, int number)
{
	int	position;
	int	size;
	int	rotations;

	position = find_position(stack, number);
	size = stack_len(stack);
	if (position <= size / 2)
		rotations = position;
	else
	rotations = size - position;
	return (rotations);
}

void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_a;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	target_position;

	if (!a || !b)
		return ;
	current_a = a;
	while (current_a)
	{
		target_position = find_target_position(b, current_a->data);
		cost_a = calculate_rotations(a, current_a->data);
		cost_b = calculate_rotations(b, target_position);
		total_cost = cost_a + cost_b;
		current_a->push_cost = total_cost;
		current_a = current_a->next;
	}
}

t_stack_node *find_cheapest_move(t_stack_node *a)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;
	int				min_cost;

	current = a;
	cheapest = current;
	min_cost = current->push_cost;
	while (current)
	{
		if (current->push_cost < min_cost)
		{
			min_cost = current->push_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	push_cheapest_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*current;

	current = *a;
	cheapest = find_cheapest_move(a);
	while (current->data != cheapest->data)
	{
		if (cheapest->push_cost > 0)
			rotate(&a, 'a');
		else
			
	}
}