/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:08:06 by mefische          #+#    #+#             */
/*   Updated: 2025/05/05 11:59:31 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long n, char *base)
{
	int		i;
	int		count;
	char	nbr[20];

	i = 0;
	count = 0;
	if (n == 0)
	{
		ft_putstr("0");
		return (1);
	}
	while (n > 0)
	{
		nbr[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
	{
		ft_putchar(nbr[i]);
		count++;
	}
	return (count);
}
