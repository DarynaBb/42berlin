#include "push_swap.h"

void	sort(t_stack_node **a, t_stack_node **b)
{
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
		sort_two_desc(b);
	}
	push_cheapest_node(a, b);
}

