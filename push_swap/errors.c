/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbilenko <dbilenko@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:10:57 by dbilenko          #+#    #+#             */
/*   Updated: 2025/02/10 14:10:59 by dbilenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
	free(stack);
}

void	print_error_and_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}
