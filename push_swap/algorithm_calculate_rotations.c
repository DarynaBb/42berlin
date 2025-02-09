#include "push_swap.h"

t_stack_node *find_cheapest_move(t_stack_node *stack)
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
	// printf("cheapest number:%d\n", cheapest->data);
	return (cheapest);
}

void bring_target_to_top(t_stack_node **b, int target_position, char stack_name)
{
	if (!b || !*b)
		exit(1);
	int rotations = target_position;

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

void	repeat(t_stack_node **stack, char stack_name, void (*f)(t_stack_node **, char), int times)
{
	while (times--)
		f(stack, stack_name);
}

void	push_cheapest_node_into_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	int				cost_a;
	int				cost_b;

	while (stack_len(*a) > 3)
	{
		calculate_cost_desc(*a, *b);
		cheapest = find_cheapest_move(*a);
		if (!cheapest || cheapest->push_cost == INT_MAX)
		{
			// printf("Error: No valid cheapest node found to push.\n");
			free_stack(*a);
			free_stack(*b);
			print_error_and_exit();
		}
		cost_a = calculate_rotations_a_desc(*a, cheapest->data);
		cost_b = calculate_rotations_b_desc(*b, find_target_position(*b, cheapest->data));
		if (cost_a > 0 && cost_b > 0)
		{
			rotate_both(a, b, cost_a, cost_b);
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			reverse_rotate_both(a, b, -cost_a, -cost_b);
		}
		else if (cost_a > 0)
		{
			repeat(a, 'a', rotate, cost_a);
			if (cost_b < 0)
				repeat(b, 'b', reverse_rotate, -cost_b);
		}
		else if (cost_b > 0)
		{
			repeat(b, 'b', rotate, cost_b);
			if (cost_a < 0)
				repeat(a, 'a', reverse_rotate, -cost_a);
		}
		else
		{
			reverse_rotate_both(a, b, -cost_a, -cost_b);
		}
		pb(a, b);
	}
	
}

void	push_cheapest_node_into_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	int				cost_a;
	int				cost_b;

	while (stack_len(*b) > 0)
	{
		calculate_cost_asc(*a, *b);
		cheapest = find_cheapest_move(*b);
		if (!cheapest || cheapest->push_cost == INT_MAX)
		{
			free_stack(*a);
			free_stack(*b);
			print_error_and_exit();
		}
		cost_a = calculate_rotations_a_asc(*a, find_target_position_asc(*a, cheapest->data));
		cost_b = calculate_rotations_b_asc(*b, cheapest->data);
		if (cost_a > 0 && cost_b > 0)
		{
			rotate_both(a, b, cost_a, cost_b);
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			reverse_rotate_both(a, b, -cost_a, -cost_b);
		}
		else if (cost_a > 0)
		{
			repeat(a, 'a', rotate, cost_a);
			if (cost_b < 0)
				repeat(b, 'b', reverse_rotate, -cost_b);
		}
		else if (cost_b > 0)
		{
			repeat(b, 'b', rotate, cost_b);
			if (cost_a < 0)
				repeat(a, 'a', reverse_rotate, -cost_a);
		}
		else
		{
			reverse_rotate_both(a, b, -cost_a, -cost_b);
		}
		pa(a, b);
	}
}

