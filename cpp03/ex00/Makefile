NAME = a.out

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=gnu++98 -pedantic

SRCS_TEST = ClapTrap.cpp
SRCS =	main.cpp $(SRCS_TEST)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
