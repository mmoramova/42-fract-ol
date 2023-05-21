/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:30:44 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/21 09:34:48 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_mandelbrot(t_mlx *mlx)
{
	int	i;
	int	j;
	i = 0;
	j = 0;

	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			x_center = mlx->x_min + (double)i* (mlx->x_max-mlx->x_min) / WIDTH;
			y_center = mlx->y_min + (double)j* (mlx->y_max-mlx->y_min) / HEIGHT;
			if (ft_mandelbrot(x_center, y_center) < 1000)
				ft_mlx_pixel_put(&mlx->img, i, j, 255);
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

	while ((x*x + y*y) <= 4 && iter_num < 1000)
	{
		temp = x*x - y*y + x_center;
		y = 2*x*y + y_center;
		x = temp;
		iter_num++;
	}
	return (iter_num);
}
