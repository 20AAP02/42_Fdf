CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

NAME	= fdf

INCLUDE_FDF	= sources/

OBJ_FILES	= main.c $(wildcard sources/*.c)
OBJS			= $(OBJ_FILES:.c=.o)

.PHONY: all clean fclean re $(MAKE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(RM) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE_FDF) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all