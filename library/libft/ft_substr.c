/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:34:01 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/31 13:33:39 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_b(char *sub, char const *s, unsigned int start, size_t len)
{
	size_t			j;

	j = 0;
	if (!sub)
		return (0);
	while (j < len)
	{
		sub[j] = s[start];
		j++;
		start++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = ft_strdup("");
		return (sub);
	}
	if (len > (slen - start))
		len = slen - start;
	sub = (char *)malloc (sizeof(char) * (len + 1));
	ft_b(sub, s, start, len);
	return (sub);
}
