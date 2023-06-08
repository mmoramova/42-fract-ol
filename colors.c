/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoramov <mmoramov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:59:30 by mmoramov          #+#    #+#             */
/*   Updated: 2023/06/08 19:43:03 by mmoramov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int iter, int clr)
{
	int	colorrange[4];

	if (clr == 1)
	{
		colorrange[0] = 16054772;
		colorrange[1] = 10999749;
		colorrange[2] = 7648411;
		colorrange[3] = 6065545;
	}
	else if (clr == 2)
	{
		colorrange[0] = 12930178;
		colorrange[1] = 15495836;
		colorrange[2] = 12930178;
		colorrange[3] = 15495836;
	}
	else if (clr == 3)
	{
		colorrange[0] = 12930178;
		colorrange[1] = 15495836;
		colorrange[2] = 16035514;
		colorrange[3] = 16645579;
	}
	return (colorrange[iter % 4]);
}
