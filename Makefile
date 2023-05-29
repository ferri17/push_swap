# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 19:36:01 by fbosch            #+#    #+#              #
#    Updated: 2023/05/29 22:00:10 by fbosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[1;32m
COLOUR_RED=\033[1;31m
COLOUR_BLUE=\033[1;34m
COLOUR_YELLOW=\x1b[33;01m
COLOUR_END=\033[0m


LIBFT = libft.a
LIBFT_DIR = libft/

SRC = main.c
SRC_DIR = src/

INCLUDE_DIR = include/

SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))

OBJ_SRC = $(SRC_FILES:%.c=%.o)
DEPENDS = 

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
LIBRARY = ar rc

EXECUTABLES = *.out

RM = /bin/rm -f

.PHONY: all clean fclean re bonus

all: make_libs $(NAME)

make_libs:
	@printf "$(COLOUR_YELLOW)Compiling libft... \xE2\x8C\x9B\n$(COLOUR_END)"
	$(MAKE) -C $(LIBFT_DIR)
	@printf "$(COLOUR_GREEN)Libft compiled succesfully \xE2\x9C\x85\n$(COLOUR_END)"

$(NAME): $(OBJ_SRC) $(LIBFT_DIR)$(LIBFT)
		@printf "$(COLOUR_GREEN)Linking...\n$(COLOUR_END)"
		$(CC) $(OBJ_SRC) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
		@printf "$(COLOUR_GREEN)Compilation done!\xE2\x9C\x85\n$(COLOUR_END)"


clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(OBJ_SRC) $(EXECUTABLES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(NAME)

re: fclean all

%.o: %.c $(DEPENDS) $(LIBFT_DIR)$(LIBFT)
	@printf "$(COLOUR_YELLOW)Compiling... $(COLOUR_END)"
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
