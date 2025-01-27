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

void	rotate_both(t_stack_node **a, t_stack_node **b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}