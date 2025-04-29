/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:18:44 by mefische          #+#    #+#             */
/*   Updated: 2025/04/29 18:15:55 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

/*# include <fcntl.h> //for open

int	main(void)
{
	int		fd;
	char	*c;

	c = "Hellooo";
	fd = open("z", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	ft_putstr_fd(c, fd);
	close(fd);
	if (close(fd) == -1)
		return (1);
}*/