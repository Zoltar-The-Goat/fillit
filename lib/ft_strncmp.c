/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:51:08 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 08:23:42 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int c;

	c = 0;
	while (s1[c] == s2[c] && s1[c] && s2[c] && c < (int)n)
		c++;
	if (c == (int)n)
		c--;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
