/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:12:42 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:12:47 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_b;

	if (!*b)
		return ;
	top_b = *b;
	*b = top_b->next;
	top_b->next = *a;
	*a = top_b;
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_a;

	if (!*a)
		return ;
	top_a = *a;
	*a = top_a->next;
	top_a->next = *b;
	*b = top_a;
	write(1, "pb\n", 3);
}
