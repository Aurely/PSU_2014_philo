/*
** philosophes.h for  in /home/trotie_m/rendu/PSU_2014_philo
** 
** Made by Trotier Marie
** Login   <trotie_m@epitech.net>
** 
** Started on  Sun Feb 22 18:19:08 2015 Trotier Marie
** Last update Fri Feb 27 17:45:22 2015 Aurélie LAO
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
  int			energy;
  int			nb_think;
  STATE			state;
  pthread_mutex_t	chopstik;
  t_philo		*prev;
  t_philo		*next;
};

void	func_eat(int philo, int next_philo, t_philo *my_philo);
void	func_think(int philo, int next_philo, t_philo *my_philo);
void	func_rest(int philo, int next_philo, t_philo *my_philo);

#endif /* !PHILOSOPHES_H_ */
