/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 19:11:06 by tmielcza          #+#    #+#             */
/*   Updated: 2015/10/05 19:14:04 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"
#include "op.h"

static int		read_param(size_t size, t_arena const *a, size_t pc)
{
	int		any;
	short	short_indirect;
	char	*data;
	size_t	tmp;

	any = 0;
	short_indirect = 0;
	tmp = 0;
	if (size == 2)
		data = (char *)&short_indirect;
	else
		data = (char *)&any;
	while (tmp != size)
	{
		data[tmp] = a->mem[pc];
		move_pc(&pc, 1);
		tmp++;
	}
	ltob(data, size);
	if (size == 2)
		return (short_indirect);
	else
		return (any);
}

static size_t	get_param_size(t_arg_type param_type, t_op const *op)
{
	size_t		param_s;

	param_s = 0;
	if (param_type == T_REG)
		param_s = 1;
	else if (param_type == T_IND)
		param_s = 2;
	else if (param_type == T_DIR)
	{
		if (op->ind_size == 0)
			param_s = 4;
		else
			param_s = 2;
	}
	return (param_s);
}

void			init_params(t_instruction *instr, t_op const *op,
							t_arena const *a, size_t pc)
{
	size_t		i;
	size_t		param_s;

	move_pc(&pc, 1);
	instr->size = 1;
	if (op->ocp == 1)
	{
		move_pc(&pc, 1);
		instr->size += 1;
	}
	i = 0;
	while (i < instr->nb_params)
	{
		param_s = get_param_size(instr->args_types[i], op);
		instr->size += param_s;
		instr->params[i] = read_param(param_s, a, pc);
		move_pc(&pc, param_s);
		i++;
	}
}
