/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:13:07 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/23 18:22:02 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_mlx *param)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	write(1, "Error\n", 6);
	while (param->map[++i] != NULL)
		free(param->map[i]);
	while (param->map[++j] != NULL)
		free(param->map2[j]);
	exit (1);
}

int	ft_quit(t_mlx *param)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (param->map[++i] != NULL)
		free(param->map[i]);
	while (param->map[++j] != NULL)
		free(param->map2[j]);
	exit(0);
	return (0);
}

void	ft_progress1(t_mlx *param, int y, int x)
{
	if (param->map2[y][x + 1] == '0' || param->map2[y][x + 1] == 'C' )
	{
		param->map2[y][x + 1] = 'A';
		ft_progress1(param, y, x + 1);
	}
	if (param->map2[y][x - 1] == '0' || param->map2[y][x - 1] == 'C')
	{
		param->map2[y][x - 1] = 'A';
		ft_progress1(param, y, x - 1);
	}
	if (param->map2[y - 1][x] == '0' || param->map2[y - 1][x] == 'C')
	{
		param->map2[y - 1][x] = 'A';
		ft_progress1(param, y - 1, x);
	}
	if (param->map2[y + 1][x] == '0' || param->map2[y + 1][x] == 'C')
	{
		param->map2[y + 1][x] = 'A';
		ft_progress1(param, y + 1, x);
	}	
}

void	ft_progress2(t_mlx *param, int y, int x)
{
	if (param->map2[y][x + 1] == 'A' || param->map2[y][x + 1] == 'E')
	{
		param->map2[y][x + 1] = '0';
		ft_progress2(param, y, x + 1);
	}
	if (param->map2[y][x - 1] == 'A' || param->map2[y][x - 1] == 'E')
	{
		param->map2[y][x - 1] = '0';
		ft_progress2(param, y, x - 1);
	}
	if (param->map2[y - 1][x] == 'A' || param->map2[y - 1][x] == 'E')
	{
		param->map2[y - 1][x] = '0';
		ft_progress2(param, y - 1, x);
	}
	if (param->map2[y + 1][x] == 'A' || param->map2[y + 1][x] == 'E')
	{
		param->map2[y + 1][x] = '0';
		ft_progress2(param, y + 1, x);
	}	
}

void	ft_check_it(t_mlx *param, int x, int b, int a)
{
	a = param->pos_y;
	b = param->pos_x;
	x = 0;
	if (param->player != 1 || param->coin < 1 || param->exit != 1)
		ft_error(param);
	while (param->map2[++x] != NULL)
		if (ft_strlen(param->map2[0]) - ft_strlen(param->map2[x]) != 0)
			ft_error(param);
	if (param->map2[param->pos_y][param->pos_x] == 'P')
		param->map2[param->pos_y][param->pos_x] = 'A';
	ft_progress1(param, a, b);
	ft_progress2(param, a, b);
	a = -1;
	b = -1;
	while (param->map2[++a] != NULL)
	{
		while (param->map2[a][++b] != '\0')
			if (param->map2[a][b] == 'C' || param->map2[a][b] == 'E' )
				ft_error(param);
		b = -1;
	}
	return ;
}
