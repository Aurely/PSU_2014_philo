/*
** ex2.c for  in /home/lao_e/rendu/PSU_2014_philo/threads_exemple/ex2
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Feb 22 10:07:27 2015 Aurélie LAO
** Last update Sun Feb 22 10:31:50 2015 Aurélie LAO
*/

#include <pthread.h>
#include <stdio.h>

int		size = 0;
pthread_mutex_t m_prod = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m_cons = PTHREAD_MUTEX_INITIALIZER;

void		*producer(void *arg)
{
  while (42)
    {
      pthread_mutex_lock(&m_prod);
      ++size;
      pthread_mutex_unlock(&m_cons);
    }
}

void		*consumer(void *arg)
{
  int		i;
  int		v;

  i = 0;
  while (i < 100)
    {
      pthread_mutex_lock(&m_cons);
      v = size;
      pthread_mutex_unlock(&m_prod);
      printf("-> %d : %d\n", i, v);
      ++i;
    }
}

int		main()
{
  pthread_t	th_prod;
  pthread_t	th_cons;

  pthread_create(&th_prod, NULL, producer, NULL);
  pthread_create(&th_cons, NULL, consumer, NULL);
  pthread_join(th_cons, NULL);
  return 0;
}
