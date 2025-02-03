#include "push_swap.h"

int find_value_at_position(t_stack_node *stack, int position)
{
    int index = 0;

    while (stack)
    {
        if (index == position)
            return stack->data;
        stack = stack->next;
        index++;
    }

    return -1; // Return -1 if the position is invalid
}

int	calculate_rotations(t_stack_node *stack, int number)
{
	int	position;
	int	size;
	int	rotations;

	position = find_position(stack, number);
	if (position == -1)
        return (-1);
	size = stack_len(stack);
	if (position <= size / 2)
		rotations = position;
	else
	rotations = size - position;
	printf("rotations number %d for number %d\n", rotations, number);
	return (rotations);
}

void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node *current_a;
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	target_position;
	int target_value;

	if (!a || !b)
		return ;
	current_a = a;
	while (current_a)
	{
		target_position = find_target_position(b, current_a->data);
		if (target_position == -1)
		{
			printf("Error: No valid target position for number %d\n", current_a->data);
			current_a->push_cost = INT_MAX; // Mark as impossible to move
			current_a = current_a->next;
			continue;
		}
		target_value = find_value_at_position(b, target_position);
        if (target_value == -1) // Error handling for invalid position
        {
            printf("Error: Target value not found in stack B for position %d\n", target_position);
            current_a->push_cost = INT_MAX;
            current_a = current_a->next;
            continue;
        }
		cost_a = calculate_rotations(a, current_a->data);
		cost_b = calculate_rotations(b, target_value);
		printf("cost A: %d\n", cost_a);
		printf("cost B: %d\n", cost_b);

		if (cost_a == -1 || cost_b == -1)
		{
			printf("Error: Invalid cost for number %d\n", current_a->data);
			current_a->push_cost = INT_MAX;
		}
		else
		{
			total_cost = cost_a + cost_b;
			printf("total cost: %d\n", total_cost);
			current_a->push_cost = total_cost;
		}
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
	printf("cheapest number:%d\n", cheapest->data);
	return (cheapest);
}

void	push_cheapest_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;
	t_stack_node	*current;
	int				position;

	current = *a;
	calculate_cost(*a, *b);
	cheapest = find_cheapest_move(*a);
	if (!cheapest || cheapest->push_cost == INT_MAX)
    {
        printf("Error: No valid cheapest node found to push.\n");
        return;
    }

	position = find_position(*a, cheapest->data);
	while (current->data != cheapest->data)
	{
		if (position < stack_len(*a) / 2)
			rotate(a, 'a');
		else 
			reverse_rotate(a, 'a');
		current = current->next;
	}
	pb(a, b);
}