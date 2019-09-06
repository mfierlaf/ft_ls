/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:04:35 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/05 15:22:40 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

char *option(int ac, char **av)
{
	char *var;
	int i;
	int j;

	if((var = malloc(sizeof(char) * 0)) == NULL)
		return (NULL);
	i = 1;
	j = 1;
	while (i < ac && av[i][0] == '-')
	{
		while (av[i][j])
		{
			var = ft_strjoin_free(var, av[i], 1);
			j++;
		}
		j = 0;
		i++;
	}
	return var;
}
