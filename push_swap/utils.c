#include "push_swap.h"

static int	n_is_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		i;

	i = 0;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	n = n_is_negative(n, fd);
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	while (--i >= 0)
		write(fd, &str[i], 1);
}

long ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		if ((num * sign) < INT_MIN || (num * sign) > INT_MAX)
			print_error_and_exit();
		i++;
	}
	return (num * sign);
}

int	is_sorted(t_stack_node *a)
{
	t_stack_node *current;
	current = a;
	while (current && current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_len(t_stack_node *stack)
{
	int	stack_len;

	stack_len = 0;
	while (stack)
	{
		stack_len++;
		stack = stack->next;
	}
	// printf("Stack length:%d\n", stack_len);
	return (stack_len);
}