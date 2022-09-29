/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:21:10 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/26 12:21:13 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_border(int x, int y, t_mlx *param)
{
	int	tmp;

	tmp = x;
	while (param->map[++y] != NULL)
		if (param->map[y][0] != '1')
			ft_error(param);
	y--;
	while (x != 0)
	{
		if (param->map[y][x] != '1')
			ft_error(param);
		x--;
	}
	while (y != 0)
	{
		if (param->map[y][tmp] != '1')
			ft_error(param);
		y--;
	}
	return ;
}
