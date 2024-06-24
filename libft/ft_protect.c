/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caigner <caigner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 22:26:37 by caigner           #+#    #+#             */
/*   Updated: 2024/05/12 22:58:51 by caigner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	*ft_protect(t_common *c, void *ptr, ...)
{
	va_list ap;
	void *to_free;

	if (!ptr)
	{
		va_start(ap, ptr);
		while ((to_free = va_arg(ap, void *)) != NULL)
		{
			free(to_free);
		}
		va_end(ap);
		ft_clean_exit(c, NULL, 1);
		return (NULL);
	}
	return (ptr);
}
