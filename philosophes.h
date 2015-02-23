/*
** philosophes.h for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 18:19:08 2015 Trotier Marie
** Last update Mon Feb 23 18:24:13 2015 Trotier Marie
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

typedef struct	s_philo {
  pthread_t	th_philo;  
  char		*name;
  int		rice;
}		t_philo;


typedef struct	s_state {
  int		etat;
}		t_state;

#define true 1
#define false 0

#endif /* !PHILOSOPHES_H_ */
