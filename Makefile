NAME = push_swap
SRC = main.c\
		parsing.c\
		utils.c\
		commands.c\
		algorithm.c\
		chunks.c\

OBJS = ${SRC:.c=.o}
CFLAGS = -Werror -Wextra -Wall

all: ${NAME}

${NAME}:	${OBJS}
		gcc ${SRC} -o ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re