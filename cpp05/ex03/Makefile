NAME = a.out

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   Form.cpp \
	   PresidentialPardonForm.cpp \
	   RobotomyRequestForm.cpp \
	   ShrubberyCreationForm.cpp \
	   Intern.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
