/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:41:48 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/10 19:04:19 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_mandelbrot(double xo, double yo)
{
    int iter_num;
    double x;
    double y;
    double temp;

    iter_num = 0;
    x = 0;
    y = 0;

    while ((x*x + y*y) <= 4 && iter_num < 1000)
    {
        temp = x*x - y*y + xo;
        y = 2*x*y + yo;
        x = temp;
        iter_num++; 
    }
    return iter_num;
}

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
    int     j;

    double x_min;
    double y_min;
    double x_max;
    double y_max;

    i = 0;
    j = 0;
    x_min = -2;
    x_max = 0.6;
    y_min = -1.2;
    y_max = 1.2;

    double xo;
    double yo;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Fract-ol");
    
    while (i < 500)
    {
        j = 0;
        while (j < 500)
        {
            xo = x_min + (double)i* (x_max-x_min)/500; //width
            yo = y_min + (double)j* (y_max-y_min)/500; //height
            if (ft_mandelbrot(xo, yo) < 1000)
                mlx_pixel_put(mlx, mlx_win, i, j, 0xFFFFFF);
            j++;
        }
        i++;
    }

    /*

        while (i < 600)
    {
        j = 0;
        while (j < 600)
        {
            mlx_pixel_put(mlx, mlx_win, 200+i, 200+j, 0xFFFFFF);
            j++;
        }
        i++;
    }*/
        
    /* while (i < 60)
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
        mlx_pixel_put(mlx, mlx_win, 550+i, 550, 0xFF0000);
        mlx_pixel_put(mlx, mlx_win, 610, 550+i, 0xFFFFFF);
        mlx_pixel_put(mlx, mlx_win, 550, 550+i, 0xFFFFFF);
        i++;
	}*/


    mlx_loop(mlx);

    return (0);
}