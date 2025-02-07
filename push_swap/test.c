#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	// int	largest;
	int	smallest;

	if (stack_len(*a) == 3)
	{
		sort_three(a);
		return;
	}
	if (stack_len(*a) == 2)
	{
		sort_two(a);
		return;
	}
	else 
	{
		pb(a, b);
		pb(a, b);
		push_cheapest_node(a, b);
		sort_three(a);

		// printf("Stack A:\n");
		// t_stack_node *current = *a;
		// while (current)
		// {
		// 	printf("%d\n", current->data);
		// 	current = current->next;
		// }
		
		// printf("Stack B:\n");
		// t_stack_node *temp = *b;
		// while (temp)
		// {
		// 	printf("%d\n", temp->data);
		// 	temp = temp->next;
		// }

		push_cheapest_node_into_a(a, b);
		
		smallest = find_smallest(*a);
		// printf("smallest: %d\n", smallest);
		bring_target_to_top(a, find_position(*a, smallest), 'a');


		// if (is_sorted_desc(*b))
		// {
		// 	largest = find_largest(*b);
		// 	bring_target_to_top(b, find_position(*b, largest));
		// 	while (stack_len(*b) > 0)
		// 		pa(a, b);
		// }
	}
}

