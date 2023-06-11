/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:41:48 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 23:06:20 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img.mlx_img)
		mlx_destroy_image(mlx->mlx, mlx->img.mlx_img);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		type;

	type = ft_find_type(argc, argv);
	if (type == 0)
		return (0);
	mlx = ft_mlx_init(type, argv);
	if (mlx.mlx == NULL || mlx.win == NULL)
		return (0);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
