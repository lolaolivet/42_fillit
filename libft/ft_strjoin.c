/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:08:55 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/24 16:27:20 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	char *start;

	if (s1 && s2)
	{
		if (!(result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		start = result;
		while (*s1)
			*(result++) = *(s1++);
		while (*s2)
			*(result++) = *(s2++);
		*result = '\0';
		return (start);
	}
	return (0);
}
