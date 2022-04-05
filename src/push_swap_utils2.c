/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:52:38 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/18 15:48:30 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strcmp(char *s1,char *s2)
{
	unsigned int	i;

	i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
	{
		if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s1[i] > s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

int is_empty(t_d_list *p_stack)
{
    if (p_stack == NULL)
        return (1);
    return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		r;
	char	*ptr;

	ptr = (char *)str;
	i = 0;
	s = 1;
	r = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	while ((ptr[i] == '-') || (str[i] == '+'))
	{
		if (ptr[i] == '-')
			s = s * -1;
		if (ptr[i + 1] == '-' || ptr[i + 1] == '+')
			return (0);
		i++;
	}
	while ((ptr[i] >= '0') && (ptr[i] <= '9'))
	{
		r = (r * 10) + (ptr[i] - '0');
		i++;
	}
	return (r * s);
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (!0);
	}
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = 0;
	if (!ptr)
		return (0);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}