CC			= c++ -Wall -Wextra -Werror -std=c++98
RM			= rm -rf
NAME		= ./megaphone
NAME_SHORT	= megaphone

SRCS_DIR 	= .
SRCS		= megaphone.cpp


$(NAME)		: $(SRCS)
			@$(CC) $(SRCS) -o $(NAME)

clean		:

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
