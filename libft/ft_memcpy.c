/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:44:02 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 16:03:53 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d_cpy;
	unsigned const char	*s_cpy;

	d_cpy = (unsigned char *)dst;
	s_cpy = (unsigned const char *)src;
	if (d_cpy == s_cpy)
		return (dst);
	while (n--)
	{
		*d_cpy = *s_cpy;
		d_cpy++;
		s_cpy++;
	}
	return (dst);
}
