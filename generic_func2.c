/*
** generic_func2.c for  in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Dec  8 21:39:41 2008 christophe sundas
** Last update Wed Dec 10 22:11:03 2008 tugdual sarazin
*/

#include "op.h"
#include "vm.h"

/*
** calcul la taille des params pour 
** sti ldi lldi 
*/
int	cod_typ_parms_size2(unsigned int typecode, int nbparms)
{
  unsigned char	c;
  unsigned char	d;
  int		res;
  int		i;
  int		filtre;

  res = 0;
  i = 0;
  filtre = 128;
  while (i < (nbparms * 2))
    {
      c = (typecode & filtre);
      c >>= 7;
      typecode <<= 1;
      d = (typecode & filtre);
      d >>= 7;
      typecode <<= 1;
      i += 2;
      res += parms_size2(c , d);
    }
  return (res);
}

/*
** 01 -> registre un octet
** 10 -> direct DIR_SIZE 2
** 11 -> indirect IND_SIZE 2
** 00 -> rien
*/
int	parms_size2(unsigned char a, unsigned char b)
{
  if ((a == 0) && (b == 1))
    return (T_REG);
  if ((a == 1) && (b == 0))
    return (2);
  if ((a == 0) && (b == 0))
    return (0);
  if (a == 1 && b == 1)
    return (IND_SIZE);
  return (0);
}

/*
** Applique un modulo de mem size aux addr
** pour que le memoire soit circulaire
*/
int	addr(int val)
{
  val %= MEM_SIZE;
  if (val < 0)
    val = MEM_SIZE + val;
  return (val);
}

/*
** converti un char[4] en unsigned int
*/
unsigned int	char_to_uint(unsigned char *valc)
{
  unsigned int	vali;

  vali = 0;
  vali |= ((unsigned int) valc[0]) << 24;
  vali |= ((unsigned int) valc[1]) << 16;
  vali |= ((unsigned int) valc[2]) << 8;
  vali |= ((unsigned int) valc[3]);
  return (vali);
}

/*
** converti un char[4] en signed int
*/
int	char_to_int(unsigned char *valc)
{
  int	vali;

  vali = 0;
  vali |= ((int) valc[0]) << 24;
  vali |= ((int) valc[1]) << 16;
  vali |= ((int) valc[2]) << 8;
  vali |= ((int) valc[3]);
  return (vali);
}
