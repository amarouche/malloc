NAME=	libmy_malloc_$(shell uname).so

FINAL_NAME=	libmy_malloc.so

RM=		rm -f *.so

CC=		gcc

CFLAGS=		-fPIC -W -Wall -Werror

SRC=	    my_malloc.c \
		free.c \
		functions.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -o $(NAME) $(OBJ) $(CFLAGS)
		ln -s $(NAME) $(FINAL_NAME)
clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME) $(FINAL_NAME)

re:		fclean clean all
