/*
** data.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Tue Feb 24 11:13:06 2015 Trotier Marie
** Last update Thu Feb 26 19:40:21 2015 Trotier Marie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void		func_eat(int philo, int next_philo, t_philo my_philo, int b)
{
  pthread_mutex_lock(&baguette);
  my_philo.rice[philo] = my_philo.rice[philo] - 1;
  printf("philo %d -> fonction ---> eat     | O |\n", b);
  pthread_mutux_unlock(&baguette);
  /*
    lock ou unlock les mutex -> baguettes
    diminuer le nombre de riz
   */
}

void		func_think(int philo, int next_philo, t_philo my_philo, int b)
{
  if (my_philo.think[philo] < MAX_THINK || my_philo.think[philo] == MAX-THINK)
    func_rest(philo, next_philo, b);
  else
    {
      pthread_mutex_lock(baguette[philo]);
      printf("philo %d -> fonction ---> think     | O |\n", b);
      my_philo.think[philo] = my_phuli.think[philo] + 1;
      pthread_mutex_unlock(baguette[philo]);
    }
}

void		func_rest(int philo, int next_philo, int b)
{
  pthread_mutex_unlock(&baguette);
  printf("philo %d -> fonction ---> rest     . O .\n", b);
}
