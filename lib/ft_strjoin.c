/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:53:12 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 02:09:19 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		c;
	int		i;

	i = -1;
	c = -1;
	if (s1 && s2)
	{
		n_str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (n_str)
		{
			while (s1[++c])
				n_str[c] = s1[c];
			c--;
			while (s2[++i])
				n_str[++c] = s2[i];
			n_str[++c] = '\0';
			return (n_str);
		}
	}
	return (NULL);
}
