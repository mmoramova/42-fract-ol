/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:05:46 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 12:22:48 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_mlx *mlx, int keycode)
{
	double	x_len;
	double	y_len;

	x_len = mlx->x_max - mlx->x_min;
	y_len = mlx->y_max - mlx->y_min;
	if (keycode == 123)
	{
		mlx->x_min -= x_len * MOVE;
		mlx->x_max -= x_len * MOVE;
	}
	if (keycode == 124)
	{
		mlx->x_min += x_len * MOVE;
		mlx->x_max += x_len * MOVE;
	}
	if (keycode == 125)
	{
		mlx->y_min += y_len * MOVE;
		mlx->y_max += y_len * MOVE;
	}
	if (keycode == 126)
	{
		mlx->y_min -= y_len * MOVE;
		mlx->y_max -= y_len * MOVE;
	}
}

void	ft_zoom(t_mlx *mlx, int keycode, double x, double y)
{
	double	x_len;
	double	y_len;

	x_len = mlx->x_max - mlx->x_min;
	y_len = mlx->y_max - mlx->y_min;
	if (keycode == 5)
	{
		mlx->x_min -= ((x_len / ZOOM) - x_len) * x;
		mlx->x_max += ((x_len / ZOOM) - x_len) * (1 - x);
		mlx->y_min -= ((y_len / ZOOM) - y_len) * y;
		mlx->y_max += ((y_len / ZOOM) - y_len) * (1 - y);
	}
	if (keycode == 4)
	{
		mlx->x_min -= ((x_len * ZOOM) - x_len) * x;
		mlx->x_max += ((x_len * ZOOM) - x_len) * (1 - x);
		mlx->y_min -= ((y_len * ZOOM) - y_len) * y;
		mlx->y_max += ((y_len * ZOOM) - y_len) * (1 - y);
	}
	ft_mlx_render(mlx);
}

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		ft_close(mlx);
	}
	if (keycode >= 123 && keycode <= 126)
	{
		ft_move(mlx, keycode);
		ft_mlx_render(mlx);
	}
	if (keycode == 257)
	{
		mlx->color += 1;
		if (mlx -> color > 3)
			mlx -> color = 1;
		ft_mlx_render(mlx);
	}
	return (0);
}

int	ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if (mlx -> type == 2 && keycode == 1)
	{
		mlx->x_cntr = -3 + 6 * (double) x / WIDTH;
		mlx->y_cntr = -3 + 6 * (double) y / HEIGHT;
		ft_mlx_render(mlx);
	}
	if (keycode == 4 || keycode == 5)
	{
		ft_zoom(mlx, keycode, (double) x / WIDTH, (double)y / HEIGHT);
	}
	return (0);
}
