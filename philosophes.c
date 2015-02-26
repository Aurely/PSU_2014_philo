/*
** philosophes.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 15:30:22 2015 Trotier Marie
** Last update Thu Feb 26 20:08:49 2015 Trotier Marie
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
  //  printf("AAA - tmp->energy[%d] = %d\n", b, tmp->energy[b]);
  if (pthread_mutex_trylock(&tmp->baguette[b]) != 0/* = Mutex unlock = Gauche libre*/)
    {
	  /* printf("BBB - tmp->energy[b] = %d\n", tmp->energy[b]); */
      if (pthread_mutex_trylock(&tmp->baguette[a]) != 0/* = mutex unlock = Droite libre*/)
	{
	  if (tmp->energy[b] == 1)
	    {
	      tmp->energy[b] == 0;
	      func_think(b, a, tmp);
	      //printf("philo %d -> energy = %d - fonction ---> think     | O |\n", b, tmp->energy[b]);
	    }
	  else
	    {
	      tmp->energy[b] == 0;
	      func_eat(b, a, tmp);
	      //printf("philo %d -> energy = %d - fonction ---> eat       | O |\n", b, tmp->energy[b]);
	    }
	}
      else /* Droite prise */
	{
	  if (tmp->energy[b] == 1)
	    {
	      tmp->energy[b] == 0;
	      func_think(b, a, tmp);
	      //printf("philo %d -> energy = %d - fonction ---> think     | O |\n", b, tmp->energy[b]);
	    }
	  else
	    {
	      tmp->energy[b] == 0;
	      func_rest(b, a, tmp);
	      //printf("philo %d -> energy = %d - fonction ---> rest      | O |\n", b, tmp->energy[b]);
	    }
	}
     }
  else /* baguette de gauche prise*/
    {
	  /* printf("CCC - tmp->energy[b] = %d\n", tmp->energy[b]); */
      if (pthread_mutex_trylock(&tmp->baguette[a]) != 0/* = mutex unlock = Droite libre*/)
	{
	  if (tmp->energy[b] == 1)
	    {
	      tmp->energy[b] = 0;
	      func_think(b, a, tmp);
	      //printf("philo %d -> energy = %d - fonction ---> think     . O |\n", b, tmp->energy[b]);
	    }
	  else
	    func_rest(b, a, tmp);
	    //printf("philo %d -> energy = %d - fonction ---> rest      . O |\n", b, tmp->energy[b]);
	}
      else /* Droite prise*/ 
	{
	  if (tmp->energy[b] == 1)
	    func_rest(b, a, tmp);
	    //printf("philo %d -> energy = %d - fonction ---> rest      . O .\n", b, tmp->energy[b]);
	}
    }
  sleep(2);
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
      my_philo.energy[i] = 1;
      i++;
    }
  i = 0;
  while (i < PHIL)
    {
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
