/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:55:13 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/12 03:13:58 by Zoltar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_real_split(char **split_arr, char *str, char c, size_t w_count)
{
	size_t		i;
	size_t		start;
	size_t		curr_count;

	i = 0;
	start = 0;
	curr_count = 0;
	while (str[i] != '\0' && curr_count < w_count)
	{
		if (str[i] != c)
		{
			start = i;
			while (str[i] != c && str[i] != '\0')
				i++;
			split_arr[curr_count] = ft_strsub(str, start, i - start);
			curr_count++;
		}
		else
			i++;
	}
	split_arr[curr_count] = NULL;
	return (split_arr);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret_arr;
	size_t count;

	if (!s)
		return (NULL);
	count = ft_wordcount((char*)s, c);
	ret_arr = NULL;
	if ((ret_arr = (char **)ft_memalloc(sizeof(char *) * count + 1)) == NULL)
		return (NULL);
	ret_arr = ft_real_split(ret_arr, (char *)s, c, count);
	return (ret_arr);
}