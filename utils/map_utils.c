/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatabay <yatabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:20:58 by yatabay           #+#    #+#             */
/*   Updated: 2022/11/29 22:57:31 by yatabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	len(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		leftcount;
	int		rightcount;

	leftcount = 0;
	rightcount = 0;
	newstr = malloc(sizeof(char) * ((len(s1) + len(s2)) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[leftcount])
	{
		newstr[leftcount] = s1[leftcount];
		leftcount++;
	}
	while (s2[rightcount])
	{
		newstr[leftcount] = s2[rightcount];
		leftcount++;
		rightcount++;
	}
	newstr[leftcount] = '\0';
	return (newstr);
}

void	*cal_memset(void *s, int c, size_t n)
{
	char	*src;

	src = s;
	while (n--)
		*src++ = (char)c;
	return (s);
}

void	*fr_calloc(size_t nmemb, size_t size)
{
	void	*newstr;
	size_t	total;

	total = nmemb * size;
	newstr = malloc(total);
	if (newstr == NULL)
		return (0);
	cal_memset(newstr, 0, total);
	return ((void *)newstr);
}
