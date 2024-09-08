NAME = cub3D
CC = cc
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

SRC = 	main.c \
		ft_pexit.c \
		\
		parsing/ft_parsing.c \
		parsing/ft_check_arg_nbr.c \
		parsing/ft_check_map_file_extension.c \
		parsing/ft_get_text.c \
		parsing/ft_init_data.c \
		parsing/ft_cut_text.c \
		parsing/ft_store_map.c \
		parsing/ft_check_ids_good_path.c \
		parsing/ft_check_map_size.c \
		parsing/ft_check_map_one_good_char.c \
		parsing/ft_check_map_closed.c \
		parsing/ft_utils.c
#ft_init_png.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

all : $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -lm ./MLX42/build/libmlx42.a -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -g -c $< -o $@ -Iinclude -Ilibft/include -IMLX42/include/

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