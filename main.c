/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoltar <Zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 00:31:17 by Zoltar            #+#    #+#             */
/*   Updated: 2017/11/12 05:09:19 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libft.h"
#include "includes/fillit.h"

int	main(int ac, char ** av)
{
	int fd;
	if (ac == 2)
	{
		if(get_pieces(av[1]))
		{
			close(fd);
			return (0);
		}
	}
	write(2, "error", 5);
	return (1);
}