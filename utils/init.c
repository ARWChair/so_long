/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:52:45 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:56:14 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_keypress(int keysym, t_main *main)
{
	if (keysym == 0xff1b)
		close_program(main);
	else if (keysym == 100)
		r_move(main);
	else if (keysym == 97)
		l_move(main);
	else if (keysym == 119)
		u_move(main);
	else if (keysym == 115)
		d_move(main);
	return (0);
}

void	free_map(t_main *main)
{
	free(main->map.sceleton);
	free(main->sp.floor.img);
	free(main->sp.exit.img);
	free(main->sp.collectableim.img);
	free(main->sp.player.img);
	free(main->sp.wall.img);
}

void	free_window(t_main *main)
{
	free(main->win);
	free(main->mlx);
	free(main);
}

int	close_program(t_main *main)
{
	mlx_destroy_display(main->mlx);
	free_map(main);
	free_window(main);
	exit(0);
	return (0);
}

void	init_win(t_main *main, char *map)
{
	int		fd;
	char	*temp;
	char	*map2;
	int		nls;

	fd = open(map, O_RDONLY);
	temp = loadmap(fd);
	map2 = ft_strdup(temp);
	main->map.sceleton = map2;
	main->map.maxlen = 34;
	main->map.maxheight = 17;
	render_image(main);
	first_render(main);
	nls = get_newlines(map2) + 1;
	init_error(main, nls);
	close(fd);
	free(temp);
	main->map.mapheight = get_map_hight(main->map.sceleton);
	main->map.moves = 1;
	main->map.maplen = get_line_len(main);
	main->map.ppos = get_player_pos(main);
	main->map.coll.amount = get_collectable_count(main);
	main->map.coll.current = 0;
}
