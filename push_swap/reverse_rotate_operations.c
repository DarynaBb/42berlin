#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack, char stack_name)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	second_last = *stack;
	while (second_last->next && second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (stack_name && stack_name == 'a')
		write(1, "rra\n", 4);
	if (stack_name && stack_name == 'b')
		write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack_node **a,
			t_stack_node **b, int rotations_a, int rotations_b)
{
	while (rotations_a > 0 && rotations_b > 0)
	{
		reverse_rotate(a, 0);
		reverse_rotate(b, 0);
		write(1, "rrr\n", 4);
		rotations_a--;
		rotations_b--;
	}
	while (rotations_a > 0)
	{
		reverse_rotate(a, 'a');
		rotations_a--;
	}
	while (rotations_b > 0)
	{
		reverse_rotate(b, 'b');
		rotations_b--;
	}
}
