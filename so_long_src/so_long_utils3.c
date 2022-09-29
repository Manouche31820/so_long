/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:20:58 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/26 12:21:02 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw2(int a, int b, t_mlx *p)
{
	while (p->map[++a] != NULL)
	{
		while (p->map[a][++b] != '\0')
		{
			if (p->map[a][b] == '1')
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_flor[0],
					p->x_map, p->y_map);
			else if (p->map[a][b] == 'C')
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_coin[0],
					p->x_map, p->y_map);
			else if (p->map[a][b] == 'E')
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr,
					p->img_out[0], p->x_map, p->y_map);
			else if (p->map[a][b] == 'P')
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr,
					p->img_char[p->i], p->pos_x, p->pos_y);
			else if (p->map[a][b] != '0')
				ft_error(p);
			p->x_map += 80;
		}
		b = -1;
		p->y_map += 80;
		p->x_map = 0;
	}
	return ;
}

void	ft_init_char2(t_mlx *param, int a, int b)
{
	while (param->map[++a] != NULL)
	{
		while (param->map[a][++b] != '\0')
		{
			if (param->map[a][b] == 'P')
			{
				param->player++;
				param->pos_x = b * 80;
				param->pos_y = a * 80;
			}
			else if (param->map[a][b] == 'C')
				param->coin++;
			else if (param->map[a][b] == 'E' && param->exit++)
				if (param->exit >= 2)
					ft_error(param);
		}
		b = -1;
	}
}

void	ft_set_i1(int x, int y, t_mlx *param)
{
	param->img_char[0] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/1.xpm", &x, &y);
	param->img_char[1] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/2.xpm", &x, &y);
	param->img_char[2] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/3.xpm", &x, &y);
	param->img_char[3] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/4.xpm", &x, &y);
	param->img_char[4] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/5.xpm", &x, &y);
	param->img_char[5] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/6.xpm", &x, &y);
	param->img_char[6] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/7.xpm", &x, &y);
	param->img_char[7] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/8.xpm", &x, &y);
	param->img_char[8] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/9.xpm", &x, &y);
	param->img_char[9] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/10.xpm", &x, &y);
}

void	ft_set_i2(int x, int y, t_mlx *param)
{
	param->img_char[10] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/11.xpm", &x, &y);
	param->img_char[11] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/12.xpm", &x, &y);
	param->img_char[12] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/13.xpm", &x, &y);
	param->img_char[13] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/14.xpm", &x, &y);
	param->img_char[14] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/15.xpm", &x, &y);
	param->img_char[15] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/16.xpm", &x, &y);
	param->img_char[16] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/17.xpm", &x, &y);
	param->img_char[17] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/char/18.xpm", &x, &y);
}

void	ft_init_char(t_mlx *param)
{
	int	a;
	int	b;

	a = -1;
	b = -1;
	ft_init_char2(param, a, b);
	if (param->coin == 0)
		ft_error(param);
	a = -1;
	while (param->map[++a] != NULL)
		param->map2[a] = ft_strdup(param->map[a]);
	param->map2[a] = NULL;
}
