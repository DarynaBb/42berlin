#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	smallest;
	
	if (is_sorted(*a))
		return ;
	if (stack_len(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	if (stack_len(*a) == 2)
	{
		sort_two(a);
		return ;
	}
	else
	{
		pb(a, b);
		pb(a, b);
		push_cheapest_node_into_b(a, b);
		sort_three(a);
		push_cheapest_node_into_a(a, b);
		smallest = find_smallest(*a);
		bring_target_to_top(a, find_position(*a, smallest), 'a');
	}
}

int main(int argc, char **argv)
{
	t_stack_node *a = NULL;
	t_stack_node *b = NULL;

	a = validate_arguments(argc - 1, argv + 1);
	if (!a)
	{
		free_stack(a);
		print_error_and_exit();
	}
	sort(&a, &b);
	free_stack(a);
	free_stack(b);
	return 0;
}

// printf("Stack A:\n");
	// t_stack_node *current = a;
	// while (current)
	// {
	// 	printf("%d\n", current->data);
	// 	current = current->next;
	// }

	// printf("Stack B:\n");
	// t_stack_node *temp = b;
	// while (temp)
	// {
	// 	printf("%d\n", temp->data);
	// 	temp = temp->next;
	// }