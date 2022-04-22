CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=9000
RM	= rm -f

NAME	= fdf

INCLUDE_FDF			= sources/
INCLUDE_LIBFT		= 42_libft/
INCLUDE_FT_PRINTF	= ft_printf/

OBJ_FT_PRINTF	:= $(shell find ft_printf/ -name '*.c')
OBJ_LIBFT		:= $(shell find 42_libft/ -name '*.c')
OBJ_FDF			:= main.c $(shell find sources/ -name '*.c')

OBJS	= $(OBJ_FDF:.c=.o) $(OBJ_LIBFT:.c=.o) $(OBJ_FT_PRINTF:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(RM) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE_FDF) -I$(INCLUDE_LIBFT) -I$(INCLUDE_FT_PRINTF) -Imlx -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: clean all