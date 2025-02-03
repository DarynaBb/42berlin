#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Assuming validate_arguments is correctly setting up stack a
    a = validate_arguments(argc - 1, argv + 1);
	if (!a)
    {
        printf("Stack initialization failed.\n");
        return (1);
    }

    // Call ra function to rotate stack a
    // swap(&a);
	// rotate(&a);
	// reverse_rotate(&a);
	// sort_two(&a);
	// swap(&a, 'a');
	// sort_three(&a);
	// find_smallest(a);
	// find_largest(a);
	// find_position(a, 15);
	// find_target_position(a, 15);
    sort(&a, &b);
    // calculate_rotations(a, 15);
    
    // calculate_cost(a, b);

    printf("Initial Stack A:\n");
    t_stack_node *current = a;
    while (current)
    {
        printf("Data: %d\n", current->data);
        current = current->next;
    }

    // Test find_target_position
    // int test_number = 15; // Example number to test
    // printf("\nTesting find_target_position for number: %d\n", test_number);
    // int target_pos = find_target_position(a, test_number);
    // printf("Target Position: %d\n", target_pos);

	t_stack_node *temp = b;
    while (temp)
    {
        write(1, "B-Element: \n", 9);
        ft_putnbr_fd(temp->data, 1); // Replace with your number printing function
        write(1, "\n", 1);
        temp = temp->next;
    }

    return 0;
}
// int main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;

// 	a = validate_arguments(argc - 1, argv + 1);
	// t_stack_node *current = a;
	// while (current)
	// {
	// 	write(1, "Element: ", 9);
	// 	ft_putnbr_fd(current->data, 1); // Replace with your number printing function
	// 	write(1, "\n", 1);
	// 	current = current->next;
	// }
	// write(1, "Stack B:\n", 9);
    // current = b;
    // while (current)
    // {
    //     ft_putnbr_fd(current->data, 1);
    //     write(1, "\n", 1);
    //     current = current->next;
    // }
	// if (is_sorted(a))
    // {
    //     write(1, "Stack A is already sorted.\n", 26);
    //     return (0);  // Exit early if sorted
    // }
	// ra(&a);
	// return (0);
// }

// int main(int argc, char **argv)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if(argc == 1 || argc == 2 && !argv[1][0])
// 		return (1);
// 	else if (argc == 2)
// 		argv = ft_split(argv[1], ' ');
// 	init_stack_a(&a, argv + 1);
// 	if (!stack_sorted(a))
// 	{
// 		if (stack_len(a) == 2)
// 			sa(&a, false);
// 		else if (stack_len(a) == 3)
// 			sort_three(&a);
// 		else
// 			sort_stacks(&a, &b);
// 	}
// 	free_stack(&a);
// 	return (0);
// }