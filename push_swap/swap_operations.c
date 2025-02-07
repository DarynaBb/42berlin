#include "push_swap.h"

void	swap(t_stack_node **stack, char stack_name)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = NULL;
	second = NULL;
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (stack_name && stack_name == 'a')
		write(1, "sa\n", 3);
	if (stack_name && stack_name == 'b')
		write(1, "sb\n", 3);
}

void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "ss\n", 3);
}
