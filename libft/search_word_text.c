/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_word_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/26/12 03:38:43 by vo-nguye          #+#    #+#             */
/*   Updated: 2020/26/12 03:38:43 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     search_word(char *text, char *word)
{
    int i;
    int length;
    char **list;
    int found;

    found = 0;
    list = ft_split(text, ' ');
    length = ft_strlen(word);
    i = 0;
    while(list[i] != NULL && found != 1)
    {
        if (ft_strncmp(word, list[i], length) == 0)
            found = 1;
        free(list[i]);
        i++;
    }
    free(list);
    return found;
}