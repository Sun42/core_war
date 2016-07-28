/*
** generic_func4.c for vm in /u/all/sundas_c/public/vm
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Dec 10 07:14:40 2008 tugdual sarazin
** Last update Wed Dec 10 21:49:51 2008 tugdual sarazin
*/

#include "op.h"
#include "vm.h"

unsigned char	gl_memory[MEM_SIZE];

/*
** Remplis le tableau de char[4] avec la valeur du int nb
*/
void	int_to_char(unsigned char charc[4], int nb)
{
  charc[0] = ((0xFF000000 & nb) >> 24);
  charc[1] = ((0x00FF0000 & nb) >> 16);
  charc[2] = ((0x0000FF00 & nb) >> 8);
  charc[3] = ((0x000000FF & nb));
}

/*
** Remplis le tableau de char[2] avec la valeur du shor int nb
*/
void	sint_to_char(unsigned char charc[2], short int nb)
{
  charc[0] = ((0x0000FF00 & nb) >> 8);
  charc[1] = ((0x000000FF & nb));
}

/*
** Renvois un pointeur sur le debut de l'argument
** demande en parametre pos
*/
unsigned char	*get_pos(int offset, int pos)
{
  int		i;
  int		dec;

  i = 0;
  dec = 2;
  while (i < pos)
    {
      dec += size_argu(addr(gl_memory[offset]), i);
      i++;
    }
  dec = addr(offset + dec);
  return (gl_memory + dec);
}

int     is_valid_inst(unsigned char c)
{
  if (c > 0 && c < 17)
    return (1);
  return (0);
}
