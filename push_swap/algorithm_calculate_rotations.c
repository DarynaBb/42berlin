#include "push_swap.h"

int	calculate_rotations_a(t_stack_node *stack, int number)
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
	// printf("rotations number %d for number %d\n", rotations, number);
	return (rotations);
}

int calculate_rotations_b(t_stack_node *stack, int target_position)
{
	int	size;
	int	rotations;

	size = stack_len(stack);
	if (target_position < 0 || target_position >= size)
	{
		// printf("Error: Invalid target position %d for stack size %d\n", target_position, size);
		return (-1);
	}
	if (target_position <= (size) / 2)
		rotations = target_position;
	else
		rotations = -(size - target_position);

	// printf("Rotations in stack B for target position %d: %d\n", target_position, rotations);
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
	// printf("rotations number %d for number %d\n", rotations, number);
	return (rotations);
}

int calculate_rotations_a_asc(t_stack_node *stack, int target_position)
{
	int	size;
	int	rotations;

	size = stack_len(stack);
	if (target_position < 0 || target_position >= size)
	{
		// printf("Error: Invalid target position %d for stack size %d\n", target_position, size);
		return (-1);
	}
	if (target_position <= (size) / 2)
		rotations = target_position;
	else
		rotations = -(size - target_position);

	// printf("Rotations in stack A for target position %d: %d\n", target_position, rotations);
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
		if (target_position == -1)
		{
			// printf("Error: No valid target position for number %d\n", current_a->data);
			current_a->push_cost = INT_MAX;
			current_a = current_a->next;
			continue;
		}
		cost_a = calculate_rotations_a(a, current_a->data);
		cost_b = calculate_rotations_b(b, target_position);
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
			current_a->push_cost = total_cost;
		}
		else
		{
			// printf("Error: Invalid cost for number %d\n", current_a->data);
			current_a->push_cost = INT_MAX;
		}
		current_a = current_a->next;
	}
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

void	push_cheapest_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	int				cost_a;
	int				cost_b;

	while (stack_len(*a) > 3)
	{
		calculate_cost(*a, *b);
		cheapest = find_cheapest_move(*a);
		if (!cheapest || cheapest->push_cost == INT_MAX)
		{
			// printf("Error: No valid cheapest node found to push.\n");
			return;
		}
		cost_a = calculate_rotations_a(*a, cheapest->data);
		cost_b = calculate_rotations_b(*b, find_target_position(*b, cheapest->data));
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
			printf("Error: No valid cheapest node found to push.\n");
			return;
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
		// printf("Stack A:\n");
		// t_stack_node *current = *a;
		// while (current)
		// {
		// 	printf("%d\n", current->data);
		// 	current = current->next;
		// }
		
		// printf("Stack B:\n");
		// t_stack_node *temp = *b;
		// while (temp)
		// {
		// 	printf("%d\n", temp->data);
		// 	temp = temp->next;
		// }
		pa(a, b);
	}
	
}

