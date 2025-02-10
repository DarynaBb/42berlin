/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_asc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:08 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:10:36 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rotations_a_asc(t_stack_node *stack, int target_position)
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

int	handle_positive_costs(int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		cost_a = -cost_a;
		cost_b = -cost_b;
	}
	if (cost_a > cost_b)
		return (cost_a);
	else
		return (cost_b);
}

int	calculate_push_cost(int cost_a, int cost_b)
{
	int	total_cost;

	if (cost_a != INT_MAX && cost_b != INT_MAX)
	{
		if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
		{
			total_cost = handle_positive_costs(cost_a, cost_b);
		}
		else
		{
			if (cost_a < 0)
				cost_a = -cost_a;
			if (cost_b < 0)
				cost_b = -cost_b;
			total_cost = cost_a + cost_b;
		}
		return (total_cost);
	}
	return (INT_MAX);
}

void	calculate_cost_asc(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				target_position;

	if (!a || !b)
		return ;
	current_b = b;
	while (current_b)
	{
		target_position = find_target_position_asc(a, current_b->data);
		if (target_position == -1)
		{
			current_b->push_cost = INT_MAX;
			current_b = current_b->next;
			continue ;
		}
		cost_a = calculate_rotations_a_asc(a, target_position);
		cost_b = calculate_rotations_b_asc(b, current_b->data);
		total_cost = calculate_push_cost(cost_a, cost_b);
		current_b->push_cost = total_cost;
		current_b = current_b->next;
	}
}
