/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:25:25 by mrigal            #+#    #+#             */
/*   Updated: 2017/11/21 15:40:28 by mrigal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_len(int n)
{
	unsigned int len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_new_str(int len, int n, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	neg;

	len = ft_find_len(n);
	neg = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	if (n < 0)
		n = n * -1;
	return (ft_new_str(len, n, neg, str));
}
