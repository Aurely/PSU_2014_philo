/*
** philosophes.h for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 18:19:08 2015 Trotier Marie
** Last update Sat Feb 28 11:22:49 2015 Trotier Marie
*/

#ifndef PHILOSOPHES_H_
# define PHILOSOPHES_H_

# define PHIL		7
# define MAX_THINK	3
# define INIT_RICE	10

typedef enum	E_STATE 
{
  REST,
  THINK,
  EAT
}		STATE;

typedef struct s_philo	t_philo;

struct		s_philo
{
  int			id;
  int			rice;
  int			nb_think;
  STATE			state;
  pthread_mutex_t	chopstik;
  t_philo		*prev;
  t_philo		*next;
};

void	*func_eat(t_philo *philo);
void	*func_think(t_philo *philo);
void	*func_rest(t_philo *philo);

#endif /* !PHILOSOPHES_H_ */
