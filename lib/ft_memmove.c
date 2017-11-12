/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:14:27 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 01:18:54 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *o_dst;
	char *n_src;
	char *n_dst;

	o_dst = dst;
	n_src = (char *)src;
	n_dst = (char *)dst;
	if (dst < src)
	{
		while (len--)
			*n_dst++ = *n_src++;
	}
	else
	{
		while (len--)
			n_dst[len] = n_src[len];
	}
	return (o_dst);
}
