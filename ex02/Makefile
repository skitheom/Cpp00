# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 16:15:58 by sakitaha          #+#    #+#              #
#    Updated: 2025/01/17 03:53:30 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
NAME     := ex02
SRCS     := Account.cpp tests.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) tmp.log

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: CXXFLAGS += -DACCOUNT_USE_FIXED_TIMESTAMP
test: re
	@echo "== Running Tests =="
	./$(NAME) > tmp.log
	diff --color 19920104_091532.log tmp.log || (echo "Test Failed"; exit 1)
	@echo "== Tests Completed =="


debug: CXXFLAGS += -fsanitize=address -g
debug: $(NAME)
	./$(NAME)

valgrind: all
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re debug leaks valgrind test
