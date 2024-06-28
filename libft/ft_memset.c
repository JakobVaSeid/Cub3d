/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:29:56 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:40:40 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* int main ()
{
		int i;
		i = 0;

	//char test[10];
	char test_fake[10];

	// Original
	//memset(test+5, 'b', sizeof(char) * 5);
	//memset(test, 'a', sizeof(char) * 5);

	// Fake
	ft_memset(test_fake, 'A', sizeof(char) * 5);
	ft_memset(test_fake+5, 'B', sizeof(char) * 5);
	
	//printf("Original Memset: %s \n",test);
	printf("Fake Memset: %s \n", test_fake);
	
} */
