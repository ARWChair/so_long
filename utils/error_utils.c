/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:24:18 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:49:09 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	max_rounds(t_main *main, char *map)
{
	int	len;
	int	high;
	int	total;

	len = get_line_len(main);
	high = get_newlines(map);
	total = len * high;
	return (total);
}

char	*first_replace(int ppos, char *dup, t_main *main)
{
	if (dup[ppos] == 'P')
	{
		if (dup[ppos - 1] == 'C' || dup[ppos - 1] == '0')
			dup[ppos - 1] = 'X';
		if (dup[ppos + 1] == 'C' || dup[ppos + 1] == '0')
			dup[ppos + 1] = 'X';
		if (dup[ppos - get_line_len(main)] == 'C'
			|| dup[ppos - get_line_len(main)] == '0')
			dup[ppos - get_line_len(main)] = 'X';
		if (dup[ppos + get_line_len(main)] == 'C'
			|| dup[ppos + get_line_len(main)] == '0')
			dup[ppos + get_line_len(main)] = 'X';
	}
	return (dup);
}

char	*check_and_replace(char *dup, t_main *main)
{
	int	counter;

	counter = 0;
	while (dup[counter])
	{
		if (dup[counter] == 'X')
		{
			if (dup[counter - 1] == '0' || dup[counter - 1] == 'C')
				dup[counter - 1] = 'X';
			else if (dup[counter + 1] == '0' || dup[counter + 1] == 'C')
				dup[counter + 1] = 'X';
			if (dup[counter - get_line_len(main)] == '0'
				|| dup[counter - get_line_len(main)] == 'C')
				dup[counter - get_line_len(main)] = 'X';
			if (dup[counter + get_line_len(main)] == '0'
				|| dup[counter + get_line_len(main)] == 'C')
				dup[counter + get_line_len(main)] = 'X';
		}
		counter++;
	}
	return (dup);
}

int	check_for_error_exit(char *dup, t_main *main)
{
	int	counter;

	counter = 0;
	while (dup[counter])
	{
		if (dup[counter] == 'X')
		{
			if (dup[counter - 1] == 'E' || dup[counter + 1] == 'E'
				|| dup[counter - get_line_len(main)] == 'E'
				|| dup[counter + get_line_len(main)] == 'E')
				return (1);
		}
		counter++;
	}
	return (0);
}
