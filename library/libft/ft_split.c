/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:56:30 by adakhama          #+#    #+#             */
/*   Updated: 2025/10/31 15:19:27 by adakhama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	**ft_cond(char **res, const char *s, char c, size_t len)
{
	size_t	i;
	int		j;
	int		s_word;

	i = 0;
	j = 0;
	s_word = -1;
	while (i <= len)
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == len) && s_word >= 0)
		{
			res[j] = fill_word(s, s_word, i);
			if (!(res[j]))
			{
				ft_free(res, j);
				return (NULL);
			}
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_cond(res, s, c, len);
	return (res);
}
