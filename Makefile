CC = gcc -Wall -Werror -Wextra -g -MMD
SRC = test.c ft_memcpy.c
OBJ = test.o ft_memcpy.o
NAME = a.out
all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(OBJ) -Lmlx -lmlx -lXext -lX11 -lm -O3 -o $(NAME)

%.o : %.c
	$(CC) -Imlx -Lmlx -lmlx -lXext -lX11 -lm -O3 -c $< -o $@

clean :
	rm -f test.o test.d

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY: re all clean fclean
-include test.d
