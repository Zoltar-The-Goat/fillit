/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ananelli <ananelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:59:12 by ananelli          #+#    #+#             */
/*   Updated: 2017/11/07 03:01:36 by ananelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp_lst;
	t_list *count_lst;

	count_lst = *alst;
	while (count_lst)
	{
		tmp_lst = count_lst->next;
		del(count_lst->content, count_lst->content_size);
		free(count_lst);
		count_lst = tmp_lst;
	}
	*alst = NULL;
}
