/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:46:45 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/08 20:05:39 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mlx_render(t_mlx *mlx)
{
	if (mlx->type == 1)
		ft_render_mandelbrot(mlx);
	else if (mlx->type == 2)
		ft_render_julia(mlx);
	else
		ft_render_burningship(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.mlx_img, 0, 0);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img-> bits_per_pixel / 8));
	*(int *)pixel = color;
}

t_mlx	ft_mlx_init(int type, char **argv)
{
	t_mlx	mlx;

	if (type == 1)
		mlx = ft_mlx_init_mandelbrot();
	else if (type == 2)
		mlx = ft_mlx_init_julia();
	else
		mlx = ft_mlx_init_burningship();
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, argv[1]);
	mlx.color = 1;
	mlx.img.mlx_img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.mlx_img, &mlx.img.bits_per_pixel, &mlx.img.line_len, &mlx.img.endian);
	ft_mlx_render(&mlx);
	return (mlx);
}

int	ft_find_type(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Please type name of one of the following:", 1);
		ft_putstr_fd("1./ mandelbrot\n2. julia\n3. burningship", 1);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && ft_strlen(argv[1]) == 10)
		return (1);
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && ft_strlen(argv[1]) == 5)
		return (2);
	else if (ft_strncmp(argv[1], "burningship", 11) == 0 && ft_strlen(argv[1]) == 11)
		return (3);
	else
	{
		ft_putstr_fd("Please type name of one of the following:", 1);
		ft_putstr_fd("1./ mandelbrot\n2. julia\n3. burningship", 1);
	}
	return (0);
}
