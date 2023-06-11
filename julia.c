/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:32:57 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 23:31:42 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	ft_mlx_init_julia(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	mlx.type = 2;
	mlx.x_min = -2;
	mlx.x_max = 2;
	mlx.y_min = -2;
	mlx.y_max = 2;
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

	i = -1;
	while (i++ < WIDTH)
	{
		j = -1;
		while (j++ < HEIGHT)
		{
			xo = mlx->x_min + (double)i * (mlx->x_max - mlx->x_min) / WIDTH;
			yo = mlx->y_min + (double)j * (mlx->y_max - mlx->y_min) / HEIGHT;
			iter = ft_julia(xo, yo, mlx);
			if (iter < 100)
				ft_mlx_pixel_put(&mlx->img, i, j, ft_color(iter, mlx->color));
			else
				ft_mlx_pixel_put(&mlx->img, i, j, 0);
		}
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
