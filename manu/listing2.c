/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:45:29 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/05 11:17:44 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftls.h"

void listing(char *s, char *option)
{
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		*buf;

	buf = malloc(sizeof(struct stat));
	if ((dirp = opendir(s)) == NULL)
	{
		ft_printf("Error : %s Folder Doesn't exist\n", s);
		return ;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		lstat(dp->d_name, buf);
		ft_printf("%s : %d", dp->d_name, buf->st_mode);
		if (ft_strchr(option, 'l'))
			option_l(dp, option);
		else
		{
			if (dp->d_name[0] != '.')
				ft_printf("%s\n", dp->d_name);
			if (dp->d_name[0] == '.' && ft_strchr(option, 'a'))
				ft_printf("%s\n", dp->d_name);
			if (ft_strchr(option, '-') && ft_strchr(option, 'R'))
			{
				if (dp->d_type == DT_DIR && ft_strcmp(dp->d_name, ".") != 0 &&
						ft_strcmp(dp->d_name, ".."))
					listing(dp->d_name, option);
			}
		}
	}
	closedir(dirp);
}
