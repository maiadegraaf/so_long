# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lde-la-h <lde-la-h@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/27 11:32:06 by lde-la-h      #+#    #+#                  #
#    Updated: 2021/11/12 10:34:30 by lde-la-h      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror
NAME	= libmlx.a
HEADER	= .
LIBFT	= ../libft
MLX		= ../mlx

# AR is an archiving tool
AR		= ar rcs

SRCS	= ./src/ft_ARGB.c \
		./src/ft_clear_window.c \
		./src/ft_create_canvas.c \
		./src/ft_draw_line.c \
		./src/ft_get_pixel.c \
		./src/ft_hook.c \
		./src/ft_init.c \
		./src/ft_key_hook.c \
		./src/ft_point.c \
		./src/ft_put_canvas.c \
		./src/ft_set_pixel.c \
		./src/ft_set_string.c \

OBJS	= ${SRCS:.c=.o}

# Compile, default rule.
all: $(NAME)

# To create the .o files, take the .c file and
# use -c to compile or assemble the source file, then -o to output.
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBFT) -I $(MLX) -g

# Compile everything, first create the objects.
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean library file
fclean: clean
	rm -f $(NAME)

# Re-compile
re:	fclean all

# Phonies as not to confuse make, these are actual commands, not files.
.PHONY: all, clean, fclean, re
