/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Fri Feb 27 17:57:21 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <pthread.h>
#include "philosophes.h"

void	init_philo(t_philo **tab)
{
  int	i;

  i = 0;
  tab[i]->id = i;
  tab[i]->rice = INIT_RICE;
  tab[i]->nb_think = 0;
  pthread_mutex_init(&(tab[i]->chopstik), NULL);
  tab[i]->energy = 1;
  ++i;
  while (i < PHIL)
    {
      tab[i]->id = i;
      tab[i]->nb_think = 0;
      tab[i]->rice = INIT_RICE;
      pthread_mutex_init(&(tab[i]->chopstik), NULL);
      tab[i]->energy = 1;
      tab[i]->prev = tab[i - 1];
      tab[i - 1]->next = tab[i];
      ++i;
    }
  tab[0]->prev = tab[PHIL];
  tab[PHIL-1]->next = tab[0];
}



int		main()
{
  t_philo	**tab;
  int		i;

  i = 0;
  if (!(tab = malloc(sizeof(t_philo) * PHIL)))
    return (-1);
  while (i < PHIL)
    {
      if (!(tab[i] = malloc(sizeof(t_philo))))
	return (-1);
      ++i;
    }
  init_philo(tab);
  while (i < PHIL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
  return (0);
}
