NAME = cub3d
SOURCES = cub3d.c init_game.c movement.c validate.c free.c map_checker.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I. -I./ft_printf
LIBXFLAGS = -lmlx -lXext -lX11
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)						
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBXFLAGS) -o $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)

fclean:
	@$(RM) -rf $(OBJECTS)
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re