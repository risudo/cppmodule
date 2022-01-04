NAME = phonebook

SRCS = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=gnu++98

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

sanitize: $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=undefined -fsanitize=address -o $(NAME) $(OBJS)


.PHONY: all clean fclean re
