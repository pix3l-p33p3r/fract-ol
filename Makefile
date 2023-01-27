NAME = fractol

CFLAGS	= -Wall -Werror -Wextra
CFLAGS += -O2 -g3 -fsanitize=address
CC	= cc

SRCS    = sources/main.c \
		sources/mandelbrot_4th.c \
		sources/julia.c \
		sources/mandelbrot.c \
		sources/plan.c \
		sources/zoom.c \
		sources/utils.c \
		sources/colors.c \
		sources/render.c \
		sources/put_pixel.c \
		sources/events.c \

OBJ 	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

