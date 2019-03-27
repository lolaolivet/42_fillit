/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:28:44 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/24 15:28:41 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char c)
{
	int count;
	int word;

	count = 0;
	word = 0;
	while (str[count])
	{
		if (str[count] != c)
		{
			word++;
			while (str[count] && str[count] != c)
				count++;
		}
		count++;
	}
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !c)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (ft_count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			tab[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	tab[j] = 0;
	return (tab);
}
