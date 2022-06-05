/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:16:20 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/03 16:12:20 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"

int	ft_mandelbrot(t_fract *fract, int x, int y)
{
	int		iter;
	double	r_sqr;
	double	i_sqr;

	if (fract->fract_type == mandelbrot)
	{
		fract->c = (t_complex){.i = -2.0 + y * 4.0 / (fract->zoom * \
		fract->img_size) + (fract->mv_y), .r = -2.0 + x * 4.0 / \
		(fract->zoom * fract->img_size) + (fract->mv_x)};
	}
	else
	{
		fract->c = (t_complex){.i = -2.0 + y * 4.0, .r = -2.0 + x * 4.0};
	}
	fract->z = (t_complex){0, 0};
	iter = -1;
	r_sqr = 0;
	i_sqr = 0;
	while (r_sqr + i_sqr <= 4 && ++iter < fract->max_iteration)
	{
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = r_sqr - i_sqr + fract->c.r;
		r_sqr = (fract->z.r * fract->z.r) + fract->angle;
		i_sqr = fract->z.i * fract->z.i;
	}
	return (iter);
}
/*
{
    zx = scaled x coordinate of pixel # (scale to be between -R and R)
    zy = scaled y coordinate of pixel # (scale to be between -R and R)
    while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration)
    {
        xtemp = zx * zx - zy * zy
        zy = 2 * zx * zy  + cy
        zx = xtemp + cx

        iteration = iteration + 1
    }

    if (iteration == max_iteration)
        return black;
    else
        return iteration;
}
*/

int	ft_julia(t_fract *fract, int x, int y)
{
	int		iter;
	double	temp;

	fract->c.i = (0 + fract->julia_x);
	fract->c.r = (0 + fract->julia_y);
	fract->z.i = -2.0 + y * 4.0 / (fract->zoom * 600) +(fract->mv_y);
	fract->z.r = -2.0 + x * 4.0 / (fract->zoom * 600) +(fract->mv_x);
	iter = 0;
	temp = 0;
	while ((fract->z.i * fract->z.i) + (fract->z.r * \
	fract->z.r) < 4 && iter < fract->max_iteration)
	{
		temp = (fract->z.r * fract->z.r) - (fract->z.i * fract->z.i);
		fract->z.i = 2 * (fract->z.i * fract->z.r) + fract->c.i;
		fract->z.r = temp + fract->c.r;
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
