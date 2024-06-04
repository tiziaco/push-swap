# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 11:38:10 by tiacovel          #+#    #+#              #
#    Updated: 2024/06/04 16:40:28 by tiacovel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT_PATH = lib/libft

SRC =	$(wildcard src/*.c)

OBJ	= $(SRC:.c=.o)

RM		= rm -f
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LINK = -Llib/libft -lft

# Color and styles
COLOR_RESET = \033[0m
BOLD_GREEN = \033[1;32m
GREEN = \033[0;32m
RED = \033[0;31m
HIDE = @

all: dependencies $(NAME)

dependencies:
    # Check if libft has been downloaded
    ifeq ($(wildcard $(LIBFT_PATH)/*),)
		@git submodule update --init --recursive
		@echo "$(GREEN)Submodules downloaded.$(COLOR_RESET)"
    endif

    # Check if libft is compiled
    ifeq ($(wildcard $(LIBFT_PATH)/libft.a),)
		@make -s -C $(LIBFT_PATH)
    endif
	@echo "$(GREEN)Libft compiled ✅$(COLOR_RESET)"

$(NAME): $(OBJ)
		$(CC) -g -O0 $(OBJ) $(LINK) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C lib/libft
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all dependencies clean fclean re