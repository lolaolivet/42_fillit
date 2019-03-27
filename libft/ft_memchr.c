/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:41:03 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/17 16:33:16 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	s2;

	i = 0;
	s1 = (unsigned char *)s;
	s2 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == s2)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
