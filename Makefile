# Variables
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX = minilibx-linux/libmlx.a
MLX_PATH = minilibx-linux
LIBFT = utils/libft/libft.a
UTILS_PATH = utils
INCLUDE = -I inc -I $(UTILS_PATH)/inc -I $(MLX_PATH)

# Fichiers sources
SRCS = src/so_long.c src/parse/*.c

# Objets
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(NAME)

# Compiler le Makefile dans utils
$(NAME): $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(MLX_PATH) -lmlx -lm -lX11 -o $(NAME)

# Compiler la libft
$(LIBFT):
	make -C $(UTILS_PATH)/libft

# Compiler la mlx
$(LIBMLX):
	make -C $(MLX_PATH)

# Nettoyage des objets
clean:
	rm -f $(OBJS)
	make clean -C $(UTILS_PATH)/libft
	make clean -C $(MLX_PATH)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make fclean -C $(UTILS_PATH)/libft
	make fclean -C $(MLX_PATH)

# Recompiler
re: fclean all
