/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:44:46 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 20:04:19 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_next;

	if (lst == NULL || (*del) == NULL)
		return ;
	tmp = *lst;
	while (tmp != NULL)
	{
		tmp_next = tmp -> next;
		tmp -> next = NULL;
		(*del)(tmp -> content);
		free(tmp);
		tmp = tmp_next;
	}
	*lst = NULL;
}
