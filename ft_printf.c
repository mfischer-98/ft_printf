/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:14:53 by mefische          #+#    #+#             */
/*   Updated: 2025/04/29 18:26:26 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//static void	ft_check (...)

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	int		len;
	va_list	ap;

	i = 0;
	count = 0;
	len = 0;
	va_start(ap, s);
	if (!s)
		return (0);
	while(s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == '%')
				ft_putchar('%');
			if (s[i] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (s[i] == 's')
				ft_putstr(va_arg(ap, char *)); //enviar como parametro para a helper function
			else if (s[i] == 'd' || s[i] == 'i')
				ft_putnbr(va_arg(ap, int));
			else if (s[i] == 'p') // pointer in hexadecimal format
				ft_pointer(va_arg(ap, void *));
			else if (s[i] == 'x') // hexadecimal lowercase
				ft_printhex(va_arg(ap, unsigned long));
			/*else if (s[i] == 'X') // hexadecimal uppercase
			else if (s[i] == 'u') // unsigned decimal*/
			else
				return (1); //error message
			i++;
		}
		write(1, &s[i], 1);
		count++;
		i++;
	}
	len += count;
	va_end(ap);
	return (len);
}

int	main()
{
	int		x = 26;
	char	str[] = "42 now";

	ft_printf("%d", x);
	ft_printf("\n");
	ft_printf("");
	ft_printf("Print this.\n");
	ft_printf("The number is %d.\n", x);
	ft_printf("The number is %s.\n", str);
	ft_printf("The number is %i. And then %s.\n", x, str);
	ft_printf("Number %i in hexadecimal is %x.\n", x);
	ft_printf("Memory address of x is %p.\n", x);
}
