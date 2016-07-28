/*
** fill_param.c for vm in /afs/epitech.net/users/epitech_2011s/sundas_c/public/vm
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Dec 10 07:32:44 2008 tugdual sarazin
** Last update Wed Dec 10 22:09:48 2008 tugdual sarazin
*/

#include "op.h"
#include "vm.h"
#include "my.h"

unsigned char	gl_memory[MEM_SIZE];

/*
** Remplis la structure t_param
*/
t_param		*fill_param(int offset, int pos)
{
  t_param	*param;

  param = xmalloc(sizeof(*param));
  param->code_instruct = gl_memory[offset];
  param->tailleparam = size_argu(offset, pos);
  param->typeparam = type_argu(offset, pos);
  if (param->tailleparam == 4)
    {
      param->val_l_uint = char_to_uint(get_pos(offset, pos));
      int_to_char(param->tab_l_uint, param->val_l_uint);
    }
  else if (param->tailleparam == 2)
    {
      param->val_s_uint = char_to_usint(get_pos(offset, pos));
      sint_to_char(param->tab_s_uint, param->val_s_uint);
    }
  else if (param->tailleparam == 1)
    param->val_c_uchar = *get_pos(offset + pos - 1, pos);
  return (param);
}
