/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:29:12 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 23:40:05 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_error(t_main *main, int lines)
{
	int	init;

	init = 0;
	if (check_for_ascii(main->map.sceleton, 'P') == 1)
		init++;
	if (check_for_ascii(main->map.sceleton, 'E') == 1)
		init++;
	if (check_for_equal(main, lines, 0, 0) == 1)
		init++;
	if (surround_by_walls(main->map.sceleton, lines, 0, 1) == 1)
		init++;
	if (move_and_check(main) == 1)
		init++;
	if (init != 5)
	{
		ft_printf("Error\nMap is invalid, please try a diffrent one");
		close_program(main);
	}
}

int	move_and_check(t_main *main)
{
	int		ppos;
	int		current;
	int		maxrounds;
	char	*dup;

	current = 0;
	ppos = get_player_pos(main);
	dup = ft_strdup(main->map.sceleton);
	maxrounds = max_rounds(main, dup);
	dup = first_replace(ppos, dup, main);
	while (current < maxrounds)
	{
		if (check_for_error_exit(dup, main) == 1)
		{
			free(dup);
			return (1);
		}
		dup = check_and_replace(dup, main);
		current++;
	}
	free(dup);
	return (0);
}

int	check_for_equal(t_main *main, int lines, int currentline, int linelentotal)
{
	int	linelencurrent;
	int	counter;

	currentline = 0;
	linelentotal = get_line_len(main) - 1;
	counter = 0;
	linelencurrent = 0;
	while (currentline < lines)
	{
		while (main->map.sceleton[counter])
		{
			if (main->map.sceleton[counter] == '\n')
			{
				if (linelencurrent != linelentotal)
					return (0);
				counter++;
				linelencurrent = 0;
				break ;
			}
			counter++;
			linelencurrent++;
		}
		currentline++;
	}
	return (1);
}
