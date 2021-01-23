/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 08:16:55 by vo-nguye          #+#    #+#             */
/*   Updated: 2021/01/06 08:16:55 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void test_env()
{
	init_env_list();
	print_split(get_env_as_array());
	printf("________\n");
	export_var("salut", "copain");
	print_split(get_env_as_array());
	unset_env("salut");
	printf("________\n");
	print_split(get_env_as_array());
	printf("%s\n", get_value_and_free_or_not("author", 0));
	destroy_env();
}

int main()
{
	test_env();
}