/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:28:43 by mrigal            #+#    #+#             */
/*   Updated: 2018/01/10 10:24:02 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	pos_min(int *tab)
{
	int		i;
	int		min;
	int		tmp[4];

	i = 0;
	while (i < 4)
	{
		tmp[i] = tab[i];
		i++;
	}
	min = ft_sort_asc_tab(tmp);
	return (min);
}

static int	pos_max(int *tab)
{
	int		i;
	int		max;
	int		tmp[4];

	i = 0;
	while (i < 4)
	{
		tmp[i] = tab[i];
		i++;
	}
	max = ft_sort_desc_tab(tmp);
	return (max);
}

static int	pos_valid(t_grid *g, t_tetris *t, int x, int y)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (j < 4 && g->tab[t->x[j] + x + (y + t->y[j]) * (g->size + 1)] == '.')
	{
		j++;
		k++;
	}
	i = 0;
	if (k == 4)
	{
		j = -1;
		while (++j < 4)
			g->tab[t->x[j] + x + (y + t->y[j]) * (g->size + 1)] = t->letter;
		return (1);
	}
	return (0);
}

void		takeof_tetr(char *grid, char letter)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		if (grid[i] == letter)
			grid[i] = '.';
		i++;
	}
}

int			backtrack(t_tetris *t, t_grid *g, int x, int y)
{
	int		xmax;
	int		ymax;

	xmax = g->size - ((pos_max(t->x) - pos_min(t->x) + 1));
	ymax = g->size - ((pos_max(t->y) - pos_min(t->y) + 1));
	while (y <= ymax)
	{
		while (x <= xmax)
		{
			if (pos_valid(g, t, x, y))
			{
				if (t->next && (backtrack(t->next, g, 0, 0)))
					return (1);
				else if (!t->next)
					return (1);
				else
					takeof_tetr(g->tab, t->letter);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
