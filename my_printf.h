/*
** my_printf.h for my_printf in /u/all/sundas_c/cu/rendu/unix/projet/my_printf
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Wed Nov 26 22:43:16 2008 christophe sundas
** Last update Thu Nov 27 21:40:18 2008 christophe sundas
*/

#ifndef __MY_PRINTF_H__
# define __MY_PRINTF_H__
#include <stdarg.h>
typedef struct	s_converter
{
  char		converter;
  char		*(*f)();
}		t_converter;

typedef struct	s_precision
{
  int		set;
  int		precision;
}		t_precision;

typedef	struct	s_flag
{
  char		align;
  char		add;
  int		force_sign;
  int		force_space;
  char		sharp;
}		t_flag;

typedef struct	s_spec
{
  t_flag	flag;
  t_precision	precis;
  int		largeur;
  char		modifier;
  char		converter;	
}		t_spec;
/*
** printf.h
*/

int		my_printf(char *format, ...);

/*
** parser.h
*/
int		parse_format(char *format, va_list vlist);
int		is_regular(char c);

/*
** fill spec.h
*/
int		fill_spec(char *format, t_spec *spec, va_list *vlist);
int		fill_converter(char *format, t_spec *spec);
int		my_char_is_num(char c);
int		fill_modifier(char *format, t_spec *spec);

/*
** fill flag1.h
*/
int		fill_flag(char *format, t_spec *spec);
int		is_flag(char c);

/*
** fill flag2.h
*/
void		fill_sharp(char *format, int cpt, t_spec *spec);
void		fill_force_space(char *format, int cpt, t_spec *spec);
void		fill_force_sign(char *format, int cpt, t_spec *spec);
void		fill_add(char *format, int cpt, t_spec *spec);
void		fill_align(char *format, int cpt, t_spec *spec);

/*
** fill_largeur.h
*/
int		fill_largeur(char *format, t_spec *spec, va_list *vlist);
int		fill_largeur_star(t_spec *spec, va_list *vlist);

/*
** fill_precision
*/
int		fill_precision(char *format, t_spec *spec, va_list *vlist);
int		fill_precision_star(t_spec *spec, va_list *vlist);

/*
** Converter.h indicateur de conversion
*/
int		is_converter(char c);
int		print_converter(t_spec *spec, va_list *vlist);

/*
** converter short
*/
int		print_h_converter(t_spec *spec, va_list *vlist);

/*
** converter long
*/
int		print_l_converter(t_spec *spec, va_list *vlist);

/*
** print_string.h %c, %s ,%S , %p, %% 
*/
char		*print_char(va_list *vlist);
char		*print_string(va_list *vlist);
char		*print_pointer(va_list *vlist);
char		*print_percent();

/*
** print_special string .h
*/
char		*print_string_special(va_list *vlist);
char		*print_char_asoctal(unsigned char c);
int		cpt_special_str(char *str);
int		cpt_char_asoctal(unsigned char c);

/*
** print_decimal.h %d %i %u
*/
char		*print_signed_decimal(va_list *vlist);
char		*print_unsigned_decimal(va_list *vlist);

/*
** print_short_decimal %hd %hi %hu
*/
char		*print_h_signed_decimal(va_list *vlist);
char		*print_h_unsigned_decimal(va_list *vlist);

/*
** print_long_decimal %li %ld %lu
*/
char		*print_l_signed_decimal(va_list *vlist);
char		*print_l_unsigned_decimal(va_list *vlist);

/*
** print short undecimal %ho %hx %hX
*/
char		*print_h_octal(va_list *vlist);
char		*print_h_hexa_up(va_list *vlist);
char		*print_h_hexa_low(va_list *vlist);

/*
** print_undecimal.h %x %o %X %b
*/
char		*print_octal(va_list *vlist);
char		*print_hexa_up(va_list *vlist);
char		*print_hexa_low(va_list *vlist);
char		*print_binary(va_list *vlist);

/*
** %lo %lx %lX
*/
char		*print_l_octal(va_list *vlist);
char		*print_l_hexa_up(va_list *vlist);
char		*print_l_hexa_low(va_list *vlist);

/*
** Calcul.h
*/
void		my_putnbr_base(int n, char *base);
int		my_putnbr_base_cpt(int n, char *base);
void		my_putnbr_base2(int n, char *base, char *tabstr, int *indice);
int		my_putnbr_base_cptu(unsigned int n, char *base);
void		my_putnbr_base2u(unsigned int n, char *base, char tabstr[], int *indice);

/*
** calcul short.h 
*/
void		my_putnbr_base2h(short int n, char *base, char tabstr[], int *i);
int		my_putnbr_base_cpth(short int n, char *base);
void		my_putnbr_base2hu(short unsigned int n, char *base, char tabstr[], int *i);
int		my_putnbr_base_cpthu(short unsigned int n, char *base);

/*
** calcul long.h
*/
void		my_putnbr_base2l(long int n, char *base, char tabstr[], int *i);
int		my_putnbr_base_cptl(long int n, char *base);
void		my_putnbr_base2lu(long unsigned int n, char *base, char tabstr[], int *i);
int		my_putnbr_base_cptlu(long unsigned int n, char *base);

/*
** display_converted.h
*/
int		display_converted(char *str, t_spec *spec);
int		is_num_converter(char c);
int		display_unsigned_num(char *str, t_spec *spec);
int		display_nan_converted(char *str, t_spec *spec);
int		display_core(char *str);

/*
** utils display
*/
char		*add_to_str(char *add, char *str);
char		*add_to_str2(char *prefixe, char *prec, char *str);
int		r_max2(int a, int b);
void		display_spaces(int lenstr, int final_width, t_spec *spec);
void		display_spaces_nan(int lenstr, int final_width);

/*
** utils display2.c
*/
char		*mk_precis(int nb);

/*
** sharp.h
*/
char		*mk_sharp_flag(t_spec *spec);
int		need_mk_sharp(t_spec *spec);

/*
** display unsigned
*/
char		*mk_precision_unsigned(char *str, t_spec *spec);

/*
**display signed
*/
int		display_signed_num(char *str,t_spec *spec);
char		*mk_signed_prefix(char *str, t_spec *spec);
char		*mk_precision_signed_r(char *str, t_spec *spec);

/*
** lib my.h
*/
int		my_getnbr(char *str);
int		my_strlen(char *c);
int		my_putstr(char *str);
char		*my_strcat(char *str1, char *str2);
char		*my_strdup(char *str);
void		my_putchar(char c);
char		*my_strncat(char *str1, char *str2, int n);
char		*my_strcpy(char *dest, char *src);

#endif
