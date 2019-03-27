/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:01:26 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/17 16:38:27 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len_dest;

	i = 0;
	len_dest = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[len_dest + i] = s2[i];
		i++;
	}
	s1[len_dest + i] = '\0';
	return (s1);
}
