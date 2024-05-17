# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvieira <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 19:38:38 by fvieira           #+#    #+#              #
#    Updated: 2023/05/05 19:38:39 by fvieira          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

CXX = c++

CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Bureaucrat.cpp \
	Form.cpp
	

%.o:	%.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC) -o $(NAME)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all


.SILENT:
