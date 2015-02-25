/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Wed Feb 25 17:53:10 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "philosophes.h"

pthread_mutex_t m_creation = PTHREAD_MUTEX_INITIALIZER;

/* void	*init(void *arg) */
/* { */
/*   int	*data; */

/*   data = *(int **)arg; */
/*   pthread_mutex_lock(&m_creation); */
/*   data[1] = rand() % 3; */
/*   printf("data[1] = %d\n", data[1]); */
/*   pthread_mutex_unlock(&m_creation); */
/* } */

/* void		init_state(void *arg) */
/* { */
/*   int	*data; */
/*   int	i; */

/*   i = 0; */
/*   data = *(int **)arg; */
/*   while (i < 7) */
/*     { */
/*       if (data[i] == EAT) */
/* 	func_eat(&data, i + 1, 3); */
/*       else if (data[i] == THINK) */
/* 	func_think(&data, i + 1); */
/*       else */
/* 	func_rest(&data, i + 1); */
/*       i++; */
/*     } */
/* } */

/* void		*create_philo() */
/* { */
/*   int		i; */
/*   pthread_t	th; */
/*   pthread_t	*t_philo; */
/*   int		*rice; */
/*   int		*data; */

/*   i = 0; */
/*   srand(time(0)); */
/*   if (((t_philo = malloc(sizeof(pthread_t) * 7)) == NULL) || */
/*       ((data = malloc(sizeof(int) * 7)) == NULL) || */
/* -      ((rice = malloc(sizeof(int) * 7)) == NULL)) */
/*     return; */
/*   while (i < 7) */
/*     { */
/*       /\* pthread_create(&th, NULL, init, &data); *\/ */
/*       rice[i] = 5; */
/*       t_philo[i] = th; */
/*       i++; */
/*     } */
/*   init_etat(&data); */
/* } */

void		*create_philo(void *arg)
{
  static int	a = 0;
  int		b;
  t_philo	*tmp;

  tmp = arg;
  b = a;
  a++;
  if (pthread_mutex_trylock(*tmp->baguette[b]) != 0/* = Mutex unlock = Gauche libre*/)
    {
      if (pthread_mutex_trylock(*tmp->baguette[a]) != 0/* = mutex unlock = Droite libre*/)
	{
	  
	}
      else
	{
	}
    }
  else /* baguette de gauche prise*/
    {

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
      my_philo.rice[i] = 5;
      my_philo.state[i] = 'R';
      my_philo.energy[i] = '1';
      my_philo.baguette[i] = PTHREAD_MUTEX_INITIALIZER;
      pthread_mutex_unlock(*my_philo.baguette[i]);
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
