/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:04:22 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 23:39:50 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_main		*main;

	if (argc <= 1)
	{
		ft_printf("Error\nMap is invalid, please try a diffrent one");
		exit(1);
	}
	main = (t_main *)malloc(sizeof(t_main));
	main->mlx = mlx_init();
	main->win = mlx_new_window(main->mlx, 1360, 680, "Dungeon crawler");
	init_win(main, argv[1]);
	mlx_hook(main->win, 2, 1L, handle_keypress, main);
	mlx_hook(main->win, 17, 0, close_program, main);
	mlx_loop_hook(main->mlx, render_next_frame, main);
	mlx_loop(main->mlx);
	return (0);
}
