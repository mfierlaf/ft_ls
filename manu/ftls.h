/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:59:33 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/04 16:03:22 by tde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
#	include <sys/types.h>
#	include <pwd.h>

typedef struct	s_option
{
	int		total;
	char	type;
	char	*right;
	int		nb_link;
	char	*owner;
	char	*group;
	int		size;
	char	*month;
	int		day;
	int		hour;
	int		min;
	int		pathlen;
}				t_option;
typedef struct	s_files t_files;
struct s_files
{
	char		*file;
	t_option	*options;
	t_files		*suivant;
};
typedef struct s_names t_names;
struct	s_names
{
	char	*name;
	t_files	*file;
	int		nat;
	t_names	*suivant;
};
typedef struct	s_stock
{
	t_option		*opt;
	int				i;
	int				j;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		*buf;
	struct pwuid	*pwd;
	t_names			*premiern;
	t_files			*premierf;
	t_names			*actueln;
	t_files			*actuelf;
	t_names			*tmpn;
	t_files			*tmpf;
	int				o_a;
	int				o_R;
	int				o_r;
	int				o_l;
	int				o_t;
}				t_stock;
void			option_l(t_stock *stock);
void			listing(t_stock *stock);
void			*list_init(char c, t_stock *stock);
#endif
