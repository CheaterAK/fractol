/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:06 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 11:05:12 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

void	draw_fract2(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == julia)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == burningship)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
}

void	draw_fract(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == mandelbrot)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == tricorn)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			my_put_pixel(&fract->img, x, y, color(fract, iter, iter, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			my_put_pixel(&fract->img, x, y, color(fract, 255, 255, 255));
		else
			my_put_pixel(&fract->img, x, y, 0x0);
	}
	draw_fract2(fract, x, y, iter);
}

void	mfract_checkpx(t_fract *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < fract->mini_fract_size)
	{
		while (y < fract->mini_fract_size)
		{
			draw_mfract1(fract, x, y);
			draw_mfract2(fract, x, y);
			draw_mfract3(fract, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

void	draw_mfract1_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract1_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract1, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	if (fract->mini_fract1_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract1, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window,
		fract->mini_fract1.img, fract->img_size, fract->mini_fract_size * 0);
}

void	draw_mfract1(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract1_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract1, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	if (fract->mini_fract1_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			my_put_pixel(&fract->mini_fract1, x, y,
				color(fract, iter, iter, iter));
		else
			my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	draw_mfract1_2(fract, x, y);
}
