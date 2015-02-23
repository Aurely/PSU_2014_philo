/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Mon Feb 23 19:03:38 2015 Trotier Marie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t m_creation = PTHREAD_MUTEX_INITIALIZER;

void	*init(void *arg)
{
  static int	i = 0;
  int	*data;
  int	rd;
  
  data = *(int **)arg;
  srand(time(NULL));
  rd = rand()%3;
  data[i] = rd;
  i++;
 
  // pthread_mutex_lock(&m_creation);
  // pthread_mutex_unlock(&m_creation);
}

void		*create_philo()
{
  int		i;
  pthread_t	th;
  pthread_t	t_philo[7];
  int		rice[7];
  int		data[7];

  i = 0;
  while (i < 7)
    {
      pthread_create(&th, NULL, init, &data);
      rice[i] = 5;
      t_philo[i] = th;
      printf("%d philosophes\n", i);
      i++;
    }
}

int	main()
{
  //pthread_t     th_philo;

  //pthread_create(&th_philo, NULL, create_philo, NULL);
  //pthread_join(th_philo, NULL);

  create_philo();
  return (0);
}
