# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:41:41 by sfathima          #+#    #+#              #
#    Updated: 2022/04/27 13:20:24 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIB_DIR	= libft
LIB		= libft.a

SRC_DIR = srcs
OBJ_DIR	= obj
INC_DIR	= include

SRCS = main.c ft_check.c sort.c sort_big.c sort_small.c quick_sort.c stack_a.c stack_b.c utlis.c  ft_atoi.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%c=%o))

CC 		= gcc
CFLAG	= -g -Wall -Werror -Wextra
AR		= ar crs
RM		= rm -rf

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAG) -I $(INC_DIR) -I $(LIB_DIR) -c $< -o $@

all: $(NAME)

$(NAME):  $(LIB) $(OBJS) 
		@$(CC) $(CFLAG) $(OBJS) $(LIB_DIR)/$(LIB) -o $@
		
$(LIB):
	@make -C $(LIB_DIR) all

clean:
		@make -C $(LIB_DIR) fclean
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
	