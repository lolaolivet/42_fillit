# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrigal <mrigal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 16:08:54 by mrigal            #+#    #+#              #
#    Updated: 2018/01/10 10:23:36 by lolivet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

SRC_PATH	= ./
INC_PATH	= ./
LIB_PATH	= libft/
OBJ_PATH	= obj/

CC			= gcc
CC_FLAGS	= -Werror -Wextra -Wall

SRC_NAME	= main.c backtracking.c test.c placefirst.c
INC_NAME	= fillit.h

SRCS		= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS		= $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INCS		= $(addprefix -I,$(INC_PATH))

OBJ_NAME	= $(SRC_NAME:.c=.o)

.PHONY: all, $(NAME), clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_PATH)
	$(CC) -o $(NAME) $(OBJS) -lm -L $(LIB_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INCS) -o $@ -c $<

clean:
	make -C $(LIB_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)

re: fclean all
