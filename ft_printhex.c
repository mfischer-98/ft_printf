#include "printf.h"


int	ft_printhex(unsigned long n)
{
	const char	hex_ref[17];
	int			i;
	int			count;
	char		nbr[20];

	//strlcpy??  "0123456789abcdef";
	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putstr("0");
		return (0); //ou 1?
	}
	while (n > 0)
	{
		nbr[i] = hex_ref[n % 16];
		n = n/16;
		i++;
	}
	while (i--)
	{
		ft_putchar(nbr[i]);
		count++;
	}
	return (count);
}