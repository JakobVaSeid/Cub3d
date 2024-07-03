NAME = cub3d
LIBFT = libft
SOURCES =	cub3d.c \
			init_game.c \
			movement.c \
			validate.c \
			free.c \
			map_checker.c \
			read_map.c \
			utils.c \
			check_file.c \
			map_utils_check.c \
			raycaster_1.c \
			raycaster_2.c \
			render.c \
			get_next_line.c \
			get_next_line_utils.c
OBJDIR = build
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
DEP = $(OBJECTS:%.o=%.d)
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -g -I. -I./ft_printf
LIBXFLAGS = -lmlx -lXext -lX11
MATHFLAGS = -lm
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)
	make --no-print-directory -C ./libft
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBXFLAGS) $(MATHFLAGS) -o $(NAME) -L./libft -lft

$(OBJDIR)/%.o:%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	make clean --no-print-directory -C ./libft
	@$(RM) -rf $(OBJDIR)

fclean: clean
	make fclean --no-print-directory -C ./libft
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re