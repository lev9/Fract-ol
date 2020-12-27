/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	antibud(t_fractol *fr)
{
	fr->screenx = fr->w / 2 + (fr->farx * (fr->w * 1.5 * 0.25)) + fr->w / 8;
	fr->screeny = fr->w / 2 + (fr->fary * (fr->h * 1.5 * 0.25));
	if (fr->screenx < fr->w && fr->screeny < fr->h)
		fr->buf[(int)(fr->screenx * fr->w + fr->screeny)] += 10;
}

void	apply(t_fractol *fr, int i, int min)
{
	int	a;

	a = 0;
	if (fr->style == 50 || fr->style == 52)
		a = min;
	while (a < i)
	{
		fr->curx = fr->farx;
		fr->cury = fr->fary;
		fr->farx = fr->curx * fr->curx - fr->cury * fr->cury + fr->cx;
		fr->fary = 2 * fr->curx * fr->cury + fr->cy;
		fr->screenx = fr->w / 2 + (fr->farx * (fr->w * 1.5 * 0.25)) + fr->w / 8;
		fr->screeny = fr->h / 2 + (fr->fary * (fr->h * 1.5 * 0.25));
		fr->c = 1;
		if (fr->style == 50)
			fr->c = i + 6;
		else if (fr->style == 52)
			fr->c = i + 1;
		if (fr->screenx < fr->w && fr->screeny < fr->h)
		{
			fr->buf[(int)(fr->screenx * fr->w + fr->screeny)] += fr->c;
			fr->buf[(int)(fr->w * fr->screenx + fr->w - fr->screeny)] += fr->c;
		}
		a++;
	}
}

void	handle_spot(t_fractol *fr, int min, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		fr->curx = fr->farx;
		fr->cury = fr->fary;
		fr->farx = fr->curx * fr->curx - fr->cury * fr->cury + fr->cx;
		fr->fary = 2 * fr->curx * fr->cury + fr->cy;
		if (fr->farx * fr->farx + fr->fary * fr->fary > 4.0)
		{
			if (i > min && fr->style != 54)
			{
				fr->curx = 0.0;
				fr->cury = 0.0;
				fr->farx = 0.0;
				fr->fary = 0.0;
				apply(fr, i, min);
			}
			break ;
		}
		else if (fr->style == 54 && i > min)
			antibud(fr);
		i++;
	}
}

void	addcolor(t_fractol *fr)
{
	int	a;

	a = 0;
	while (a < fr->w * fr->h)
	{
		if (fr->buf[a] > 0)
		{
			if (fr->style == 49)
				fr->buf[a] = energy((double)(fr->buf[a]));
			else if (fr->style == 51)
				fr->buf[a] = beach_color((double)(fr->buf[a]));
			else if (fr->style == 52)
				fr->buf[a] = fr->buf[a] * fr->buf[a];
		}
		a++;
	}
}

void	buddhabrot(t_fractol *fr)
{
	int	count;

	minim(fr);
	maxim(fr);
	get_spots(fr);
	get_zoom(fr->style, fr);
	image_values(fr);
	count = 0;
	while (count < fr->spots)
	{
		get_random(count, fr);
		fr->curx = 0.0;
		fr->cury = 0.0;
		fr->farx = 0.0;
		fr->fary = 0.0;
		fr->cx = (fr->randx - fr->value / 2) / (0.5 * fr->zoom * fr->value);
		fr->cy = (fr->randy - fr->value / 2) / (0.5 * fr->zoom * fr->value);
		handle_spot(fr, fr->min, fr->max);
		count++;
	}
	if (fr->style == 49 || fr->style == 51 || fr->style == 52)
		addcolor(fr);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
