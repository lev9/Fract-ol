/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterjulia(t_fractol *fr, double x, double y, int pixel)
{
	t_point point;
	double	curx;
	double	cury;
	int		i;

	point.farx = (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->posx;
	point.fary = (y - fr->h / 2) / (0.5 * fr->zoom * fr->w) + fr->posy;
	i = 0;
	while (i < fr->iter)
	{
		curx = point.farx;
		cury = point.fary;
		point.farx = curx * curx - cury * cury + fr->cx;
		point.fary = 2 * curx * cury + fr->cy;
		if (paint(fr, i, point, pixel) == 0)
			break ;
		i++;
	}
}

void	julia(t_fractol *fr)
{
	double	x;
	double	y;
	int		pixel;
	int		z;

	z = get_z(fr);
	pixel = fr->w * fr->h / THREADS * z;
	y = fr->h / THREADS * z;
	while (y < fr->h / THREADS * (z + 1))
	{
		x = 0;
		while (x < fr->w)
		{
			iterjulia(fr, x, y, pixel);
			x++;
			pixel++;
		}
		y++;
	}
	pthread_exit(NULL);
}

void	itermandel(t_fractol *fr, int pixel, t_const c)
{
	t_point point;
	double	curx;
	double	cury;
	int		i;

	point.farx = 0.0;
	point.fary = 0.0;
	curx = 0.0;
	cury = 0.0;
	i = 0;
	while (i < fr->iter)
	{
		curx = point.farx;
		cury = point.fary;
		point.farx = curx * curx - cury * cury + c.cx;
		if (fr->type == 3)
			point.fary = 2 * fabs(curx * cury) + c.cy;
		else
			point.fary = 2 * curx * cury + c.cy;
		if (paint(fr, i, point, pixel) == 0)
			break ;
		i++;
	}
}

void	mandel(t_fractol *fr)
{
	double	x;
	double	y;
	t_const	c;
	int		pixel;
	int		z;

	z = get_z(fr);
	pixel = fr->w * fr->h / THREADS * z;
	y = fr->h / THREADS * z;
	while (y < fr->h / THREADS * (z + 1))
	{
		c.cy = (y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->posy;
		x = 0;
		while (x < fr->w)
		{
			c.cx = (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->posx;
			itermandel(fr, pixel, c);
			x++;
			pixel++;
		}
		y++;
	}
	pthread_exit(NULL);
}

void	draw_set(t_fractol *fr)
{
	pthread_t	threads[THREADS];

	image_values(fr);
	create_threads(threads, fr);
	join_threads(threads);
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
