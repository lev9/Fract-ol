/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		highlihtbuddha(int x, int y, t_fractol *fr)
{
	if (x > fr->w + 40 && y > 115 && y < 125)
		mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c2, "hot buddha");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c1, "hot buddha");
	if (x > fr->w + 40 && y > 130 && y < 140)
		mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c2, "blue buddha");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c1, "blue buddha");
	if (x > fr->w + 40 && y > 145 && y < 155)
		mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c2, "buddha light");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c1, "buddha light");
	if (x > fr->w + 40 && y > 160 && y < 170)
		mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c2, "color buddha");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c1, "color buddha");
	if (x > fr->w + 40 && y > 175 && y < 185)
		mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c2, "buddhabrot");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c1, "buddhabrot");
	if (x > fr->w + 40 && y > 190 && y < 200)
		mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c2, "antibuddha");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c1, "antibuddha");
	return (1);
}

int		highlightsettings(int x, int y, t_fractol *fr)
{
	if (fr->type == 1)
	{
		if (x > fr->w + 40 && y > 225 && y < 240)
			mlx_string_put(fr->mlx, fr->win, fr->t, 240, fr->c2, "mouse zoom");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 240, fr->c1, "mouse zoom");
		if (x > fr->w + 40 && y > 280 && y < 295)
			mlx_string_put(fr->mlx, fr->win, fr->t, 295, fr->c2, "mouse shape");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 295, fr->c1, "mouse shape");
		if (x > fr->w + 40 && y > 305 && y < 320)
			mlx_string_put(fr->mlx, fr->win, fr->t, 320, fr->c2, "reset shape");
		else
			mlx_string_put(fr->mlx, fr->win, fr->t, 320, fr->c1, "reset shape");
	}
	if (x > fr->w + 40 && y > 250 && y < 265)
		mlx_string_put(fr->mlx, fr->win, fr->t, 265, fr->c2, "reset zoom");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 265, fr->c1, "reset zoom");
	return (1);
}

int		highlightiter(int x, int y, t_fractol *fr)
{
	if (x > fr->w + 40 && y > 525 && y < 540 && x < fr->w + 75)
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 540, fr->c2, "   - 10");
	else
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 540, fr->c1, "   - 10");
	if (x > fr->w + 40 && y > 525 && y < 540 && x > fr->w + 75)
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 540, fr->c2,
		"           + 10");
	else
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 540, fr->c1,
		"           + 10");
	if (x > fr->w + 40 && y > 545 && y < 560 && x < fr->w + 75)
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 560, fr->c2, "   -100");
	else
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 560, fr->c1, "   -100");
	if (x > fr->w + 40 && y > 545 && y < 560 && x > fr->w + 75)
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 560, fr->c2,
		"           +100");
	else
		mlx_string_put(fr->mlx, fr->win, fr->w + 20, 560, fr->c1,
		"           +100");
	return (0);
}

int		highlightnames(int x, int y, t_fractol *fr)
{
	if (x > fr->w + 40 && y > 115 && y < 125)
		mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c2, "energy");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 125, fr->c1, "energy");
	if (x > fr->w + 40 && y > 130 && y < 140)
		mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c2, "gold");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 140, fr->c1, "gold");
	if (x > fr->w + 40 && y > 145 && y < 155)
		mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c2, "metal");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 155, fr->c1, "metal");
	if (x > fr->w + 40 && y > 160 && y < 170)
		mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c2, "candy");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 170, fr->c1, "candy");
	if (x > fr->w + 40 && y > 175 && y < 185)
		mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c2, "rainbow");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 185, fr->c1, "rainbow");
	if (x > fr->w + 10 && y > 190 && y < 200)
		mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c2, "bluey");
	else
		mlx_string_put(fr->mlx, fr->win, fr->t, 200, fr->c1, "bluey");
	return (0);
}

int		highlighter(int x, int y, t_fractol *fr)
{
	if (fr->type != 4)
	{
		highlightnames(x, y, fr);
		highlightsettings(x, y, fr);
		highlightiter(x, y, fr);
	}
	else
		highlihtbuddha(x, y, fr);
	return (0);
}
