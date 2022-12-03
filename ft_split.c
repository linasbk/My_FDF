/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:07:20 by lsabik            #+#    #+#             */
/*   Updated: 2022/11/25 15:07:22 by lsabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	get_num_word(char *s, char sep)
{
	int	count;
	int	i;
	int	new_word;

	count = 0;
	new_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == sep)
			new_word = 1;
		if (s[i] != sep && s[i] != '\n' && new_word)
		{
				count++;
				new_word = 0;
		}
		i++;
	}
	return (count);
}

char	*word_dup(char *s, char c, int *lenght)
{
	int		i;
	int		k;
	char	*word;

	i = *lenght;
	while (s[i] == c)
		i++;
	k = i;
	while (s[i] != c)
		i++;
	word = ft_substr(s, k, i - k);
	*lenght = i;
	return (word);
}

char	**ft_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		lenght;
	int		full_len;

	i = 0;
	lenght = 0;
	if (!s)
		return (NULL);
	full_len = get_num_word((char *)s, c);
	str = malloc(sizeof(char *) * (full_len + 1));
	if (!str)
		return (NULL);
	while (i < full_len)
	{
		str[i] = word_dup((char *)s, c, &lenght);
		if (!str[i])
			return (ft_free(str, i));
		i++;
	}
	str[i] = 0;
	return (str);
}
