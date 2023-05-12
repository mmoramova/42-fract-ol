/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:32:57 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/12 20:36:05 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_julia(double x, double y)
{
    int iter_num;
    double temp;

    iter_num = 0;


    while ((x*x + y*y) <= 4 && iter_num < 1000)
    {
        temp = x*x - y*y - 0.7;
        y = 2*x*y + 0.028015;
        x = temp;
        iter_num++;
    }
    return iter_num;
}

/*
    x_min = -3.5;
    x_max = 1.5;
    y_min = -2.2;
    y_max = 2.2;

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
            if (ft_julia(xo, yo) < 1000)
                mlx_pixel_put(mlx, mlx_win, i, j, 0xFFFFFF);
            j++;
        }
        i++;
    }*/
