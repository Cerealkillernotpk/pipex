/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:08:18 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/29 16:35:30 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbpos(int nb, int fd)
{
	if (nb > 0)
	{
		ft_putnbpos(nb / 10, fd);
		nb = nb % 10 + '0';
		write(fd, &nb, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd > -1)
	{
		if (n == 0)
			write(fd, "0", 1);
		if (n < 0)
		{
			if (n == -2147483648)
				write(fd, "-2147483648", 11);
			else
			{
				write(fd, "-", 1);
				n *= -1;
			}
		}
		if (n > 0)
			ft_putnbpos(n, fd);
	}
}
