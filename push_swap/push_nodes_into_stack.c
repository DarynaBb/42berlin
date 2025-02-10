#include "push_swap.h"

void	align_stacks(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b)
{
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
			free_stack(*a);
			free_stack(*b);
			print_error_and_exit();
		}
		cost_a = calculate_rotations_a_desc(*a, cheapest->data);
		cost_b = calculate_rotations_b_desc(*b, 
				find_target_position(*b, cheapest->data));
		align_stacks(a, b, cost_a, cost_b);
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
		cost_a = calculate_rotations_a_asc(*a, 
				find_target_position_asc(*a, cheapest->data));
		cost_b = calculate_rotations_b_asc(*b, cheapest->data);
		align_stacks(a, b, cost_a, cost_b);
		pa(a, b);
	}
}
