/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Tue Feb 24 10:58:12 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t m_creation = PTHREAD_MUTEX_INITIALIZER;

void	*init(void *arg)
{
  int	*data;

  data = *(int **)arg;
  pthread_mutex_lock(&m_creation);
  srand(time(0));
  data[1] = rand() % 3;
  printf("data[1] = %d\n", data[1]);
  pthread_mutex_unlock(&m_creation);
}

void		init_state(void *arg)
{
  int	*data;
  int	i;

  i = 0;
  data = *(int **)arg;
  while (i < 7)
    {
      if (data[i] == 2 /*MANGE*/)
	{
	  /*RANDOM 0 || 1
	    data[i + 1] = 0;REPOS;*/
	}
      else if (data[i] == 1 /*REFLECHIS*/)
	{
	  /*
	data[i + 1] = 2;
	  */
	}
      else
	{
	  /*
	data[i + 1] = 0 REPOS;*/
	}
      i++;
    }
}

void		*create_philo()
{
  int		i;
  pthread_t	th;
  pthread_t	*t_philo;
  int		*rice;
  int		*data;

  i = 0;
  if (((t_philo = malloc(sizeof(pthread_t) * 7)) == NULL) ||
      ((data = malloc(sizeof(int) * 7)) == NULL) ||
      ((rice = malloc(sizeof(int) * 7)) == NULL))
    return;
  while (i < 7)
    {
      pthread_create(&th, NULL, init, &data);
      rice[i] = 5;
      t_philo[i] = th;
      i++;
    }
  init_etat(&data);
}

int	main()
{
  //pthread_t     th_philo;

  //pthread_create(&th_philo, NULL, create_philo, NULL);
  //pthread_join(th_philo, NULL);

  create_philo();
  return (0);
}
