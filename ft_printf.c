/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:14:53 by mefische          #+#    #+#             */
/*   Updated: 2025/04/29 17:18:29 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
				ft_putstr(va_arg(ap, char *)); //como vou imprimir a variavel correta e manter a linhas da funcao?
			else if (s[i] == 'p') // pointer in hexadecimal format
				write (1, &s[i], 5); // probably not 0x at start?
			else if (s[i] == 'd') // decimal number
				ft_itoa(va_arg(ap, int)); //not sure
			else if (s[i] == 'i') // integer
				ft_itoa(va_arg(ap, int));
/*			else if (s[i] == 'u') // unsigned decimal
			else if (s[i] == 'x') // hexadecimal lowercase
			else if (s[i] == 'X') // hexadecimal uppercase*/
			else
				return (1); //error message
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
	int		x = 12;
	char	str[] = "42 now";

	ft_printf("%d", x);
	ft_printf("\n");
	ft_printf("");
	ft_printf("Print this.\n");
	ft_printf("The number is %d.\n", x);
	ft_printf("The number is %s.\n", str);
	ft_printf("The number is %d. And then %s.\n", x, str);
}
