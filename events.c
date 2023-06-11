/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:05:46 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 23:18:16 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move(t_mlx *mlx, int keycode)
{
	double	x_len;
	double	y_len;

	x_len = mlx->x_max - mlx->x_min;
	y_len = mlx->y_max - mlx->y_min;
	if (keycode == ARROW_LEFT)
	{
		mlx->x_min -= x_len * MOVE;
		mlx->x_max -= x_len * MOVE;
	}
	if (keycode == ARROW_RIGHT)
	{
		mlx->x_min += x_len * MOVE;
		mlx->x_max += x_len * MOVE;
	}
	if (keycode == ARROW_DOWN)
	{
		mlx->y_min += y_len * MOVE;
		mlx->y_max += y_len * MOVE;
	}
	if (keycode == ARROW_UP)
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
	if (keycode == ZOOM_IN)
	{
		mlx->x_min -= ((x_len / ZOOM) - x_len) * x;
		mlx->x_max += ((x_len / ZOOM) - x_len) * (1 - x);
		mlx->y_min -= ((y_len / ZOOM) - y_len) * y;
		mlx->y_max += ((y_len / ZOOM) - y_len) * (1 - y);
	}
	if (keycode == ZOOM_OUT)
	{
		mlx->x_min -= ((x_len * ZOOM) - x_len) * x;
		mlx->x_max += ((x_len * ZOOM) - x_len) * (1 - x);
		mlx->y_min -= ((y_len * ZOOM) - y_len) * y;
		mlx->y_max += ((y_len * ZOOM) - y_len) * (1 - y);
	}
}

int	ft_key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		ft_close(mlx);
	else if (keycode >= ARROW_LEFT && keycode <= ARROW_UP)
		ft_move(mlx, keycode);
	else if (keycode == SHIFT)
	{
		if (mlx -> color++ > 3)
			mlx -> color = 1;
	}
	else
		return (1);
	ft_mlx_render(mlx);
	return (0);
}

/*For julia: x = <-3, 3>; y = <-3, 3> -> len = 6 */
int	ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if (mlx -> type == 2 && keycode == LEFT_CLICK)
	{
		mlx->x_cntr = -3 + 6 * (double)x / WIDTH;
		mlx->y_cntr = -3 + 6 * (double)y / HEIGHT;
	}
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT)
		ft_zoom(mlx, keycode, (double)x / WIDTH, (double)y / HEIGHT);
	else
		return (1);
	ft_mlx_render(mlx);
	return (0);
}
