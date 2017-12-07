/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:13:00 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 05:39:26 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *n_src;
	unsigned char *n_dst;

	n_src = (unsigned char *)src;
	n_dst = (unsigned char *)dst;
	while (n--)
		*n_dst++ = *n_src++;
	return (dst);
}
