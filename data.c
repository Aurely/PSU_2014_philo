/*
** data.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Tue Feb 24 11:13:06 2015 Trotier Marie
** Last update Thu Feb 26 20:11:32 2015 Trotier Marie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "philosophes.h"

void		func_eat(int philo, int next_philo, t_philo *my_philo)
{
  pthread_mutex_lock(&my_philo->baguette[philo]);
  my_philo->rice[philo] = my_philo->rice[philo] - 1;
  printf("philo %d -> fonction ---> eat     | O |\n", philo);
  printf("energy = %d\n\n", philo, my_philo->energy[philo]);
  pthread_mutex_unlock(&my_philo->baguette[philo]);
  /*
    lock ou unlock les mutex -> baguettes
    diminuer le nombre de riz
   */
}

void		func_think(int philo, int next_philo, t_philo *my_philo)
{
  if (my_philo->think[philo] < MAX_THINK || my_philo->think[philo] == MAX_THINK)
    func_rest(philo, next_philo, my_philo);
  else
    {
      pthread_mutex_lock(&my_philo->baguette[philo]);
      printf("philo %d -> fonction ---> think     | O |\n", philo);
      printf("philo %d -> energy = %d\n\n", philo, my_philo->energy[philo]);
      my_philo->think[philo] = my_philo->think[philo] + 1;
      pthread_mutex_unlock(&my_philo->baguette[philo]);
    }
}

void		func_rest(int philo, int next_philo, t_philo *my_philo)
{
  pthread_mutex_unlock(&my_philo->baguette[philo]);
  printf("philo %d -> fonction ---> rest     . O .\n", philo);
  printf("philo %d -> energy = %d\n\n", philo, my_philo->energy[philo]);
}
