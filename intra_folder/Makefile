CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
DEFINES	= -D ESC=53 -D KEY_Z=6 -D KEY_X=7 -D KEY_PLUS=24 -D KEY_MINUS=27 -D KEY_LEFT=123 \
			-D KEY_RIGHT=124 -D KEY_DOWN=125 -D KEY_UP=126 -D KEY_B=11 -D KEY_SPACE=49

NAME	= fdf
LIB		= libft.a

INCLUDE_FDF			= sources/
INCLUDE_LIBFT		= libft/42_libft/
INCLUDE_FT_PRINTF	= libft/ft_printf/

SRCS			:= main.c $(shell find sources/ -name '*.c')

OBJS	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) $(LIB) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	$(RM) $(OBJS)

$(LIB):
	make -f libft/Makefile -s

.c.o:
	$(CC) $(CFLAGS) $(DEFINES) -I$(INCLUDE_FDF) -I$(INCLUDE_LIBFT) -I$(INCLUDE_FT_PRINTF) -Imlx -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIB)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIB)

re:	fclean all