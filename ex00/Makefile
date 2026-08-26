NAME := numbersDontExist
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -g

SRC := \
	   ScalarConverter.cpp \
	   main.cpp

SRC_DIR := src/
OBJ_DIR := obj/

OBJ := $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

