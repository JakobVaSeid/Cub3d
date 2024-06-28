/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:29:23 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 16:44:44 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	strlenth;

	if (s == 0)
		return (0);
	i = 0;
	strlenth = ft_strlen(s);
	if ((strlenth - start) < len)
		len = (strlenth - start);
	if (start >= strlenth)
		len = 0;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	while (i < len)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* 
int main ()
{
	char test[] = "Ab wann soll der String ausgegeben werden?";
	char *result = ft_substr("hola", 2, 1);

	printf("Teilsting:%s", result);
} */
