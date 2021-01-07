/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:03:43 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/04/01 16:03:43 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*current;

	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		current = *alst;
		while (current->next != 0)
			current = current->next;
		current->next = new;
	}
}
