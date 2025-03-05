# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpicard <anpicard@student.42.fr>          +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/03/05 10:10:04 by anpicard          #+#    #+#            #
#    Updated: 2024/03/05 10:10:04 by anpicard         ###   ########.fr      #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Compiler and flags
CC = cc
CFLAGS := -Wall -Wextra -Werror -g
MLX_FLAGS := -lX11 -lXext

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
UTILS_DIR = utils
MLX_DIR = minilibx-linux
PARSE_DIR = src/parse

# Source files
SRC_FILES = src/so_long.c src/utils.c src/game.c src/map.c src/player.c src/transparent.c \
            $(PARSE_DIR)/map_parser.c $(PARSE_DIR)/rectangle_parser.c $(PARSE_DIR)/utils_parser.c $(PARSE_DIR)/validation.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Libraries
LIBFT = $(UTILS_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Include paths
INCLUDES = -I$(INC_DIR) -I$(UTILS_DIR)/includes -I$(MLX_DIR)

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
RED = \033[0;91m
BOLD = \033[1m

# Progress bar variables
TOTAL_FILES = $(words $(SRC_FILES))
CURR_FILE = 0

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@if [ ! -f $(NAME) ] || [ -n "$?" ]; then \
		echo "$(YELLOW)Linking executable $(NAME)...$(DEF_COLOR)"; \
		$(CC) $(OBJ_FILES) -L$(UTILS_DIR) -lft $(MLX) $(MLX_FLAGS) -o $(NAME) && \
		echo "$(GREEN)$(BOLD)Executable '$(NAME)' compiled successfully$(DEF_COLOR)"; \
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parse

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval CURR_FILE := $(shell echo $$(($(CURR_FILE) + 1))))
	@echo "$(YELLOW)Compiling [$$(echo "$(CURR_FILE) * 100 / $(TOTAL_FILES)" | bc)%%] $(notdir $<)$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): FORCE
	@$(MAKE) -s -C $(UTILS_DIR)

$(MLX):
	@echo "$(BLUE)Compiling minilibx...$(DEF_COLOR)"
	@$(MAKE) -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(UTILS_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "$(CYAN)Object files cleaned$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(UTILS_DIR) fclean
	@echo "$(BLUE)Executable '$(NAME)' removed$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Project rebuilt successfully$(DEF_COLOR)"

FORCE:

force: $(LIBFT) $(MLX) $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) -L$(UTILS_DIR) -lft $(MLX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Executable '$(NAME)' compiled successfully$(DEF_COLOR)"

.PHONY: all clean fclean re force FORCE
