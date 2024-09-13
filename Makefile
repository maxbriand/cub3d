NAME = cub3D

PARS =  parsing/ft_pexit.c \
		parsing/ft_init_png.c \
		parsing/ft_check_arg_nbr.c \
		parsing/ft_check_ids_good_path.c \
		parsing/ft_check_map_closed.c \
		parsing/ft_check_map_file_extension.c \
		parsing/ft_check_map_one_good_char.c \
		parsing/ft_check_map_size.c \
		parsing/ft_cut_text.c \
		parsing/ft_get_text.c \
		parsing/ft_init_data.c \
		parsing/ft_parsing.c \
		parsing/ft_store_map.c \
		parsing/ft_utils.c

SRCS = 	mandatory/main.c \
		mandatory/ft_define_struct.c \
		mandatory/ft_ultimate_free.c \
		mandatory/ft_ray_casting.c \
		mandatory/ft_move.c \
		mandatory/ft_mouse_move.c \
		mandatory/ft_key_hook.c \
		mandatory/ft_print_ray.c \
		mandatory/ft_move_hook.c \
		mandatory/ft_print_fps.c \
		mandatory/ft_define_color_text.c

BONUS = bonus/main.c \
		bonus/ft_define_struct_bonus.c \
		bonus/ft_ultimate_free_bonus.c \
		bonus/ft_ray_casting_bonus.c \
		bonus/ft_move_bonus.c \
		bonus/ft_mouse_move_bonus.c \
		bonus/ft_key_hook_bonus.c \
		bonus/ft_print_ray_bonus.c \
		bonus/ft_move_hook_bonus.c \
		bonus/ft_print_fps_bonus.c \
		bonus/ft_define_color_text_bonus.c

OBJS=$(SRCS:.c=.o) $(PARS:.c=.o)

OBJS_BONUS=$(BONUS:.c=.o) $(PARS:.c=.o)

RM =rm -f

CC = cc

CFLAGS= -I./MLX42/include -I./libft/include -I./includes -Wall -Werror -Wextra -g

MLXFLAGS= -Iinclude -L./MLX42/build -lmlx42 -ldl -lglfw -pthread -lm -Ofast

MLX_INCLUDE_FLAGS = -I/usr/include -Imlx_linux -O3 -c

all: $(NAME)

$(NAME) : $(OBJS)
	@make --directory=./libft
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j4
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) ./libft/libft.a ./MLX42/build/libmlx42.a -o $@
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mCompilation successful!\033[0m"; \
	fi

bonus: $(OBJS_BONUS)
	@make --directory=./libft
	@cd MLX42 && cmake -B build
	@cd MLX42 && cmake --build build -j16
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) ./libft/libft.a ./MLX42/build/libmlx42.a -o $(NAME)_bonus
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mBonus compilation successful!\033[0m"; \
	fi


%.o: %.c
	$(CC) $(CFLAGS) $(MLX_INCLUDES_FLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME) $(NAME)_bonus

re: fclean $(NAME)

.PHONY: all bonus clean fclean re