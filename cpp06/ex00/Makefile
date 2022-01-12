NAME = convert

SRCS =	main.cpp Converter.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=gnu++98 -pedantic

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

sanitize: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address -o $(NAME) $(OBJS)

.PHONY: all clean fclean re
