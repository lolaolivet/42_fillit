/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placefirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:29:21 by mrigal            #+#    #+#             */
/*   Updated: 2018/01/10 10:52:15 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int		fill_coord(t_tetris *t)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(t->x = (int*)malloc(sizeof(int) * 4)) ||
			!(t->y = (int*)malloc(sizeof(int) * 4)))
		ft_exit();
	while (t->tab[i])
	{
		if (t->tab[i] == '#')
		{
			t->y[j] = i / 5;
			t->x[j] = (i % 5);
			j++;
		}
		i++;
	}
	return (0);
}

static char		**ft_set_left(char **s)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp = s[i][0];
		s[i][0] = s[i][1];
		s[i][1] = s[i][2];
		s[i][2] = s[i][3];
		s[i][3] = tmp;
		i++;
	}
	return (s);
}

static char		**ft_set_up(char **s)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < 4)
	{
		tmp = s[0][i];
		s[0][i] = s[1][i];
		s[1][i] = s[2][i];
		s[2][i] = s[3][i];
		s[3][i] = tmp;
		i++;
	}
	return (s);
}

static char		*ft_set_upleft(char *str)
{
	char	*p;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(str, '\n');
	ft_strclr(str);
	if (!(p = (char *)ft_memalloc(sizeof(char) * (21))))
		ft_exit();
	while (!(tmp[0][0] == '#' || tmp[0][1] == '#' || tmp[0][2] == '#' ||
				tmp[0][3] == '#'))
		tmp = ft_set_up(tmp);
	while (!(tmp[0][0] == '#' || tmp[1][0] == '#' || tmp[2][0] == '#' ||
				tmp[3][0] == '#'))
		tmp = ft_set_left(tmp);
	while (tmp[i])
	{
		ft_strcat(p, tmp[i]);
		ft_strcat(p, "\n");
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
	return (p);
}

t_tetris		*place_first(t_tetris *t)
{
	int		i;

	i = 0;
	t->tab = ft_set_upleft(t->tab);
	fill_coord(t);
	return (t);
}
