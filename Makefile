# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbosch <fbosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 19:36:01 by fbosch            #+#    #+#              #
#    Updated: 2023/06/16 16:20:16 by fbosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[1;32m
COLOUR_RED=\033[1;31m
COLOUR_BLUE=\033[1;34m
COLOUR_YELLOW=\x1b[33;01m
COLOUR_END=\033[0m

NAME = push_swap
BONUS_NAME = checker

LIBFT = libft.a
LIBFT_DIR = libft/

SRC = main.c argument_checker.c free_memory.c list_utils.c utils.c\
stack_swap_push.c stack_rotate.c stack_reverse_rotate.c sort.c sort2.c\
sort_utils.c sort_utils2.c

BONUS_SRC = main_bonus.c stack_swap_push_bonus.c stack_rotate_bonus.c\
stack_reverse_rotate_bonus.c argument_checker.c free_memory.c\
list_utils.c utils.c stack_swap_push.c stack_rotate.c stack_reverse_rotate.c\
sort.c sort2.c sort_utils.c sort_utils2.c

SRC_DIR = src/

INCLUDE_DIR = include/
BUILD_DIR = .build/


SRC_FILES = $(addprefix $(SRC_DIR),$(SRC))
BONUS_FILES = $(addprefix $(SRC_DIR),$(BONUS_SRC))

OBJ = $(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC_FILES))
BONUS_OBJ = $(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(BONUS_FILES))

DEP = $(OBJ:%.o=%.d) $(BONUS_OBJ:%.o=%.d)

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPFLAGS = -I$(INCLUDE_DIR) -MMD -MP
DIR_DUP = mkdir -p $(@D)
LIBRARY = ar rc

EXECUTABLES = *.out *.exe

RM = /bin/rm -f


all: make_libs $(NAME)

make_libs:
	@printf "$(COLOUR_YELLOW)Compiling libft... \xE2\x8C\x9B\n$(COLOUR_END)"
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_DIR)$(LIBFT)
		@printf "$(COLOUR_GREEN)Linking... $(COLOUR_END)"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $(NAME)
		@printf "$(COLOUR_GREEN)Compilation done!\xE2\x9C\x85\n$(COLOUR_END)"

bonus: make_libs .bonus

.bonus: $(BONUS_OBJ) $(LIBFT_DIR)$(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_DIR)$(LIBFT) -o $(BONUS_NAME)
	@touch .bonus

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(LIBFT_DIR)$(LIBFT)
	@printf "$(COLOUR_YELLOW)Compiling... $(COLOUR_END)$(patsubst $(BUILD_DIR)%,%,$@)\n"
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

norm:
	norminette -R CheckForbiddenSourceHeader
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(OBJ) $(OBJ_BONUS) $(DEP) $(EXECUTABLES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(COLOUR_RED)Deleting...\xE2\x9D\x97\\xE2\x9D\x97\\xE2\x9D\x97\n$(COLOUR_END)"
	$(RM) $(NAME) $(BONUS_NAME)
	$(RM) -r $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
	
-include $(DEP)