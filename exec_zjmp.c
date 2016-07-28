/*
** exec_zjmp.c for coerwar in /u/epitech_2011s/sundas_c/public/vm
** 
** Made by marc buron
** Login   <buron_m@epitech.net>
** 
** Started on  Fri Dec  5 17:39:56 2008 marc buron
** Last update Wed Dec 10 21:58:48 2008 tugdual sarazin
*/

#include "op.h"
#include "my.h"
#include "vm.h"
#include "my_printf.h"

void		exec_zjmp(t_champ *tabchamp, int i)
{
  short int	adr;
  int		pc;
  
  adr = char_to_sint_gl(tabchamp[i].memory.pc + 1);
  pc = tabchamp[i].memory.pc;
  if (tabchamp[i].memory.carry == 1)
    {
      tabchamp[i].memory.pc = addr(pc + (adr % IDX_MOD));
      
    }
  tabchamp[i].nbwait = op_tab[8].nbr_cycles - 1;
}
