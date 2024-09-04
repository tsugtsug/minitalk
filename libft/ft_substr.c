/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:28:30 by yokamura          #+#    #+#             */
/*   Updated: 2022/10/17 20:19:02 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rtn;
	int				i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		rtn[i] = s[start];
		i++;
		start++;
	}
	rtn[i] = '\0';
	return (rtn);
}
