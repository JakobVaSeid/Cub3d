/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:59:11 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:12:36 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/* #include <strings.h>
#include <stdio.h>
int main ()
{
	char test[] = "Hallo Hallo";
	char test1[] = "Test Test";

	ft_bzero(test + 3, 8);
	bzero(test1 + 3 , 1);

	printf("%s\n", test);
	printf("%s\n", test1);
} */
