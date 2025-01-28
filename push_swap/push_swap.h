#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int		data;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;

	struct s_stack_node *target_node;
	struct s_stack_node *next;
	// struct s_stack_node *prev;
} t_stack_node;

//Errors
void print_error_and_exit(void);

// Validate arguments
t_stack_node	*validate_arguments(int argc, char **argv);

// Utils
long ft_atol(const char *str);
void ft_putnbr_fd(int n, int fd);
int	is_sorted(t_stack_node *a);
int stack_len(t_stack_node *stack);

// Operations
void	swap(t_stack_node **stack, char stack_name);
void	swap_both(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	rotate(t_stack_node **stack, char stack_name);
void	rotate_both(t_stack_node **a, t_stack_node **b);
void	reverse_rotate(t_stack_node **stack, char stack_name);
void	reverse_rotate_both(t_stack_node **a, t_stack_node **b);

// Sort
void	sort_two(t_stack_node **stack);
void	sort_three(t_stack_node **stack);

// Algorithm - find target position
int	find_smallest(t_stack_node *stack);
int	find_largest(t_stack_node *stack);
int	find_position(t_stack_node *b, int number);
int	find_target_position(t_stack_node *b, int number);


// //Handle errors

//Stack initiation

//Nodes initiation

//Stack utils

//Commands

//Algorithms

#endif