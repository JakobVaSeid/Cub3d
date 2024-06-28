/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:33:32 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:34:44 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ft_dest;
	const char	*ft_src;

	ft_dest = dest;
	ft_src = src;
	i = 0;
	if (ft_dest == ft_src)
		return (dest);
	while (i < n)
	{
		ft_dest[i] = ft_src[i];
		i++;
	}
	return (ft_dest);
}

/* int main (void)
{
	//char s[] = "abcdefghijklmnopqrstuvwxyz";
	//char d[27];
//
	//memcpy(d, s, sizeof(char) * 27);
//
	//printf("d: %s\n", d);
//
	//char e[10];
	//memcpy(e, s+8, sizeof(char) * 9);
	//e[9] = '\0';
//
	//printf("e: %s\n", e);
//
	//return 0;
	
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char d[27];

	ft_memcpy(d, s, sizeof(char) * 27);

	printf("d: %s\n", d);
	
}  */