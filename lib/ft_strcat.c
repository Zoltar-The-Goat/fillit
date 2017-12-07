/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:45:03 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 02:08:17 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *str1;
	char *str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!*str2)
		return (s1);
	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = '\0';
	return (s1);
}
