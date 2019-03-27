/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:22:11 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/21 10:12:34 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *i;
	const char *j;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = haystack;
		j = needle;
		while (*i && *i == *j)
		{
			i++;
			j++;
		}
		if (!*j)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
