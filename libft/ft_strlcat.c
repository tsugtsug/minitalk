/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:01:08 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 16:11:32 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= dstsize)
		return (dstsize + size_src);
	i = 0;
	while (size_dst + i < dstsize - 1 && src[i])
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
