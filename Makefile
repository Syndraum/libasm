SRC_DIR		= srcs
C_DIR		= c
INCLUDE_DIR	= includes

SRCS = $(addprefix  $(SRC_DIR)/, \
			ft_strlen.s \
			ft_strcpy.s \
			ft_strcmp.s \
			ft_write.s \
			ft_read.s \
			ft_strdup.s \
		)

SRCS_B = $(addprefix $(SRC_DIR)/, \
			ft_atoi_base_bonus.s \
			ft_strstr.s \
			ft_list_push_front_bonus.s \
			ft_list_size_bonus.s \
			ft_list_sort_bonus.s \
			ft_list_remove_if_bonus.s \
		)

SRCS_C = $(addprefix $(C_DIR)/, \
			bonus.c \
			ft_atoi_base.c \
			list.c \
		)

SRCS_M = main.c

OBJS = ${SRCS:.s=.o}
OBJS_B = ${SRCS_B:.s=.o}
OBJS_C = ${SRCS_C:.c=.o}
OBJS_M = ${SRCS_M:.c=.o}

INCLUDES = $(addprefix, $(INCLUDE_DIR), header.h)
INCLUDE_BONUS	= $(addprefix, $(INCLUDE_DIR), bonus.h)

NAME	= libasm.a
TEST	= libasm

RM	= rm -f

CC = gcc

CFLAG = -Wall -Wextra -Werror

.s.o:
	nasm -fmacho64 $<

.c.o:
	${CC} ${CFLAG} -c  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} ${INCLUDES}
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_B} ${INCLUDES} ${INCLUDES_BONUS}
	ar rc ${NAME} ${OBJS} ${OBJS_B}

test: ${TEST}

${TEST}:	${NAME} ${OBJS_M}
	${RM} $(OBJS_C)
	${CC} ${NAME} ${OBJS_M} -o ${TEST}

more:	bonus ${OBJS_C}
	${RM} $(OBJS_M)
	${CC} ${NAME} ${OBJS_C} -o ${TEST}

clean :
	${RM} ${OBJS} ${OBJS_M} ${OBJS_B} ${OBJS_C}

fclean:	clean
	${RM} ${NAME}
	${RM} ${TEST}

re: 	fclean all

.PHONY: all bonus test more clean fclean re