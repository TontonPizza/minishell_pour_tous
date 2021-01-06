/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:04:46 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/04/01 16:04:46 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*refresh;

	if (lst == NULL)
		return (NULL);
	refresh = lst;
	while (refresh->next != 0)
		refresh = refresh->next;
	return (refresh);
}
