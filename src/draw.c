/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:06 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/03 19:25:54 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

		// if (iter == fract->max_iteration)
		// 	my_put_pixel(&fract->img, x, y, color(0, iter, iter, iter));

void	draw_fract1(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->fract_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y);
		if (iter < fract->max_iteration && iter % 2 == 1)
			my_put_pixel(&fract->img, x, y, 0xaa0000);
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y);
		if (iter < fract->max_iteration)
			my_put_pixel(&fract->img, x, y, color(0, iter, iter, iter));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == julia)
	{
		iter = ft_julia(fract, x, y);
		if (iter < fract->max_iteration)
			my_put_pixel(&fract->img, x, y, color(250, iter, iter, iter));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == burnungship)
	{
		iter = ft_burningship(fract, x, y);
		if (iter < fract->max_iteration && iter % 2 == 1)
			my_put_pixel(&fract->img, x, y, 0xaa0000);
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
}
