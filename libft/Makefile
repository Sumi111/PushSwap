NAME	= libft.a

CC		= gcc
CFLAG	= -Wall -Werror -Wextra
RM		=rm -f
AR		= ar
ARFLAG	= crs
SRCS_1	=ft_strlen.c ft_isdigit.c ft_split.c  ft_putstr_fd.c  

SRC	=$(SRCS_1)

OBJS	= $(SRC:.c=.o)

all	: $(NAME)

%.o : %.c
	@$(CC) $(CFLAG) -c $< -o $@

clean :
	@$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAG) $@ $^


 .PHONY : all clean fclean re
