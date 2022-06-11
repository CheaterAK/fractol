/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:05:50 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 11:11:03 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

void	init_mfract(t_fract *fract)
{
	if (fract->fract_type == burningship)
	{
		fract->mini_fract1_type = julia;
		fract->mini_fract2_type = mandelbrot;
		fract->mini_fract3_type = tricorn;
	}
	if (fract->fract_type == julia)
	{
		fract->mini_fract1_type = burningship;
		fract->mini_fract2_type = mandelbrot;
		fract->mini_fract3_type = tricorn;
	}
	if (fract->fract_type == mandelbrot)
	{
		fract->mini_fract1_type = burningship;
		fract->mini_fract2_type = julia;
		fract->mini_fract3_type = tricorn;
	}
	if (fract->fract_type == tricorn)
	{
		fract->mini_fract1_type = burningship;
		fract->mini_fract2_type = julia;
		fract->mini_fract3_type = mandelbrot;
	}
	mfract_checkpx(fract);
}

void	color_init(t_fract *fract)
{
	fract->r = 1;
	fract->g = 1;
	fract->b = 1;
	fract->o = 0;
}

void	fract_init2(char *fract_name, t_fract *fract)
{
	if (!strcmp(fract_name, "Tricorn"))
	{
		fract->angle = 0;
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = tricorn;
	}
	else if (!strcmp(fract_name, "Julia"))
	{
		fract->angle = 0;
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = julia;
	}
	init_mfract(fract);
}

void	fract_init(char *fract_name, t_fract *fract)
{
	color_init(fract);
	fract->color_shift = 0;
	if (!strcmp(fract_name, "Mandelbrot"))
	{
		fract->max_iteration = 150;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = mandelbrot;
		fract->mini_fract1_type = burningship;
		fract->mini_fract1_type = julia;
		fract->mini_fract3_type = tricorn;
		fract->angle = 0;
	}
	else if (!strcmp(fract_name, "Burningship"))
	{
		fract->angle = 0;
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = burningship;
	}
	fract_init2(fract_name, fract);
}

void	ft_init_prog(t_fract *fract)
{
	fract->prog = mlx_init();
	fract->parent_window = mlx_new_window(fract->prog, 800, 600, "first_prog");
	fract->img_size = 600;
	fract->img.img = mlx_new_image(fract->prog, fract->img_size,
			fract->img_size);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
	fract->mini_fract_size = 200;
	fract->mini_fract1.img = mlx_new_image(fract->prog, fract->mini_fract_size,
			fract->mini_fract_size);
	fract->mini_fract1.addr = mlx_get_data_addr(fract->mini_fract1.img,
			&fract->mini_fract1.bpp, &fract->mini_fract1.line_len,
			&fract->mini_fract1.endian);
	fract->mini_fract2.img = mlx_new_image(fract->prog, fract->mini_fract_size,
			fract->mini_fract_size);
	fract->mini_fract2.addr = mlx_get_data_addr(fract->mini_fract2.img,
			&fract->mini_fract2.bpp, &fract->mini_fract2.line_len,
			&fract->mini_fract2.endian);
	fract->mini_fract3.img = mlx_new_image(fract->prog, fract->mini_fract_size,
			fract->mini_fract_size);
	fract->mini_fract3.addr = mlx_get_data_addr(fract->mini_fract3.img,
			&fract->mini_fract3.bpp, &fract->mini_fract3.line_len,
			&fract->mini_fract3.endian);
}
