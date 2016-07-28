/*
** mem.c for vm in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Dec  9 02:27:48 2008 christophe sundas
** Last update Wed Dec 17 12:52:59 2008 christophe sundas
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

unsigned char gl_memory[MEM_SIZE];

/*
** initialise les octets de la memoire virtuelle a 0
*/
void	init_gl_memory()
{
  int	i;
  
  i = 0;
  while (i < MEM_SIZE)
    {
      gl_memory[i] = 0;
      i++;
    }
}

/*
** charge les body des champions en memoire
** de la maniere la plus eloignee possible
*/
void	load_champs_in_gl_memory(t_champ *tabchamp)
{
  int	mem_required;
  int	i;
  int	espace_champ;
  int	index;

  i = 0;
  index = 0;
  mem_required = get_memory_required(tabchamp);
  espace_champ = (MEM_SIZE - mem_required) / gl_nbchamps;
  if (mem_required > MEM_SIZE)
    error(MSG_ERROR_MEM_CAPACITY);
  while (i < gl_nbchamps)
    {
      load_champ_in_gl_memory(&tabchamp[i], index);
      i++;
      index += tabchamp[i].s_header.prog_size + espace_champ;
    }
}

/*
** charge un champion en memoire a un index precis
*/
void	load_champ_in_gl_memory(t_champ *champ, int index)
{
  unsigned char	*tab_bin;
  
  tab_bin = ret_body(*champ);
  copy_into_gl_mem(tab_bin, index, champ->s_header.prog_size);
  champ->memory.pc = index;
  free(tab_bin);
}

/*
** somme de lq taille des champions en octet
**
*/
int	get_memory_required(t_champ *tabchamp)
{
  int	i;
  int	res;

  res = 0;
  i = 0;
  while (i < gl_nbchamps)
    {
      res += tabchamp[i].s_header.prog_size;
      i++;
    }
return (res);
}	

/*
** copie dans le memoire virtuelle un champion
** de indice a mem_size
*/
void	copy_into_gl_mem(unsigned char *tab_bin, int indice, int limit)
{
  int	i;

  i = 0;
  while (i < limit)
    {
      if ((i + indice) < (MEM_SIZE - 1))
	gl_memory[i + indice] = tab_bin[i];
      i++;
    }
}
