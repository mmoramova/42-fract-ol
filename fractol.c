/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:41:48 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/12 20:33:45 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	t_mlx mlx2;

	mlx2 = *mlx;
	printf("Hello from key_hook!\n");
	printf("Key code is: %d\n", keycode);

	if (keycode == 53)//ESC
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	t_mlx mlx2;

	mlx2 = *mlx;
	printf("Hello from mouse_hook!\n");
	printf("Mouse key code is: %d\n", keycode);
	printf("Mouse axis are: %d and %d\n", x ,y);
	mlx_pixel_put(mlx->mlx , mlx->win, x, y, 0xFF0000);
	return (0);
}

int	ft_close(int keycode, t_mlx *mlx)
{
	t_mlx mlx2;

    mlx2 = *mlx;
    printf("Close key code is: %d\n", keycode);
    mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		return(0);
	mlx = ft_mlx_init();
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return(0);
	mlx.win = mlx_new_window(mlx.mlx , WIDTH, HEIGHT, argv[1]);
	if (mlx.win == NULL)
		return(0);
	mlx.img.mlx_img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.mlx_img, &mlx.img.bits_per_pixel, &mlx.img.line_len, &mlx.img.endian);
	ft_render_mandelbrot(&mlx);

    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.mlx_img, 0 ,0);
    mlx_key_hook(mlx.win, key_hook, &mlx);
    mlx_mouse_hook(mlx.win, mouse_hook, &mlx);

    //mlx_hook(mlx_win, 2, 1L<<0, ft_close, &mlx);

    mlx_loop(mlx.mlx);

    return (0);
}
