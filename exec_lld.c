/*
** exec_lld.c for corewar in /u/epitech_2011s/sundas_c/public/vm
** 
** Made by marc buron
** Login   <buron_m@epitech.net>
** 
** Started on  Fri Dec  5 17:35:13 2008 marc buron
** Last update Wed Dec 10 22:06:49 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "vm.h"
#include "my_printf.h"

/*
** incremente l'indice dans le tab char et exec ld
*/
void		exec_lld(t_champ *tabchamp, int i)
{
  int		offset;
  t_param	*param1;
  char		param2;

  param1 = fill_param(tabchamp[i].memory.pc, 1);
  offset = addr(tabchamp[i].memory.pc + 2 + param1->tailleparam);
  param2 = gl_memory[offset];
  if (is_reg(param2) && (param1->typeparam == T_IND))
    ind_l_lld(tabchamp, i, param1, param2);
  if (is_reg(param2) && (param1->typeparam == T_DIR))
    dir_l_lld(tabchamp, i, param1, param2);
  tabchamp[i].nbwait = op_tab[1].nbr_cycles - 1;
  tabchamp[i].memory.pc = addr(offset + T_REG);
  free(param1);
  tabchamp[i].memory.carry = !tabchamp[i].memory.carry;
}

/*
** load un long en indirect (pc + val)
*/
void	ind_l_lld(t_champ *tabchamp, int i, t_param *p1, char p2)
{
  int	save;
  int	pc;
  int	res;
  
  pc = tabchamp[i].memory.pc;
  save = (p1->val_s_uint);
  res = pc + save;
  tabchamp[i].memory.regtab[p2 - 1] =  char_to_int_gl(res);
}

void	dir_l_lld(t_champ *tabchamp, int i, t_param *p1, char p2)
{
  int	adr;
  int	save;
  
  adr = addr(tabchamp[i].memory.pc + p1->val_l_uint);
  save = char_to_int_gl(adr);
  tabchamp[i].memory.regtab[p2 - 1] = save;
}
