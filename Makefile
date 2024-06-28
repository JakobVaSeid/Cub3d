NAME = cub3d
LIBFT = libft
SOURCES =	cub3d.c \
			init_game.c \
			movement.c \
			validate.c \
			free.c \
			map_checker.c \
			read_map.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I. -I./libft
LIBXFLAGS = -lmlx -lXext -lX11
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)			
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBXFLAGS) -o $(NAME) libft/libft.a

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean -sC $(LIBFT)

fclean:
	@$(RM) -rf $(OBJECTS)
	@make fclean -sC $(LIBFT)
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re