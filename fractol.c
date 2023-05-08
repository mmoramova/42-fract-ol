/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:41:48 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/08 14:42:20 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_test(char *str)
{
    int i;
    
    i = 0;
    if (str)
        i++;
}


int	main(int argc, char **argv)
{
	if (argc > 0)
        ft_test(argv[2]);

    void	*mlx;
	void	*mlx_win;
    int     i;

    i = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Fract-ol");
    while (i < 60)
    {
        mlx_pixel_put(mlx, mlx_win, 250-i, 250, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 250+i, 250, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 250, 250-i, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 250, 250+i, 0xFFFFFF);
        i++;
	}
    i = 0;
    while (i < 60)
    {
        mlx_pixel_put(mlx, mlx_win, 550+i, 610, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 550+i, 550, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 610, 550+i, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 550, 550+i, 0xFFFFFF);
        i++;
	}
    mlx_loop(mlx);

    return (0);
}