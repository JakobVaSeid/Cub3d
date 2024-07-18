/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:04:18 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/18 14:35:49 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trible_free(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
}

bool	get_number(t_game *game, char *str)
{
	char	*num[3];
	int		hex;

	num[0] = ft_substr(str, 2, len_until_sc(str, ',') - 2);
	if (!ft_atoi(num[0]))
		return (false);
	num[1] = ft_substr(str, len_until_sc(str, ',') + 1, \
	len_until_sc(str + len_until_sc(str, ',') + 1, ','));
	if (!ft_atoi(num[1]))
		return (free(num[0]), false);
	num[2] = ft_substr(str, len_until_sc(str, ',') + \
	len_until_sc(str + len_until_sc(str, ',') + 1, ',') + 2, ft_strlen(str));
	if (!ft_atoi(num[2]))
		return (trible_free(num[0], num[1], num[2]), false);
	hex = rgb_to_hex(ft_atoi(num[0]), ft_atoi(num[1]), ft_atoi(num[2]));
	if (str[0] == 'F')
		game->f_color = hex_to_dec(hex);
	else if (str[0] == 'C')
		game->c_color = hex;
	trible_free(num[0], num[1], num[2]);
	return (true);
}

//rgb to hex
int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

//hex to decimal
int	hex_to_dec(int hex)
{
	int	dec;
	int	r;
	int	g;
	int	b;

	r = (hex >> 16) & 0xFF;
	g = (hex >> 8) & 0xFF;
	b = hex & 0xFF;
	dec = r * 65536 + g * 256 + b;
	return (dec);
}
