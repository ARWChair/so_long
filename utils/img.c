/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:38:32 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:55:19 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	first_render(t_main *main)
{
	int	i;
	int	j;

	j = 0;
	while (j <= main->map.maxheight)
	{
		i = 0;
		while (i <= main->map.maxlen)
		{
			mlx_put_image_to_window(main->mlx, main->win,
				main->sp.wall.img, i * 40, j * 40);
			i++;
		}
		j++;
	}
}

int	render_next_frame(t_main *main)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = (((main->map.maxheight * 40) - (main->map.mapheight * 40)) / 2);
	while (i < main->map.maxheight * 40)
	{
		j = (((main->map.maxlen * 40) - (main->map.maplen * 40)) / 2);
		while (j < main->map.maxlen * 40)
		{
			check_for_image(counter, main, j, i);
			if (main->map.sceleton[counter] == '\0')
				break ;
			if (main->map.sceleton[counter] == '\n')
				j += 1000;
			j += 40;
			counter++;
		}
		i += 40;
	}
	return (0);
}

void	render_image(t_main *main)
{
	main->sp.floor.img = mlx_xpm_file_to_image(main->mlx,
			"./Textures/floor.xpm", &main->sp.floor.imw, &main->sp.floor.imh);
	main->sp.player.img = mlx_xpm_file_to_image(main->mlx,
			"./Textures/player.xpm",
			&main->sp.player.imw, &main->sp.player.imh);
	main->sp.collectableim.img = mlx_xpm_file_to_image(main->mlx,
			"./Textures/collectable.xpm",
			&main->sp.collectableim.imw, &main->sp.collectableim.imh);
	main->sp.exit.img = mlx_xpm_file_to_image(main->mlx,
			"./Textures/door.xpm", &main->sp.exit.imw, &main->sp.exit.imh);
	main->sp.wall.img = mlx_xpm_file_to_image(main->mlx,
			"./Textures/wall.xpm", &main->sp.wall.imw, &main->sp.wall.imh);
}

void	check_for_image(int counter, t_main *main, int j, int i)
{
	if (main->map.sceleton[counter] == '0')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.floor.img, j, i);
	else if (main->map.sceleton[counter] == 'P')
		mlx_put_image_to_window(main->mlx,
			main->win, main->sp.player.img, j, i);
	else if (main->map.sceleton[counter] == 'C')
		mlx_put_image_to_window(main->mlx, main->win,
			main->sp.collectableim.img, j, i);
	else if (main->map.sceleton[counter] == 'E')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.exit.img, j, i);
	else if (main->map.sceleton[counter] == '1')
		mlx_put_image_to_window(main->mlx, main->win, main->sp.wall.img, j, i);
}
