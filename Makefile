SOURCES =	main.c	./utils/init.c	./utils/move.c	./utils/getter.c	./utils/map_utils.c	./utils/map.c	./utils/error.c	./utils/error_utils.c	./utils/img.c

OBJ =	$(SOURCES:.c=.o)
CC	=	gcc -g
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	so_long

all: $(NAME)

printf = ./ft_printf/libftprintf.a

libft = ./libft/libft.a

MLX = ./minilibx-linux/libmlx_Linux.a

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SOURCES) $(MLX) $(libft) $(printf) -lXext -lX11

	@echo "\[\033[4;35m                                                            \n\
	  ▄████████  ▄██████▄          ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄      \n\
	 ███    ███ ███    ███        ███         ███    ███ ███▀▀▀██▄   ███    ███     \n\
	 ███    █▀  ███    ███        ███         ███    ███ ███   ███   ███    █▀      \n\
	 ███        ███    ███        ███         ███    ███ ███   ███  ▄███            \n\
	███████████ ███    ███        ███         ███    ███ ███   ███ ▀▀███ ████▄      \n\
	        ███ ███    ███        ███         ███    ███ ███   ███   ███    ███     \n\
	  ▄█    ███ ███    ███        ███▌     ▄  ███    ███ ███   ███   ███    ███     \n\
	▄████████▀   ▀██████▀  █████  ███████▄▄██  ▀██████▀   ▀█   █▀    ████████▀      \n\
                                                                       	 		\033[0m"
	@echo "                                \033[44mBy: Ayoub0x1"

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all