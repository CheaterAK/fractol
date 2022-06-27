/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:46:28 by akocabas          #+#    #+#             */
/*   Updated: 2022/06/27 17:27:36 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fract_bonus.h"

void	ft_error_message(void)
{
	printf("Usage: ./fractol [fratals] [preset for julia]\n WARNING: \nIf you \
don't use a preset, the imaginary number and the real number are treated as 0.\
\n fratals :\n---> Mandelbrot\n---> Julia\n---> Burningship\n---> Tricorn\n pr\
esets:\n---> 1 = 0, 0.8i\n---> 2 = -0.4, -0.6i\n---> 3 = -0.70176, -0.3842i\n-\
--> 4 = 0.285, 0.01i\nExample Code : ./fractol Julia 2\n");
}

void	ft_invalid_julia(void)
{
	printf("Invalid julia preset\nTry valid one following like in the guide.\n");
	ft_error_message();
	exit(1);
}

void	ft_invalid_fract(void)
{
	printf("Invalid fractol\nTry valid one following like in the guide.\n");
	ft_error_message();
	exit(1);
}
