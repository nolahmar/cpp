CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:	phonebook

phonebook:	main.o phonebook.o contact.o
	$(CC)	$(CFLAGS) main.o phonebook.o contact.o -o phonebook

main.o: main.cpp phonebook.hpp contact.hpp
	$(CC)	$(CFLAGS) -c main.cpp

phonebook.o: phonebook.cpp phonebook.hpp contact.hpp
	$(CC)	$(CFLAGS) -c phonebook.cpp

contact.o: contact.cpp contact.hpp
	$(CC)	$(CFLAGS) -c contact.cpp

fclean:
	rm -f *.o phonebook
	