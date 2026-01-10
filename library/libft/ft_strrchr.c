/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:31:10 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/28 14:43:50 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	while (i--)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (0);
}
