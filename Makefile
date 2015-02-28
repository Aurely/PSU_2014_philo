##
## Makefile for philo in /home/lao_e/rendu/PSU_2014_philo
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Fri Feb 20 09:59:46 2015 Aurélie LAO
## Last update Sat Feb 28 20:21:23 2015 Trotier Marie
##

CC	=	gcc

RM	=	rm -f

NAME	=	philo

SRC	=	philosophes.c \
		states.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -W -pedantic -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(SRC) -lpthread

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
