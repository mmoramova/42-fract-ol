/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:32:57 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/08 19:55:19 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	ft_mlx_init_julia(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	mlx.type = 2;
	mlx.x_min = -2.2;
	mlx.x_max = 2.2;
	mlx.y_min = -2.2;
	mlx.y_max = 2.2;
	mlx.x_cntr = -0.9;
	mlx.y_cntr = 0.0290;
	return (mlx);
}

void	ft_render_julia(t_mlx *mlx)
{
	int		i;
	int		j;
	double	xo;
	double	yo;
	int		iter;

	i = 0;
	j = 0;
	xo = 0;
	yo = 0;

	printf("x su %f a %f\n", mlx->x_min, mlx->x_max);
	printf("y su %f a %f\n", mlx->y_min, mlx->y_max);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			xo = mlx->x_min + (double)i * (mlx->x_max-mlx->x_min) / WIDTH;
			yo = mlx->y_min + (double)j * (mlx->y_max-mlx->y_min) / HEIGHT;
			iter = ft_julia(xo, yo, mlx);
			if (iter < 100)
				ft_mlx_pixel_put(&mlx->img, i, j, ft_color(iter, mlx->color));
			else
				ft_mlx_pixel_put(&mlx->img, i, j, 0);
			j++;
		}
		i++;
	}
}

int	ft_julia(double x, double y, t_mlx *mlx)
{
	int		iter_num;
	double	temp;

	iter_num = 0;

	while ((x * x + y * y) <= 4 && iter_num < 100)
	{
		temp = x * x - y * y + mlx->x_cntr;
		y = 2 * x * y + mlx->y_cntr;
		x = temp;
		iter_num++;
	}
	return (iter_num);
}
