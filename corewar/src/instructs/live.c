/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmielcza <tmielcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 11:02:36 by tmielcza          #+#    #+#             */
/*   Updated: 2015/07/31 14:28:04 by tmielcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_protos.h"

void		live(t_vm *vm, t_process *process)
{
	t_player const	*last;

	process->nb_lives++;
	last = get_player(vm, process->instruction.params[0]);
	if (last != NULL)
	{
		vm->last_living_player = last;
	}
	move_pc(&process->pc, process->instruction.size);
}
