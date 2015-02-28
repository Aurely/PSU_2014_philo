/*
** data.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Tue Feb 24 11:13:06 2015 Trotier Marie
** Last update Sat Feb 28 15:20:37 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "philosophes.h"

void		func_eat(t_philo *philo)
{
  /*  etat, baguettes et riz, nb_think*/
  if (philo->rice > 0)
    {
      pthread_mutex_lock(&(philo->chopstik));
      pthread_mutex_lock(&(philo->next->chopstik));
      philo->rice--;
      philo->nb_think = 0;
      philo->state = EAT;
      printf("philosophe %d -> eat     | O |\n", philo->id);
    }
  else
    func_rest(philo);
}

void		func_think(t_philo *philo)
{
  if (philo->nb_think < MAX_THINK)
    {
      pthread_mutex_lock(&(philo->chopstik));
      /*pthread_mutex_lock(philo->&next->chopstik);*/
      philo->nb_think++;
      philo->state = THINK;
      printf("philosophe %d -> think     | O .\n", philo->id);
    }
  else
    func_rest(philo);
}

void		func_rest(t_philo *philo)
{
  pthread_mutex_unlock(&(philo->chopstik));
  pthread_mutex_unlock(&(philo->next->chopstik));
  philo->state = REST;
  philo->nb_think = 0;
  printf("philosophe %d -> rest     . O .\n", philo->id);
}
