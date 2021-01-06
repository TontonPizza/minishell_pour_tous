/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:04:24 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/04/01 16:04:24 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*refresh;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		refresh = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = refresh;
	}
	*lst = NULL;
}
