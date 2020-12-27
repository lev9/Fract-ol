/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	beach_color(double n)
{
	int	r;
	int	g;
	int	b;

	r = 70.0 - (2.0 * n);
	if (r > 225.0)
		r = 225.0;
	if (r < 0.0)
		r = -r;
	if (r > 225.0)
		r = 225.0;
	g = 140.0 - (2.0 * n);
	if (g < 0.0)
		g = -g;
	if (g > 225.0)
		g = 225.0;
	b = 210.0 - (2.0 * n);
	if (b < 0.0)
		b = -b;
	if (b > 225.0)
		b = 225.0;
	return (0 | (r << 16) | (g << 8) | b);
}

int	get_gray(double n)
{
	int	r;
	int	g;
	int	b;

	r = 225.0 - (8.0 * n);
	if (r < 0)
		return (0x000000);
	g = 225.0 - (8.0 * n);
	if (g < 0)
		g = 225.0;
	b = 225.0 - (8.0 * n);
	if (b < 0)
		b = 225.0;
	return (0 | (r << 16) | (g << 8) | b);
}

int	energy(double n)
{
	int col[20];

	col[0] = 0xFF1F00;
	col[1] = 0xFF3D00;
	col[2] = 0xFF5C00;
	col[3] = 0xFF7A00;
	col[4] = 0xFF9900;
	col[5] = 0xFFB800;
	col[6] = 0xFFD600;
	col[7] = 0xFFF500;
	col[8] = 0xEBFF00;
	col[9] = 0xCCFF00;
	col[10] = 0xADFF00;
	col[11] = 0x8FFF00;
	col[12] = 0x70FF00;
	col[13] = 0x52FF00;
	col[14] = 0x33FF00;
	col[15] = 0x14FF00;
	col[16] = 0x00FF0A;
	col[17] = 0x00FA0A;
	col[18] = 0x00F50A;
	col[19] = 0x00F009;
	if (n > 19 && n < 40)
		n = (int)n % 20;
	return (col[(int)n]);
}

int	rainbow(double n)
{
	int	i;
	int	colors[7];

	i = n;
	colors[0] = 0x9400D3;
	colors[1] = 0x4B0082;
	colors[2] = 0x0000FF;
	colors[3] = 0x00FF00;
	colors[4] = 0xFFFF00;
	colors[5] = 0xFF7F00;
	colors[6] = 0xFF0000;
	if (i > 6)
		i = i % 7;
	return (colors[i]);
}
