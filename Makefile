NAME = lem-in

SRC = ./src/main.c
OBJ = ./obj/main.o

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ./libft

.PHONY: clean fclean all re lib

all: lib $(NAME)

$(NAME): $(OBJ)
				@echo Compiling $(NAME)
				@$(GCC) $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L $(LIB) -lft
				@echo ======[Done]======

$(OBJ): ./obj/%.o : ./src/%.c
				@echo "$(NAME) >>> Add/Update $^"
	    		@$(GCC) $(FLAGS) -c -I $(INC) $< -o $@

lib:
				@$(MAKE) -C $(LIB)

clean:
				@$(MAKE) -C $(LIB) clean
				@echo Clean objects $(NAME)
				@rm -rf $(OBJ)

fclean: clean
				@$(MAKE) -C $(LIB) fclean
				@echo Clean $(NAME)
				@rm -rf $(NAME)
				@echo ======[Clean]======

re: fclean all
