/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:43:32 by mefische          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:27 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

/*# include <fcntl.h> //for open

int	main(void)
{
	int	fd;
	int	c;

	c = -2147483648;
	fd = open("z", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	ft_putnbr_fd(c, fd);
	close(fd);
	if (close(fd) == -1)
		return (1);
}*/