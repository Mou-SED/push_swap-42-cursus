/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:38:35 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/10 20:40:42 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_plus_or_minus(int c)
{
   if (c == '+' || c == '-')
      return (!0);
   return (0);
}

int is_space(int c)
{
   if (c == ' ' || c == '\t' || c == 32)
      return (!0);
   return (0);
}

char	*ft_strjoin_char(char *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	if (!s1)
   { 
      s1 = (char *)malloc(sizeof(char) * 1);
      s1[0] = '\0';        
   }
	newstr = (char *)malloc((sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 2)));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
   newstr[i++] = c;
	j = 0;
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

char **join_args(char **str)
{
   char *ptr;
   char **ptr2;
   int i;
   
   ptr = NULL;
   i = 0;
   while(str[i])
      ptr = ft_strjoin_char(ptr, str[i++], ' ');
   ptr2 = ft_split(ptr,' ');
   return (ptr2);
}

long long ft_atoi_long(const char *str)
{
	int            i;
	int            s;
	unsigned long  r;
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
