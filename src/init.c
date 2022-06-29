/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:05:50 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/28 22:18:34 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract.h"
#include "./mlx.h"

void	ft_fract_init(char *fract_name, t_fract *fract)
{
	if (!strcmp(fract_name, "help"))
		ft_help();
	else if (!strcmp(fract_name, "Mandelbrot"))
	{
		fract->max_iteration = 150;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = mandelbrot;
	}
	else if (!strcmp(fract_name, "Julia"))
	{
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = julia;
	}
	else
		ft_invalid_fract();
}

void	ft_init_prog(t_fract *fract)
{
	fract->prog = mlx_init();
	fract->img_size = IMG_SIZE;
	fract->parent_window = mlx_new_window(fract->prog, fract->img_size,
			fract->img_size, "fract'ol");
	fract->img.img = mlx_new_image(fract->prog, fract->img_size,
			fract->img_size);
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
}
