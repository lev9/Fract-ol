/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   styles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		candy(t_fractol *fr, int i, t_point point, int pixel)
{
	double	a;

	a = 4.5;
	if (fr->type == 1)
		a = 3.3;
	if (fr->type == 3)
		a = 4.0;
	i = i + 1 - 1;
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
		return (0);
	fr->buf[pixel] = unicorny((a - (point.farx * point.farx +
	point.fary * point.fary)) * (fr->twist / 0.8));
	return (1);
}

int		rb(t_fractol *fr, int i, t_point point, int pixel)
{
	i = 0;
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		fr->buf[pixel] = rainbow((point.farx * point.farx +
		point.fary * point.fary) * 10);
		return (0);
	}
	return (1);
}

int		bluey(t_fractol *fr, int i, t_point point, int pixel)
{
	if (point.farx * point.farx + point.fary * point.fary > 4.0)
	{
		fr->buf[pixel] = i * 200;
		return (0);
	}
	return (1);
}

void	get_iter(t_fractol *fr)
{
	if (fr->style == 50)
		fr->iter = 170;
	else if (fr->style == 51)
	{
		if (fr->type == 3)
			fr->iter = 20;
		else
			fr->iter = 10;
	}
	else if (fr->style == 52)
	{
		if (fr->type == 3)
			fr->iter = 10;
		else
			fr->iter = 40;
	}
	else if (fr->style == 53 && fr->type == 3)
		fr->iter = 20;
	else if (fr->style == 54 && fr->type == 3)
		fr->iter = 20;
	else
		fr->iter = 70;
}

int		get_multi(t_fractol *fr)
{
	int	n;

	if (fr->thread1 == (int)pthread_self() ||
	fr->thread2 == (int)pthread_self())
		n = 0;
	else if (fr->thread3 == (int)pthread_self() ||
	fr->thread4 == (int)pthread_self())
		n = 1;
	else if (fr->thread5 == (int)pthread_self() ||
	fr->thread6 == (int)pthread_self())
		n = 2;
	else if (fr->thread7 == (int)pthread_self() ||
	fr->thread8 == (int)pthread_self())
		n = 3;
	else if (fr->thread9 == (int)pthread_self() ||
	fr->thread10 == (int)pthread_self())
		n = 4;
	else
		n = 5;
	n += fr->style;
	if (n > 54)
		n = 49 + n - 55;
	return (n);
}
