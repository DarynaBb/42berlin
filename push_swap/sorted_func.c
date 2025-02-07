#include "push_swap.h"

void	sort_two(t_stack_node **stack)
{
	if ((*stack)->data > (*stack)->next->data)
		swap(stack,'a');
}

void	sort_two_desc(t_stack_node **stack)
{
	if ((*stack)->data < (*stack)->next->data)
		swap(stack,'a');
}

// void	sort_three(t_stack_node **stack)
// {
// 	t_stack_node	*current;

// 	current = *stack;
// 	if (!current || !current->next || !current->next->next)
// 		return;
// 	if (!is_sorted(*stack))
// 		{
// 			//3 2 1
// 		if (current->data > current->next->data && current->next->data > current->next->next->data)
// 		{
// 			swap(stack, 'a');
// 			reverse_rotate(stack, 'a');
// 		}
// 		// 3 1 2
// 		else if (current->data > current->next->data && current->data > current->next->next->data)
// 			rotate(stack, 'a');
// 		// 2 3 1
// 		else if (current->data < current->next->data && current->next->data > current->next->next->data && current->data > current->next->next->data)
// 		// else if (current->data < current->next->data && current->next->data > current->next->next->data)
// 			reverse_rotate(stack, 'a');
// 		// 2 1 3
// 		else if (current->data > current->next->data && current->next->data < current->next->next->data)
// 			swap(stack, 'a');
// 		// 1 3 2
// 		else if (current->data < current->next->data && current->data > current->next->next->data)
// 		{
// 			swap(stack, 'a');
// 			rotate(stack, 'a');
// 		}
// 	}
// }

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*current;

	current = *stack;
	if (!current || !current->next || !current->next->next)
		return;

	if (current->data > current->next->data && current->next->data > current->next->next->data)
	{ // 3 2 1
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else if (current->data > current->next->data && current->data > current->next->next->data)
	{ // 3 1 2
		rotate(stack, 'a');
	}
	else if (current->data < current->next->data && current->next->data > current->next->next->data && current->data > current->next->next->data)
	{ // 2 3 1
		reverse_rotate(stack, 'a');
	}
	else if (current->data > current->next->data && current->next->data < current->next->next->data)
	{ // 2 1 3
		swap(stack, 'a');
	}
	else if (current->data < current->next->data && current->next->data > current->next->next->data)
	{ // 1 3 2
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}
