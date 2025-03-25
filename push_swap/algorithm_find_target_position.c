#include "push_swap.h"

int	find_smallest(t_stack_node *stack)
{
	t_stack_node	*current;
	int				smallest;

	current = stack;
	smallest = current->data;
	if (!stack)
		return (0);
	while(current)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
	}
	// printf("smallest number: %d\n", smallest);
	return (smallest);
}

int	find_largest(t_stack_node *stack)
{
	int				largest;
	t_stack_node	*current;

	if (!stack)
		return (0);
	current = stack;
	largest = current->data;
	while(current)
	{
		if (current->data > largest)
			largest = current->data;
		current = current->next;
	}
	// printf("largest number: %d\n", largest);
	return (largest);
}

int	find_position(t_stack_node *stack, int number)
{
	int				position;
	t_stack_node	*current;

	position = 0;
	current = stack;
	while (current)
	{
		if (current->data == number)
		{
			printf("find_position: number %d found at position %d\n", number, position);
			return (position);
		}
			
		current = current->next;
		position++;
	}
	printf("find_position: number %d not found, returning -1\n", number);
	return (-1);
}

int find_target_position(t_stack_node *b, int number)
{
 t_stack_node *current;
 int smallest;
 int largest;
 int position;

 if (!b)
  return (-1);
 smallest = find_smallest(b);
 largest = find_largest(b);
//  if (number > largest || number < smallest)
//  {
//   int p = find_position(b, smallest);
//   // printf("target position: %d\n", (position));
//   if (p + 1 == stack_len(b))
//    return (0);
//   else
//    return (p + 1);
//  }
 
 current = b;
 position = 0;
 int min_diff = INT_MAX;
 int best_position = 0;
 while (current)
 {
  if (number > current->data && (number - current->data) < min_diff)
  {
   min_diff = number - current->data;
   best_position = position;
  }
  current = current->next;
  position++;
 }
 return (best_position);
}

