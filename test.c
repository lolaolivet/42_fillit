/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 18:35:05 by mrigal            #+#    #+#             */
/*   Updated: 2018/01/10 10:24:54 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		check_char(char *str)
{
	int p;
	int h;
	int n;
	int i;

	p = 0;
	h = 0;
	n = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '.')
			p++;
		if (str[i] == '#')
			h++;
		if (str[i] == '\n')
			n++;
		i++;
	}
	if (p != 12 || h != 4 || n != 4)
		return (0);
	return (1);
}

int		check_forms(char *str, int i, int k)
{
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i == 0 && str[i] == '#')
				k++;
			if ((i > 0) && str[i - 1] == '#')
				k++;
			if ((i < 20) && str[i + 1] == '#')
				k++;
			if ((i < 16) && str[i + 5] == '#')
				k++;
			if ((i > 5) && str[i - 5] == '#')
				k++;
		}
		i++;
	}
	if (k >= 6 && k <= 8)
		return (1);
	return (0);
}

int		check_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] != '\n')
		{
			j++;
			i++;
		}
		if ((i < 20 && j != 4) || (i == 20 && j != 0) || (i > BUF_MAX))
			return (0);
		i++;
	}
	return (1);
}

void	check_letter(int k)
{
	if (k > 26)
		ft_exit();
}
