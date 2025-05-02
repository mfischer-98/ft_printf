/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa_recursive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:08:06 by mefische          #+#    #+#             */
/*   Updated: 2025/05/02 16:17:30 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa_recursive(unsigned int n, char *base)
{
	int	count;

	count = 0;
	n = (unsigned long)n;
	if (n >= 16)
		count += ft_printhexa_recursive(n / 16, base);
	return (count + ft_putchar(base[n % 16]));
}
