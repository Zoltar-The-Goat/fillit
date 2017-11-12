/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:55:41 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 06:24:48 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_intmin(void)
{
	char	*buf;

	buf = ft_strnew(11);
	ft_strcpy(buf, "-2147483648");
	return (buf);
}

static int	ft_is_neg(int *n, int *size, int *temp, char *sign)
{
	*size = 0;
	*temp = *n;
	*sign = '+';
	if (*n == -2147483648)
		return (1);
	else if (*n < 0)
	{
		*sign = '-';
		*temp *= -1;
		*n *= -1;
		*size += 1;
	}
	return (0);
}

static void	ft_set_size(int *temp, int *size)
{
	while (*temp > 9)
	{
		*temp /= 10;
		*size += 1;
	}
	*size += 1;
}

static void	final(char *ret, char *sign, int *n)
{
	ret[0] = (*n % 10) + 48;
	if (*sign == '-')
	{
		ret[0] = '-';
		ret[1] = (*n % 10) + 48;
	}
}

char		*ft_itoa(int n)
{
	int		size;
	int		start;
	int		temp;
	char	sign;
	char	*ret;

	start = 0;
	if (ft_is_neg(&n, &size, &temp, &sign))
		return (ft_intmin());
	ft_set_size(&temp, &size);
	ret = (char *)ft_memalloc(size + 1);
	if (ret)
	{
		ret[size + 1] = '\0';
		while (n > 9)
		{
			while (start < size)
				ret[start++] = (n % 10) + 48;
			size--;
			start = 0;
			n /= 10;
		}
		final(ret, &sign, &n);
	}
	return (ret);
}
