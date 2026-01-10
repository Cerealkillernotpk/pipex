/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:28:12 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/28 16:23:23 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t					i;
	const unsigned char		*str1;
	unsigned char			*str2;

	str1 = src;
	str2 = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		i = n - 1;
		while (i < n)
		{
			str2[i] = str1[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
