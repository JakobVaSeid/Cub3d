/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:26:01 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:32:28 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

/* #include <stdio.h>
 	 int main ()
{
	char test1[] = "This has the same";
	char test2[] = "This has the same";
	
	char test3[] = "This is Shorter";
	char test4[] = "This is bigger";
	
	char test5[] = "This is bigger";
	char test6[] = "This is Shorter";

	printf("%d\n",ft_memcmp(test1, test2, 0));
	printf("%d\n",ft_memcmp(test3, test4, 10));
	printf("%d\n",ft_memcmp(test5, test6, 10));
} */