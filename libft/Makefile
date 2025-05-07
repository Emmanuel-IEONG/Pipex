# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eieong <eieong@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:48:54 by eieong            #+#    #+#              #
#    Updated: 2025/01/17 12:01:53 by eieong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc
CFLAGS := -Wall -Werror -Wextra
INCLUDE := -I ./libft/
RM := rm -f

DIR_LIBFT := libft
SRC_LIBFT := ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_freetab.c \

SRC_LIBFT_BONUS := ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

SRC_GNL := get_next_line_bonus.c

SRC_FTPRINTF := ft_printf/ft_printf.c \
				ft_printf/ft_printothers.c \

SRCS_LIBFT := $(addprefix $(DIR_LIBFT)/, $(SRC_LIBFT))
SRCS_LIBFT_BONUS := $(addprefix $(DIR_LIBFT)/, $(SRC_LIBFT_BONUS))
ALLSRCS_LIBFT := $(SRCS_LIBFT) $(SRCS_LIBFT_BONUS)

OBJ := $(SRCS_LIBFT:.c=.o) $(SRC_GNL:.c=.o) $(SRC_FTPRINTF:.c=.o)

OBJBONUS := $(ALLSRCS_LIBFT:.c=.o)

$(NAME): $(OBJ)
	@ar rcs $@ $^

all:	$(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJBONUS)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

bonus: $(OBJBONUS)
	@ar rcs $(NAME) $(OBJBONUS)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

.PHONY: all clean fclean re bonus
