NAME = a.out

SRCS =	main.cpp \
		Ice.cpp \
		Cure.cpp \
		AMateria.cpp \
		Character.cpp \
		MateriaSource.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++ -std=gnu++98 -pedantic
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
