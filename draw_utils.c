/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		paint(t_fractol *fr, int i, t_point point, int pixel)
{
	int	n;

	n = fr->style;
	if (fr->multi == 1)
		n = get_multi(fr);
	if (n == 49)
	{
		if (fr->type == 3)
			return (shipenergy(fr, i, point, pixel));
		else
			return (energystyle(fr, i, point, pixel));
	}
	else if (n == 50)
		return (light(fr, i, point, pixel));
	else if (n == 51)
		return (metal(fr, i, point, pixel));
	else if (n == 52)
		return (candy(fr, i, point, pixel));
	else if (n == 53)
		return (rb(fr, i, point, pixel));
	else if (n == 54)
		return (bluey(fr, i, point, pixel));
	return (0);
}

void	draw(t_fractol *fr)
{
	if (fr->type == 4)
		buddhabrot(fr);
	else
		draw_set(fr);
}

void	set_values2(t_fractol *fr)
{
	if (fr->type == 3)
	{
		fr->zoom = 0.50;
		fr->iter = 70.0;
		fr->posx = 0.0;
		fr->posy = 0.0;
		fr->style = 49;
		fr->twist = 8.0;
	}
	else if (fr->type == 4)
	{
		fr->posx = 0.0;
		fr->posy = 0.0;
		fr->style = 49;
	}
}

void	set_values(t_fractol *fr)
{
	fr->t = fr->w + 50;
	fr->c1 = 0xbdaabf;
	fr->c2 = 0xa338eb;
	fr->mouse = 0;
	fr->zoom = 0.75;
	if (fr->type == 1)
	{
		fr->cx = -0.7;
		fr->cy = 0.27015;
		fr->style = 49;
		fr->iter = 70.0;
		fr->posx = 0.0;
		fr->posy = 0.0;
		fr->twist = 1;
	}
	else if (fr->type == 2)
	{
		fr->style = 49;
		fr->iter = 70.0;
		fr->posx = -(fr->w / 2) / (0.5 * fr->zoom * fr->w) / 2;
		fr->posy = 0.0;
		fr->twist = 8.0;
	}
	else
		set_values2(fr);
}

void	image_values(t_fractol *fr)
{
	int		pix_bits;
	int		line_pix;
	int		endian;

	fr->img = mlx_new_image(fr->mlx, fr->w, fr->h);
	fr->buf = (int*)mlx_get_data_addr(fr->img, &pix_bits, &line_pix, &endian);
}
