/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:52:57 by adakhama          #+#    #+#             */
/*   Updated: 2025/11/04 18:07:34 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, size_t *len)
{
	unsigned int	i;

	if (s == NULL)
		ft_putstr("(null)", len);
	else
	{
		i = 0;
		while (s[i])
			ft_putchar(s[i++], len);
	}
}
