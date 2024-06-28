/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:30:53 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/21 18:11:26 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *) s);
		else
			s++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int main ()
{
	const char *test = "Hello is there an Z?";
	
	char *result = ft_strchr(test, '\0');
	char *result2 = strchr(test, '\0');
	printf("%s\n", result);
	printf("%s\n", result2);
} */