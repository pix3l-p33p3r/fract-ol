NAME = fractol
# 	* command to compile our functions
CFLAGS	= -g3 -Wall -Werror -Wextra 
CFLAGS += -fsanitize=address
CC	= cc
# 	* functions that must be compiled through our makefile
SRCS    = main.c 

# 	* create our executable file
# 	* replace all files with .c extension to .o extension
OBJ 	= $(SRCS:.c=.o)



%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

run: re
	./$(NAME)
