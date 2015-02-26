##
## Makefile for philo in /home/lao_e/rendu/PSU_2014_philo
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Fri Feb 20 09:59:46 2015 Aurélie LAO
## Last update Thu Feb 26 19:50:11 2015 Trotier Marie
##

CC	=	gcc

RM	=	rm -f

NAME	=	philo

SRC	=	philosophes.c \
		data.c

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:
		$(CC) -o $(NAME) $(SRC) -lpthread

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
