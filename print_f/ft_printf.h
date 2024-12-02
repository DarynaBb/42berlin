#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

int	print_char(char c);
int	print_str(char *str);
int	print_int(int num);
int	print_unsigned_int(int num);

#endif