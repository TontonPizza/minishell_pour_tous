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

char 	*expand_env_variable(char *word, int *cursor)  // word[0] == $
{
		char 	*result;
		int 	brace;
		int 	i;

		result = 0;
		brace = 0;
		i = *cursor;
		if (word[++i] == '{')
			brace = 1;
		else if (ft_isalpha(word[i]) == 0)
		{
			*cursor = i;
			return (ft_strdup("$"));
		}
		while (ft_isalpha(word[i]))
			result = join_char_and_free(result, word[i++]);
		while (ft_isalnum(word[i]))
			result = join_char_and_free(result, word[i++]);
		if (brace == 1)
		{
			while (word[i] && word[i] != '}')
				i++;
		}
		*cursor = i;
		return (get_value_and_free_or_not(result, 1));
}

char	*expand_backslash_and_parameters(char *word)
{
	char	*result;
	int		i;
	int		mode;

	i = 0;
	mode = -1;
	result = ft_strdup("");
	while (word[i])
	{
		if (word[i] == '\'')
			mode *= -1;
		if (word[i] == '\\' && mode < 0
			&& is_char_in_set(word[i + 1], "\\\"$") == 1 && i++)
			result = join_char_and_free(result, word[i++]);
		else if (word[i] == '$')
			result = ft_strjoin_and_free(result, expand_env_variable(word + i, &i));
		else
			result = join_char_and_free(result, word[i++]);
	}
	return (result);
}


//char	**expand_word(char *word)
//{
//	char	**result;
//	int 	i;
//
//	i = 0;
//	word = expand_backslash_and_parameters(word);
//	result = word_split(word);
//	while (result[i])
//	{
//		result[i] = remove_quote(result[i]);
//		i++;
//	}
//
//	return (result);
//}









