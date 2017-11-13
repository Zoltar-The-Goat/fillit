/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 09:54:21 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 23:26:02 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"


// has problems covering same square or going right to left
int			istrino(char *piece, int s, int c)
{
	if(piece[s])
	{
		if (piece[s] == '#')
			return ((istrino(piece, s + 1, c + 1) + istrino(piece, s + 5, c + 1)) + 1);
		else if(c == 0)
			return (istrino(piece, s + 1, c));
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