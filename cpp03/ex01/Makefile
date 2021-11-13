NAME = a.out

SRCS =	main.cpp \
		ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++ -std=gnu++98
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
