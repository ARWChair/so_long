/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:13:18 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:57:20 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*free_dict(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*loadmap(int fd)
{
	static char	*dict;
	char		*buffer;
	int			byte_read;

	if (!dict)
		dict = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		dict = free_dict(dict, buffer);
	}
	free(buffer);
	return (dict);
}

int	get_newlines(char *map)
{
	int	counter;
	int	pos;

	counter = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[pos] == '\n' && (map[pos + 1] != '\0' && map[pos + 1] != '\n'))
			counter++;
		pos++;
	}
	return (counter);
}

int	check_for_ascii(char *map, int symbol)
{
	int	found;
	int	pos;

	found = 0;
	pos = 0;
	while (map[pos])
	{
		if (map[pos] == symbol)
			found++;
		pos++;
	}
	return (found);
}

int	surround_by_walls(char *map, int lines, int passed, int valid)
{
	int	counter;

	counter = 0;
	while (map[counter])
	{
		if (map[counter] == '\n')
		{
			if (passed < lines - 1)
			{
				if (map[counter + 1] != '1' || map[counter - 1] != '1')
					valid = 0;
			}
			passed++;
			counter++;
		}
		if (passed == 0 || passed == lines - 1)
		{
			if (map[counter] != '1')
				valid = 0;
		}
		counter++;
	}
	return (valid);
}
