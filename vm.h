/*
** vm.h for vm in /u/all/sundas_c/cu/rendu/unix/projet/corewar
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Nov 28 16:41:39 2008 christophe sundas
** Last update Sat Dec 13 18:39:51 2008 christophe sundas
*/
#ifndef __VM_H__
# define __VM_H__

#define MSG_ERROR_FILE_ACCESS "File %file_name is not accessible"
#define MSG_ERROR_BIN "file name is not a corewar executable"
#define MSG_ERROR_MALLOC "Can't perform malloc"
#define INSTRUCT_ERROR "Undefined instruction" /*pour debug */
#define MSG_ERROR_MEM_CAPACITY "Can't load progs, mem_size exceeded"
#define INVALID_INSTRUCT 0
#define INST_SIZE 1
#define TYPE_PARAM_SIZE 1
#define NUM_CHAMP_LEN 4
#define MAX_CHAMP_NUMBERS 4

extern	int		gl_nbchamps; /*nb de champions lances au start*/
extern	unsigned char	gl_memory[MEM_SIZE];/* memoire virtuelle*/
extern	int		gl_cycle_to_die;
extern	int		gl_cptlive;
extern	int		gl_livetoken;

typedef	int		reg;
typedef struct		s_memchamp
{
  reg			regtab[REG_NUMBER];
  reg			pc;
  int			carry;
}			t_memchamp;

typedef struct		champ
{
  char			*fullpath;
  int			prognum;
  t_memchamp		memory;
  header_t		s_header;
  int			alive;/*  check si le champion joue*/
  int			live;/* passe a un lorsaue le hcampion execute live*/
  int			nbwait;
}			t_champ;

typedef struct		s_param
{
  char			code_instruct;
  int			tailleparam;/*1 2 4 */
  int			typeparam; /*indirect  direct registre */
  int			val_l_uint;
  unsigned char		tab_l_uint[4];
  short int		val_s_uint;
  unsigned char		tab_s_uint[2];
  unsigned char		val_c_uchar;
}			t_param;

typedef struct          s_coresp
{
  int                   num;
  void                  (*func)(t_champ *tabchamp, int index);
} t_coresp;
   
void			my_exit(t_champ *tabchamp);

/*
** memoire virtuelle
*/
void			init_gl_memory();
void			load_champs_in_gl_memory(t_champ *tabchamp);
void			load_champ_in_gl_memory(t_champ *champ, int cpt);
void			copy_into_gl_mem(unsigned char *tab_bin, int indice, int limit);
int			get_memory_required(t_champ *tabchamp);
/*
** INIT champ.c
*/
t_champ			*mk_tab_champ(int start , int ac, char **av);
t_champ			init_champ(char *champion, int numchamp);/*lui passerune adresse pour pc en 3eme parametre */
void			my_aff_reg(t_champ champ);
void			init_memory(t_champ *champ);
void			my_aff_memory2(t_champ *champs);
void			my_free_tabchamp(t_champ *champs);

/*
** corewar.h
*/
void			read_champ(char *champion);
void			control_magicfile(header_t s_header);

/*
** read_header.h
*/
void			mk_big_endian(header_t *s_header);
void			read_header(int fd1, header_t *s_header);
void			my_aff_header(header_t s_header);

/*
** read body.h
*/
unsigned char		*read_cor(int fd1, int size);
void			read_instruct(unsigned char *tab_bin, int limit);
void			exec_instruct(t_champ *tabchamp, int index);
int			find_instruct(unsigned char instruct);
int			is_valid_inst(unsigned char c);
unsigned char		*ret_body(t_champ my_champ);
void			exec_instruct2(t_champ *tabchamp, int index);
/*
** sheduling.h
*/
int			check_champ_still_alive(t_champ *tabchamp);
void			all_champ_play(t_champ *tabchamp);
void			scheduling(t_champ *tabchamp);
void			verif_now(t_champ *tabchamp);
/*
** exec_live.h
*/
void			exec_live(t_champ *tabchamp, int index);
void			mklive(int numplayer, t_champ *tabchamp);

/*
** exec_ld.h
*/
void			exec_ld(t_champ *tabchamp, int index);
void			ind_l_ld(t_champ *tabchamp, int i, t_param *p1, char p2);
void			dir_s_ld(t_champ *tabchamp, int i, t_param *p1, char p2);

/*
** exec_st.h
*/
void			exec_st(t_champ *tabchamp, int index);
void			ind_l_st(t_champ *tabchamp, int i, t_param *p2, char p1);
void			dir_s_st(t_champ *tabchamp, int i, t_param *p2, char p1);
void			dir_l_st(t_champ *tabchamp, int i, t_param *p2, char p1);

/*
** exec_zjmp.h
*/
void			exec_zjmp(t_champ *tabchamp, int index);

/*
** exec_lld.h
*/
void			exec_lld(t_champ *tabchamp, int index);
void			dir_s_lld(t_champ *tabchamp, int i, t_param *p1, char p2);
void			dir_l_lld(t_champ *tabchamp, int i, t_param *p1, char p2);
void			ind_l_lld(t_champ *tabchamp, int i, t_param *p1, char p2);

/*
** generic_func.h
*/
void			error(char *error);
unsigned int		rev_int(unsigned int nb);
int			cod_typ_parms_size(unsigned int typecode, int nbparms);
int			parms_size(unsigned char a, unsigned char b);

/*
** generic_func2.h
*/
int			parms_size2(unsigned char a, unsigned char b);
int			cod_typ_parms_size2(unsigned int typecode, int nbparms);
int			addr(int val);
unsigned int		char_to_uint(unsigned char *valc);
int			char_to_int(unsigned char *valc);

/*
** generic_func3.h
*/
int			is_reg(unsigned char value);
int			size_argu(int offset, int pos);
int			type_argu(int offset, int pos);
short int		char_to_sint(unsigned char *valc);
unsigned short int	char_to_usint(unsigned char *valc);

/*
** generic_func4.h
*/
void			sint_to_char(unsigned char charc[2], short int nb);
void			int_to_char(unsigned char charc[4], int nb);
unsigned char		*get_pos(int offset, int pos);

/*
** conv_gl.h
*/
short int		char_to_sint_gl(int offset);
unsigned short int	char_to_usint_gl(int offset);
int			char_to_int_gl(int offset);
unsigned int		char_to_uint_gl(int offset);

/*
** fill_param.h
*/
t_param			*fill_param(int offset, int pos);

/*
** debug.h
*/
void			my_aff_reg(t_champ champ);

/*
** xalloc.h
*/
void			*xmalloc(int size);

/*
** index des registres dans le tab de registre
*/
#define ir1 0
#define ir2 1
#define ir3 2
#define ir4 3
#define ir5 4
#define ir6 5
#define ir7 6
#define ir8 7
#define ir9 8
#define ir10 9
#define ir11 10
#define ir12 11
#define ir13 12
#define ir14 13
#define ir15 14

#define r1 1
#define r2 2
#define r3 3
#define r4 4
#define r5 5
#define r6 6
#define r7 7
#define r8 8
#define r9 9
#define r10 10
#define r11 11
#define r12 12
#define r13 13
#define r14 14
#define r15 15

#endif
