/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:14:22 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 20:57:47 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_error(char *str)
{
	int	value;

	value = 0;
	if (is_plus_or_minus(*str) && !ft_isdigit(*(str + 1)))
		return (1);
	if (is_plus_or_minus(*str) && str++)
		value = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (!ft_isdigit(*str))
			value = 1;
		str++;
	}
	return (value);
}

int	check_error_overflow(char *str)
{
	long	num;

	num = ft_atoi_long(str);
	if (num > MAX_INT || num < MIN_INT)
		return (1);
	return (0);
}

void	check_dupl_args(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
				ft_print_error();
			j++;
		}
		i++;
	}
}

void	ft_print_error(void)
{
	printf("Error\n");
	exit(1);
}
