/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainisprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:59:31 by laskolin          #+#    #+#             */
/*   Updated: 2019/10/23 13:35:39 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}