/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jseidere <jseidere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:23:09 by jseidere          #+#    #+#             */
/*   Updated: 2024/07/05 11:06:36 by jseidere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int len_until_sc(char *str, char c)
{
	int i;

	i = 0;
	while(str[i] && str[i] != c /* && str[i] != ',' */)
		i++;
	return (i);
}

char	*norm_line(char *str)
{
   int  i;
   int	j;
   char *result;
   char	*tmp;

   i = 0;
   j = 0;
   result = ft_strdup("");
   tmp = NULL;
   while(str[i])
   {
		skip_spaces(str, &i);
		tmp = ft_substr(str, i, len_until_sc(str + i, ' '));
		result = ft_strjoin(result, tmp);
		if(is_dir(tmp) || is_fc(tmp))
			result = ft_strjoin(result, " ");
		i += len_until_sc(str + i, ' ');
		skip_spaces(str, &i);
		free(tmp);
   }
	return (result);
}
