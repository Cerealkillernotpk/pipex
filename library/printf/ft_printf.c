/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:35:24 by marvin            #+#    #+#             */
/*   Updated: 2025/11/05 15:25:32 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convertions(char c, va_list list, size_t *len)
{
	if (c == 'c')
		ft_putchar(va_arg(list, int), len);
	else if (c == 's')
		ft_putstr(va_arg(list, char *), len);
	else if (c == 'p')
		ft_putbase("0123456789abcdef", (size_t) va_arg(list, void *), 0, len);
	else if (c == 'd')
		ft_putnbr((long)va_arg(list, int), len);
	else if (c == 'i')
		ft_putnbr((long)va_arg(list, int), len);
	else if (c == 'u')
		ft_putnbr(va_arg(list, unsigned int), len);
	else if (c == 'x')
		ft_putbase("0123456789abcdef", va_arg(list, unsigned int), 1, len);
	else if (c == 'X')
		ft_putbase("0123456789ABCDEF", va_arg(list, unsigned int), 1, len);
	else if (c == '%')
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	list;

	i = 0;
	len = 0;
	va_start(list, str);
	if (str[i] == '%' && str[i + 1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i++], &len);
		else
		{
			ft_convertions(str[i + 1], list, &len);
			i += 2;
		}
	}
	va_end(list);
	return (len);
}
