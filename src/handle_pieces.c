/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:30 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/16 19:03:30 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

int			ret_empty(char *piece, int num)
{
	int empty;
	int corner;
	int x;
	int y;

	empty = -1;
	y = 0;
	x = 19;
	while (!(piece[x] >= 'A' && piece[x] <= 'Z'))
		x--;
	if (piece[x - 4] >= 'A' && piece[x - 4] <= 'Z')
	 	x++;
	corner = x;
	x = corner - ((5 * ((num % 10) - 1)) + ((num / 10) - 1));
	printf("x: %d, corner: %d\n\n", x, corner);
	while (x + y <= corner)
	{
		if ((y == num % 10 && y % 2 == 0) || (y == num % 10 && y % 3 == 0))
			x = (x - y) + 5;
		if (piece[x + y] == '.' && empty == -1)
			empty = y * 10;
		else if (piece[x + y] == '.')
			empty = empty + y;
		printf("x: %d, y: %d, empty: %d\n", x, y, empty);
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
		*empty = ret_empty(piece, num);
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

	// printf("%s\t %d\n\n", piece_arr[3], 3);
	// printf("\nLxw: %d, empty: %d\n", dimensions(piece_arr[3], &empty), empty);
	// printf("---------------------------------------\n\n");

	int z = -1;
	while(piece_arr[++z] && z < num_piece)
	{
		printf("%s\t %d\n\n", piece_arr[z], z);
		printf("\nLxw: %d, empty: %d\n", dimensions(piece_arr[z], &empty), empty);
		printf("---------------------------------------\n\n");
	}

	free(piece);
	free(piece_arr);
	if(ret == 0)
		return (1);
	else
		return (0);
}
