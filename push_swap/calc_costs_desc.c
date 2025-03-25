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

int calculate_rotations_b_desc(t_stack_node *stack, int target_position)
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
		target_position = find_target_position_desc(b, current_a->data);
		if (target_position == -1)
		{
			current_a->push_cost = INT_MAX;
			current_a = current_a->next;
			continue;
		}
		cost_a = calculate_rotations_a_desc(a, current_a->data);
		cost_b = calculate_rotations_b_desc(b, target_position);

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
			}
			else
			{
				if (cost_a < 0)
					cost_a = -cost_a;
				if (cost_b < 0)
					cost_b = -cost_b;
				total_cost = cost_a + cost_b;
			}
			current_a->push_cost = total_cost;
		}
		else
			current_a->push_cost = INT_MAX;
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
	// printf("cheapest number:%d\n", cheapest->data);
	return (cheapest);
}

void bring_target_to_top(t_stack_node **b, int target_position, char stack_name)
{
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
		calculate_cost_asc(*a, *b);
		cheapest = find_cheapest_move(*a);
		if (!cheapest || cheapest->push_cost == INT_MAX)
		{
			// printf("Error: No valid cheapest node found to push.\n");
			return;
		}
		// cost_a = calculate_rotations_number(*a, cheapest->data);
		// cost_b = calculate_rotations_position(*b, find_target_position(*b, cheapest->data, -1));
		cost_a = calculate_rotations_a_desc(*a, cheapest->data);
		cost_b = calculate_rotations_b_desc(*b, find_target_position_desc(*b, cheapest->data));
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
		calculate_cost_desc(*a, *b);
		cheapest = find_cheapest_move(*b);
		if (!cheapest || cheapest->push_cost == INT_MAX)
		{
			printf("Error: No valid cheapest node found to push.\n");
			return;
		}
		// cost_a = calculate_rotations_position(*a, find_target_position(*a, cheapest->data, 1));
		// cost_b = calculate_rotations_number(*b, cheapest->data);
		cost_a = calculate_rotations_a_asc(*a, find_target_position_asc(*a, cheapest->data));
		cost_b = calculate_rotations_b_asc(*b, cheapest->data);
		if (cost_a > 0 && cost_b > 0)
			rotate_both(a, b, cost_a, cost_b);
		else if (cost_a < 0 && cost_b < 0)
			reverse_rotate_both(a, b, -cost_a, -cost_b);
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
			reverse_rotate_both(a, b, -cost_a, -cost_b);
		pa(a, b);
	}
	
}

// void push_cheapest_node(t_stack_node **a, t_stack_node **b, int direction)
// {
//     t_stack_node *cheapest;
//     int cost_a;
//     int cost_b;

//     // Use different conditions for when direction is ascending or descending
//     while ((direction == -1 && stack_len(*a) > 3) || (direction == 1 && stack_len(*b) > 0))
//     {
//         calculate_cost(*a, *b, direction);
//         cheapest = find_cheapest_move(direction == -1 ? *a : *b);
//         if (!cheapest || cheapest->push_cost == INT_MAX)
//         {
//             return;
//         }

//         if (direction == -1) // descending (from a to b)
//         {
//             cost_a = calculate_rotations_number(*a, cheapest->data);
//             cost_b = calculate_rotations_position(*b, find_target_position(*b, cheapest->data, direction));
//         }
//         else // ascending (from b to a)
//         {
//             cost_a = calculate_rotations_position(*a, find_target_position(*a, cheapest->data, direction));
//             cost_b = calculate_rotations_number(*b, cheapest->data);
//         }

//         if (cost_a > 0 && cost_b > 0)
//         {
//             rotate_both(a, b, cost_a, cost_b);
//         }
//         else if (cost_a < 0 && cost_b < 0)
//         {
//             reverse_rotate_both(a, b, -cost_a, -cost_b);
//         }
//         else if (cost_a > 0)
//         {
//             repeat(a, 'a', rotate, cost_a);
//             if (cost_b < 0)
//                 repeat(b, 'b', reverse_rotate, -cost_b);
//         }
//         else if (cost_b > 0)
//         {
//             repeat(b, 'b', rotate, cost_b);
//             if (cost_a < 0)
//                 repeat(a, 'a', reverse_rotate, -cost_a);
//         }
//         else
//         {
//             reverse_rotate_both(a, b, -cost_a, -cost_b);
//         }

//         if (direction == -1) // descending (from a to b)
//             pb(a, b);
//         else // ascending (from b to a)
//             pa(a, b);
//     }
// }
