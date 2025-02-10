#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					data;
	int					push_cost;
	struct s_stack_node	*next;
}	t_stack_node;

//Errors
void			free_stack(t_stack_node *stack);
void			print_error_and_exit(void);

// Validate arguments
t_stack_node	*validate_arguments(int argc, char **argv);


// Utils
long			ft_atol(const char *str);
void			ft_putnbr_fd(int n, int fd);
int				is_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

// Operations
void			swap(t_stack_node **stack, char stack_name);
void			swap_both(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **stack, char stack_name);
void			rotate_both(t_stack_node **a,
					t_stack_node **b, int rotations_a, int rotations_b);
void			reverse_rotate(t_stack_node **stack, char stack_name);
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b, int rotations_a, int rotations_b);

// Sort
void			sort_two(t_stack_node **stack);
void			sort_three(t_stack_node **stack);

// Calc cost descending
int				calculate_rotations_a_desc(t_stack_node *stack, int number);
void			calculate_cost_desc(t_stack_node *a, t_stack_node *b);
int				calculate_rotations_b_desc(t_stack_node *stack,
					int target_position);

// Calc cost ascending
int				calculate_rotations_a_asc(t_stack_node *stack,
					int target_position);
int				calculate_rotations_b_asc(t_stack_node *stack, int number);
void			calculate_cost_asc(t_stack_node *a, t_stack_node *b);

// Calculate push cost
int				calculate_push_cost(int cost_a, int cost_b);

// Algorithm - find target position
int				find_smallest(t_stack_node *stack);
int				find_largest(t_stack_node *stack);
int				find_position(t_stack_node *stack, int number);
int				find_target_position(t_stack_node *b, int number);
int				find_target_position_asc(t_stack_node *stack, int number);

// Algorithm - push cheapest node
void			push_cheapest_node_into_b(t_stack_node **a, t_stack_node **b);
void			bring_target_to_top(t_stack_node **b,
					int target_position, char stack_name);
void			push_cheapest_node_into_a(t_stack_node **a, t_stack_node **b);
void			repeat(t_stack_node **stack, char stack_name,
					void (*f)(t_stack_node **, char), int times);
t_stack_node	*find_cheapest_move(t_stack_node *stack);

// Test
void			sort(t_stack_node **a, t_stack_node **b);

#endif