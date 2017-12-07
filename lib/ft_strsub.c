/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:52:44 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 02:01:16 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*n_str;
	int		c;

	if (s)
	{
		c = -1;
		n_str = (char *)ft_memalloc(len + 1);
		if (n_str)
		{
			while (++c < (int)len)
			{
				n_str[c] = s[start];
				start++;
			}
			n_str[c] = '\0';
			return (n_str);
		}
		free(n_str);
	}
	return (NULL);
}
