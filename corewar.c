/*
** corewar.c for VM in /u/all/sundas_c/cu/rendu/unix/projet/corewar
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Nov 28 16:39:47 2008 christophe sundas
** Last update Wed Dec 10 22:05:30 2008 tugdual sarazin
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "vm.h"
#include "my_printf.h"

/*
** lit les fichiers binaires en param, utilise pour debug only
*/
/*void	read_champ(char *champion)
{
  int			fd1;
  header_t		s_header;
  unsigned char		*tab_bin;

   if ((fd1 = open(champion, O_RDONLY)) == -1)
    error(MSG_ERROR_BIN);
  read_header(fd1, &s_header);
  tab_bin = read_cor(fd1, s_header.prog_size);
  read_instruct(tab_bin, s_header.prog_size);
  free(tab_bin);
  close(fd1);
}
*/
