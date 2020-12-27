/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	energystyle(t_fractol *fr, int i, t_point point, int pixel)
{
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		if (i > 200)
			i %= 200;
		fr->buf[pixel] = energy(i);
		return (0);
	}
	return (1);
}

int	shipenergy(t_fractol *fr, int i, t_point point, int pixel)
{
	int	newpix;

	newpix = pixel - i * 3 * fr->w;
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		if (newpix > 0)
			fr->buf[newpix] = get_gray(i);
		return (0);
	}
	return (1);
}

int	light(t_fractol *fr, int i, t_point point, int pixel)
{
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		if (fr->type == 1)
			fr->buf[pixel] = beach_color(i * fr->twist);
		return (0);
	}
	if (fr->type != 1)
		fr->buf[pixel] = beach_color(i * fr->twist);
	return (1);
}

int	metal(t_fractol *fr, int i, t_point point, int pixel)
{
	i = 0;
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		fr->buf[pixel] = get_gray(3.0 - point.farx * point.farx
		+ point.fary * point.fary);
		return (0);
	}
	return (1);
}
