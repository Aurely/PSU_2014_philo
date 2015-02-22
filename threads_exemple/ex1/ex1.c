/*
** ex1.c for  in /home/lao_e/rendu/PSU_2014_philo/threads_exemple/ex1
** 
** Made by Aurélie LAO
** Login   <lao_e@epitech.net>
** 
** Started on  Sun Feb 22 09:39:15 2015 Aurélie LAO
** Last update Sun Feb 22 10:05:12 2015 Aurélie LAO
*/

#include <pthread.h>
#include <time.h>
#include <stdio.h>

void		*func1(void *arg)
{
  /* int		i; */
  char		*str;

  /* i = *(int *)arg; */
  str = *(char **)arg;
  printf("str1 = %s\n", str);
  sleep(1);
  pthread_exit(0);
}

void		*func2(void *arg)
{
  /* int		i; */
  char		*str;

  /* i = *(int *)arg; */
  str = *(char **)arg;
  printf("str2 = %s\n", str);
  sleep(2);
  pthread_exit(0);
}

int		main()
{
  pthread_t	th1;
  pthread_t	th2;
  /* int		nb1; */
  /* int		nb2; */
  char		*str1;
  char		*str2;

  /* nb1 = 45; */
  /* nb2 = 67; */
  str1 = "test du premier";
  str2 = "test du second";

  /*
    PROTOTIPE DE CREATE :
    int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
			void *(*start_routine) (void *), void *arg);
  */

  /* pthread_create(&th1, NULL, func1, &nb1); */
  /* pthread_create(&th2, NULL, func2, &nb2); */
  pthread_create(&th1, NULL, func1, &str1);
  pthread_create(&th2, NULL, func2, &str2);
  pthread_join(th1, NULL);
  pthread_join(th2, NULL);
  return 0;
}
