NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

FT_CTYPE = src/ft_ctype/
FT_PRINTF = src/ft_stdio/ft_printf/
FT_STDIO = src/ft_stdio/
FT_STDLIB = src/ft_stdlib/
FT_STRING = src/ft_string/
GNL = src/get_next_line/
LIST = src/ft_list/
ARRAY = src/ft_arrstr/

SRC =	$(FT_CTYPE)ft_isalpha.c \
		$(FT_CTYPE)ft_isdigit.c \
		$(FT_CTYPE)ft_isalnum.c \
		$(FT_CTYPE)ft_isascii.c \
		$(FT_CTYPE)ft_isprint.c \
		$(FT_CTYPE)ft_toupper.c \
		$(FT_CTYPE)ft_tolower.c \
		$(FT_CTYPE)ft_isspace.c \
		\
		$(FT_PRINTF)ft_printf.c \
		$(FT_PRINTF)ft_parser.c \
		$(FT_PRINTF)ft_print_char.c \
		$(FT_PRINTF)ft_print_hexanbr.c \
		$(FT_PRINTF)ft_print_nbr.c \
		$(FT_PRINTF)ft_print_pt.c \
		$(FT_PRINTF)ft_print_str.c \
		$(FT_PRINTF)ft_print_unnbr.c \
		$(FT_PRINTF)ft_up_or_low.c \
		\
		$(FT_STDIO)ft_putchar_fd.c \
		$(FT_STDIO)ft_putstr_fd.c \
		$(FT_STDIO)ft_putendl_fd.c \
		$(FT_STDIO)ft_putnbr_fd.c \
		\
		$(FT_STDLIB)ft_atoi.c \
		$(FT_STDLIB)ft_atol.c \
		$(FT_STDLIB)ft_calloc.c \
		$(FT_STDLIB)ft_itoa.c \
		\
		$(FT_STRING)ft_bzero.c \
		$(FT_STRING)ft_memset.c \
		$(FT_STRING)ft_memcpy.c \
		$(FT_STRING)ft_memmove.c \
		$(FT_STRING)ft_memchr.c \
		$(FT_STRING)ft_memcmp.c \
		$(FT_STRING)ft_split.c \
		$(FT_STRING)ft_strchr.c \
		$(FT_STRING)ft_strdup.c \
		$(FT_STRING)ft_striteri.c \
		$(FT_STRING)ft_strjoin.c \
		$(FT_STRING)ft_strlcat.c \
		$(FT_STRING)ft_strlcpy.c \
		$(FT_STRING)ft_strlen.c \
		$(FT_STRING)ft_strmapi.c \
		$(FT_STRING)ft_strcmp.c \
		$(FT_STRING)ft_strncmp.c \
		$(FT_STRING)ft_strnstr.c \
		$(FT_STRING)ft_strrchr.c \
		$(FT_STRING)ft_substr.c \
		$(FT_STRING)ft_strtrim.c \
		$(FT_STRING)ft_count_char.c \
		$(FT_STRING)ft_strcut.c \
		\
		$(GNL)get_next_line.c \
		$(GNL)get_next_line_utils.c \
		\
		$(LIST)ft_create_elem.c \
		$(LIST)ft_list_at.c \
		$(LIST)ft_list_clear.c \
		$(LIST)ft_list_last.c \
		$(LIST)ft_list_push_back.c \
		$(LIST)ft_list_push_front.c \
		$(LIST)ft_list_push_strs.c \
		$(LIST)ft_list_reverse.c \
		$(LIST)ft_list_size.c \
		\
		$(ARRAY)ft_arrfree.c \
		$(ARRAY)ft_arrcat.c \
		$(ARRAY)ft_arrlen.c \
		$(ARRAY)ft_arrprintf.c \
		$(ARRAY)ft_arrjoin.c \
		$(ARRAY)ft_arrcpy.c \
		$(ARRAY)ft_arrfind.c \
		$(ARRAY)ft_arrncpy.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

PREPRO_FILES = $(patsubst %.c, %.txt, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./include

clean:
	@rm -f $(OBJ)
	@rm -f $(PREPRO_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re
