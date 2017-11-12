/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:50:25 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 05:35:42 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reset(int *pos1, int *pos2, int last_pos)
{
	*pos1 = last_pos;
	*pos2 = 0;
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int pos1;
	int pos2;
	int last_pos;

	pos1 = 0;
	pos2 = 0;
	if (little[0] == '\0')
		return (char *)(big);
	while (big[pos1] != '\0' && pos1 < (int)len)
	{
		if (big[pos1] == little[pos2])
		{
			last_pos = pos1;
			while (big[pos1] == little[pos2] && pos1 < (int)len)
			{
				pos1++;
				pos2++;
				if (little[pos2] == '\0')
					return (&(((char *)big)[last_pos]));
			}
			reset(&pos1, &pos2, last_pos);
		}
		pos1++;
	}
	return (NULL);
}
