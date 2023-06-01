# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbosch <fbosch@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 19:36:01 by fbosch            #+#    #+#              #
#    Updated: 2023/06/01 02:48:30 by fbosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[1;32m
COLOUR_RED=\033[1;31m
COLOUR_BLUE=\033[1;34m
COLOUR_YELLOW=\x1b[33;01m
COLOUR_END=\033[0m

NAME = push_swap

LIBFT = libft.a
LIBFT_DIR = libft/

SRC = main.c
SRC_DIR = src/

INCLUDE_DIR = include/
BUILD_DIR = .build/


SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC_FILES))

DEP = $(OBJ:%.o=%.d)
DEPENDS =

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -I$(INCLUDE_DIR) -MMD -MP
DIR_DUP = mkdir -p $(@D)
LIBRARY = ar rc

EXECUTABLES = *.out *.exe

RM = /bin/rm -f

.PHONY: all clean fclean re bonus

all: make_libs $(NAME)

make_libs:
	@printf "$(COLOUR_YELLOW)Compiling libft... \xE2\x8C\x9B\n$(COLOUR_END)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_DIR)$(LIBFT)
		@printf "$(COLOUR_GREEN)Linking... $(COLOUR_END)"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
		@printf "$(COLOUR_GREEN)Compilation done!\xE2\x9C\x85\n$(COLOUR_END)"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(DEPENDS) $(LIBFT_DIR)$(LIBFT)
	@printf "$(COLOUR_YELLOW)Compiling... $(COLOUR_END)$(patsubst $(BUILD_DIR)%,%,$@)\n"
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(OBJ) $(DEP) $(EXECUTABLES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(NAME)
	$(RM) -r $(BUILD_DIR)

re: fclean all

	
