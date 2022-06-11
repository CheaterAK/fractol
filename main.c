/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:21:02 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/11 11:06:52 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fract.h"
#include "minilibx_macos/mlx.h"

int	ft_destroy_it(t_fract *fract)
{
	mlx_destroy_window(fract->prog, fract->parent_window);
	exit(0);
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
