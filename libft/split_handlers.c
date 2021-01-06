/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:58:13 by vo-nguye          #+#    #+#             */
/*   Updated: 2020/02/01 15:58:13 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_char_to_split(char **words, char *plus)
{
	char	**tmp;
	int		i;
	int 	k;

	k = 0;
	i = split_size(words);
	tmp = malloc(sizeof(char *) * i + 2);
	if (tmp == NULL)
		return (NULL);
	while(words[k])
	{
		tmp[k] = ft_strdup(words[k]);
		k++;
	}
	tmp[k] = ft_strdup(plus);
	tmp[k + 1] = (NULL);
	free_split(words);
	free(plus);
	return (tmp);
}

void	print_split(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		ft_putstr_fd(words[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int 	split_size(char **words)
{
	int i;

	i = 0;
	while (words && words[i])
		i++;
	return (i);
}

int 	free_split(char **words)
{
	int	i;

	i = 0;
	while (words && words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (1);
}