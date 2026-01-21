# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adakhama <adakhama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/16 13:50:46 by adakhama          #+#    #+#              #
#    Updated: 2026/01/13 17:53:50 by adakhama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

NAME = pipex

SRC =	Test/main_exemples.c \
		library/get_next_line/get_next_line_bonus.c \
		library/get_next_line/get_next_line_utils_bonus.c \
		library/struct/ft_listiter.c \
		library/struct/ft_lstadd_back.c \
		library/struct/ft_lstadd_front.c \
		library/struct/ft_lstclear.c \
		library/struct/ft_lstdelone.c \
		library/struct/ft_lstlast.c \
		library/struct/ft_lstmap.c \
		library/struct/ft_lstnew.c \
		library/struct/ft_lstsize.c \
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	make -C library/printf -s
	make -C library/libft -s
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -Llibrary/libft -Llibrary/printf -l:libft.a -l:libftprintf.a

%.o:%.c
	$(CC) $(CFLAGS) $< -c -o $@ -I library/libft -I library/printf

clean: 
	-rm -f $(OBJ)
	make -C library/printf clean -s
	make -C library/libft clean -s

fclean: clean
	-rm -f $(NAME)
	make -C library/printf fclean -s
	make -C library/libft	fclean -s

re: fclean all
	make -C library/printf re -s
	make -C library/libft re -s

# .SILENT:
.PHONY: all clean fclean re