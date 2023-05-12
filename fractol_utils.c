/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:46:45 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/12 20:36:11 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img-> bits_per_pixel / 8));
	*(int *)pixel = color;
}

t_mlx ft_mlx_init(void)
{
	t_mlx	mlx;

	mlx.mlx = NULL;
	mlx.win = NULL;
	//mlx.img = NULL;
	mlx.x_min = -2;
	mlx.x_max = 0.6;
	mlx.y_min = -1.2;
	mlx.y_max = 1.2;
	return(mlx);
}
