/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:50:55 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/28 13:04:45 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	tmp1 = s1;
	tmp2 = s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
		{
			return (tmp1[i] - tmp2[i]);
		}
		i++;
	}
	return (0);
}
