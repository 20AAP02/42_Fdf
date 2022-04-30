CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=9000 -g
RM		= rm -f
DEFINES	= -D ESC=113 -D KEY_Z=122 -D KEY_X=120 -D KEY_PLUS=43 -D KEY_MINUS=45 -D KEY_LEFT=97 \
			-D KEY_RIGHT=100 -D KEY_DOWN=115 -D KEY_UP=119 -D KEY_B=98 -D KEY_SPACE=32

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
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(RM) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(DEFINES) -I$(INCLUDE_FDF) -I$(INCLUDE_LIBFT) -I$(INCLUDE_FT_PRINTF) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all