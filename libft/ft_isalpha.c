/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:57:20 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 16:50:59 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int num)
{
	if ('A' <= num && num <= 'Z')
		return (1);
	else if ('a' <= num && num <= 'z')
		return (1);
	else
		return (0);
}
