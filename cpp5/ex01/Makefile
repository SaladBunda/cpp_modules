SRCS = Form.cpp Bureaucrat.cpp main.cpp 
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = forms

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME) 

work: $(NAME) clean

re: fclean all