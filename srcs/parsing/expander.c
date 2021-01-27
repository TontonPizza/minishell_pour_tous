/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:17:34 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/12 17:17:34 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
 *  if word is type word expand it n words
 *
 *
 *
 */



char		**expand_word(char *word)
{
	char	**result;
	int 	i;

	i = 0;
	word = expand_backslash_and_parameters(*word);
	result = word_split(result);
	while (result[i])
	{
		result[i] = remove_quote(result[i]);
		i++;
	}

	return (result);
}









