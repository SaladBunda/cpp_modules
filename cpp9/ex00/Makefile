SRCS =  main.cpp BitcoinExchange.cpp HelperFunctions.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = btc

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME) 

work: $(NAME) clean

re: fclean all