/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:16:49 by vlobunet          #+#    #+#             */
/*   Updated: 2018/02/23 18:16:50 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_norm(char *str)
{
	int	x;
	int	size;

	x = 0;
	size = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		x = 1;
	if (size - x < 19 || (size - x == 19 && str[size - 1] <= '7'))
		return (str);
	else
	{
		if (str[0] == '-')
			return ("0");
		else
			return ("-1");
	}
}

static char	*f_strcpy(char *dest, const char *src)
{
	char	*s;

	s = dest;
	while (ft_if_space(*src))
		src++;
	if (*src == '-')
		*dest++ = *src++;
	else if (*src == '+')
		*dest++ = *src++;
	while (*src >= '0' && *src <= '9')
		*dest++ = *src++;
	*dest = '\0';
	return (ft_norm(s));
}

static char	*f_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_if_space(s[i]))
		i++;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) - i));
	if (str == NULL)
		return (NULL);
	else
		return (f_strcpy(str, s));
}

int			ft_atoi(const char *str)
{
	int		n;
	int		flag;
	char	*strnew;

	n = 0;
	flag = 0;
	if (*str == '\0')
		return (0);
	strnew = f_strdup(str);
	if (*strnew == '-')
	{
		flag = 1;
		strnew++;
	}
	else if (*strnew == '+')
		strnew++;
	while (*strnew >= '0' && *strnew <= '9')
	{
		n = n * 10 + (*strnew - '0');
		strnew++;
	}
	if (flag)
		return (-n);
	else
		return (n);
}
