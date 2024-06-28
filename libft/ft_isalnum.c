/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:13:08 by jseidere          #+#    #+#             */
/*   Updated: 2023/09/20 15:21:42 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z')
		|| (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}
/* #include <stdio.h>
int main ()
	{
	printf("%i", ft_isalnum ('A'));
	printf("%i", ft_isalnum ('1'));
	printf("%i", ft_isalnum ('#'));
	} */
