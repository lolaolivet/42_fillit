/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:27:49 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/27 12:58:21 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	if (str[i] == '\n')
		i--;
	j = 0;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		--i;
		++j;
	}
	return (str);
}
