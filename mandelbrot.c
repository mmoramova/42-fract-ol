/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:30:44 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/21 12:19:51 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_mandelbrot(t_mlx *mlx)
{
	int	i;
	int	j;
	i = 0;
	j = 0;

	printf("x su %f a %f\n", mlx->x_min, mlx->x_max);
	printf("y su %f a %f\n", mlx->y_min, mlx->y_max);
	mlx->x_center = 0;
	mlx->y_center = 0;
	//mlx_clear_window(mlx->mlx, mlx->win);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx->x_center = mlx->x_min + (double)i* (mlx->x_max-mlx->x_min) / WIDTH;
			mlx->y_center = mlx->y_min + (double)j* (mlx->y_max-mlx->y_min) / HEIGHT;
			if (ft_mandelbrot(mlx->x_center, mlx->y_center) < 1000)
				ft_mlx_pixel_put(&mlx->img, i, j, 255);
			else
				ft_mlx_pixel_put(&mlx->img, i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.mlx_img, 0 ,0);
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

	while ((x*x + y*y) <= 4 && iter_num < 1000)
	{
		temp = x*x - y*y + x_center;
		y = 2*x*y + y_center;
		x = temp;
		iter_num++;
	}
	return (iter_num);
}
