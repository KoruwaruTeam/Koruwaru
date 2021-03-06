/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:55:36 by jyim              #+#    #+#             */
/*   Updated: 2015/07/31 19:58:35 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		find_opcode(char *s)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(g_op_tab[i].name, s))
			return (g_op_tab[i].bin);
		i++;
	}
	return (-1);
}

void	check_grammar(t_inst *instruction, int c)
{
	t_inst	*tmp;
	int		nb;

	if (!instruction)
		error_parse(c);
	nb = count_inst(instruction) - 1;
	if (nb != g_op_tab[instruction->value - 1].param)
		bad_parameter_nb(c);
	nb = 0;
	tmp = instruction->next;
	while (tmp && nb < g_op_tab[instruction->value - 1].param)
	{
		if ((tmp->type & g_op_tab[instruction->value - 1].arg[nb]) == 0)
			bad_parameter(c);
		tmp = tmp->next;
		nb++;
	}
}

int		is_op(int opcode)
{
	int i;
	int i2;

	i = 0;
	i2 = opcode - 1;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].bin == opcode)
			return (g_op_tab[i].oct);
		i++;
	}
	return (0);
}

int		find_dir(int opcode)
{
	int i;
	int i2;

	i = 0;
	i2 = opcode - 1;
	while (g_op_tab[i].name)
	{
		if (g_op_tab[i].bin == opcode)
		{
			if (g_op_tab[i].dir_size == 0)
				return (4);
			else
				return (2);
		}
		i++;
	}
	return (0);
}
