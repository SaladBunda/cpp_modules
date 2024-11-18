SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed2

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME) 

work: $(NAME) clean

re: fclean all