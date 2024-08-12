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
		parsing/ft_get_text.c \
		parsing/ft_init_data.c \
		parsing/ft_cut_text.c \
		parsing/ft_store_map.c \
		parsing/ft_ids_good_path.c \
		parsing/ft_map_only_good_char.c \
		parsing/ft_map_closed.c \

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