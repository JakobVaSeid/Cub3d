NAME = cub3d
SOURCES =	cub3d.c \
			init_game.c \
			movement.c \
			validate.c \
			free.c \
			map_checker.c \
			raycaster.c
OBJDIR = build
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I. -I./ft_printf
LIBXFLAGS = -lmlx -lXext -lX11
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)
	make --no-print-directory -C ./libft
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBXFLAGS) -o $(NAME) -L./libft -lft

$(OBJDIR)/%.o:%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean --no-print-directory -C ./libft
	@$(RM) -rf $(OBJDIR)

fclean: clean
	make fclean --no-print-directory -C ./libft
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re