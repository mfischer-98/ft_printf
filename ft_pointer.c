/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:23 by mefische          #+#    #+#             */
/*   Updated: 2025/05/02 16:14:54 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (0); //alterar para nil?
	count += ft_putstr("0x");
	count += ft_printhexa((uintptr_t)ptr, "0123456789abcdef");
	return (count);
}