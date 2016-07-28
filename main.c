/*
** main.c for corewar VM in /u/all/sundas_c/cu/rendu/unix/projet/corewar
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Nov 28 16:36:53 2008 christophe sundas
** Last update Wed Dec 10 23:28:49 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "vm.h"

int	gl_cycle_to_die;
int	gl_cptlive;

int	main(int ac, char **av)
{
  t_champ	*tabchamp;
  
  if (ac < 2)
    {
      my_putstr("Usage : Nom champion [1-4]");
      exit(-1);
    }
  init_gl_memory();
  gl_cycle_to_die = CYCLE_TO_DIE;
  gl_cptlive = 0;
  gl_livetoken = -1;
  tabchamp = mk_tab_champ(1, ac, av);
  load_champs_in_gl_memory(tabchamp);
  scheduling(tabchamp);
  my_free_tabchamp(tabchamp);
  return (0);
}

void	my_exit(t_champ *tabchamp)
{
  my_free_tabchamp(tabchamp);
  exit(1);
}
