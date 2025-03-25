#include "push_swap.h"

int calculate_rotations_position(t_stack_node *stack, int target_position)
{
	int size;
	int rotations;

	size = stack_len(stack);
	if (target_position < 0 || target_position >= size)
		return (-1);
	if (target_position <= size / 2)
		rotations = target_position;
	else
		rotations = -(size - target_position);
	return (rotations);
}

int calculate_rotations_number(t_stack_node *stack, int number)
{
	int position;
	int size;
	int rotations;

	position = find_position(stack, number);
	if (position == -1)
		return (-1);
	size = stack_len(stack);
	if (position <= size / 2)
		rotations = position;
	else
		rotations = -(size - position);
	return (rotations);
}

// void calculate_cost(t_stack_node *stack_a, t_stack_node *stack_b, int order)
// {
// 	t_stack_node *current_node;
// 	int cost_a;
// 	int cost_b;
// 	int total_cost;
// 	int target_position;

// 	if (!stack_a || !stack_b)
// 		return;

// 	// Iterate through stack_b for cost calculations
// 	current_node = stack_b;

// 	while (current_node)
// 	{
// 		// Find the target position based on the order (1 for ascending, -1 for descending)
// 		if (order == 1)
// 			target_position = find_target_position_asc(stack_a, current_node->data);
// 			// target_position = find_target_position_asc(stack_a, current_node->data);
// 		else if (order == -1)
// 			target_position = find_target_position_desc(stack_b, current_node->data);
// 			// target_position = find_target_position_desc(stack_b, current_node->data);
// 		else
// 			return; // Invalid order

// 		if (target_position == -1)
// 		{
// 			current_node->push_cost = INT_MAX;
// 			current_node = current_node->next;
// 			continue;
// 		}

// 		// Calculate rotations for both stacks
// 		if (order == 1)
// 		{
// 			// cost_a = calculate_rotations_position(stack_a, target_position);
// 			// cost_b = calculate_rotations_number(stack_b, current_node->data);
// 			cost_a = calculate_rotations_a_asc(stack_a, target_position);
// 			cost_b = calculate_rotations_b_asc(stack_b, current_node->data);
// 		}
// 		else
// 		{
// 			// cost_a = calculate_rotations_number(stack_a, current_node->data);
// 			// cost_b = calculate_rotations_position(stack_b, target_position);
// 			cost_a = calculate_rotations_a_desc(stack_a, target_position);
// 			cost_b = calculate_rotations_b_desc(stack_b, current_node->data);
// 		}
		

// 		// Calculate total cost
// 		if (cost_a != INT_MAX && cost_b != INT_MAX)
// 		{
// 			// Check if simultaneous rotations are possible
// 			if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
// 			{
// 				if (cost_a < 0 && cost_b < 0)
// 				{
// 					cost_a = -cost_a;
// 					cost_b = -cost_b;
// 				}
// 				total_cost = (cost_a > cost_b) ? cost_a : cost_b;
// 			}
// 			else
// 			{
// 				if (cost_a < 0)
// 					cost_a = -cost_a;
// 				if (cost_b < 0)
// 					cost_b = -cost_b;
// 				total_cost = cost_a + cost_b;
// 			}
// 			current_node->push_cost = total_cost;
// 		}
// 		else
// 		{
// 			current_node->push_cost = INT_MAX;
// 		}

// 		current_node = current_node->next;
// 	}
// }
