/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:30 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/13 04:03:19 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

// return an LxW size for the piece
static int	dimensions(char *piece)
{
	int l;
	int w;
	int x;

	x = 0;
	l = 0;
	if (piece && piece[0] != '\0')
	{
		while(piece[x] != '\n')
		{
			while(piece[x] && x < 20)
			{
				// printf("X : %d,\tL : %d\n", x, l);
				if((piece[x] >= 'A' && piece[x] <= 'Z'))
				{
					l++;
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
			// printf("\n");
			// printf("\tX : %d,\tL : %d\n\n", x, l);
		}

		// //check width
		// x = 0;
		w = 0;
		// while(piece[x])
		// {
		// 	while(piece[x] != '\n')
		// 	{
		// 		if((piece[x] >= 'A' && piece[x] <= 'Z'))
		// 		{
		// 			w++;
		// 			while(x % 5 != 0)
		// 				x--;
		// 			x += 5;
		// 		}
		// 		else
		// 			x++;
		// 	}
		// 	while(x % 5 != 0)
		// 		x--;
		// 	x += 5;
		// }
		return((l * 10) + w);
	}
	return(0);
}
// create an alpha label the piece
static char	label(char c, int num)
{
	if(!c)
		return('\0');
	else if(c == '#')
		return(num + 65);
	else
		return(c);
}

/*
	creates a 2d array and fills with a given piece

	however a bug when setting each peice, fills previous
*/
int			get_pieces(char *file)
{
	int ret;
	int i;
	int num_piece;
	int fd;

	char c;
	char *piece;

	char **piece_arr;

	i = 0;
	num_piece = 0;
	fd = open(file, O_RDONLY);
	if(!(is_valid(fd)))
		return (0);
	fd = open(file, O_RDONLY);
	piece = (char *)ft_memalloc(sizeof(char) * 21);
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
			piece_arr[num_piece] = (char *)ft_memalloc(sizeof(char) * i++);
			// printf("trino_num :%d\n", istrino(piece, 0, 0));
			// if(istrino(piece, 0, 0) == 4)
				while(--i >= 0)
					piece_arr[num_piece][i] = label(piece[i], num_piece);
			// else
			// 	return (0);
			num_piece++;
			i = -2;
		}
	}

	piece_arr[num_piece] = "\0";
	printf("%s\t 0\n\n", piece_arr[0]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[0]));

	printf("%s\t 1\n\n", piece_arr[1]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[1]));

	printf("%s\t 2\n\n", piece_arr[2]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[2]));

	printf("%s\t 3\n\n", piece_arr[3]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[3]));

	printf("%s\t 4\n\n", piece_arr[4]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[4]));

	printf("%s\t 5\n\n", piece_arr[5]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[5]));

	printf("%s\t 6\n\n", piece_arr[6]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[6]));

	printf("%s\t 7\n\n", piece_arr[7]);
	printf("Lxw: %d\n--------------\n", dimensions(piece_arr[7]));
	free(piece);
	free(piece_arr);
	if(ret == 0)
		return (1);
	else
		return (0);
}



// printf("%s\t 0\n\n", piece_arr[0]);
// printf("%s\t 1\n\n", piece_arr[1]);
// printf("%s\t 2\n\n", piece_arr[2]);
// printf("%s\t 3\n\n", piece_arr[3]);
// printf("%s\t 4\n\n", piece_arr[4]);
// printf("%s\t 5\n\n", piece_arr[5]);
// printf("%s\t 6\n\n", piece_arr[6]);
// printf("%s\t 7\n\n", piece_arr[7]);
// printf("---------------------------------------\n");