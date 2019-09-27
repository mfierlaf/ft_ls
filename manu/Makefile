# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 14:58:04 by tde-brit          #+#    #+#              #
#    Updated: 2019/09/04 15:45:13 by tde-brit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = main.c listing.c list_init.c print_l.c little_l.c high_r.c little_r.c \
freelstfiles.c freelstnames.c freeoptions.c print.c

HEADERS = ftls.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make re -C ./libft
	@make clean
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -L libft/ -lft


clean:
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
