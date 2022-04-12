NAME	=	server
NAME2	=	client

INCLUDE	=	-I./includes \
			-I./libft/includes

LIBFT	=	-L./libft -lft

SRCS	=	server.c
SRCS2	=	client.c

OBJS	=	${SRCS:.c=.o}
OBJS2	=	${SRCS2:.c=.o}

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME) $(NAME2)

$(NAME)	:	$(OBJS)
			$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(OBJS) -o $(NAME)

$(NAME2) :	$(OBJS2)
			$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(OBJS2) -o $(NAME2)

.c.o	:	
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

clean	:	
			$(RM) $(OBJS)
			$(RM) $(OBJS2)

fclean	:	clean
			$(RM) $(NAME)
			$(RM) $(NAME2)

re		:	fclean all

.PHONY	:	all clean fclean re