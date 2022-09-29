/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:22:26 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/23 18:34:47 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collision2(t_mlx *param, int *i, int a)
{
	if (param->map[param->case_y][param->case_x] == '1')
			*i += 80 * a;
	if (param->map[param->case_y][param->case_x] == 'C')
	{
		param->map[param->case_y][param->case_x] = '0';
		param->coin--;
	}
	return ;
}

void	ft_collision(t_mlx *param, int key)
{
	int	x;
	int	y;

	x = param->pos_x;
	y = param->pos_y;
	param->case_y = (y / 80);
	param->case_x = (x / 80);
	param->move++;
	if (key == UP)
		ft_collision2(param, &param->pos_y, 1);
	if (key == RIGHT)
		ft_collision2(param, &param->pos_x, -1);
	if (key == LEFT)
		ft_collision2(param, &param->pos_x, 1);
	if (key == DOWN)
	{
		ft_collision2(param, &param->pos_y, -1);
	}
	if (param->map[param->case_y][param->case_x] == 'E' && param->coin == 0)
		ft_quit(param);
}

void	ft_set_img(t_mlx *param)
{
	int	x;
	int	y;
	int	i;

	i = -1;
	param->img_font[0] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/fond.xpm", &x, &y);
	param->img_flor[0] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/flor.xpm", &x, &y);
	param->img_coin[0] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/coin.xpm", &x, &y);
	param->img_out[0] = mlx_xpm_file_to_image(param->mlx_ptr,
			"./so_long_src/chest.xpm", &x, &y);
	if (param->img_flor[0] == NULL || param->img_font[0] == NULL
		|| param->img_coin[0] == NULL || param->img_out[0] == NULL)
		ft_error(param);
	ft_set_i1(x, y, param);
	ft_set_i2(x, y, param);
	while (i < 17)
		if (param->img_char[++i] == NULL)
			ft_error(param);
}

char	*ft_non(char *s1)
{
	int	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		if (s1[i] == '\n')
			s1[i] = '\0';
		i++;
	}
	return (s1);
}

void	ft_set_map(t_mlx *param, char **argv)
{
	int	fd;
	int	y;
	int	x;

	y = 0;
	x = -1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || ft_strlen(argv[1]) <= 4
		|| ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
		ft_error(param);
	param->map[y] = ft_non(get_next_line(fd));
	if (param->map[y] == NULL)
		ft_error(param);
	while (param->map[y++] != NULL)
		param->map[y] = ft_non(get_next_line(fd));
	y = 0;
	while (param->map[0][++x] != '\0')
		if (param->map[0][x] != '1')
			ft_error(param);
	x--;
	ft_check_border(x, y, param);
	close(fd);
}
