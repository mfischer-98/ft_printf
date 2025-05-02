/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:14:53 by mefische          #+#    #+#             */
/*   Updated: 2025/05/02 16:16:22 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(char format, va_list ap)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_unsig_putnbr(va_arg(ap, unsigned int)));
	else if (format == 'x')
		return (ft_printhexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printhexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
 	else if (format == 'p')
		return (ft_pointer(va_arg(ap, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_check(s[i], ap);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

/* int	main()
{
	int		x = 26;
	int		count = 0;
	char	str[] = "lets go";
	char	c = 'm';

	//Percentage
	ft_printf("Percentage: %%\n");
	
	//Character
	count = ft_printf("Caracter: %c.\n", c);
	printf ("Return value: %d\n", count);

	//String
	count = ft_printf("String: %s.\n", str);
	printf ("Return value printf: %d\n", count);

	//Decimal or integer
	count = ft_printf("Decimal number: %d.\n", x);
	printf ("Return value: %d\n", count);
	
	count = printf("Integer number: %d.\n", x);
	printf ("Return value: %d\n", count);

	//Two variables
	ft_printf("Integer %i and then string %s.\n", x, str);

	//Unsigned int
	ft_printf ("Unsigned int: %u\n", 10);
	ft_printf ("Unsigned int negative: %u\n", -1);
	printf ("Unsigned int negative: %u\n", -2147483647);

	//Hexadecimal underscore
	ft_printf("Integer %i in hexadecimal is %x.\n", x, 26);

	//Hexadecimal upperscore
	ft_printf("Integer %i in hexadecimal is %X.\n", x, 26);

	//Pointer
	ft_printf("Memory address of x is %p.\n", &c);
	printf("Printf memory address of x is %p.\n", &c);
} */