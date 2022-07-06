/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:16:20 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/04 23:01:15 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"

int	ft_mandelbrot(t_fract *fract, int x, int y, int scale)
{
	int			iter;
	long double	r_sqr;
	long double	i_sqr;

	fract->c = (t_complex){.i = -2.0 + y * 4.0 / (fract->zoom * (fract->img_size
				/ scale)) + (fract->mv_y), .r = -2.0 + x * 4.0 / (fract->zoom
			* (fract->img_size / scale)) + (fract->mv_x)};
	fract->z = (t_complex){0, 0};
	iter = -1;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && ++iter < (fract->max_iteration / scale))
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r ;
		r_sqr = fract->z.r * fract->z.r + fract->julia_x;
		i_sqr = fract->z.i * fract->z.i + fract->julia_y;
	}
	return (iter);
}

int	ft_julia(t_fract *fract, int x, int y, int scale)
{
	int			iter;
	long double	temp;

	fract->c.r = fract->julia_x;
	fract->c.i = fract->julia_y;
	fract->z.i = -2.0 + y * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_y);
	fract->z.r = -2.0 + x * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_x);
	iter = 0;
	temp = 0;
	while ((fract->z.i * fract->z.i) + (fract->z.r * fract->z.r) < 4
		&& iter < (fract->max_iteration / scale))
	{
		temp = (fract->z.r * fract->z.r) - (fract->z.i * fract->z.i);
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = temp + fract->c.r;
		iter++;
	}
	return (iter);
}

int	ft_tricorn(t_fract *fract, int x, int y, int scale)
{
	int			iter;
	long double	r_sqr;
	long double	i_sqr;

	fract->c.i = -2.0 + y * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_y);
	fract->c.r = -2.0 + x * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_x);
	fract->z.i = 0;
	fract->z.r = 0;
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && iter < (fract->max_iteration / scale))
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r;
		r_sqr = -1 * fract->z.r * fract->z.r;
		i_sqr = -1 * fract->z.i * fract->z.i;
		iter++;
	}
	return (iter);
}

int	ft_burningship(t_fract *fract, int x, int y, int scale)
{
	int			iter;
	long double	r_sqr;
	long double	i_sqr;

	fract->c.i = -2.0 + y * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_y);
	fract->c.r = -2.0 + x * 4.0 / (fract->zoom * (fract->img_size / scale))
		+ (fract->mv_x);
	fract->z = (t_complex){.i = 0, .r = 0};
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && iter < (fract->max_iteration / scale))
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r;
		if (fract->z.i < 0)
			fract->z.i *= -1;
		if (fract->z.r < 0)
			fract->z.r *= -1;
		r_sqr = fract->z.r * fract->z.r;
		i_sqr = fract->z.i * fract->z.i;
		iter++;
	}
	return (iter);
}

void	ft_julia_preset(char preset, t_fract *fract)
{
	if (preset == '1')
	{
		fract->julia_x = 0;
		fract->julia_y = .8;
	}
	else if (preset == '2')
	{
		fract->julia_x = -.4;
		fract->julia_y = -.6;
	}
	else if (preset == '3')
	{
		fract->julia_x = -.70176;
		fract->julia_y = .3842;
	}
	else if (preset == '4')
	{
		fract->julia_x = .285;
		fract->julia_y = -.01;
	}
}
