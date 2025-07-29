# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cafabre <camille.fabre003@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 18:00:00 by cafabre           #+#    #+#              #
#    Updated: 2025/07/29 10:15:24 by cafabre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./
OPS_DIR = ./operations_src/
PARSING_DIR = ./parsing_src/
SORTING_DIR = ./sorting_src/
STACK_DIR = ./stack_src/
UTILS_DIR = ./utils_src/

SRCS = $(SRC_DIR)main.c \
	   $(SRC_DIR)push_swap.c \
	   $(UTILS_DIR)ft_atoi.c \
	   $(UTILS_DIR)utils.c \
	   $(PARSING_DIR)parse_args.c \
	   $(PARSING_DIR)check_errors.c \
	   $(STACK_DIR)stack_init.c \
	   $(STACK_DIR)stack_free.c \
	   $(STACK_DIR)stack_operations.c \
	   $(STACK_DIR)stack_utils1.c \
	   $(STACK_DIR)stack_utils2.c \
	   $(OPS_DIR)operations_swap.c \
	   $(OPS_DIR)operations_push.c \
	   $(OPS_DIR)operations_rotate1.c \
	   $(OPS_DIR)operations_rotate2.c \
	   $(SORTING_DIR)sort_small.c \
	   $(SORTING_DIR)sort_medium.c \
	   $(SORTING_DIR)sort_large.c \
	   $(SORTING_DIR)sort_optimize.c \
	   $(SORTING_DIR)normalize.c \
	   $(SORTING_DIR)push_back.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re