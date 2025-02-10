/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:23 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:26 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack, char stack_name)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!*stack || !(*stack)->next)
		return ;
	current = *stack;
	*stack = current->next;
	temp = current;
	while (current->next)
		current = current->next;
	current->next = temp;
	temp->next = NULL;
	if (stack_name && stack_name == 'a')
		write(1, "ra\n", 3);
	if (stack_name && stack_name == 'b')
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
					int rotations_a, int rotations_b)
{
	while (rotations_a > 0 && rotations_b > 0)
	{
		rotate(a, 0);
		rotate(b, 0);
		write(1, "rr\n", 3);
		rotations_a--;
		rotations_b--;
	}
	while (rotations_a > 0)
	{
		rotate(a, 'a');
		rotations_a--;
	}
	while (rotations_b > 0)
	{
		rotate(b, 'b');
		rotations_b--;
	}
}
