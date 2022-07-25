/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawm_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:15:42 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/06 06:56:12 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_bonus.h"
#include "mlx.h"

void	ft_draw_mfract3_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract3_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract3, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	if (fract->mini_fract3_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract3, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
}

void	ft_draw_mfract3(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract3_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract3, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	if (fract->mini_fract3_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract3, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	ft_draw_mfract3_2(fract, x, y);
}

void	ft_draw_mfract2_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract2_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract2, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	if (fract->mini_fract2_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract2, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
}

void	ft_draw_mfract2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract2_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract2, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	if (fract->mini_fract2_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract2, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	ft_draw_mfract2_2(fract, x, y);
}
