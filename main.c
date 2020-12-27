/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fr(char *argu)
{
	t_fractol	*fr;
	t_fractol	newfractol;

	fr = &newfractol;
	fr->argu = argu;
	fr->mlx = mlx_init();
	fr->type = type(fr);
	fr->w = SIZE;
	fr->h = SIZE;
	fr->multi = 0;
	fr->win = mlx_new_window(fr->mlx, fr->w + 150, fr->h, "fract'ol");
	border(fr);
	set_values(fr);
	directions();
	draw(fr);
	if (fr->type != 4)
		text_window(fr);
	else
		text_buddha(fr);
	if (fr->type == 1)
		mlx_string_put(fr->mlx, fr->win, fr->w + 130, 240, 0xbdaabf, "<-");
	mlx_mouse_hook(fr->win, deal_mouse, fr);
	mlx_hook(fr->win, 2, 1L << 0, deal_key, fr);
	mlx_hook(fr->win, 6, 1L << 6, deal_mouse2, fr);
	mlx_loop(fr->mlx);
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || unvalid(argv[1]))
		return (errormessage());
	fr(argv[1]);
	return (0);
}
