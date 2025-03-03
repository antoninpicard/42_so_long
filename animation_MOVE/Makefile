# Nom de l'exécutable
NAME = so_long

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinc -Iminilibx-linux
LIBS = -Lminilibx-linux -lmlx_Linux -lXext -lX11

# Dossiers
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

# Fichiers sources et objets
SRCS = $(SRC_DIR)/animation.c $(SRC_DIR)/so_long.c $(SRC_DIR)/build_path.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -rf $(OBJ_DIR)

# Nettoyage complet
fclean: clean
	rm -f $(NAME)

# Recompilation
re: fclean all

# Phony targets
.PHONY: all clean fclean re