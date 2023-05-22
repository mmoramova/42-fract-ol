/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:30:44 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/22 17:06:52 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx ft_mlx_init_mandelbrot(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	//mlx.img = NULL;
	mlx.type = 1;
	mlx.x_min = -2;
	mlx.x_max = 0.6;
	mlx.y_min = -1.2;
	mlx.y_max = 1.2;
	return (mlx);
}

void	ft_render_mandelbrot(t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;
	i = 0;
	j = 0;

	printf("x su %f a %f\n", mlx->x_min, mlx->x_max);
	printf("y su %f a %f\n", mlx->y_min, mlx->y_max);
	//mlx_clear_window(mlx->mlx, mlx->win);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx->x_center = mlx->x_min + (double)i* (mlx->x_max-mlx->x_min) / WIDTH;
			mlx->y_center = mlx->y_min + (double)j* (mlx->y_max-mlx->y_min) / HEIGHT;
			iter = ft_mandelbrot(mlx->x_center, mlx->y_center);
			if (iter < 100)
				ft_mlx_pixel_put(&mlx->img, i, j, ft_color(iter));
			else
				ft_mlx_pixel_put(&mlx->img, i, j, 0);
			j++;
		}
		i++;
	}
}

int	ft_mandelbrot(double x_center, double y_center)
{
	int		iter_num;
	double	x;
	double	y;
	double	temp;

	iter_num = 0;
	x = 0;
	y = 0;

	while ((x*x + y*y) <= 4 && iter_num < 100)
	{
		temp = x*x - y*y + x_center;
		y = 2*x*y + y_center;
		x = temp;
		iter_num++;
	}
	return (iter_num);
}
