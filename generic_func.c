/*
** generic_func.c for vm in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Dec  8 00:13:22 2008 christophe sundas
** Last update Wed Dec 10 21:58:03 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"
#include "my.h"

/*
**  Fonction generique error
*/
void	error(char *error)
{
  if (error != NULL)
    my_putstr_error(error);
  my_putchar('\n');
  exit(EXIT_FAILURE);
}

/*
** revun int en big endian
*/
unsigned int	rev_int(unsigned int nb)
{
  unsigned int	revnb;

  revnb = 0;
  revnb |= ((0xFF000000 & nb) >> 24);
  revnb |= ((0x00FF0000 & nb) >> 8);
  revnb |= ((0x0000FF00 & nb) << 8);
  revnb |= ((0x000000FF & nb) << 24);
  return (revnb);
}

/*
**lit loctet de codage des type params et retourne la taille aue 
** prendra les futurs params
** ld,lld,st,and,or,xor,aff
*/
int	cod_typ_parms_size(unsigned int typecode, int nbparms)
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
      res += parms_size(c , d);
    }
  return (res);
}

/*
** en fonction du type de codage retourne la taille
** 01 -> registre un octet
** 10 -> direct DIR_SIZE 4
** 11 -> indirect IND_SIZE 2 
** 00 -> rien
*/
int	parms_size(unsigned char a, unsigned char b)
{
  if ((a == 0) && (b == 1))
    return (T_REG);
  if ((a == 1) && (b == 0))
    return (DIR_SIZE);
  if ((a == 0) && (b == 0))
    return (0);
  if (a == 1 && b == 1)
    return (IND_SIZE);
  return (0);
}

/*
** Control si c bien un magic file .cor
*/
void	control_magicfile(header_t s_header)
{
  if (s_header.magic != COREWAR_EXEC_MAGIC)
    error(MSG_ERROR_BIN);
}
