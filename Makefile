# Compiler
CC = gcc

# Compiler flags
WARNFLAGS = -Wall -Wextra -Werror
CFLAGS = -I./lib_ft -I./lib_ft_printf
LDFLAGS = -L./lib_ft -l:libft.a -L./lib_ft_printf -lftprintf

# Default sources
SRCS = main.c basic_utilities.c validation.c navigation_commands.c navigation_both.c sort_fts.c list_utilities.c array_utilities.c sorting_utilities.c sort_small_list.c shifter_fts.c
OBJS = $(SRCS:.c=.o)

# Program Name
NAME = push_swap

# Libft src
LIBFT = ./lib_ft/libft.a

# ft_printf
FTPRINTF = ./lib_ft_printf/libftprintf.a

# Default rule
all: $(LIBFT) $(FTPRINTF) $(GNL) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(WARNFLAGS) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

# Make lib_ft
$(LIBFT):
	make -C lib_ft

# Make lib_ft_printf
$(FTPRINTF):
	make -C lib_ft_printf

# Clean up obj files
clean:
	make -C lib_ft clean
	make -C lib_ft_printf clean
	rm -f $(OBJS)

# Full clean up
fclean: clean
	rm $(NAME)
	make -C lib_ft fclean
	make -C lib_ft_printf fclean

# Rebuild
re: fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONY: all clean fclean re bonus
