/*
** init_champ.c for vm in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Tue Dec  9 03:46:45 2008 christophe sundas
** Last update Wed Dec 10 21:44:44 2008 tugdual sarazin
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "vm.h"

int	gl_nbchamps;

/*
** cree un tableau de champion
** pbm ->linitialisation dun champ a besoin dun pc en parametre 
** deja defini :/
*/
t_champ	*mk_tab_champ(int start, int ac, char **av)
{
  int		i;
  t_champ	*tabchamp;
  int		num;
    
  num = ac - start;
  gl_nbchamps = ((MAX_CHAMP_NUMBERS > (num)) ? (num) : MAX_CHAMP_NUMBERS);
  if ((tabchamp = malloc(sizeof(*tabchamp) * gl_nbchamps)) == NULL)
    error(MSG_ERROR_MALLOC);
  i = 0;
  while (i < gl_nbchamps)
    {
      tabchamp[i] = init_champ(av[i + start], i + 1);
      i++;
    }
  return (tabchamp);
}

/*
** initialise un champion
** charge le header
** initialise la memoire dun champion
** defini un numero de champion ?
** defini le pc a combien ?? -> le pc a definir plus tard dans le prog
*/
t_champ		init_champ(char *champion, int numchamp)
{
  int		fd1;
  t_champ	my_champ;
  
  if ((fd1 = open(champion, O_RDONLY)) == -1)
    error(MSG_ERROR_BIN);
  read_header(fd1, &(my_champ.s_header));
  close(fd1);
  my_champ.fullpath = champion;
  my_champ.prognum = numchamp;
  my_champ.alive = 1;
  my_champ.live = 0;
  my_champ.nbwait = 0;
  init_memory(&my_champ);
  return (my_champ);
}

/*
** initialise la memoire dun champion en debut de prog
*/
void	init_memory(t_champ *champ)
{
  int	i;
  
  i = 1;
  champ->memory.pc = 0;
  champ->memory.carry = 0;
  champ->memory.regtab[ir1] = champ->prognum;
  while (i < REG_NUMBER)
    {
      champ->memory.regtab[i] = 0;
      i++;
    }
}
