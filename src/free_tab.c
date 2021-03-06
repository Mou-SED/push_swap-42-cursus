/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:06:04 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 09:11:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tab_without_index(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}
