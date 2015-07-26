/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 21:16:39 by jyim              #+#    #+#             */
/*   Updated: 2013/12/08 17:51:01 by jyim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*cons(char *src, t_list *first)
{
	t_list		*tmp;

	tmp = ft_lstnew(src, ft_strlen(src));
	tmp->content = src;
	tmp->next = first;
	return (tmp);
}

t_list		*inser_tri(char *s1, t_list *first)
{
	if (first == NULL)
		return (cons(s1, first));
	else if (ft_strcmp(s1, first->content) < 0)
		return (cons(s1, first));
	else
		first->next = inser_tri(s1, first->next);
	return (first);
}
