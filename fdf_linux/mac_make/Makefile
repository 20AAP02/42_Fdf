CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=1
MINILIBX = -lmlx -framework OpenGL -framework AppKit
LIB1	= ar -rcs
LIB2	= ranlib
RM	= rm -f

NAME	= libft.a

INCLUDE0	= ft_printf/
INCLUDE1	= 42_libft/
INCLUDE2	= fdf_dir/

FT_PRINTF	= ft_printf/ft_printf_functions0.c ft_printf/ft_printf_functions1.c ft_printf/ft_printf_functions2.c \
					ft_printf/ft_printf_functions3.c ft_printf/ft_printf_functions4.c ft_printf/ft_printf_functions5.c \
					ft_printf/ft_printf_functions6.c ft_printf/ft_printf.c
PRINTF_OBJ	= $(FT_PRINTF:.c=.o)

LIBFT	= 42_libft/ft_isascii.c 42_libft/ft_isprint.c 42_libft/ft_isalpha.c 42_libft/ft_isdigit.c 42_libft/ft_isalnum.c \
					42_libft/ft_tolower.c 42_libft/ft_toupper.c 42_libft/ft_strlen.c 42_libft/ft_strlcpy.c 42_libft/ft_strlcat.c \
					42_libft/ft_memset.c 42_libft/ft_bzero.c 42_libft/ft_memcpy.c 42_libft/ft_memmove.c 42_libft/ft_striteri.c \
					42_libft/ft_memchr.c 42_libft/ft_memcmp.c 42_libft/ft_strdup.c 42_libft/ft_calloc.c 42_libft/ft_itoa.c \
					42_libft/ft_putchar_fd.c 42_libft/ft_putstr_fd.c 42_libft/ft_putendl_fd.c 42_libft/ft_putnbr_fd.c \
					42_libft/ft_substr.c 42_libft/ft_strjoin.c 42_libft/ft_strtrim.c 42_libft/ft_split.c 42_libft/ft_strmapi.c \
					42_libft/ft_lstsize.c 42_libft/ft_lstlast.c 42_libft/ft_lstadd_front.c 42_libft/ft_lstadd_back.c \
					42_libft/ft_lstnew.c 42_libft/ft_lstdelone.c 42_libft/ft_lstclear.c 42_libft/ft_lstiter.c 42_libft/ft_lstmap.c \
					42_libft/ft_strchr.c 42_libft/get_next_line.c
LIB_OBJ	= $(LIBFT:.c=.o)

FDF_LIB	= $(wildcard sources/*.c)
FDF_LIB_OBJ = $(FDF_LIB:.c=.o) 

.PHONY: all re fclean clean compile_fdf compile_libft

all:	fdf clean

fdf:	compile_libft $(NAME) compile_fdf
	$(CC) $(CFLAGS) -I$(INCLUDE0) -I$(INCLUDE1) -I$(INCLUDE2) $(MINILIBX) main.c libft.a -o fdf
	echo "Done"

$(NAME): $(PRINTF_OBJ) $(LIB_OBJ) $(FDF_LIB_OBJ) $(INCLUDE0) $(INCLUDE1) $(INCLUDE2)
	$(LIB1) $(NAME) $(PRINTF_OBJ) $(LIB_OBJ) $(FDF_LIB_OBJ)
	$(LIB2) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDE0) -I$(INCLUDE1) -I$(INCLUDE2) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(LIB_OBJ) $(PRINTF_OBJ) $(FDF_LIB_OBJ)
	$(RM) $(NAME)

fclean:	clean
	$(RM) fdf

re: clean all

compile_fdf:
	echo "Compiling fdf..."

compile_libft:
	echo "Compiling libft..."