/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <avallete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 02:46:35 by avallete          #+#    #+#             */
/*   Updated: 2016/12/30 15:08:13 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_element(t_select *env, t_dlst *elem)
{
	if (elem == env->args)
		env->args = env->args->next;
	ft_dlstdelone(&elem, elem_destructor);
	env->page.arguments -= 1;
	if (!env->page.arguments)
		ft_quit(env);
}

void	delete_selected_elements(t_select *env)
{
	t_dlst *tmp;

	tmp = env->args;
	while (tmp)
	{
		if (((t_elem*)tmp->content)->mode & IS_SELECTED)
			delete_element(env, tmp);
		tmp = tmp->next;
	}
}

void	delete_current_element(t_select *env)
{
	t_dlst	*tmp;

	tmp = env->page.current_element;
	if (env->page.current_element->next)
		env->page.current_element = env->page.current_element->next;
	else if (env->page.current_element->back)
	{
		env->page.current_element = env->page.current_element->back;
		--env->page.pos.z;
	}
	else
	{
		env->page.current_element = env->args;
		env->page.pos.z = 0;
	}
	delete_element(env, tmp);
}

void	delete_all(t_dlst *dlst)
{
	if (dlst && dlst->next)
		delete_all(dlst->next);
	if (dlst)
		ft_dlstdelone(&dlst, elem_destructor);
}
