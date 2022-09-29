/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:34:59 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/23 18:37:26 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdio.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define KEY_PRESS 2
# define KEY_RELEASE 3

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*map[2000];
	char	*map2[2000];
	int		x_map;
	int		y_map;
	int		pos_x;
	int		pos_y;
	int		key_down;
	int		key_up;
	int		key_left;
	int		key_right;
	int		case_x;
	int		case_y;
	int		taille;
	t_img	*img_font[1];
	t_img	*img_char[18];
	t_img	*img_flor[1];
	t_img	*img_coin[1];
	t_img	*img_out[1];
	int		i;
	int		coin;
	int		exit;
	int		player;
	int		move;
}	t_mlx;

void	ft_init_char2(t_mlx *param, int a, int b);
void	ft_draw2(int a, int b, t_mlx *param);
char	*ft_non(char	*str);
void	ft_error(t_mlx *param);
int		ft_mouvement_p(int key, t_mlx *param);
int		ft_draw_map(t_mlx *param);
void	ft_progress1(t_mlx *param, int y, int x);
void	ft_progress2(t_mlx *param, int y, int x);
int		ft_quit(t_mlx *param);
void	ft_check_it(t_mlx *param, int x, int b, int a);
void	ft_init_char(t_mlx *param);
void	ft_collision(t_mlx *param, int key);
void	ft_set_map(t_mlx *param, char **argv);
void	ft_set_img(t_mlx *param);
void	ft_solong(t_mlx *param, char **argv);
void	ft_set_i1(int x, int y, t_mlx *param);
void	ft_set_i2(int x, int y, t_mlx *param);
void	ft_check_border(int x, int y, t_mlx *param);

#endif
