/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:03:23 by mshehata          #+#    #+#             */
/*   Updated: 2022/12/03 16:53:30 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*char_s;
	size_t	i;

	char_s = (char *)s;
	i = 0;
	while (i < n)
	{
		char_s[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char s[] = "This is my test phrase";
// 	ft_bzero(s, 10) ;

// 	printf(("%s\n"), s);
// }

// you can use memset
