NAME = cube

SRCS = 	main.c\
		ft_define_struct.c\
		ft_ultimate_free.c\
		ft_ray_casting.c

OBJS=$(SRCS:.c=.o)

RM=rm -f

CC= clang

CFLAGS= -I./MLX42/include -I./libft -g

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

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re