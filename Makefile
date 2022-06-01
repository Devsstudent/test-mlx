CC = gcc -Wall -Werror -Wextra
SRC = test.c
OBJ = test.o
NAME = a.out
all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(OBJ) -Imlx -Lmlx -lmlx -lXext -lX11 -lm -O3 -o $(NAME)

%.o : %.c
	$(CC) -Imlx -Lmlx -lmlx -lXext -lX11 -lm -O3 -c $< -o $@

clean :
	rm -f test.o

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY: re all clean fclean 
