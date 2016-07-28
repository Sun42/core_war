/*
** champ.c for vm in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Dec  9 21:44:14 2008 christophe sundas
** Last update Wed Dec 10 21:55:41 2008 tugdual sarazin
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include "vm.h"

/*
** libere la memoire malloquee du tableau de champions 
*/
void    my_free_tabchamp(t_champ *champs)
{
  free(champs);
}
