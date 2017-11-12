/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoltar <zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 01:42:48 by zoltar            #+#    #+#             */
/*   Updated: 2017/11/07 02:02:29 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *n_mem;

	n_mem = (void *)malloc(size);
	if (n_mem)
		ft_bzero(n_mem, size);
	return (n_mem);
}
