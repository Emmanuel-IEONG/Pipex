# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 14:39:46 by eieong            #+#    #+#              #
#    Updated: 2025/06/03 11:56:47 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex
LIBFT := ../libft/libft.a \

RM := rm -rf
CC := cc
CFLAGS := -Wall -Wextra -Werror -g

GREEN		:= \033[0;32m
LGREEN		:= \033[1;32m
PURPLE		:= \033[0;35m
LPURPLE		:= \033[1;35m

SRC :=	pipex_bonus.c \
		pipex_parse_bonus.c \
		pipex_cleanup_bonus.c \
		pipex_utils.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(GREEN)----Compiling lib----"
	@make all -C ../libft
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $@
	@echo "\n$(LGREEN)Pipex Compiled!\n"

clean:	
	@echo "$(PURPLE)----Cleaning----"
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@make clean -C ../libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ../libft
	@echo "\n$(LPURPLE)ALL CLEANED!\n"

re: fclean all

.PHONY: all clean fclean re
