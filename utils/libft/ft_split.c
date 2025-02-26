/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:03:17 by anpicard          #+#    #+#             */
/*   Updated: 2024/11/12 13:47:58 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	nb_words;
	size_t	i;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char	*ft_copy_words(char const *src, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_all(char **array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**split_words(char const *s, char c, char **split)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			split[k] = ft_copy_words(s + j, i - j);
			if (!split[k++])
			{
				free_all(split, k);
				return (NULL);
			}
		}
	}
	split[k] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	return (split_words(s, c, split));
}

// int	main(void)
// {
// 	char	*test;
// 	char	**split;
// 	test = ft_strdup(" bonjour*a*tous*****");
// 	split = ft_split(test, '*');
// 	printf("value 1: %s\n", split[1]);
// 	free_all(split, 3);
// 	free(test);
// 	return (0);
// }