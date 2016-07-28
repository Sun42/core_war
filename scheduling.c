/*
** sheduling.c for vm in /u/epitech_2011s/sundas_c/public/vm
** 
** Made by marc buron
** Login   <buron_m@epitech.net>
** 
** Started on  Tue Dec  9 23:09:44 2008 marc buron
** Last update Wed Dec 10 23:18:14 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "vm.h"
#include "my_printf.h" 

/*
** verifie le nombre de champions en vie
*/
int	check_champ_still_alive(t_champ *tabchamp)
{
  int	i;
  int	champions_alive;

  i = 0;
  champions_alive = 0;
  while (i < gl_nbchamps)
    {
      if (tabchamp[i].alive == 1)
	{
	  if (tabchamp[i].live == 1)
	    {
	      tabchamp[i].live = 0;
	      champions_alive++;
	    }
	  else
	    {
	      tabchamp[i].alive = 0;
	    }
	}
      i++;
    }
  return (champions_alive);
}

/*
** fait jouer chaque champions
*/
void	all_champ_play(t_champ *tabchamp)
{
  int	i;

  i = 0;
  while (i < gl_nbchamps)
    {
      exec_instruct(tabchamp, i);
      i = i + 1;
    }
}

/*
** cycle du corewar
*/
void	scheduling(t_champ *tabchamp)
{
  int	cycle;

  cycle = 1;
  while (cycle)
    {
      all_champ_play(tabchamp);
      if (cycle >= gl_cycle_to_die)
	{
	  verif_now(tabchamp, &cycle);
	  cycle = 1;
	}
      cycle++;
    }
}

/*
** on verifie s'il reste des champions en vie
** fin de la partie 
*/
void	verif_now(t_champ *tabchamp)
{
  int	champs_alive;
  
    if (champs_alive == 1)
    {
      my_printf("joueur %d a gagne\n", gl_livetoken);
      my_exit(tabchamp);
    }
  if (champs_alive == 0)
    {
      if (gl_livetoken != -1)
	my_printf("joueur %d a gagne\n", gl_livetoken);
      my_exit(tabchamp);
    }
}
