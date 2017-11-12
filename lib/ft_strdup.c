/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 04:19:29 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 01:28:33 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char *dest;

	dest = (char *)ft_memalloc(ft_strlen(src) + 1);
	if (dest)
		return (ft_strcpy(dest, src));
	return (NULL);
}
