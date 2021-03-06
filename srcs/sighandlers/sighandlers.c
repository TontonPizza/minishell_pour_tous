/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/65 14:21:39 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/03/65 14:21:39 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void sighandler_int(int signum)
{

}

void sighandler_quit(int signum)
{
	write(1, "sigquit exit\n", 12);
	exit(0);
}