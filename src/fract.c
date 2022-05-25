/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:56:17 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/25 10:00:43 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

int	color(int o, int r, int g, int b)
{
	r = (r * 10) % 256;
	g = (g * 0) % 256;
	if (r < 50)
		r = 50;
	b = (b * 0) % 256;
	return (o << 24 | r << 16 | g << 8 | b);
}

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	ft_chk_px(t_fract *fract)
{
	int		iter;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 600)
	{
		while (y < 600)
		{
			if (fract->fract_type == mandelbrot)
			{
				iter = ft_mandelbrot(fract, x, y);
				if (iter < fract->max_iteration)
					my_put_pixel(&fract->img, x, y, color(160, iter, iter, iter));
				// if (iter < fract->max_iteration )
					// my_put_pixel(&fract->img, x, y, 0x0ff0000);
				else
					my_put_pixel(&fract->img, x, y, 0x0);
			}
			if (fract->fract_type == tricorn)
			{
				iter = ft_tricorn(fract, x, y);
				if (iter < fract->max_iteration)
					my_put_pixel(&fract->img, x, y, color(0, iter, iter, iter));
				else
					my_put_pixel(&fract->img, x, y, 0x0);
			}
			if (fract->fract_type == burnungship)
			{
				iter = ft_burningship(fract, x, y);
				if (iter < fract->max_iteration)
					my_put_pixel(&fract->img, x, y, color(0, iter, iter, iter));
				else
					my_put_pixel(&fract->img, x, y, 0x0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	x = 295;
	y = 295;
	while (x <= 305)
	{
		while (y <= 305)
		{
			my_put_pixel(&fract->img, x, y, 0x00ffffff);
			y++;
		}
	y = 295;
	x++;
	}
	mlx_put_image_to_window(fract->prog, fract->parent_window, \
	fract->img.img, 0, 0);
}
