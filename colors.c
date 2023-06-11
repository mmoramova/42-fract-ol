/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:59:30 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/11 12:21:50 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int iter, int color_type)
{
	if (color_type == 1)
		return (ft_create_trgb(iter * 5, 100, 100 + iter * 5));
	else if (color_type == 2)
		return (ft_create_trgb(240, 100 + iter * 10, 100 + iter * 10));
	else
		return (ft_create_trgb(100 + iter * 5, 100, 100 + iter * 5));
}

int	ft_create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
