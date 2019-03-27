/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:25:53 by mrigal            #+#    #+#             */
/*   Updated: 2018/01/10 10:24:14 by lolivet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define BUF_SIZE	22
# define BUF_MAX	546

typedef struct		s_tetris
{
	struct s_tetris	*next;
	char			*tab;
	int				**coords;
	int				*x;
	int				*y;
	int				size;
	char			letter;
}					t_tetris;

typedef struct		s_grid
{
	char			*tab;
	int				size;
}					t_grid;

int					check_forms(char *str, int i, int k);
int					check_size(char *str);
int					check_char(char *str);
void				check_letter(int k);
int					backtrack(t_tetris *t, t_grid *g, int x, int y);
t_tetris			*place_first(t_tetris *t);

#endif
