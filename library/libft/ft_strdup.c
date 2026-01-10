/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:53:49 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/28 13:05:27 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		n;
	char	*dest;

	i = 0;
	n = 0;
	while (src[i])
		i++;
	dest = 0;
	dest = malloc ((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[n])
	{
		dest[n] = src[n];
		n ++;
	}
	dest[n] = '\0';
	return (dest);
}
