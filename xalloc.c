/*
** xalloc.c for xalloc in /afs/epitech.net/users/epitech_2011s/sundas_c/public/vm
** 
** Made by tugdual sarazin
** Login   <sarazi_t@epitech.net>
** 
** Started on  Wed Dec 10 08:49:45 2008 tugdual sarazin
** Last update Wed Dec 10 08:59:09 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

void	*xmalloc(int size)
{
  void	*var;

  var = malloc(size);
  if (var == NULL)
    error(MSG_ERROR_MALLOC);
  return (var);
}
