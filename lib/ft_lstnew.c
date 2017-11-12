/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:57:21 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 04:33:43 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlst;

	nlst = (t_list *)ft_memalloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	if (content == NULL)
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	else
	{
		nlst->content = (void *)ft_memalloc(content_size);
		if (nlst->content == NULL)
			return (NULL);
		ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	nlst->next = NULL;
	return (nlst);
}
