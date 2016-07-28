/*
** exec_st.c for corewar in /u/epitech_2011s/sundas_c/public/vm
** 
** Made by marc buron
** Login   <buron_m@epitech.net>
** 
** Started on  Fri Dec  5 17:35:57 2008 marc buron
** Last update Wed Dec 10 22:13:41 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "vm.h"
#include "my_printf.h"

void		exec_st(t_champ *tcp, int i)
{
  int		offset;
  char		p1;
  t_param	*p2;
  int		adr;

  tcp[i].memory.regtab[0] = 8;
  p1 = gl_memory[addr(tcp[i].memory.pc + 2)];
  p2 = fill_param(tcp[i].memory.pc, 2);
  offset = addr(tcp[i].memory.pc + 2 + p2->tailleparam);
  if (is_reg(p1) && (p2->typeparam == T_IND))
      {
	adr = tcp[i].memory.pc + (p2->val_s_uint % IDX_MOD);
	int_to_char(gl_memory + adr, tcp[i].memory.regtab[p1 - 1]);
      }
  if (is_reg(p1) && (p2->typeparam == T_REG) && is_reg(p2->val_c_uchar))
    tcp[i].memory.regtab[p2->val_c_uchar - 1] = tcp[i].memory.regtab[p1 - 1];
  tcp[i].nbwait = op_tab[2].nbr_cycles - 1;
  tcp[i].memory.pc = addr(offset + T_REG);
  free(p2);
}
