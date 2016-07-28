/*
** exec_live.c for corewar in /u/epitech_2011s/sundas_c/public/vm
** 
** Made by marc buron
** Login   <buron_m@epitech.net>
** 
** Started on  Fri Dec  5 17:31:27 2008 marc buron
** Last update Wed Dec 10 22:51:27 2008 tugdual sarazin
*/

#include "op.h"
#include "my.h"
#include "vm.h"
#include "my_printf.h"

int		gl_cptlive;
int		gl_cycle_to_die;
int		gl_livetoken;

void		exec_live(t_champ *tabchamp, int index)
{
 int		offset;
 unsigned int	numplayer;
 unsigned  char	tab[4];
 
 
 my_printf(" index %i \n", index);
 offset = addr(tabchamp[index].memory.pc + INST_SIZE);
 gl_cptlive++;
 tabchamp[index].memory.pc += addr(INST_SIZE + NUM_CHAMP_LEN);
  tab[0] = gl_memory[addr(offset)];
  tab[1] = gl_memory[addr(offset + 1)];
  tab[2] = gl_memory[addr(offset + 2)];
  tab[3] = gl_memory[addr(offset + 3)];
  my_printf(" %x %X %X %X\n" , tab[0], tab[1],tab[2],tab[3]);
  numplayer = char_to_int(tab);
  my_printf("le joueur %X est en vie \n", numplayer);
  if (gl_cptlive == NBR_LIVE)
    {
      gl_cptlive = 0;
      gl_cycle_to_die -= CYCLE_DELTA;
    }
  mklive(numplayer, tabchamp);
  tabchamp[index].nbwait = op_tab[0].nbr_cycles - 1;
}

/*
** passe numplayer.live a 1 si numplayer existe
*/
void	mklive(int numplayer, t_champ *tabchamp)
{
  int	i;
  
  i = 0;
  while (i < gl_nbchamps)
    {
      if (tabchamp[i].alive == 1)
	{
	  if (numplayer == tabchamp[i].memory.regtab[0])
	    {
	      gl_livetoken = numplayer;
	      tabchamp[i].live = 1;
	    }
	}
      i++;
    }
}
