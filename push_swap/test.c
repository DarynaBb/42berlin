#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
	int	largest;

	if (stack_len(*a) == 3)
	{
		sort_three(a);
		return;
	}
	if (stack_len(*a) < 3)
	{
		sort_two(a);
		return;
	}
	else 
	{
		pb(a, b);
		pb(a, b);
		push_cheapest_node(a, b);
		if (is_sorted_desc(*b))
		{
			largest = find_largest(*b);
			bring_target_to_top(b, find_position(*b, largest));
			while (stack_len(*b) > 0)
				pa(a, b);
		}
	}
}

