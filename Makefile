NAME = lem-in

SRC =	./src/main.c \
		./src/check_number.c \
		./src/collect_number.c \
		./src/count_space.c \
		./src/ft_is_signed_integer.c \
		./src/ft_is_space_digit_str.c \
		./src/ft_isdigitstr.c \
		./src/check_link.c \
		./src/ft_strjoin_free.c \
		./src/check_x_y_line.c \
		./src/analyse_line.c \
		./src/implementation_data_val.c \
		./src/data_validation.c \
		./src/graph_add_link.c \
		./src/graph_add_room.c \
		./src/graph_create.c \
		./src/graph_tool.c

OBJ =	./obj/main.o \
		./obj/check_number.o \
		./obj/collect_number.o \
		./obj/count_space.o \
		./obj/ft_is_signed_integer.o \
		./obj/ft_is_space_digit_str.o \
		./obj/ft_isdigitstr.o \
		./obj/check_link.o \
		./obj/ft_strjoin_free.o \
		./obj/check_x_y_line.o \
		./obj/analyse_line.o \
		./obj/implementation_data_val.o \
		./obj/data_validation.o \
		./obj/graph_add_link.o \
		./obj/graph_add_room.o \
		./obj/graph_create.o \
		./obj/graph_tool.o

MAKE = make

GCC = gcc
FLAGS = -Wall -Werror -Wextra

INC = ./includes
LIB = ./libft

.PHONY: clean fclean all re lib

all: lib $(NAME)

$(NAME): $(OBJ) lem_in_ok
				@$(GCC) $(FLAGS) -o $(NAME) $(OBJ) -I $(INC) -L $(LIB) -lft
				@echo "> \\033[4;m$(NAME)\\033[0m  :  [\\033[38;5;214mOK\\033[0m]"

lem_in_ok :
			@echo -n \

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
