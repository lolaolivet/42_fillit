/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:45:57 by mrigal            #+#    #+#             */
/*   Updated: 2018/01/10 10:24:30 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int		fillit_checker(char *buf)
{
	if (check_size(buf) == 1 && check_forms(buf, 0, 0) == 1 &&
			check_char(buf) == 1)
		return (1);
	else
		ft_putstr("error\n");
	return (0);
}

static void		open_file(int fd, t_tetris **tmp1, int tmp, char symbol)
{
	int			rd;
	char		buf[BUF_SIZE];
	t_tetris	**cur;
	t_tetris	*new;

	cur = tmp1;
	ft_bzero(buf, BUF_SIZE);
	while ((rd = read(fd, buf, 21)) != 0)
	{
		if (!(new = (t_tetris *)malloc(sizeof(t_tetris))) ||
				!(new->tab = (char *)malloc(sizeof(char) * (21))) ||
				fillit_checker(buf) == 0 || symbol == 98)
			exit(-1);
		new->tab = buf;
		place_first(new);
		new->letter = symbol;
		symbol++;
		ft_bzero(buf, BUF_SIZE);
		tmp = rd;
		new->next = NULL;
		*cur = new;
		cur = &(new->next);
	}
	if (tmp != 20)
		ft_exit();
}

static char		*init_grid(int size)
{
	char	*grid;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	if (!(grid = ft_memalloc((size + 1) * (size + 1) + 1)))
		exit(-1);
	while (y < size)
	{
		while (x < size)
		{
			grid[i] = '.';
			i++;
			x++;
		}
		grid[i++] = '\n';
		x = 0;
		y++;
	}
	return (grid);
}

static void		ft_solve(t_tetris *tmp, t_tetris *i, t_grid *grid, char **argv)
{
	int		fd;
	int		k;

	fd = 0;
	k = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_exit();
	open_file(fd, &tmp, 0, 65);
	i = tmp;
	while (i)
	{
		i = i->next;
		k++;
	}
	check_letter(k);
	grid->size = ft_sqrt_round(k);
	grid->tab = init_grid(grid->size);
	while (!backtrack(tmp, grid, 0, 0))
	{
		grid->size++;
		ft_strdel(&grid->tab);
		grid->tab = init_grid(grid->size);
	}
	ft_putstr(grid->tab);
	close(fd);
}

int				main(int argc, char **argv)
{
	t_tetris	tmp;
	t_grid		grid;
	t_tetris	i;

	ft_bzero(&tmp, sizeof(tmp));
	ft_bzero(&i, sizeof(i));
	ft_bzero(&grid, sizeof(grid));
	if (argc == 2)
		ft_solve(&tmp, &i, &grid, argv);
	else
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}
