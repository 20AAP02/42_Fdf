CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=9000
LIB1	= ar -rcs
LIB2	= ranlib
RM	= rm -f

NAME	= libft.a

INCLUDE_LIBFT		= libft/42_libft/
INCLUDE_FT_PRINTF	= libft/ft_printf/

SRCS	:= $(shell find libft/42_libft -name '*.c') $(shell find libft/ft_printf -name '*.c')

OBJS	= $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB1) $(NAME) $(OBJS)
	$(LIB2) $(NAME)
	$(RM) $(OBJS)
	echo "libft compiled"

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE_LIBFT) -I$(INCLUDE_FT_PRINTF) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all