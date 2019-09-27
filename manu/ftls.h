/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:59:33 by tde-brit          #+#    #+#             */
/*   Updated: 2019/09/16 15:16:36 by mfierlaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>

typedef struct		s_option
{
	unsigned char	type;
	char			*right;
	int				nb_link;
	char			*owner;
	char			*group;
	int				size;
	char			*htime;
	long			time;
	char   			*pathname;
	int				major;
	int				minor;
	unsigned char	d_type;
	char			*path;
	char			*file;
}					t_option;

typedef struct	s_files t_files;
struct s_files
{
	t_option		*options;
	t_files			*suivant;
};
typedef struct s_names t_names;
struct	s_names
{
	t_files	*actuelf;
	t_files	*premierf;
	int		max_nblink;
	int		max_size;
	int 	max_major;
	int		max_minor;
	char	*max_owner;
	char	*max_group;
	char	*name;
	int		nat;
	int		total;
	t_names	*suivant;
	int		types;
};

typedef struct		s_stock
{
	int				i;
	int				j;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		buf;
	t_names			*premiern;
	t_names			*actueln;
	t_names			*tmpn;
	t_names			*lastn;
	int				o_a;
	int				o_R;
	int				o_r;
	int				o_l;
	int				o_t;
	int				checkp;
}					t_stock;

void				listing(t_stock *stock);
void				*list_init(char c, t_stock *stock);
t_stock				*little_l(t_stock *stock);
void				print_l(t_stock *stock);
t_stock				*high_r(t_stock *stock);
t_stock				*little_r(t_stock *stock);
void				freelstfiles(t_stock *stock, int l);
void				freelstnames(t_stock *stock);
void				freeoptions(t_stock *stock, int l);
void				print(t_stock *stock);
#endif
