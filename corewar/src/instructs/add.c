/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 23:08:32 by crenault          #+#    #+#             */
/*   Updated: 2015/07/30 23:08:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		add(t_vm *vm, t_process *proc)
{
	t_instruction	*instr;
	int				p0;
	int				p1;
	int				p2;
	int				res;

	(void)vm;
	instr = &proc->instruction;
	p0 = instr->params[0];
	p1 = instr->params[1];
	p2 = instr->params[2];
	if (check_param(instr->args_types[0], p0)
		|| check_param(instr->args_types[1], p1)
		|| check_param(instr->args_types[2], p2))
	{
		res = loadreg(&proc->registers[p0]) + loadreg(&proc->registers[p1]);
		storeg(&proc->registers[p2], &res, sizeof(res));
	}
	move_pc(&proc->pc, instr->size);
}