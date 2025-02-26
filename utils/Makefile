LIBFT = libft
SRC_DIR = printf/
OBJ_DIR = obj/
HEADERS_DIR = inc/
HEADERS_FILE = ft_printf.h libft.h
SRCS_FILE = ft_printf.c util/ft_convert_hex.c util/pointer_set.c util/util.c
NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -I
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_FILE))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILE))
OBJS = $(addprefix $(OBJ_DIR), $(SRCS_FILE:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) Makefile | $(OBJ_DIR)
	$(CC) $(FLAGS) $(HEADERS_DIR) -c $< -o $@

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/util

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean;
	@rm -f $(LIBFT)/libft.a
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRCS) $(HEADERS) $(LIBFT)

.PHONY: all clean fclean re norm