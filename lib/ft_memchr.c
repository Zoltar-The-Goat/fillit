/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:15:08 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 01:24:17 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char bit;
	char *str;

	str = (char *)s;
	bit = (char)c;
	while (n--)
	{
		if (*str == bit)
			return (str);
		str++;
	}
	return (NULL);
}
