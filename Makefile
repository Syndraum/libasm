SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCC = main.c

OBJS = ${SRCS:.s=.o}
OBJC = ${SRCC:.c=.o}

NAME = libasm.a
NAME_TEST = libasm.out

RM	= rm -f

CC = gcc

CFLAG = -Wall -Wextra -Werror

all:	${NAME}

.s.o:
	nasm -fmacho64 $<

.c.o:
	${CC} ${CFLAG} -c  $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

test:	${NAME} ${OBJC}
	${CC} ${NAME} ${OBJC} -o ${NAME_TEST}

clean :
	${RM} ${OBJS} ${OBJC}

fclean:	clean
	${RM} ${NAME}
	${RM} ${NAME_TEST}

re: 	fclean all