/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 21:30:59 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 16:20:47 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	unsigned char		*s_cpy;
	unsigned char		c_cpy;

	s_cpy = (unsigned char *)s;
	c_cpy = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (s_cpy[i] == c_cpy)
			return ((void *)&s_cpy[i]);
		i++;
	}
	return (NULL);
}
