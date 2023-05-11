/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:41:48 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/11 16:47:38 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	t_vars vars2;

    vars2 = *vars;
    printf("Hello from key_hook!\n");
    printf("Key code is: %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	t_vars vars2;

    vars2 = *vars;
    printf("Hello from mouse_hook!\n");
    printf("Mouse key code is: %d\n", keycode);
    printf("Mouse axis are: %d and %d\n", x ,y);
    mlx_pixel_put(vars->mlx , vars->win, x, y, 0xFF0000);
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	t_vars vars2;

    vars2 = *vars;
    printf("Close key code is: %d\n", keycode);
    mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

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

    t_vars vars;

    //void	*mlx;
	//void	*mlx_win;
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

	//mlx = mlx_init();
    vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx , 500, 500, "Fract-ol");

    while (i < 500)
    {
        j = 0;
        while (j < 500)
        {
            xo = x_min + (double)i* (x_max-x_min)/500; //width
            yo = y_min + (double)j* (y_max-y_min)/500; //height
            if (ft_mandelbrot(xo, yo) < 1000)
                mlx_pixel_put(vars.mlx , vars.win, i, j, 0xFFFFFF);
            j++;
        }
        i++;
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

    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_mouse_hook(vars.win, mouse_hook, &vars);
    //mlx_hook(mlx_win, 2, 1L<<0, ft_close, &vars);
    mlx_loop(vars.mlx);

    return (0);
}
