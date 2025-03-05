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

# Colors and formatting
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m
BOLD = \033[1m

# Progress bar variables
TOTAL_FILES = $(words $(SRC_FILES))
CURR_FILE = 0

# Silent mode (make V=1 for verbose output)
ifndef V
	MAKEFLAGS += --silent
	VERBOSE = @
else
	VERBOSE =
endif

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJ_FILES)
	$(VERBOSE)$(CC) $(OBJ_FILES) -L$(UTILS_DIR) -lft $(MLX) $(MLX_FLAGS) -o $(NAME)
	$(VERBOSE)printf "\n$(GREEN)$(BOLD)Executable '$(NAME)' compiled successfully$(DEF_COLOR)\n"

$(OBJ_DIR):
	$(VERBOSE)mkdir -p $(OBJ_DIR)
	$(VERBOSE)mkdir -p $(OBJ_DIR)/parse

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(eval CURR_FILE := $(shell echo $$(($(CURR_FILE) + 1))))
	$(VERBOSE)printf "$(YELLOW)Compiling [%3d%%] %-33s$(DEF_COLOR)\r" $$(($(CURR_FILE) * 100 / $(TOTAL_FILES))) $(notdir $<)
	$(VERBOSE)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT): force
	$(VERBOSE)make -C $(UTILS_DIR)

$(MLX):
	$(VERBOSE)make -C $(MLX_DIR)

clean:
	$(VERBOSE)rm -rf $(OBJ_DIR)
	$(VERBOSE)make -C $(UTILS_DIR) clean
	$(VERBOSE)make -C $(MLX_DIR) clean
	$(VERBOSE)printf "$(CYAN)Object files cleaned$(DEF_COLOR)\n"

fclean: clean
	$(VERBOSE)rm -f $(NAME)
	$(VERBOSE)make -C $(UTILS_DIR) fclean
	$(VERBOSE)printf "$(BLUE)Executable '$(NAME)' removed$(DEF_COLOR)\n"

force:
	$(VERBOSE)make -C $(UTILS_DIR)
	$(VERBOSE)make -C $(MLX_DIR)
	$(VERBOSE)$(CC) $(CFLAGS) $(OBJ_FILES) -L$(UTILS_DIR) -lft $(MLX) $(MLX_FLAGS) -o $(NAME)

re:
	$(VERBOSE)$(MAKE) fclean
	$(VERBOSE)$(MAKE) all
	$(VERBOSE)printf "$(GREEN)$(BOLD)Project rebuilt successfully$(DEF_COLOR)\n"

.PHONY: all clean fclean re
