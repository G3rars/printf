/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:16:30 by jergonza          #+#    #+#             */
/*   Updated: 2023/09/26 11:16:34 by jergonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lst(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(content);
		free(node);
		return (NULL);
	}
	node->content = (void *)content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	save = lst;
	newlist = ft_lst(f(lst->content));
	save = save->next;
	while (save)
	{
		ft_lstadd_back(&newlist, ft_lst(f(save->content)));
		save = save->next;
	}
	if (ft_lstsize(lst) != ft_lstsize(newlist))
	{
		ft_lstclear(&newlist, del);
		return (NULL);
	}
	return (newlist);
}
