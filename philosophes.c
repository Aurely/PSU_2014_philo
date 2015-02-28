/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Sat Feb 28 19:20:20 2015 Aurélie LAO
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

  tab = (t_philo*)arg;
  while (tab->state != DEATH)
    {
      if (tab->state == THINKG || tab->state == THINKD)
	{
	  if (tab->nb_think > MAX_THINK)
	    tab->state = REST;
	  if (tab->rice > 0)
	    {
	      if (tab->state == THINKG)
		{
		  if ((pthread_mutex_lock(&tab->next->chopstik) == 0))
		    tab->state = EAT;
		}
	      else
		if ((pthread_mutex_lock(&tab->chopstik) == 0))
		  tab->state = EAT;
	    }
	  else
	    {
	      if (tab->state == THINKG)
		pthread_mutex_unlock(&tab->chopstik);
	      else
		pthread_mutex_unlock(&tab->next->chopstik);
	      tab->state = DEATH;
	    }
	}
      else if (tab->state == REST)
	{
	  tab->nb_think = 0;
	  if (tab->rice > 0)
	    {
	      if ((pthread_mutex_trylock(&tab->chopstik) == 0))
		{
		  if ((pthread_mutex_trylock(&tab->next->chopstik) == 0))
		    tab->state = EAT;
		  else
		    pthread_mutex_unlock(&tab->chopstik);
		}
	      if (tab->state != EAT && pthread_mutex_trylock(&tab->chopstik) != 0)
		tab->state = THINKG;
	      else if (tab->state != EAT && pthread_mutex_trylock(&tab->next->chopstik) != 0)
		tab->state = THINKD;
	    }
	  else
	    tab->state = DEATH;
	}
      else if (tab->state == EAT)
	{
	  tab->nb_think = 0;
	  pthread_mutex_unlock(&tab->chopstik);
	  pthread_mutex_unlock(&tab->next->chopstik);
	  tab->state = REST;
	  tab->rice = tab->rice - 1;
	}
    }
  pthread_exit(0);
  return NULL;
}

int		main()
{
  t_philo	**tab;
  pthread_t	threads[PHIL];
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
      pthread_create(&(threads[i]), NULL, &action, tab[i]);
      ++i;
    }
  i = 0;
  while (i < PHIL)
    {
      pthread_join(threads[i++], NULL);
    }
  /* while (i < PHIL) */
  /*   free(tab[i++]); */
  /* free(tab); */
  return (0);
}
