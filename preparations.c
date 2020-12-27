/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	border(t_fractol *fr)
{
	int		x;
	int		y;
	int		col;

	col = 0x000000;
	if (fr->type == 4)
		col = 0x301533;
	y = 0;
	while (y < fr->h)
	{
		x = 0;
		while (x < 150)
		{
			mlx_pixel_put(fr->mlx, fr->win, fr->w + x, y, col);
			x++;
		}
		y++;
	}
}

void	text_buddha(t_fractol *fr)
{
	border(fr);
	mlx_string_put(fr->mlx, fr->win, fr->t, 30, fr->c1, "Julia");
	mlx_string_put(fr->mlx, fr->win, fr->t, 45, fr->c1, "Mandelbrot");
	mlx_string_put(fr->mlx, fr->win, fr->t, 60, fr->c1, "Burning ship");
	mlx_string_put(fr->mlx, fr->win, fr->t, 75, fr->c1, "Buddhabrot");
	mlx_string_put(fr->mlx, fr->win, fr->t, 110, fr->c1, "styles:");
	mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c1, "hot buddha");
	mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c1, "blue buddha");
	mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c1, "buddha light");
	mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c1, "color buddha");
	mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c1, "buddhabrot");
	mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c1, "antibuddha");
}

void	text_window2(t_fractol *fr)
{
	char *it;

	it = ft_itoa(fr->iter);
	if (fr->type == 1)
	{
		mlx_string_put(fr->mlx, fr->win, fr->t, 240, fr->c1, "mouse zoom");
		mlx_string_put(fr->mlx, fr->win, fr->t, 295, fr->c1, "mouse shape");
		mlx_string_put(fr->mlx, fr->win, fr->t, 320, fr->c1, "reset shape");
	}
	mlx_string_put(fr->mlx, fr->win, fr->t, 360, fr->c1, "multistyle:");
	mlx_string_put(fr->mlx, fr->win, fr->t, 373, fr->c1, "m | m");
	mlx_string_put(fr->mlx, fr->win, fr->t, 390, fr->c1, "zoom:");
	mlx_string_put(fr->mlx, fr->win, fr->t, 403, fr->c1, "z | x");
	mlx_string_put(fr->mlx, fr->win, fr->t, 420, fr->c1, "move:");
	mlx_string_put(fr->mlx, fr->win, fr->t, 433, fr->c1, "a | w | d | s");
	mlx_string_put(fr->mlx, fr->win, fr->t, 475, fr->c1, "iteration:");
	mlx_string_put(fr->mlx, fr->win, fr->w + 65, 500, fr->c1,
	it);
	free(it);
	mlx_string_put(fr->mlx, fr->win, fr->w + 20, 540, fr->c1,
	"   - 10    + 10");
	mlx_string_put(fr->mlx, fr->win, fr->w + 20, 560, fr->c1,
	"   -100    +100");
}

void	text_window(t_fractol *fr)
{
	mlx_string_put(fr->mlx, fr->win, fr->t, 110, fr->c1, "styles:");
	mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c1, "energy");
	mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c1, "gold");
	mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c1, "metal");
	mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c1, "candy");
	mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c1, "rainbow");
	mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c1, "bluey");
	mlx_string_put(fr->mlx, fr->win, fr->t, 30, fr->c1, "Julia");
	mlx_string_put(fr->mlx, fr->win, fr->t, 45, fr->c1, "Mandelbrot");
	mlx_string_put(fr->mlx, fr->win, fr->t, 60, fr->c1, "Burning ship");
	mlx_string_put(fr->mlx, fr->win, fr->t, 75, fr->c1, "Buddhabrot");
	mlx_string_put(fr->mlx, fr->win, fr->t, 265, fr->c1, "reset zoom");
	text_window2(fr);
}
