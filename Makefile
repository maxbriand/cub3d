NAME = cube

SRCS = 	mandatory/main.c\
		mandatory/ft_define_struct.c\
		mandatory/ft_ultimate_free.c\
		mandatory/ft_ray_casting.c\
		mandatory/ft_move.c\
		mandatory/ft_mouse_move.c\
		mandatory/ft_key_hook.c


BONUS = bonus/main.c\
		bonus/ft_define_struct.c\
		bonus/ft_ultimate_free.c\
		bonus/ft_ray_casting.c\
		bonus/ft_move.c\
		bonus/ft_mouse_move.c\
		bonus/ft_key_hook.c


OBJS=$(SRCS:.c=.o)

OBJS_BONUS=$(BONUS:.c=.o)

RM =rm -f

CC = clang

CFLAGS= -I./MLX42/include -I./libft -I./includes -g

MLXFLAGS= -Iinclude -ldl -lglfw -pthread -lm -Ofast #Ofast is supposed to have better performance, but i can remove it
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
	@cd MLX42 && cmake --build build -j4
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) ./libft/libft.a ./MLX42/build/libmlx42.a -o $(NAME)_bonus
	@if [ $$? -eq 0 ]; then \
		echo "\033[32;1mBonus compilation successful!\033[0m"; \
	fi



%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME) $(NAME)_bonus

re: fclean $(NAME)

.PHONY: all bonus clean fclean re