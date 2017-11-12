/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:48:16 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 02:13:34 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		len--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
