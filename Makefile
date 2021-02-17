NAME	   = libftprintf

INC_DIR	   = .

SRCS	   = ft_printf.c ft_printf_utils.c ft_printf_x_p.c ft_printf_all_exept_x_p.c ft_strchr.c ft_atoi.c ft_isdigit.c ft_putstr_fd.c ft_itoa.c ft_strlen.c ft_itoa_base.c

OBJS	   = ${SRCS:.c=.o}

DEPS	   = ft_printf.h

CFLAGS	   = -Wall -Wextra -Werror -I${INC_DIR}

AR		   = ar rc

.c.o :		${DEPS}
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			${AR} ${NAME}.a ${OBJS}

bonus:		${BONUS_OBJS}
			${AR} ${NAME}.a ${BONUS_OBJS}

clean:		
			rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}.a

re:			fclean all

.PHONY:		all clean fclean re