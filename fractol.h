/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:42:37 by mmoramov          #+#    #+#             */
/*   Updated: 2023/05/21 12:34:04 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <limits.h>
# include <math.h>
# include "libft/libft.h"
# include "miniLibX/mlx.h"

#define HEIGHT 500
#define WIDTH 500
#define MOVE 0.2
#define ZOOM 0.01

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
	double	x_min;
	double	x_max;
	double	x_center;
	double	y_min;
	double	y_max;
	double	y_center;
}	t_mlx;

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
t_mlx	ft_mlx_init(void);
void	ft_render_mandelbrot(t_mlx *mlx);
int		ft_mandelbrot(double x_center, double y_center);
int		ft_julia(double x, double y);

#endif
