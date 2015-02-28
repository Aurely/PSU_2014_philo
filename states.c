/*
** states.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sat Feb 28 20:13:56 2015 Trotier Marie
** Last update Sat Feb 28 20:24:33 2015 Trotier Marie
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philosophes.h"

void	func_eat(t_philo *tab)
{
  tab->nb_think = 0;
  pthread_mutex_unlock(&tab->chopstik);
  pthread_mutex_unlock(&tab->next->chopstik);
  tab->state = REST;
  tab->rice = tab->rice - 1;
}

void	func_think(t_philo *tab)
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

void	func_rest(t_philo *tab)
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
