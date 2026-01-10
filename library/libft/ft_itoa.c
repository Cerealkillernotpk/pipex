/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:01:18 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/29 15:44:54 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long nb)
{
	long	compt;

	compt = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		compt++;
	while (nb)
	{
		nb = nb / 10;
		compt++;
	}
	return (compt);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*result;
	long			nbr;

	nbr = (long)n;
	len = ft_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (nbr == 0)
		result[len--] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= (-1);
	}
	while (nbr)
	{
		result[len--] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	return (result);
}
