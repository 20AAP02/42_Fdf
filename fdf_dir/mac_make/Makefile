CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=9000
RM	= rm -f
DEFINES	= -D ESC=53 -D KEY_Z=6 -D KEY_X=7 -D KEY_PLUS=24 -D KEY_MINUS=27 -D KEY_LEFT=123 \
			-D KEY_RIGHT=124 -D KEY_DOWN=125 -D KEY_UP=126 -D KEY_B=11 -D KEY_SPACE=49

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
	$(CC) $(CFLAGS) $(DEFINES) -I$(INCLUDE_FDF) -I$(INCLUDE_LIBFT) -I$(INCLUDE_FT_PRINTF) -Imlx -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: clean all