#ifndef PRINTF_H

# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# Printf function
int	ft_printf(const char *, ...);

# Helper functions
size_t	ft_strlen(const char *s);
voi
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif