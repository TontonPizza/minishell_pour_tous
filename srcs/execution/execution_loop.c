/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/40 04:24:33 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/02/40 04:24:33 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int 	execution_loop(t_token *list)
{
	t_token	*cursor = list;
	char 	**command;

	if (cursor == 0)
		return;
	/*
	 *  parcourir curssor, vérifier la conformité, gérer les redirections
	 *  mettre tous les mots libre dans un char **command
	 *
	 * pousser la list jusqu'apres le premier | si il ya
	 */

	/*
	 *  chercher l'executable si /
	 *  sinon chercher si builtin
	 */

	/*
	 *  executer le merdier
	 */

	execution_loop(cursor);
}