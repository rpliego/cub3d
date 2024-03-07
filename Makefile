NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
RM = rm -rf


SRC =		srcs/main.c \
			srcs/utils/errors.c \
			srcs/utils/utils_parser.c \
			srcs/parser/extract_map.c \
			srcs/parser/parser.c \
			srcs/parser/check_elements.c \
			srcs/parser/clean_map.c \
			srcs/parser/validate_info.c \
			srcs/parser/validate_map.c


OBJ = $(SRC:.c=.o)
MLX_DIR = inc/mlx
LIBFT_DIR = inc/libft
INCLUDE = inc/cub3d.h

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ) $(INCLUDE) Makefile
	$(CC) $(CFLAGS) $(OBJ) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT_DIR)/libft.a

%.o: %.c $(INCLUDE)
	$(CC) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re