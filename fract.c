/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocabas <akocabas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:56:17 by akocabas          #+#    #+#             */
/*   Updated: 2022/05/21 12:33:17 by akocabas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fract.h"
#include "minilibx_macos/mlx.h"

t_fract	fract_init(char *fract_name)
{
	t_fract		fract;
	t_complex	c;
	t_complex	z;

	write(1, "kod burada2.1", 13);
	if (!strcmp(fract_name, "Mandelbrot"))
	{
		write(1, "kod burada2.2", 13);
		fract.max_iteration = 300;
		write(1, "kod burada2 gecti", 18);
	}
	write(1, "kod burada2.3", 13);
	return (fract);
	}

int	color(int o, int r, int g, int b)
{
	r = (r * 10) % 256;
	g = (g * 20) % 256;
	b = (b * 30) % 256;
	return (o << 24 | r << 16 | g << 8 | b);
}

int	algo(t_fract *fract, int x, int y)
{
	int		iter;
	double	r_sqr;
	double	i_sqr;

	write(1, "kod burada4.1", 13);
	fract->z.i = -2.0 + x * 4.0 / (600);
	fract->z.r = -2.0 + y * 4.0 / (600);
	fract->c.i = 0;
	fract->c.r = 0;
	iter = 0;
	r_sqr = 0;
	i_sqr = 0;
	write(1, "kod burada4.2", 13);
	while (r_sqr + i_sqr <= 4 && iter < fract->max_iteration)
	{
		fract->z->i = 2 * (fract->z->i * fract->z->r) + fract->c->i;
		fract->z->r = r_sqr - i_sqr + fract->c->r;
		r_sqr = fract->z->r * fract->z->r;
		i_sqr = fract->z->i * fract->z->i;
		iter++;
	}
	write(1, "kod burada4.3", 13);
	return (iter);
}

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	draw_fract(t_data *img, t_fract *fract)
{
	int		iter;
	int		x;
	int		y;

	write(1, "kod burada3.1", 13);
	x = 0;
	y = 0;
	while (x < 600)
	{
		while (y < 600)
		{
			write(1, "kod burada3.2", 13);
			iter = algo(fract, x, y);
			write(1, "kod burada3.3", 13);
			if (iter < fract->max_iteration)
				my_put_pixel(img, x, y, color(0, iter, iter, iter));
			else
				my_put_pixel(img, x, y, 0x000000);
			y++;
			write(1, "kod burada3.4", 13);
		}
		y = 0;
		x++;
	}
}

int	main(int ac, char *av[])
{
	void	*prog;
	void	*parent_window;
	t_data	img;
	t_fract	fract;

	write(1, "kod burada1", 11);
	if (ac < 2)
	{
		printf("duzgun gir fractal giriniz. './fract help' komutunu deneyin");
		return (1);
	}
	prog = mlx_init();
	parent_window = mlx_new_window(prog, 600, 600, "first_prog");
	img.img = mlx_new_image(prog, 600, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	write(1, "kod burada2", 11);
	fract = fract_init(av[1]);
	write(1, "kod burada3", 11);
	draw_fract(&img, &fract);
	mlx_put_image_to_window(prog, parent_window, img.img, 0, 0);
	mlx_loop(prog);
}
