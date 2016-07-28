/*
** generic_func3.c for vm in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Dec 10 05:40:22 2008 christophe sundas
** Last update Wed Dec 10 22:12:55 2008 tugdual sarazin
*/

#include "op.h"
#include "vm.h"
#include "my.h"

unsigned char	gl_memory[MEM_SIZE];

int	is_reg(unsigned char value)
{
  if (value >= 1 && value <= 16)
    return (1);
  return (0);
}

/*
** renvoi la taille du parametre
*/
int	size_argu(int offset, int pos)
{
  char	codage;
  
  if (gl_memory[offset] == 1)
    return (DIR_SIZE);
  else if (gl_memory[offset] == 9 ||\
	   gl_memory[offset] == 12 || gl_memory[offset] == 15)
    return (IND_SIZE);
  codage = (addr(gl_memory[offset + 1]) >> (8 - (pos * 2))) & 0x03;
  if (codage == 1)
    return (1);
  else if (codage == 2)
    {
      if (gl_memory[offset] == 10 ||\
	  gl_memory[offset] == 11 || gl_memory[offset] == 14)
	return(IND_SIZE);
      else
	return (DIR_SIZE);
    }
  else if (codage == 3)
    return (IND_SIZE);
  return (0);
}

/*
** renvoi le type du parametre (T_REG, T_DIR, T_IND)
*/
int	type_argu(int offset, int pos)
{
  char	codage;

  if (gl_memory[offset] == 1 || gl_memory[offset] == 9\
      || gl_memory[offset] == 12 || gl_memory[offset] == 15)
    return (T_DIR);
  codage = (addr(gl_memory[offset + 1]) >> (8 - (pos * 2))) & 0x03;
  if (codage == 1)
    return (T_REG);
  else if (codage == 2)
    return (T_DIR);
  else if (codage == 3)
    return (T_IND);
  return (0);
}


/*
** converti un char[2] en signed short int
*/
short int	char_to_sint(unsigned char *valc)
{
  short int	vali;

  vali = 0;
  vali |= ((short int) valc[0]) << 8;
  vali |= ((short int) valc[1]);
  return (vali);
}

/*
** converti un char[2] en unsigned short int
*/
unsigned short int	char_to_usint(unsigned char *valc)
{
  unsigned short int	vali;

  vali = 0;
  vali |= ((unsigned short int) valc[0]) << 8;
  vali |= ((unsigned short int) valc[1]);
  return (vali);
}
