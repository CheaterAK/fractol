/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:15:42 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 08:13:05 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

void	draw_mfract3_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract3_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract3, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	if (fract->mini_fract3_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract3, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window,
		fract->mini_fract3.img, fract->img_size, fract->mini_fract_size * 2);
}

void	draw_mfract3(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract3_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract3, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	if (fract->mini_fract3_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract3, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract3, x, y, 0x0);
	}
	draw_mfract3_2(fract, x, y);
}

void	draw_mfract2_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract2_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract2, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	if (fract->mini_fract2_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract2, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window,
		fract->mini_fract2.img, fract->img_size, fract->mini_fract_size * 1);
}

void	draw_mfract2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract2_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract2, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	if (fract->mini_fract2_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract2, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract2, x, y, 0x0);
	}
	draw_mfract2_2(fract, x, y);
}
