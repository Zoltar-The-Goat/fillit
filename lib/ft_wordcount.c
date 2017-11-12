/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 20:13:27 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 11:38:14 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char *s, char c)
{
	int i;
	int flag;
	int num;

	i = 0;
	num = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			flag = 0;
		}
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			num++;
		}
		i++;
	}
	return (num);
}
