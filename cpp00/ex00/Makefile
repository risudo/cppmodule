NAME	=	megaphone

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)

CXX			=	clang++ 
CXXFLAGS	=	-Wall -Wextra -Werror -std=gnu++98
all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
