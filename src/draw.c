/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:06 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 08:14:06 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"

void	ft_draw_fract(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == mandelbrot)
	{
		if (iter < fract->max_iteration)
			ft_my_put_pixel(&fract->img, x, y, ft_color(iter, iter, iter));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
	if (fract->fract_type == julia)
	{
		if (iter < fract->max_iteration)
			ft_my_put_pixel(&fract->img, x, y, ft_color(iter, iter, iter));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
}
