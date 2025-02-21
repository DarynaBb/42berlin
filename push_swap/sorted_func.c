/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:13:36 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:13:39 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack_node **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, 'a');
}

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*c;

	c = *stack;
	if (!c || !c->next || !c->next->next)
		return ;
	if (c->data > c->next->data && c->next->data > c->next->next->data)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (c->data > c->next->data && c->data > c->next->next->data)
		rotate(stack, 'a');
	else if (c->data < c->next->data && c->next->data
		> c->next->next->data && c->data > c->next->next->data)
		reverse_rotate(stack, 'a');
	else if (c->data > c->next->data && c->next->data
		< c->next->next->data)
		swap(stack, 'a');
	else if (c->data < c->next->data && c->next->data > c->next->next->data)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}
