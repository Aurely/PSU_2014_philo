/*
** data.c for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Tue Feb 24 11:13:06 2015 Trotier Marie
** Last update Tue Feb 24 18:56:43 2015 Aurélie LAO
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void		func_eat(void *arg, int i, int rd)
{
  int		*data;
  static int	nb_eat = 0;

  data = *(int **)arg;
  rd = rand() % rd;
  if (rd == 0)
    {
      nb_eat = 0;
      data[i] = REST;
    }
  else if (rd == 1)
    {
      nb_eat = 0;
      data[i] = THINK;
    }
  else
    {
      if (nb_eat != MAX_EAT)
	{
	  data[i] = EAT;
	  nb++;
	}
      func_eat(&data, i, 2);
    }
}

void		func_think(void *arg, int i)
{
  int		*data;
  static int	nb_think = 0;
  int		rd;

  data = *(int **)arg;
  rd = rand() % 2;
  if (data[i - 1] == REST)
    {
      nb_think = 0;
      data[i] = EAT;
    }
  else
    {
      if (nb_think != MAX_THINK)
	{
	  data[i] = THINK;
	  nb_think++;
	}
    }
}

void		func_rest(void *arg, int i, int rd)
{
  int		*data;
  static int	nb_rest = 0;
  int		rd;

  data = *(int **)arg;
  if (data[i - 1] == THINK && data[i + 1])
    
}
