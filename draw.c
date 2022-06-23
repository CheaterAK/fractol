/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:06 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/13 17:19:56 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"

void	draw_fract(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == mandelbrot)
	{
		if (iter < fract->max_iteration)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	if (fract->fract_type == julia)
	{
		if (iter < fract->max_iteration)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
}