/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:21:02 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/25 08:05:42 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fract.h"
#include "../minilibx_macos/mlx.h"

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
	if (!strcmp(fract_name, "Julia"))
	{
		fract->angle = 0;
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = julia;
	}
}

void	fract_init(char *fract_name, t_fract *fract)
{
	if (!strcmp(fract_name, "Mandelbrot"))
	{
		fract->max_iteration = 150;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = mandelbrot;
		fract->angle = 0;
	}
	else if (!strcmp(fract_name, "Burningship"))
	{
		fract->angle = 0;
		fract->max_iteration = 100;
		fract->mv_x = 0;
		fract->mv_y = 0;
		fract->zoom = 1;
		fract->fract_type = burnungship;
	}
	else
		fract_init2(fract_name, fract);
}

int	main(int ac, char *av[])
{
	t_fract	fract;

	if (ac < 2)
	{
		printf("duzgun gir fractal giriniz. './fract help' komutunu deneyin");
		return (1);
	}
	fract.prog = mlx_init();
	fract.parent_window = mlx_new_window(fract.prog, 600, 600, "first_prog");
	fract.img.img = mlx_new_image(fract.prog, 600, 600);
	fract.img.addr = mlx_get_data_addr(fract.img.img, &fract.img.bpp, \
	&fract.img.line_len, &fract.img.endian);
	fract_init(av[1], &fract);
	printf("\n\n%d\n\n", fract.max_iteration);
	sleep(1);
	ft_chk_px(&fract);
	mlx_hook(fract.parent_window, 2, 0, keydown, &fract);
	mlx_mouse_hook(fract.parent_window, mouse_hook, &fract);
	printf("\n\n%d\n\n", fract.max_iteration);
	mlx_loop(fract.prog);
}
