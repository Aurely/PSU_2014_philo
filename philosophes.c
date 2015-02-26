/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Thu Feb 26 16:03:26 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "philosophes.h"

void		*create_philo(void *arg)
{
  static int	a = 0;
  int		b;
  t_philo	*tmp;

  tmp = arg;
  b = a;
  a++;
  if (pthread_mutex_trylock(&tmp->baguette[b]) != 0/* = Mutex unlock = Gauche libre*/)
    {
      if (pthread_mutex_trylock(&tmp->baguette[a]) != 0/* = mutex unlock = Droite libre*/)
	{
	  printf("fonction ---> eat       | + |\n");
	}
      else /* Droite prise */
	{
	  printf("fonction ---> think     | + .\n");
	}
     }
  else /* baguette de gauche prise*/
    {
      if (pthread_mutex_trylock(&tmp->baguette[a]) != 0/* = mutex unlock = Droite libre*/)
	{
	  printf("fonction ---> think     . + |\n");
	}
      else /* Droite prise*/ 
	{
	  printf("fonction ---> rest      . + .\n");
	}
    }
  sleep(1);
  return (NULL);
}

int	main()
{
  pthread_t     th_philo[PHIL];
  t_philo	my_philo;
  int		i;

  i = 0;
  while (i < PHIL)
    {
      my_philo.rice[i] = INIT_RICE;
      my_philo.state[i] = 'R';
      my_philo.energy[i] = '1';
      pthread_mutex_init(&my_philo.baguette[i], NULL);
      pthread_mutex_unlock(&my_philo.baguette[i]);
      pthread_create(&th_philo[i], NULL, create_philo, &my_philo);
      i++;
    }
  i = 0;
  while (i < PHIL)
    {
      pthread_join(th_philo[i], NULL);
      i = i + 1;
    }
  return (0);
}
