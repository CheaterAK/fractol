/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:21:02 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 10:55:37 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fract.h"
#include "minilibx_macos/mlx.h"

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

int	ft_m_move(int x, int y, t_fract *fract)
{
	if ((x >= fract->img_size || x < 0) || y >= fract->img_size || y < 0)
	{
		return (0);
	}
	if (!fract->key_flag)
		return (0);
	fract->julia_x = (-1 + (double)x / 300) / fract->zoom;
	fract->julia_y = (-1 + (double)y / 300) / fract->zoom;
	ft_chk_px(fract);
	return (1);
}

int	main(int ac, char *av[])
{
	t_fract	fract;

	if (ac < 2)
	{
		printf("duzgun gir fractal giriniz. './fract -help' komutunu deneyin");
		return (1);
	}
	ft_init_prog(&fract);
	fract_init(av[1], &fract);
	ft_chk_px(&fract);
	mlx_hook(fract.parent_window, 2, 0, keydown, &fract);
	mlx_hook(fract.parent_window, 4, 0, mouse_hook, &fract);
	mlx_hook(fract.parent_window, 17, 0, ft_destroy_it, &fract);
	mlx_hook(fract.parent_window, 6, 0, ft_m_move, &fract);
	mlx_loop(fract.prog);
}
