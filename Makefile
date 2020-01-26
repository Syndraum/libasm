SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s
SRCC = main.c

OBJS = ${SRCS:.s=.o}
OBJC = ${SRCC:.c=.o}

NAME = libasm.out

RM	= rm -f

CC = gcc

CFLAG = -Wall -Wextra -Werror

all:	${NAME}

.s.o:
	nasm -fmacho64 $<

.c.o:
	${CC} ${CFLAG} -c  $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${OBJC}
	${CC} -Wl,-no_pie -o ${NAME} ${OBJS} ${OBJC}

clean :
	${RM} ${OBJS} ${OBJC}

fclean:	clean
	${RM} ${NAME}

re: 	fclean all