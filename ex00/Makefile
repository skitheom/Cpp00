# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 15:29:24 by sakitaha          #+#    #+#              #
#    Updated: 2024/11/23 19:07:36 by sakitaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM       := rm -f
TARGET   := megaphone
SRCS     := megaphone.cpp
OBJS     := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

test: $(TARGET)
	@echo "== Running Tests =="
	./$(TARGET) "shhhhh... I think the students are asleep..."
	./$(TARGET) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(TARGET)
	@echo "== Tests Completed =="

debug: all
	valgrind --leak-check=full ./$(TARGET)

.PHONY: all clean fclean re test debug
