#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		print_char(char c);
int		print_str(const char *str);
int		print_int(int num);
int		print_unsigned_int(unsigned int num);
int		print_hex(unsigned int num, char spec);
int		print_pointer(uintptr_t ptr);
int		ft_printf(const char *str, ...);

// Utils
char	*dec_to_hex(uintptr_t num, char spec);
char	*hex_string(char *str, int length);
char	*handle_zero_case(void);

#endif