/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threader3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:06:51 by laskolin          #+#    #+#             */
/*   Updated: 2020/03/12 15:16:20 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	eleven(t_fractol *fr)
{
	fr->thread11 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

void	twelve(t_fractol *fr)
{
	fr->thread12 = (int)pthread_self();
	if (fr->type == 1)
		julia(fr);
	else
		mandel(fr);
}

int		get_z(t_fractol *fr)
{
	if (fr->thread1 == (int)pthread_self())
		return (0);
	else if (fr->thread2 == (int)pthread_self())
		return (1);
	else if (fr->thread3 == (int)pthread_self())
		return (2);
	else if (fr->thread4 == (int)pthread_self())
		return (3);
	else if (fr->thread5 == (int)pthread_self())
		return (4);
	else if (fr->thread6 == (int)pthread_self())
		return (5);
	else if (fr->thread7 == (int)pthread_self())
		return (6);
	else if (fr->thread8 == (int)pthread_self())
		return (7);
	else if (fr->thread9 == (int)pthread_self())
		return (8);
	else if (fr->thread10 == (int)pthread_self())
		return (9);
	else if (fr->thread11 == (int)pthread_self())
		return (10);
	else
		return (11);
}

int		create_threads(pthread_t *threads, t_fractol *fr)
{
	fr->thread1 = (int)pthread_self();
	pthread_create(&threads[0], NULL, (void *)one, fr);
	fr->thread2 = (int)pthread_self();
	pthread_create(&threads[1], NULL, (void *)two, fr);
	fr->thread3 = (int)pthread_self();
	pthread_create(&threads[2], NULL, (void *)three, fr);
	fr->thread4 = (int)pthread_self();
	pthread_create(&threads[3], NULL, (void *)four, fr);
	fr->thread5 = (int)pthread_self();
	pthread_create(&threads[4], NULL, (void *)five, fr);
	fr->thread6 = (int)pthread_self();
	pthread_create(&threads[5], NULL, (void *)six, fr);
	fr->thread7 = (int)pthread_self();
	pthread_create(&threads[6], NULL, (void *)seven, fr);
	fr->thread8 = (int)pthread_self();
	pthread_create(&threads[7], NULL, (void *)eight, fr);
	fr->thread9 = (int)pthread_self();
	pthread_create(&threads[8], NULL, (void *)nine, fr);
	fr->thread10 = (int)pthread_self();
	pthread_create(&threads[9], NULL, (void *)ten, fr);
	fr->thread11 = (int)pthread_self();
	pthread_create(&threads[10], NULL, (void *)eleven, fr);
	fr->thread12 = (int)pthread_self();
	pthread_create(&threads[11], NULL, (void *)twelve, fr);
	return (1);
}

int		join_threads(pthread_t *threads)
{
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
	pthread_join(threads[4], NULL);
	pthread_join(threads[5], NULL);
	pthread_join(threads[6], NULL);
	pthread_join(threads[7], NULL);
	pthread_join(threads[8], NULL);
	pthread_join(threads[9], NULL);
	pthread_join(threads[10], NULL);
	pthread_join(threads[11], NULL);
	return (1);
}
