/*
** read_header.c for my_select in /u/all/sundas_c/cu/public/vm
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 14:03:17 2008 christophe sundas
** Last update Wed Dec 10 22:13:44 2008 tugdual sarazin
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my.h"
#include "op.h"
#include "vm.h"
#include "my_printf.h"

/*
** lit le .cor et fill la struct header
*/
void	read_header(int fd1, header_t *s_header)
{
  if (read(fd1, s_header, sizeof(*s_header)) == -1)
    error(MSG_ERROR_BIN);
  mk_big_endian(s_header);
  control_magicfile(*s_header);
}

/*
** Affiche les infos dune structure header remplie
*/
void	my_aff_header(header_t s_header)
{
  my_putstr("Nom du prog :");
  my_putstr(s_header.prog_name);
  my_putchar('\n');
  my_printf("Magic file  :%X \n", s_header.magic);
  my_printf("Prog size : %d \n", s_header.prog_size);
  my_putstr("Commentaire :");
  my_putstr(s_header.comment);
  my_putchar('\n');
}

/*
** Passe les int magic et prog size en big endian
*/
void	mk_big_endian(header_t *s_header)
{
  s_header->magic = rev_int(s_header->magic);
  s_header->prog_size = rev_int(s_header->prog_size);
}
