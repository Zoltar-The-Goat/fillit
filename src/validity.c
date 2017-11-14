/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:54:21 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/14 12:17:28 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

int			istrino(char *piece, int c)
{
	int x;

	x = 0;
	while(piece[x])
	{
		if (piece[x] == '#')
			c++;
		x++;
	}
	if (c == 4)
	{
		x = -1;
		while(piece[++x])
			if(piece[x] == '#' && (!(piece[x + 1] == '#' ||
									piece[x - 1] == '#' ||
									piece[x + 5] == '#' ||
									piece[x - 5] == '#')))
				return (0);
		return (c);
	}
	return (0);
}

int			is_valid(int fd)
{
	int ret;
	int x;
	int count;
	char c;

	x = 1;
	count = 0;
	while ((ret = read(fd, &c, BUF)) > 0)
	{
		if (c != '\n' && c != '#' && c != '.')
			return (0);
		else if (((x) % 5 == 0) && (c != '\n'))
			return (0);
		else if (x > 19 && c != '\n')
			return (0);
		else if (x == 21)
			x = 0;
		x++;
	}
	close(fd);
	if (x != 20)
		return (0);
	return (1);
}
