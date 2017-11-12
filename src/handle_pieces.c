/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:30 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 03:22:02 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"
#include "../includes/fillit.h"

// int	is_valid(char *piece)
// {
//
//
// }

int	get_pieces(int fd)
{
	int ret;
	int i;
	int num_piece;

	char c;
	char *piece;

	char **piece_arr;

	i = 0;
	num_piece = 0;
	if((piece = (char *)ft_memalloc(sizeof(char) * 20)))
	{
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
	}
	// keep only if no '\n' at eof
	num_piece++;

	i = 0;
	if ((piece_arr = (char **)ft_memalloc(sizeof(char *) * num_piece + 1)))
	{
		printf("make it?\n");
		num_piece = 0;
		while ((ret = read(fd, &c, BUF)) > 0)
		{
			printf("ret = %d : c = %c\n", ret, c);
			piece[i] = c;
			if(i++ == 18)
			{
				piece[i] = '\0';
				printf("%s\n", piece);
				piece_arr[num_piece] = piece;
				num_piece++;
				i = 0;
			}
		}
		printf("ret = %d : c = %c\n", ret, c);
	}
	// if(ret == 0)
	// 	// success
	// else
	// 	// failure

	return (1);
}