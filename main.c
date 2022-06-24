/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:21:02 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/24 10:53:45 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
#include "minilibx_opengl_20191021/mlx.h"

int	ft_destroy_it(t_fract *fract)
{
	mlx_destroy_window(fract->prog, fract->parent_window);
	exit(0);
}

void	ft_errors(int ac, char **av, t_fract *fract)
{
	if (!(ac == 2 || ac == 3))
	{
		ft_error_message();
		exit(1);
	}
	if (ac == 3)
	{
		if (!(av[2][0] >= '1' && av[2][0] <= '4' && !av[2][1]))
			ft_invalid_julia();
		else
			ft_julia_preset(av[2][0], fract);
	}
}

int	main(int ac, char *av[])
{
	t_fract	fract;

	ft_errors(ac, av, &fract);
	ft_init_prog(&fract);
	fract_init(av[1], &fract);
	ft_chk_px(&fract);
	mlx_hook(fract.parent_window, 2, 0, keydown, &fract);
	mlx_hook(fract.parent_window, 4, 0, mouse_hook, &fract);
	mlx_hook(fract.parent_window, 17, 0, ft_destroy_it, &fract);
	mlx_hook(fract.parent_window, 6, 0, ft_m_move, &fract);
	mlx_loop(fract.prog);
}
