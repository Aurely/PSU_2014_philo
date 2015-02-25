/*
** philosophes.h for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 18:19:08 2015 Trotier Marie
** Last update Wed Feb 25 18:04:17 2015 Aurélie LAO
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# define PHIL		7
# define MAX_EAT	3
# define MAX_THINK	3
# define INIT_RICE	10

typedef struct	s_philo
{
  pthread_mutex_t bagette[PHIL];
  char		stat[PHIL];
  int		rice[PHIL];
  int		energy[PHIL];
}		t_philo;

#endif /* !PHILOSOPHES_H_ */
