/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:42:37 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 23:06:10 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <limits.h>
# include <math.h>
# include "libft/libft.h"
# include "miniLibX/mlx.h"
# include <stdlib.h>

# define HEIGHT 500
# define WIDTH 500
# define MOVE 0.1
# define ZOOM 1.1
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define ZOOM_OUT 4
# define ZOOM_IN 5
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126
# define SHIFT 257

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		type;
	double	x_min;
	double	x_max;
	double	x_cntr;
	double	y_min;
	double	y_max;
	double	y_cntr;
	int		color;
}	t_mlx;

t_mlx	ft_mlx_init(int type, char **argv);
t_mlx	ft_mlx_init_mandelbrot(void);
t_mlx	ft_mlx_init_julia(void);
t_mlx	ft_mlx_init_burningship(void);
void	ft_render_mandelbrot(t_mlx *mlx);
void	ft_render_julia(t_mlx *mlx);
void	ft_render_burningship(t_mlx *mlx);
void	ft_mlx_render(t_mlx *mlx);
void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void	ft_move(t_mlx *mlx, int keycode);
void	ft_zoom(t_mlx *mlx, int keycode, double x, double y);
int		ft_find_type(int argc, char **argv);
int		ft_key_hook(int keycode, t_mlx *mlx);
int		ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx);
int		ft_color(int iter, int color_type);
int		ft_create_trgb(int r, int g, int b);
int		ft_mandelbrot(double x_cntr, double y_cntr);
int		ft_julia(double x, double y, t_mlx *mlx);
int		ft_burningship(double x_cntr, double y_cntr);
int		ft_close(t_mlx *mlx);

#endif
