/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:25:26 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 16:07:54 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	temp = (char *)s;
	if ((char) c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	if (*s == 0)
		return (0);
	while (temp[i])
	{
		if ((unsigned char)temp[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if (j == -1)
		return (0);
	return (temp + j);
}

/* #include <string.h>
#include <stdio.h>
int main ()
{
	const char *test = "";
	
	char *result = ft_strrchr(test, '\0');
	char *result2 = strrchr(test, '\0');
	printf("Fake: %s\n", result);
	printf("Original: %s\n", result2);
}  */