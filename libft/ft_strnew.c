/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:48:19 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/24 13:51:55 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (!((s = ((char *)malloc(sizeof(char) * (size + 1))))))
		return (NULL);
	{
		ft_bzero(s, size + 1);
		return (s);
	}
	return (NULL);
}
