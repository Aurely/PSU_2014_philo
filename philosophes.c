/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Sat Feb 28 13:23:57 2015 Trotier Marie
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philosophes.h"

void	init_philo(t_philo **tab)
{
  static int	i = 0;

  tab[i]->id = i;
  tab[i]->rice = INIT_RICE;
  tab[i]->state = REST;
  tab[i]->nb_think = 0;
  pthread_mutex_init(&(tab[i]->chopstik), NULL);
  ++i;
  while (i < PHIL)
    {
      tab[i]->id = i;
      tab[i]->state = REST;
      tab[i]->nb_think = 0;
      tab[i]->rice = INIT_RICE;
      pthread_mutex_init(&(tab[i]->chopstik), NULL);
      tab[i]->prev = tab[i - 1];
      tab[i - 1]->next = tab[i];
      ++i;
    }
  tab[0]->prev = tab[PHIL];
  tab[PHIL-1]->next = tab[0];
}

void		*action(void *arg)
{
  t_philo	*tab;

  tab = arg;
  if (tab->state == REST)
    {
      if ((pthread_mutex_trylock(&tab->chopstik) != 0) &&
	  (pthread_mutex_trylock(&tab->next->chopstik) != 0))
	/*printf("fonction EAT\n");*/
	func_eat(tab);
      else if ((pthread_mutex_trylock(&tab->chopstik) != 0) ||
	       (pthread_mutex_trylock(&tab->next->chopstik) != 0))
	/*printf("fonction THINK\n");*/
	func_think(tab);
      else
	/*printf("fonction REST\n");*/
	func_rest(tab);
    }
  else if (tab->state == EAT)
    {
      if ((pthread_mutex_trylock(&tab->chopstik) != 0) &&
	  (pthread_mutex_trylock(&tab->next->chopstik) != 0) &&
	  tab->rice != 0)
	/*printf("fonction EAT_n");*/
	func_eat(tab);
      else
	/*printf("fonction REST\n");*/
	func_rest(tab);
    }
  else/*THINK*/
    {
      if ((pthread_mutex_trylock(&tab->chopstik) != 0) &&
	  (pthread_mutex_trylock(&tab->next->chopstik) != 0))
	/*printf("fonction EAT\n");*/
	func_eat(tab);
      else
	/*printf("fonction THINK");*/
	func_think(tab);
    }
  return 0;
}

int		main()
{
  t_philo	**tab;
  pthread_t	th_philo;
  int		i;

  i = 0;
  if (!(tab = malloc(sizeof(t_philo) * PHIL)))
    return (-1);
  while (i < PHIL)
    if (!(tab[i++] = malloc(sizeof(t_philo))))
      return (-1);
  init_philo(tab);
  i = 0;
  while (i < PHIL)
    {
      pthread_create(&th_philo, NULL, action, *tab);
      ++i;
    }
  while (i < PHIL)
    free(tab[i++]);
  free(tab);
  return (0);
}
