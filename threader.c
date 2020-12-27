/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	three(t_fractol *fr)
{
	fr->thread3 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	two(t_fractol *fr)
{
	fr->thread2 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	one(t_fractol *fr)
{
	fr->thread1 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	four(t_fractol *fr)
{
	fr->thread4 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	five(t_fractol *fr)
{
	fr->thread5 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}
