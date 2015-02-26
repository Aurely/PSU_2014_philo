/*
** philosophes.h for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 18:19:08 2015 Trotier Marie
** Last update Thu Feb 26 15:46:24 2015 Aurélie LAO
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# define PHIL		7
# define MAX_THINK	3
# define INIT_RICE	10

typedef struct	s_philo
{
  pthread_mutex_t baguette[PHIL];
  char		state[PHIL];
  int		rice[PHIL];
  int		energy[PHIL];
}		t_philo;

#endif /* !PHILOSOPHES_H_ */
