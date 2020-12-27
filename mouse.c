/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	press2(int x, int y, t_fractol *fr)
{
	if (fr->type == 1 && y > 225 && y < 240)
		mouse(-2, fr);
	else if (y > 250 && y < 265)
		reset(114, fr);
	else if (fr->type == 1 && y > 280 && y < 295)
		mouse(-1, fr);
	else if (fr->type == 1 && y > 305 && y < 320)
		reset(99, fr);
	else if (fr->iter < 2000)
	{
		if (y > 525 && y < 540 && x < fr->w + 75)
			iterate(103, fr);
		else if (y > 525 && y < 540 && x > fr->w + 75)
			iterate(104, fr);
		else if (y > 545 && y < 560 && x < fr->w + 75)
			iterate(106, fr);
		else if (y > 545 && y < 560 && x > fr->w + 75)
			iterate(107, fr);
	}
}

int		press(int x, int y, t_fractol *fr)
{
	if (y > 20 && y < 30)
		change_set("julia", fr);
	else if (y > 35 && y < 45)
		change_set("mandelbrot", fr);
	else if (y > 50 && y < 60)
		change_set("burningship", fr);
	else if (y > 65 && y < 75)
		change_set("buddhabrot", fr);
	else if (y > 115 && y < 125)
		style(49, fr);
	else if (y > 130 && y < 140)
		style(50, fr);
	else if (y > 145 && y < 155)
		style(51, fr);
	else if (y > 160 && y < 170)
		style(52, fr);
	else if (y > 175 && y < 185)
		style(53, fr);
	else if (y > 190 && y < 200)
		style(54, fr);
	else if (fr->type != 4)
		press2(x, y, fr);
	else
		return (0);
	return (1);
}

int		deal_mouse(int button, int x, int y, t_fractol *fr)
{
	if (x < fr->w && fr->type != 4)
	{
		if (fr->type == 1 && button == 3 && fr->mouse != 1)
			mouse(-1, fr);
		if (fr->type == 1 && button == 1 && fr->mouse == 1)
			mouse(-2, fr);
		else if (fr->mouse == 0 && (button == 1 || button == 4 || button == 5))
			zoomer(button, x, y, fr);
	}
	else
	{
		if (press(x, y, fr) == 0)
			return (0);
	}
	mlx_destroy_image(fr->mlx, fr->img);
	draw(fr);
	return (0);
}

int		julia_constant(int x, int y, t_fractol *fr)
{
	fr->cx = (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) * fr->zoom;
	fr->cy = (y - fr->h / 2) / (0.5 * fr->zoom * fr->h) * fr->zoom;
	mlx_destroy_image(fr->mlx, fr->img);
	draw(fr);
	fr->mousex = x;
	fr->mousey = y;
	return (0);
}

int		deal_mouse2(int x, int y, t_fractol *fr)
{
	if (x > fr->w)
	{
		if (x > fr->w + 40 && y > 20 && y < 30)
			mlx_string_put(fr->mlx, fr->win, fr->t, 30, fr->c2, "Julia");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 30, fr->c1, "Julia");
		if (x > fr->w + 40 && y > 35 && y < 45)
			mlx_string_put(fr->mlx, fr->win, fr->t, 45, fr->c2, "Mandelbrot");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 45, fr->c1, "Mandelbrot");
		if (x > fr->w + 40 && y > 50 && y < 60)
			mlx_string_put(fr->mlx, fr->win, fr->t, 60, fr->c2, "Burning ship");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 60, fr->c1, "Burning ship");
		if (x > fr->w + 40 && y > 65 && y < 75)
			mlx_string_put(fr->mlx, fr->win, fr->t, 75, fr->c2, "Buddhabrot");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 75, fr->c1, "Buddhabrot");
		highlighter(x, y, fr);
	}
	else if (fr->type == 1 && fr->mouse == 1 && (abs(fr->mousex - x) > 10 ||
	abs(fr->mousey - y) > 10))
		julia_constant(x, y, fr);
	return (0);
}
