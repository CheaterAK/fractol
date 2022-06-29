/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 08:58:06 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 20:54:07 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"
#include "./mlx.h"

void	ft_draw_fract2(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == julia)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == burningship)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
}

void	ft_draw_fract(t_fract *fract, int x, int y, int iter)
{
	if (fract->fract_type == mandelbrot)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
	else if (fract->fract_type == tricorn)
	{
		if (iter < fract->max_iteration && fract->color_shift == 0)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, iter));
		else if (iter < fract->max_iteration && !(iter % 2)
			&& fract->color_shift == 1)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else if (iter != fract->max_iteration && fract->color_shift == 2)
			ft_my_put_pixel(&fract->img, x, y, ft_color(fract, 255));
		else
			ft_my_put_pixel(&fract->img, x, y, 0x0);
	}
	ft_draw_fract2(fract, x, y, iter);
}

void	ft_mfract_checkpx(t_fract *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < fract->mini_fract_size)
	{
		while (y < fract->mini_fract_size)
		{
			ft_draw_mfract1(fract, x, y);
			ft_draw_mfract2(fract, x, y);
			ft_draw_mfract3(fract, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

void	ft_draw_mfract1_2(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract1_type == burningship)
	{
		iter = ft_burningship(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract1, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	if (fract->mini_fract1_type == tricorn)
	{
		iter = ft_tricorn(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract1, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window,
		fract->mini_fract1.img, fract->img_size, fract->mini_fract_size * 0);
}

void	ft_draw_mfract1(t_fract *fract, int x, int y)
{
	int	iter;

	if (fract->mini_fract1_type == mandelbrot)
	{
		iter = ft_mandelbrot(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract1, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	if (fract->mini_fract1_type == julia)
	{
		iter = ft_julia(fract, x, y, 3);
		if (iter < (fract->max_iteration / 3))
			ft_my_put_pixel(&fract->mini_fract1, x, y,
				ft_color(fract, iter));
		else
			ft_my_put_pixel(&fract->mini_fract1, x, y, 0x0);
	}
	ft_draw_mfract1_2(fract, x, y);
}