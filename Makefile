NAME = so_long

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lX11 -lXext

# Directories
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
UTILS_DIR = utils
MLX_DIR = minilibx-linux

# Source files
SRC_FILES = src/so_long.c src/parse/map_parse.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Libraries
LIBFTPRINTF = $(UTILS_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Include paths
INCLUDES = -I$(INC_DIR) -I$(UTILS_DIR)/inc -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFTPRINTF) $(MLX) $(OBJ_FILES)
	$(CC) $(OBJ_FILES) $(LIBFTPRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/parse

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
	make -C $(UTILS_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(UTILS_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(UTILS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re