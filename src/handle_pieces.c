/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:30 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/14 13:11:06 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

int			find_shape(char *piece, int num)
{
	int empty;
	int corner;
	int x;
	int y;

	empty = 0;
	y = 0;
	x = 19;
	while (!(piece[x] >= 'A' && piece[x] <= 'Z'))
		x--;
	if (piece[x - 4] == (piece[x] >= 'A' && piece[x] <= 'Z') ||
		piece[x - 8] == (piece[x] >= 'A' && piece[x] <= 'Z') ||
		piece[x - 12] == (piece[x] >= 'A' && piece[x] <= 'Z'))
		x++;
	corner = x;
	x = corner - (5 * (1 - (num % 10))) - (1 - (num / 10));
	while (x + y <= corner)
	{
		if ((y == num % 10) && (y % 2 == 0))
		/**/x += 2;
		else if (y == num % 10)
		/**/x += 1;
		if (piece[x + y] == '.' && empty == 0)
			empty = y * 10;
		else if (piece[x + y] == '.')
			empty = empty + y;
		y++;
	}
	return (empty);
}

// return an LxW size for the piece
static int	dimensions(char *piece, int *empty)
{
	int x;
	int num;

	x = 0;
	num = 0;
	while(piece[x] != '\n')
	{
		while(piece[x])// && x < 20)
		{
			if(piece[x] >= 'A' && piece[x] <= 'Z')
			{
				num++;
				while(x > 4)
					x -= 5;
				if(x != 4)
					x++;
			}
			else
				x += 5;
		}
		while(x > 4)
			x -= 5;
		if(x != 4)
			x++;
	}

	//check width
	x = 0;
	num *= 10;
	while(piece[x])
	{
		if(piece[x] >= 'A' && piece[x] <= 'Z')
		{
			num++;
			while(x % 5 != 0)
				x--;
			x += 5;
		}
		else
			x++;
	}
	if ((num / 10) * (num % 10) != 4)
		*empty = find_shape(piece, num);
	return (num);
}

// create an alpha label the piece
static char	*label(char *piece, int c)
{
	int x;

	x = 0;
	if(!piece)
		return(NULL);
	while(piece[x])
	{
		if(piece[x] == '#')
			piece[x] = c + 65;
		x++;
	}
	return(piece);
}

/*
	creates a 2d array and fills with a given piece
*/
int			get_pieces(char *file)
{
	int ret;
	int i;
	int num_piece;
	int fd;
	int empty;
	char c;
	char *piece;
	char **piece_arr;

	i = 0;
	num_piece = 0;
	empty = 0;
	fd = open(file, O_RDONLY);
	if(!(is_valid(fd)))
		return (0);
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, &c, BUF)) > 0)
	{
		if (c == '\n')
			i++;
		if (i > 0 && (i % 5) == 0)
		{
			i = 0;
			num_piece++;
		}
	}
	if(ret != 0)
		return (0);
	num_piece++;
	close(fd);

	fd = open(file, O_RDONLY);
	piece = (char *)ft_memalloc(sizeof(char) * 19);
	piece_arr = (char **)ft_memalloc(sizeof(char *) * num_piece + 1);
	i = 0;
	num_piece = 0;
	while ((ret = read(fd, &c, BUF)) > 0)
	{
		if(i >= 0)
			piece[i] = c;
		if(i++ == 18)
		{
			piece[i] = '\0';
			if(istrino(piece, 0) == 4)
				piece_arr[num_piece] = label(piece, num_piece);
			else
				return (0);
			piece = (char *)ft_memalloc(sizeof(char) * 19);
			num_piece++;
			i = -2;
		}
	}
	piece_arr[num_piece] = "\0";
	int z = -1;
	while(piece_arr[++z] && z < num_piece)
	{
		printf("%s\t %d\n\n", piece_arr[z], z);
		printf("Lxw: %d, empty: %d\n", dimensions(piece_arr[z], &empty), empty);
		printf("---------------------------------------\n\n");
	}

	free(piece);
	free(piece_arr);
	if(ret == 0)
		return (1);
	else
		return (0);
}
