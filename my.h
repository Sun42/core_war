/*
** my.h for headers de la lib libmy.a in /u/all/sundas_c/cu/rendu/include
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Mon Oct 20 13:22:36 2008 christophe sundas
** Last update Mon Nov 10 06:07:24 2008 christophe sundas
*/

#ifndef __MY_H__

# define __MY_H__
/* 
**structure de liste chainees
*/
typedef struct	s_list
{
  char		*data;
  struct s_list	*next;

}		t_list;

/*
** my_string.h 
*/
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
void	my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	my_max_int(int i1, int i2);
int	my_max_chr(char c1, char c2);
int	my_cmp_char(char c1, char c2);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
char	*my_strcat(char *str1, char *str2);
char	*my_strncat(char *str1, char *str2, int n);
int	my_strlcat(char *str1, char *str2, int n);
char	**my_str_to_wordtab(char *str);
int	my_show_to_wordtab(char **str);
char	*my_strdup(char *str);

/*
** my_math.h
*/
int	my_isneg(int n);
int	my_put_nbr(int nb);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
void	my_itoa(int nbr, char *str);

/*
** my_utils.h
*/

int	my_swap(int *a, int *b);
int	my_showmem(char *str, int size);/*Affiche contenu en ram*/
char	*sum_params(int argc, char **argv);
void    my_putstr_error(char *error);/*Affiche la string erreur sur la sortie erreur et quitte */
void    my_put_nbr_error(int numerror);/*Affiche la string erreur a partir de son errno, et quitte */
/*
** my_list.h
*/

int	my_apply_on_list(t_list *begin, int (*f)());/*applique une fonction a tous les elements*/
int	my_put_in_list(t_list **begin, char *data);/*Ajoute un element*/ 
int	my_apply_on_eq_in_list(t_list *begin, int (*f)(), void *data_ref, int (*cmp)());/*Applique une fonction a un element precis*/  
t_list	*my_find_node_eq_in_list(t_list *begin, void *data_ref, int (*cmp)());/*Trouve un noeud precis */
t_list	*my_params_in_list(int ac, char **av);/*Met les parametres dans une liste  */ 
int	my_rev_list(t_list **begin);/*Tri Reverse */ 
void	*my_find_elm_eq_in_list(t_list *begin, void *data_ref, int (*cmp)());/*Trouve un element precis */
int	my_list_size(t_list *begin);/*Retourne la taille */ 
t_list	*my_rm_all_eq_from_list(t_list **begin,void *data_ref,int (*cmp)());/*Delete les elements egaux trouves*/
int	my_show_str_in_list(t_list *begin);/*Affiche */

#endif
