#include "push_swap.h"

void	sort_two(t_stack_node **stack, char stack_name)
{
	if ((*stack)->data > (*stack)->next->data)
		swap(stack, stack_name);
}

// void	sort_three(t_stack_node **stack)
// {

// }