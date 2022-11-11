/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:28:08 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 15:51:11 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_check(unsigned long n, int sign, t_stack *stack, int flag)
{
	if ((n >= 2147483648UL && sign == 1) || (n > 2147483648UL && sign == -1))
	{
		ft_putstr_fd("Error\n", 2);
		if (flag == 0)
			ft_free_stack(stack);
		exit (1);
	}
}

int	ft_atoi(const char *str, t_stack *stack, int flag)
{
	int					sign;
	unsigned long long	n;

	sign = 1;
	n = 0;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
		{
			n = (n * 10) + (*str - '0');
			ft_check(n, sign, stack, flag);
		}
		else
			break ;
		str++;
	}
	return (n * sign);
}
