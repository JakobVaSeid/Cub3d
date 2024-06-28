/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:37:05 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/21 11:50:38 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t			strlen;
	unsigned int	i;

	i = 0;
	strlen = ft_strlen(s);
	while (s[i])
	{
		while (i < strlen)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
