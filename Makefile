NAME	=		so_long

SRCS	=		./src/so_long.c \
				./src/t_map_utils.c \
				./src/generate_map.c \
				./src/create_img.c \
				./src/key_hook.c \
				./src/tools_tools.c \
				./src/my_mlx_pixel_put.c \
				./src/t_bugs_utils.c \
				./src/bugs.c \
				./src/tarantula.c \
				./src/loop.c \
				./src/init_info.c \
				./src/draw_info.c \
				./src/img_utils.c \
				./src/end_game.c \
				./src/utils.c \
				./src/find.c \
				./src/check_err.c

BONUS_SRCS	= 	./bonus_src/bugs_bonus.c \
				./bonus_src/check_err_bonus.c \
				./bonus_src/create_img_bonus.c \
				./bonus_src/draw_info_bonus.c \
				./bonus_src/end_game_bonus.c \
				./bonus_src/enemy_bonus.c \
				./bonus_src/enemy_utils_bonus.c \
				./bonus_src/find_bonus.c \
				./bonus_src/generate_map_bonus.c \
				./bonus_src/img_utils_bonus.c \
				./bonus_src/init_info_bonus.c \
				./bonus_src/initiate_enemy_bonus.c \
				./bonus_src/key_hook_bonus.c \
				./bonus_src/loop_bonus.c \
				./bonus_src/my_mlx_pixel_put_bonus.c \
				./bonus_src/so_long_bonus.c \
				./bonus_src/t_bugs_utils_bonus.c \
				./bonus_src/t_map_utils_bonus.c \
				./bonus_src/tarantula_bonus.c \
				./bonus_src/tools_tools_bonus.c \
				./bonus_src/utils_bonus.c \
				./bonus_src/utils_bonus_bonus.c

FLAGS	=		-Wall -Werror -Wextra -Imlx -g

LIBFT	=		libraries/libft/libft.a

MLX		=		libraries/mlx/libmlx.dylib

HEADER	=		includes/so_long.h

OBJS	=		$(SRCS:%.c=%.o)

BONUS_OBJS =	$(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
ALL_OBJS = $(BONUS_OBJS)
else
ALL_OBJS = $(OBJS)
endif

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(ALL_OBJS) $(LIBFT) $(MLX)
	$(CC) -g -fsanitize=address $^ -o $(NAME)

bonus: 
	$(MAKE) WITH_BONUS=1

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libraries/libft

$(MLX):
	$(MAKE) -C libraries/mlx && test -e libmlx.dylib || ln -sf libraries/mlx/libmlx.dylib libmlx.dylib 

clean:
	make fclean -C libraries/libft
	make clean -C libraries/mlx
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f libmlx.dylib

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all