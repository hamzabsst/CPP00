NAME	= phonebook
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS 	= main.cpp phonebook.cpp

OBJS	= $(SRCS:.cpp=.o)

INC		= phonebook.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
