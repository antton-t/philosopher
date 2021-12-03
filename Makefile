# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antton-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 13:05:00 by antton-t          #+#    #+#              #
#    Updated: 2021/12/03 17:20:32 by antton-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
HEAD = -Iincludes
CFLAGS = -Wall -Wextra $(DEBUG)
DEBUG = -fsanitize=thread -g3

FILES = main.c ft_atoi.c ft_check_parse_argv.c \
				ft_print.c ft_get_time.c \
				ft_start_dinner.c ft_start_philo.c \
				ft_free.c ft_sleep.c ft_eat.c\
				ft_check_alive.c ft_tools.c ft_itoa.c\
				ft_death.c \
				
SRC_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRC_PATH), $(dir))

OBJ_PATH = objs
OBJ = $(addprefix $(OBJ_PATH)/, $(FILES:%.c=%.o))

all :   $(NAME) 

$(NAME) : $(OBJ_PATH) $(OBJ)
	$(CC) -pthread $(CFLAGS) $(HEAD) $(OBJ) -o ${NAME}

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : %.c
	$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

print:
	@echo $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
