# ************************************************************************** #
#                                                                            #
#                                                        ::::::::            #
#   Makefile                                           :+:    :+:            #
#                                                     +:+                    #
#   By: tblaudez <tblaudez@student.codam.nl>         +#+                     #
#                                                   +#+                      #
#   Created: 2020/09/17 14:41:30 by tblaudez      #+#    #+#                 #
#   Updated: 2020/10/09 15:32:45 by tblaudez      ########   odam.nl         #
#                                                                            #
# ************************************************************************** #

NAME=convert

SRC= char.cpp int.cpp float.cpp double.cpp main.cpp
OBJ= $(SRC:%.cpp=%.o)

CC= /usr/bin/clang++
CFLAGS= -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME) "+inf"
	@./$(NAME) "-inf"
	@./$(NAME) "+inff"
	@./$(NAME) "-inff"
	@./$(NAME) "nan"
	@./$(NAME) "nanf"
	@./$(NAME) "42.424242f"
	@./$(NAME) "21.212121"
	@./$(NAME) "255"
	@./$(NAME) "@"

.PHONY: all clean fclean re run
