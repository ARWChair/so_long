/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:54:32 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:53:42 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_line_len(t_main *main)
{
	int		counter;

	counter = 0;
	while (main->map.sceleton[counter])
	{
		if (main->map.sceleton[counter] == '\n')
		{
			counter++;
			break ;
		}
		counter++;
	}
	return (counter);
}

int	get_map_hight(char *map)
{
	int		counter;
	int		pos;

	counter = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[pos] == '\n')
			counter++;
		pos++;
	}
	return (counter);
}

int	get_player_pos(t_main *main)
{
	int		pos;

	pos = 0;
	while (main->map.sceleton[pos])
	{
		if (main->map.sceleton[pos] == 'P')
			return (pos);
		pos++;
	}
	return (0);
}

int	get_collectable_count(t_main *main)
{
	int		counter;
	int		pos;

	counter = 0;
	pos = 0;
	while (main->map.sceleton[pos])
	{
		if (main->map.sceleton[pos] == 'C')
			counter++;
		pos++;
	}
	return (counter);
}
