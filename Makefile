NAME = cub3d

#########
RM = rm -rf
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=address
#########

#########
FILES = main parser utils_parser utils_parser_2 extract_map

FILES += check_elements clean_map validate_info validate_map dfs

FILES += init init_utils hooks raycasting minimap draw moves

SRC = $(addsuffix .c, $(FILES))

vpath %.c srcs srcs/parser srcs/graphics srcs/utils
#########

#########
OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
#########

########
MLX_DIR = inc/mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT = inc/libft
LIBFT_FLAGS = -L$(LIBFT) -lft
########

#########
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	${CC} -MMD $(CFLAGS) -c -I inc -Imlx -I$(LIBFT) $< -o $@

all: 
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	@$(MAKE) -C $(LIBFT) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "EVERYTHING DONE  "

clean:
	$(MAKE) clean -C $(MLX_DIR) --no-print-directory
	$(MAKE) clean -C $(LIBFT) --no-print-directory
	$(RM) $(OBJ) $(DEP) --no-print-directory
	$(RM) -r $(OBJ_DIR) --no-print-directory
	@echo "OBJECTS REMOVED   "

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME) --no-print-directory
	@echo "EVERYTHING REMOVED   "

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)
