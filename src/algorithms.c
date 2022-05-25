/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:16:20 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/25 07:22:37 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"

int	ft_mandelbrot(t_fract *fract, int x, int y)
{
	int		iter;
	double	r_sqr;
	double	i_sqr;

	fract->c.i = -2.0 + y * 4.0 / (fract->zoom * 600) + (fract->mv_y);
	fract->c.r = -2.0 + x * 4.0 / (fract->zoom * 600) + (fract->mv_x);
	fract->z.i = 0;
	fract->z.r = 0;
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && iter < fract->max_iteration)
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r;
		r_sqr = (fract->z.r * fract->z.r) + fract->angle;
		i_sqr = fract->z.i * fract->z.i;
		iter++;
	}
	return (iter);
}

int	ft_tricorn(t_fract *fract, int x, int y)
{
	int		iter;
	double	r_sqr;
	double	i_sqr;

	fract->c.i = -2.0 + y * 4.0 / (fract->zoom * 600) + (fract->mv_y);
	fract->c.r = -2.0 + x * 4.0 / (fract->zoom * 600) + (fract->mv_x);
	fract->z.i = 0;
	fract->z.r = 0;
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && iter < fract->max_iteration)
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r;
		r_sqr = -1 * fract->z.r * fract->z.r;
		i_sqr = -1 * fract->z.i * fract->z.i;
		iter++;
	}
	return (iter);
}

int	ft_burningship(t_fract *fract, int x, int y)
{
	int		iter;
	double	r_sqr;
	double	i_sqr;

	fract->c.i = -2.0 + y * 4.0 / (fract->zoom * 600) + (fract->mv_y);
	fract->c.r = -2.0 + x * 4.0 / (fract->zoom * 600) + (fract->mv_x);
	fract->z.i = 0;
	fract->z.r = 0;
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && iter < fract->max_iteration)
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
