#include "printf.h"

int	ft_pointer(void *ptr)
{
	if (!ptr)
		return('nil');
	ft_putstr("0x");
	ft_printhex((unsigned long)ptr);
}