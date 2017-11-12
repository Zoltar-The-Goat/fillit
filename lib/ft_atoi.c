/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:13:48 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 05:49:00 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_atoi_space(char c)
{
	while (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_is_neg(char c, int *i)
{
	if (c == '-')
	{
		*i += 1;
		return(-1);
	}else if (c == '+')
		*i += 1;
	return(1);
}

int		ft_atoi(char *str)
{
	int i;
	int num;
	int sign;

	num = 0;
	sign = 0;
	i = 0;
	while (ft_is_atoi_space(str[i]))
		i++;
	sign = ft_is_neg(str[i], &i);
	while (str[i] && ft_isdigit(str[i]))
	{
		num *= 10;
		num += (int)str[i] - '0';
		i++;
	}
	if (sign < 0)
		return (-num);
	return (num);
}