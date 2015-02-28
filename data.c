/*
** data.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Tue Feb 24 11:13:06 2015 Trotier Marie
** Last update Sat Feb 28 11:19:01 2015 Trotier Marie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "philosophes.h"

  //philo.next

void		func_eat(t_philo *philo)
{
  //  etat, baguettes et riz, nb_think
  if (philo.rice[PHIL] > 0)
    {
      pthread_mutex_lock(philo->chopstik);
      pthread_mutex_lock(philo->&next->chopstik);
      philo->rice = rice--;
      philo->nb_think = 0;
      philo->state = EAT;
      printf("philosophe %d -> eat     | O |\n", philo);
    }
  else
    func_rest(philo);
}

void		func_think(t_philo *philo)
{
  if (nb_think > MAX_THINK) //limitation de penser = 3
    {
      pthread_mutex_lock(philo->chopstik);
      //pthread_mutex_lock(philo->&next->chopstik);
      philo->nb_think++;
      philo->state = THINK;
      printf("philosophe %d -> think     | O .\n", philo);
    }
  else
    func_rest(philo);
}

void		func_rest(t_philo *philo)
{
  pthread_mutex_unlock(philo->chopstik);
  pthread_mutex_unlock(philo->&next->chopstik);
  philo->state = REST;
  philo->nb_think = 0;
  printf("philosophe %d -> rest     . O .\n", philo);
}
