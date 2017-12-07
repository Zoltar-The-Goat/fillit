/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:00:52 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 04:34:05 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*tlst;
	t_list	*start;

	if (lst)
	{
		tlst = f(lst);
		if (!(nlst = ft_lstnew(tlst->content, tlst->content_size)))
			return (NULL);
		start = nlst;
		lst = lst->next;
		while (lst)
		{
			tlst = f(lst);
			if (!(nlst->next = ft_lstnew(tlst->content, tlst->content_size)))
				return (NULL);
			nlst = nlst->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
