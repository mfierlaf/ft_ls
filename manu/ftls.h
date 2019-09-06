/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:59:33 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/05 14:22:18 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLSH
# define FTLSH
# include "libft/libft.h"
# include <unistd.h>
# include <sys/types.h> 
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>

void	ft_ls(char *target, char *option);
char	*option(int ac, char **av);

#endif
