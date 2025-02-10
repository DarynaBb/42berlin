/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:11:07 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:10 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack_node *stack)
{
	t_stack_node	*current;
	int				smallest;

	current = stack;
	smallest = current->data;
	if (!stack)
		return (0);
	while (current)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*current;

	if (!stack)
		return (0);
	current = stack;
	largest = current->data;
	while (current)
	{
		if (current->data > largest)
			largest = current->data;
		current = current->next;
	}
	return (largest);
}

int	find_position(t_stack_node *stack, int number)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = stack;
	while (current)
	{
		if (current->data == number)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
