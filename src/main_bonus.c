/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:21:02 by akocabas          #+#    #+#             */
/*   Updated: 2022/07/06 06:58:34 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_bonus.h"
#include "mlx.h"

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
	ft_fract_init(av[1], &fract);
	ft_chk_px(&fract);
	mlx_hook(fract.parent_window, 2, (1L << 0), ft_keydown, &fract);
	mlx_hook(fract.parent_window, 4, (1L << 2), ft_mouse_hook, &fract);
	mlx_hook(fract.parent_window, 17, (1L << 0), ft_destroy_it, &fract);
	mlx_hook(fract.parent_window, 6, (1L << 6), ft_m_move, &fract);
	mlx_loop(fract.prog);
}
