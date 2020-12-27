/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	unicorny3(double n, int r, int g, int b)
{
	if (n >= 256 && n < 320)
	{
		r = n * 4.0 - 256.0 * 4.0;
		g = 196.0;
		b = 255.0;
	}
	else if (n >= 320 && n < 384)
	{
		r = 255.0;
		g = 196.0;
		b = 255.0 - (n * 4.0 - 320.0 * 4.0);
	}
	else
	{
		r = 0;
		g = 0;
		b = 0;
	}
	return (0 | (r << 16) | (g << 8) | b);
}

int	unicorny2(double n, int r, int g, int b)
{
	if (n >= 64.0 && n < 128.0)
	{
		r = 255.0 - (n * 4.0 - 64.0 * 4.0);
		g = 255.0;
		b = 196.0;
	}
	else if (n >= 128.0 && n < 192.0)
	{
		r = 196.0;
		g = 255.0;
		b = n * 4.0 - 128.0 * 4.0;
	}
	else if (n >= 192 && n < 256)
	{
		r = 196.0;
		g = 255.0 - (n * 4.0 - 192.0 * 4.0);
		b = 255.0;
	}
	else
		return (unicorny3(n, r, g, b));
	return (0 | (r << 16) | (g << 8) | b);
}

int	unicorny(double n)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	n = n * 10.0;
	if (n < 0.0)
		n = -n;
	if (n > 320.0)
		n -= 320.0;
	if (n >= 0 && n < 64.0)
	{
		r = 255.0;
		g = n * 4.0;
		b = 196.0;
	}
	else
		return (unicorny2(n, r, g, b));
	return (0 | (r << 16) | (g << 8) | b);
}
