/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoltar <zoltar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 01:55:10 by zoltar            #+#    #+#             */
/*   Updated: 2017/11/07 02:00:16 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *n_str;

	if (!(n_str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	ft_memset(n_str, (int)'\0', size + 1);
	return (n_str);
}
