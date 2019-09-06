/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:24:14 by mfierlaf          #+#    #+#             */
/*   Updated: 2019/09/05 15:13:24 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void	ft_ls(char *target, char *option)
{
	DIR	*dir;
	struct dirent *dent;
	struct stat sb;

	if ((dir = opendir(target)) == NULL)
	{
		perror ("cannot open.");
		return;
	}
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] != '.' || ft_strchr(option, 'a'))
		{
			if (!ft_strchr(option, 'R'))
				ft_printf("%s\n", dent->d_name);
			if (ft_strchr(option, 'R'))
			{

				if (dent->d_type == 4 && dent->d_name[0] != '.')
				{
					ft_printf("./%s:\n", dent->d_name);
					ft_ls(dent->d_name, option);
				}
				else
					ft_printf("%s\n", dent->d_name);
			}
		}
	}
	closedir(dir);
}
