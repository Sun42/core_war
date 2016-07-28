CC = gcc
NAME = corewar
SRC = 	main.c \
	op.c \
	champ.c \
	init_champ.c \
	mem.c \
	scheduling.c \
	fill_param.c \
	corewar.c \
	generic_func.c \
	generic_func2.c \
	generic_func3.c \
	generic_func4.c \
	conv_gl.c \
	read_header.c \
	read_body.c \
	exec_live.c \
	exec_ld.c \
	exec_st.c \
	exec_zjmp.c \
	exec_lld.c \
	xalloc.c
OBJ = $(SRC:.c=.o)
LIB = -lmy -L. -lmy_printf_`uname -m`-`uname -s`
CFLAGS += -W  -Wall -ansi -pedantic -I.
RM = rm -f
TMP = $(SRC:.c=.c~)

$(NAME) : all

all : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean :
	$(RM) $(OBJ)
	$(RM) $(TMP)

fclean : clean
	$(RM) $(NAME)

re : fclean all