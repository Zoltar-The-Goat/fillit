/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:17 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 02:30:03 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "includes/fillit.h"

int	main(int ac, char ** av)
{
	int fd;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			if(get_pieces(fd))
			{
				close(fd);
				return (0);
			}
		}
	}
	write(2, "error", 5);
	return (1);
}