NAME = a.out

SRCS = main.cpp \
	   span.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

g: CXXFLAGS += -g
g: re

-include $(DEPS)

.PHONY: all clean fclean re
