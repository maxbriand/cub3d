NAME = cub3d
CC = cc
# FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC = 	main.c \
		ft_pexit.c \
		\
		parsing/ft_parsing.c \
		parsing/ft_arg_nbr.c \
		parsing/ft_extension.c \
		parsing/ft_get_map.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -lm ./MLX42/build/libmlx42.a -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -g -c $< -o $@ -Iinclude -Ilibft/include 

$(LIBFT):
	@make --no-print-directory -C libft

clean:
	@make --no-print-directory clean -C libft
	@rm -f */*.o
	@rm -f *.o

fclean: clean
	@make --no-print-directory fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean