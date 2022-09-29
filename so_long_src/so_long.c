/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaraton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:49:27 by ebaraton          #+#    #+#             */
/*   Updated: 2022/09/23 18:12:44 by ebaraton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_solong(t_mlx *param, char **argv)
{
	ft_set_img(param);
	ft_set_map(param, argv);
	ft_init_char(param);
	param->pos_x /= 80;
	param->pos_y /= 80;
	ft_check_it(param, 0, 0, 0);
	param->pos_y *= 80;
	param->pos_x *= 80;
}

int	ft_draw_map(t_mlx *p)
{
	int		a;
	int		b;
	char	*move;

	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_font[0], 0, 0);
	a = -1;
	b = -1;
	p->x_map = 0;
	p->y_map = 0;
	ft_draw2(a, b, p);
	move = ft_itoa(p->move);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 10, 10, 0x000100, move);
	free(move);
	return (0);
}

int	ft_mouvement_p(int key, t_mlx *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		ft_quit(param);
	}
	if (key == UP || key == LEFT || key == RIGHT || key == DOWN)
	{
		param->i ++;
		if (param->i == 17)
			(param->i = 0);
	}
	if (key == UP)
		param->pos_y -= 80;
	if (key == DOWN)
		param->pos_y += 80;
	if (key == LEFT)
		param->pos_x -= 80;
	if (key == RIGHT)
		param->pos_x += 80;
	ft_collision(param, key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	*all;

	(void) argc;
	all = malloc(sizeof(*all));
	if (all == NULL)
		ft_error(all);
	all->key_up = 0;
	all->key_left = 0;
	all->key_right = 0;
	all->key_down = 0;
	all->i = 0;
	all->player = 0;
	all->exit = 0;
	all->coin = 0;
	all->move = 0;
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "mlx 42");
	ft_solong(all, argv);
	mlx_hook(all->win_ptr, KEY_PRESS, 0, ft_mouvement_p, all);
	mlx_hook(all->win_ptr, 17, 0, ft_quit, all);
	mlx_loop_hook(all->mlx_ptr, ft_draw_map, all);
	mlx_loop(all->mlx_ptr);
	return (0);
}
