/*
** read_body.c for VM in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 15:44:07 2008 christophe sundas
** Last update Wed Dec 10 23:29:53 2008 tugdual sarazin
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "op.h"
#include "vm.h"
#include "my.h"
#include "my_printf.h"

void    my_func(t_champ *tabchamp, int index ,  int indice);

/*
** lit le reste du fichier .cor
*/
unsigned char	*read_cor(int fd1, int size)
{
  unsigned char	*tab_bin;
  int		nblu;

  if ((tab_bin = malloc(sizeof(*tab_bin) * size)) == NULL)
    error(MSG_ERROR_MALLOC);
  if ((nblu = read(fd1, tab_bin, size)) == -1)
    error(MSG_ERROR_FILE_ACCESS);
  return (tab_bin);
}

/*
** lit le fichier cor en ouvrant son propre file descriptor
** on lit un nouveau header au lieu de se servir de lseek
** c moche, c supinfo mais on a pas le tps :] 
*/
unsigned char	*ret_body(t_champ my_champ)
{
  int		fd;
  unsigned char	*tab_bin;
  header_t	s_header;
  
  if ((fd = open(my_champ.fullpath, O_RDONLY)) == -1)
    error(MSG_ERROR_BIN);
  read_header(fd, &s_header);
  tab_bin = read_cor(fd, my_champ.s_header.prog_size);
  close(fd);
  return (tab_bin);
}	

/*
** execute linstruction  a laddresse pc
** si elle nexiste pas on incremente pc
*/
void		exec_instruct(t_champ *tabchamp, int index)
{
  unsigned char	instruct;
  int		offset;

  if (tabchamp[index].alive == 0)
    return ;
  if (tabchamp[index].nbwait != 0)
    {
      tabchamp[index].nbwait--;
      return ;
    }
  offset = addr(tabchamp[index].memory.pc);
  instruct = gl_memory[offset];
  if (is_valid_inst(gl_memory[offset]))
    my_func(tabchamp, index, instruct);
  else
    tabchamp[index].memory.pc = addr(tabchamp[index].memory.pc + 1);
}

void	my_func(t_champ *tabchamp, int index ,  int indice)
{
  if (indice == 1)
    exec_live(tabchamp, index);
  if (indice == 2)
    exec_ld(tabchamp, index);
  if (indice == 3)
    exec_st(tabchamp, index);
  else if (indice == 9)
    exec_zjmp(tabchamp, index);
  else if (indice == 13)
    exec_lld(tabchamp, index);
  else
    tabchamp[index].memory.pc = addr(tabchamp[index].memory.pc + 1);
}
