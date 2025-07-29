### Variablen ###

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBS = 	../ft_printf/libftprintf.a \
		../libft/libft.a

SRC = 	push_swap.c \
		push_swap_utils.c \
		conditions_one.c \
		conditions_two.c \
		simple.c \
		turk.c \
		turk_utils_one.c \
		turk_utils_two.c \
		utils_one.c \
		utils_two.c

# convert from .c to .o
OBJ = $(SRC:%.c=%.o)

all: $(NAME) 

# Rule to compile and link only when necessary
$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

# Rule to compile .c files into .o files (Prevents unnecessary relinking)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

print_obj:
	@echo $(OBJ)
