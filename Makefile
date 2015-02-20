##
## Makefile for philo in /home/lao_e/rendu/PSU_2014_philo
## 
## Made by Aurélie LAO
## Login   <lao_e@epitech.net>
## 
## Started on  Fri Feb 20 09:59:46 2015 Aurélie LAO
## Last update Fri Feb 20 10:03:03 2015 Aurélie LAO
##

CC	=	gcc

RM	=	rm -f

NAME	=	philo

SRC	=

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
