/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:30 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 05:57:53 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

// int	is_valid(char *piece)
// {
//
//
// }

int	get_pieces(char *file)
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
	piece = (char *)ft_memalloc(sizeof(char) * 21);
	while((ret = read(fd, &c, BUF)) > 0)
	{
		if(c == '\n')
			i++;
		if(i > 0 && (i % 5) == 0)
		{
			i = 0;
			num_piece++;
		}
	}
	// keep only if no '\n' at eof
	num_piece++;
	close(fd);


	fd = open(file, O_RDONLY);
	i = 0;
	piece_arr = (char **)ft_memalloc(sizeof(char *) * num_piece + 1);
	num_piece = 0;
	while ((ret = read(fd, &c, BUF)) > 0)
	{
		if(i >= 0)
			piece[i] = c;
		if(i++ == 18)
		{
			piece[i] = '\0';
			piece_arr[num_piece] = piece;
			printf("%s\t num :%d\n\n", piece_arr[num_piece], num_piece);
			num_piece++;
			i = -2;
		}
	}
	if(i++ == 19)
	{
		piece[i] = '\0';
		piece_arr[num_piece] = piece;
		printf("%s\t num :%d\n\n", piece_arr[num_piece], num_piece);
		num_piece++;
		i = -1;
	}


	printf("%s, 0\n\n", piece_arr[0]);
	printf("%s, 1\n\n", piece_arr[1]);
	printf("%s, 2\n\n", piece_arr[2]);
	printf("%s, 3\n\n", piece_arr[3]);
	printf("%s, 4\n\n", piece_arr[4]);
	printf("%s, 5\n\n", piece_arr[5]);
	printf("%s, 6\n\n", piece_arr[6]);
	printf("%s, 7\n\n", piece_arr[7]);


	// if(ret == 0)
	// 	// success
	// else
	// 	// failure

	return (1);
}












// printf("%s, 0\n\n", piece_arr[0]);
// printf("%s, 1\n\n", piece_arr[1]);
// printf("%s, 2\n\n", piece_arr[2]);
// printf("%s, 3\n\n", piece_arr[3]);
// printf("%s, 4\n\n", piece_arr[4]);
// printf("%s, 5\n\n", piece_arr[5]);
// printf("%s, 6\n\n", piece_arr[6]);
// printf("%s, 7\n\n", piece_arr[7]);