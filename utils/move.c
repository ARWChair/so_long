/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:56:23 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:38:02 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	d_move(t_main *main)
{
	if (main->map.sceleton[main->map.ppos + get_line_len(main)] != '1')
	{
		if (main->map.sceleton[main->map.ppos + get_line_len(main)] == '0')
		{
			main->map.sceleton[main->map.ppos + get_line_len(main)] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.ppos += get_line_len(main);
		}
		else if (main->map.sceleton[main->map.ppos + get_line_len(main)] == 'C')
		{
			main->map.sceleton[main->map.ppos + get_line_len(main)] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.ppos += get_line_len(main);
		}
		else if (main->map.sceleton[main->map.ppos + get_line_len(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_program(main);
			else
				main->map.moves--;
		}
		ft_printf("Moves: %i\n", main->map.moves++);
	}
}

void	u_move(t_main *main)
{
	if (main->map.sceleton[main->map.ppos - get_line_len(main)] != '1')
	{
		if (main->map.sceleton[main->map.ppos - get_line_len(main)] == '0')
		{
			main->map.sceleton[main->map.ppos - get_line_len(main)] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.ppos -= get_line_len(main);
		}
		else if (main->map.sceleton[main->map.ppos - get_line_len(main)] == 'C')
		{
			main->map.sceleton[main->map.ppos - get_line_len(main)] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.ppos -= get_line_len(main);
		}
		else if (main->map.sceleton[main->map.ppos - get_line_len(main)] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_program(main);
			else
				main->map.moves--;
		}
		ft_printf("Moves: %i\n", main->map.moves++);
	}
}

void	r_move(t_main *main)
{
	if (main->map.sceleton[main->map.ppos + 1] != '1')
	{
		if (main->map.sceleton[main->map.ppos + 1] == '0')
		{
			main->map.sceleton[main->map.ppos + 1] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.ppos++;
		}
		else if (main->map.sceleton[main->map.ppos + 1] == 'C')
		{
			main->map.sceleton[main->map.ppos + 1] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.ppos++;
		}
		else if (main->map.sceleton[main->map.ppos + 1] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_program(main);
			else
				main->map.moves--;
		}
		ft_printf("Moves: %i\n", main->map.moves++);
	}
}

void	l_move(t_main *main)
{
	if (main->map.sceleton[main->map.ppos - 1] != '1')
	{
		if (main->map.sceleton[main->map.ppos - 1] == '0')
		{
			main->map.sceleton[main->map.ppos - 1] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.ppos--;
		}
		else if (main->map.sceleton[main->map.ppos - 1] == 'C')
		{
			main->map.sceleton[main->map.ppos - 1] = 'P';
			main->map.sceleton[main->map.ppos] = '0';
			main->map.coll.current++;
			main->map.ppos--;
		}
		else if (main->map.sceleton[main->map.ppos - 1] == 'E')
		{
			if (main->map.coll.amount == main->map.coll.current)
				close_program(main);
			else
				main->map.moves--;
		}
		ft_printf("Moves: %i\n", main->map.moves++);
	}
}
