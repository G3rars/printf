CC = gcc

CFLAGS = -Werror -Wextra -Wall -I.

SRC_DIR = src/

LIBS_DIR = libft

LIBFT = libft/libft.a

TEST = test

SOURCE =  $(SRC_DIR)ft_printf.c

OBJ_O = $(SOURCE:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_O)
	cp $(LIBFT) $(NAME)
	ar -crs $@ $(OBJ_O)

$(LIBFT):
	$(MAKE) -C $(LIBS_DIR) bonus

clean:
	rm -f $(OBJ_O) && rm -f $(TEST)
	$(MAKE) -C $(LIBS_DIR) clean

fclean: clean 
	rm -f $(NAME)
	rm -f $(TEST)
	$(MAKE) -C $(LIBS_DIR) fclean

re: fclean all

.PHONY: libft 

# ESTAS REGLAS SON UNICAMENTE PARA HACER PRUEBAS

test: $(LIBFT) $(NAME) main.c
	$(CC) -o $(TEST) $(CFLAGS) main.c -lft -L. -lftprintf -L./$(LIBS_DIR)


