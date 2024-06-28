/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:58:44 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:23:53 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	else
		return (0);
}
/* 
#include <stdio.h>
int main ()
	{
	printf("%i\n",ft_isdigit('1'));
	printf("%i", ft_isdigit('A'));
	} */
