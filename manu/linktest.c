/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linktest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:27:27 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/08 14:03:01 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

char	*linktest(char *name)
{
	char *buf;

	buf = malloc(sizeof(char) * 100);
	readlink(name, buf, 100);
	buf[100] = '\0';
	return (buf);
}

int	main()
{
	char *name;

	name = linktest("test/liens");
	ft_printf("%s\n", name);
	return (0);
}
