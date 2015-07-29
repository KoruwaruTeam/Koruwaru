#ifndef ASM_H
# define ASM_H

# include "op.h"
#include "../common/libft/includes/libft.h"
#include <stdio.h> ///////////////
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

typedef struct			s_inst
{
  int             type; // ind | dir | reg
  int             is_label; //label | pas label
  int             value;
  int             where; //place de l'instruction, seulement pour la tete. -1 sinon.
	char		     		*s;
  int             size;
  int             opcode;
	struct s_inst		*next;
}						t_inst;

typedef struct    s_bytecode
{
  t_inst            *inst;
  struct s_bytecode *next;
}                 t_bytecode;

typedef struct			s_label
{
	char				    *name;
	struct s_label		*next;
  int             place;
}						t_label;

typedef struct    s_asm
{
  t_bytecode          *bytecode;
  t_label         *label;
  int             count;
  char            *name;
  char            *comment;
}                 t_asm;

int		find_opcode(char *s);
char				**ft_sp_strsplit(char const *s);
int count_tab(char **tab);
t_label *create_label(char *s, int p);
t_label *add_label(t_label *head, t_label *maillon);
t_inst *add_inst(t_inst *head, t_inst *maillon);
t_inst  *create_inst(char *s, int where, t_inst *h);
char *colle_tab(char **tab);
int   count_inst(t_inst *h);
void check_grammar(t_inst *instruction);
int is_op(int opcode);
int find_dir(int opcode);
char *erase_char(char *s);
char		*ft_strndup(char *line, int n);
char		*ft_get_head(char *line);
#endif
