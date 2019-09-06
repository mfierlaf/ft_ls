/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:37:54 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/05 14:43:07 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

int main(int ac, char **av)
{
	char *info;

	if ((info = malloc(sizeof(char) * 0)) == NULL)
		return (-1);
	if (ac == 1)
		ft_strjoin(info, "b");
	else 
		info = option(ac, av);
	ft_ls(".", info);
	return 0;
}
