/*
** conv_gl.c for vm in /afs/epitech.net/users/epitech_2011s/sundas_c/public/vm
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Dec 10 11:18:11 2008 tugdual sarazin
** Last update Wed Dec 10 12:46:37 2008 christophe sundas
*/

#include "op.h"
#include "vm.h"

unsigned char	gl_memory[MEM_SIZE];

/*
** converti un char[2] en signed short int
*/
short int	char_to_sint_gl(int offset)
{
  short int	vali;

  vali = 0;
  vali |= ((short int) gl_memory[addr(offset)]) << 8;
  vali |= ((short int) gl_memory[addr(offset + 1)]);
  return (vali);
}

/*
** converti un char[2] en unsigned short int
*/
unsigned short int	char_to_usint_gl(int offset)
{
  unsigned short int	vali;

  vali = 0;
  vali |= ((unsigned short int) gl_memory[addr(offset)]) << 8;
  vali |= ((unsigned short int) gl_memory[addr(offset + 1)]);
  return (vali);
}

/*
** converti un char[4] en signed int
*/
int	char_to_int_gl(int offset)
{
  int	vali;

  vali = 0;
  vali |= ((int) gl_memory[addr(offset)]) << 24;
  vali |= ((int) gl_memory[addr(offset + 1)]) << 16;
  vali |= ((int) gl_memory[addr(offset + 2)]) << 8;
  vali |= ((int) gl_memory[addr(offset + 3)]);
  return (vali);
}

/*
** converti un char[4] en unsigned int
*/
unsigned int	char_to_uint_gl(int offset)
{
  unsigned int	vali;

  vali = 0;
  vali |= ((unsigned int) gl_memory[addr(offset)]) << 24;
  vali |= ((unsigned int) gl_memory[addr(offset + 1)]) << 16;
  vali |= ((unsigned int) gl_memory[addr(offset + 2)]) << 8;
  vali |= ((unsigned int) gl_memory[addr(offset + 3)]);
  return (vali);
}
