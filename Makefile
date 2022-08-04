SERVER	 	= server.c

OBJSSERVER  = $(SERVER:.c=.o)

CLIENT		= client.c

OBJSCLIENT  = $(CLIENT:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra 
RM 			= rm -f

NAME		= minitalk

$(NAME):	server client

all:		$(NAME)

server: 	server.o
			$(CC) $(CFLAGS) server.o -o server

client: 	client.o
			$(CC) $(CFLAGS) client.o -o client

clean:
		$(RM) $(OBJSSERVER) $(OBJSCLIENT)

fclean:		clean
			$(RM) server client

re:			fclean all

.PHONY:		all clean fclean re 