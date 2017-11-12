/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:53:38 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 02:06:47 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret_s;
	char	*original;
	int		total;
	int		first_c;
	int		last_c;

	if (s)
	{
		original = (char *)s;
		total = ft_strlen(s);
		while (ft_isspace(*s))
			s++;
		first_c = total - ft_strlen(s);
		while (*s)
			s++;
		s--;
		while (ft_isspace(*s))
			s--;
		last_c = total - ft_strlen(s);
		ret_s = ft_alt_strsub(original, first_c, last_c);
		if (ret_s)
			return (ret_s);
	}
	return (NULL);
}
