#include "push_swap.h"

t_stack_node	*find_cheapest_move(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*cheapest;
	int				min_cost;

	if (!stack)
	{
		free_stack(stack);
		exit(1);
	}
	current = stack;
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

void	bring_target_to_top(t_stack_node **b,
		int target_position, char stack_name)
{
	int	rotations;

	if (!b || !*b)
		exit(1);
	rotations = target_position;
	if (rotations > 0)
	{
		while (rotations-- > 0)
			rotate(b, stack_name);
	}
	else
	{
		while (rotations++ < 0)
			reverse_rotate(b, stack_name);
	}
}

void	repeat(t_stack_node **stack, char stack_name,
		void (*f)(t_stack_node **, char), int times)
{
	while (times--)
		f(stack, stack_name);
}
