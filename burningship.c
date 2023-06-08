/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:46:03 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/08 20:05:48 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	ft_mlx_init_burningship(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	mlx.type = 3;
	mlx.x_min = -2;
	mlx.x_max = 0.6;
	mlx.y_min = -1.2;
	mlx.y_max = 1.2;
	return (mlx);
}

void	ft_render_burningship(t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;

	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx->x_cntr = mlx->x_min + (double)i * (mlx->x_max - mlx->x_min) / WIDTH;
			mlx->y_cntr = mlx->y_min + (double)j * (mlx->y_max - mlx->y_min) / HEIGHT;
			iter = ft_burningship(mlx->x_cntr, mlx->y_cntr);
			if (iter < 100)
				ft_mlx_pixel_put(&mlx->img, i, j, ft_color(iter, mlx->color));
			else
				ft_mlx_pixel_put(&mlx->img, i, j, 0);
			j++;
		}
		i++;
	}
}

int	ft_burningship(double x_cntr, double y_cntr)
{
	int		iter_num;
	double	x;
	double	y;
	double	temp;

	iter_num = 0;
	x = 0;
	y = 0;
	while ((x * x + y * y) <= 4 && iter_num < 100)
	{
		temp = x * x - y * y + x_cntr;
		y = fabs(2 * x * y) + y_cntr;
		x = temp;
		iter_num++;
	}
	return (iter_num);
}
