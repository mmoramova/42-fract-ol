/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:05:46 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/08 20:17:35 by mmoramov         ###   ########.fr       */
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
	ft_mlx_render(mlx);
}

void	ft_zoom(t_mlx *mlx, int keycode)
{
	double	x_len;
	double	y_len;

	//x_len = mlx->x_max - mlx->x_min;
	//y_len = mlx->y_max - mlx->y_min;

	x_len = mlx->x_max - mlx->x_min;
	y_len = mlx->y_max - mlx->y_min;
	if (keycode == 4)
	{
		mlx->x_min -= ((x_len * ZOOM) - x_len) / 2;
		mlx->x_max += ((x_len * ZOOM) - x_len) / 2;
		mlx->y_min -= ((y_len * ZOOM) - y_len) / 2;
		mlx->y_max += ((y_len * ZOOM) - y_len) / 2;

		//mlx->x_min -= ((x_len * ZOOM) - x_len) / 2;
		//mlx->x_max += ((x_len * ZOOM) - x_len) / 2;
		//mlx->y_min -= ((y_len * ZOOM) - y_len) / 2;
		//mlx->y_max += ((y_len * ZOOM) - y_len) / 2;
	}
	if (keycode == 5)
	{
		mlx->x_min -= ((x_len / ZOOM) - x_len) / 2;
		mlx->x_max += ((x_len / ZOOM) - x_len) / 2;
		mlx->y_min -= ((y_len / ZOOM) - y_len) / 2;
		mlx->y_max += ((y_len / ZOOM) - y_len) / 2;
	}
	ft_mlx_render(mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	printf("Hello from key_hook!\n");
	printf("Key code is: %d\n", keycode);
	if (keycode == 53)
	{
		ft_close(mlx);
	}
	if (keycode >= 123 && keycode <= 126)
		ft_move(mlx, keycode);
	if (keycode == 257)
	{
		mlx->color += 1;
		if (mlx -> color > 3)
			mlx -> color = 1;
		printf("Color is %d", mlx -> color);
		ft_mlx_render(mlx);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	printf("Hello from mouse_hook!\n");
	printf("Mouse key code is: %d\n", keycode);
	printf("Mouse axis are: %d and %d\n", x ,y);

	if (mlx -> type == 2)
	{
		//mlx->x_cntr = x; TODO
		//mlx->y_cntr = y;
		ft_mlx_render(mlx);
	}
	if (keycode == 4 || keycode == 5)
		ft_zoom(mlx, keycode);
	return (0);
}
