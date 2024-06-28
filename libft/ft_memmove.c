/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:55:10 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 17:14:33 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if ((unsigned char *) dest == (const unsigned char *) src)
		return (dest);
	if ((unsigned char *) dest > (const unsigned char *) src)
	{
		while (n > 0)
		{
			((unsigned char *) dest)[n - 1]
				= ((const unsigned char *) src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((const unsigned char *) src)[i];
			i++;
		}
	}
	return ((unsigned char *) dest);
}

/* #include <stdio.h>
#include <string.h>

int main() {
	char quelle[] = "Hallo, Welt!";
	char ziel[20];

	
	ft_memmove(quelle, quelle + 8, sizeof(char) * 4);
	//memmove(quelle, quelle + 8, sizeof(char) * 4);

	printf("Quelle: %s\n", quelle);

	return 0;
}
 */