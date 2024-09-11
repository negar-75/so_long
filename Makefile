SRC_FOLDER = src/
SRCS = $(addprefix $(SRC_FOLDER), \
	main.c \
	err/err.c \
	map_funcs/map_validation.c  \
	map_funcs/map_init.c \
	map_funcs/map_checker_1.c \
	map_funcs/map_checker_2.c \
	map_funcs/accessibility.c \
	map_funcs/init_data.c \
	game/game_init.c \
	game/game_render.c \
	game/game_move.c \
	game/game_msg.c \
	game/mlx_utils.c \
	game/game_clean_up.c) 

LIBS_SRCS = libs/ft_strdup_2.c

GNL_FOLDER = libs/get_next_line/
GNL_SRCS = $(addprefix $(GNL_FOLDER), \
	get_next_line_utils.c \
	get_next_line.c)

ALL_SRCS = $(SRCS) $(LIBS_SRCS) $(GNL_SRCS)
OBJS = $(ALL_SRCS:.c=.o)

PRINTF_DIR = libs/ft_printf
PRINTF_PATH = ${PRINTF_DIR}/libftprintf.a

MLX_DIR = minilibx-linux/
MLX_PATH = ${MLX_DIR}/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I ./includes -Imlx
LDFLAGS = -ldl -L${MLX_DIR} -lmlx -lm -lXext -lX11 -L$(PRINTF_DIR) -lftprintf
RM = rm -f
NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF_PATH) $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(PRINTF_PATH):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_PATH):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re
