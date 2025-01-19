SRCS = Form.cpp Bureaucrat.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = interns

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) 

fclean: clean
	rm -rf $(NAME) 

work: $(NAME) clean

re: fclean all