# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallete <avallete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 13:18:20 by avallete          #+#    #+#              #
#*   Updated: 2016/08/06 03:56:22 by avallete         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror

SRC_PATH:=./src/
SRC_NAME:=	ft_select.c\
		init.c\
		delete.c\
		input.c\
		pagination.c\
		get_element.c\
		print_element.c\
		ft_usetermcap.c\
		selected_elements.c\
		assign_colors.c\
		print_all_page.c\
		utils.c\
		elem_destructor.c\
		window_too_small.c\
		init_cursor_position.c\
		init_tests.c\
		signal_handler.c

INC_PATH=./includes/
INC_NAME=	ft_signal.h\
			ft_printf.h\
			ft_select.h\
			ft_bufferize.h\
			get_next_line.h\
			libft.h

OBJ_PATH=./obj/
OBJ_NAME=$(SRC_NAME:.c=.o)

SRC=$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH), $(OBJ_NAME))
INCF=$(addprefix $(INC_PATH), $(INC_NAME))
INC=$(addprefix -I, $(INC_PATH))

LIBFT:=-L libft/ -lft
LIBSIGNAL:=-L libsignal/ -lftsignal
CC=cc
NAME=ft_select
RED=\033[30;41m
GREEN=\033[32m
CYAN=\033[36m
ORANGE=\033[33m
NC=\033[0m

all: $(NAME)

$(NAME):$(OBJ)
	@make -s -C libft
	@make -s -C libsignal
	@echo "${GREEN}Compile $(NAME) with $(CFLAGS)${NC}";
	@$(CC) $(CLFAGS) $(OBJ) $(INC) $(LIBFT) $(LIBSIGNAL) -ltermcap -o $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@echo "${ORANGE}Create bynary $(NAME) : $@ with $<${NC}";
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@echo "${RED} Delete OBJ files ${NC}"
	@make clean -s -C libft
	@make clean -s -C libsignal
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "${RED} Delete $(NAME) file ${NC}"
	@make fclean -s -C libft
	@make fclean -s -C libsignal
	@rm -rf $(NAME)

noflags: CFLAGS=""
noflags: all

debug: CFLAGS=-g3 -O0
debug: all

re: fclean all clean

.PHONY: all clean fclean re
