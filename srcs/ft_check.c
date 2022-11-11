/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:32:32 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/27 13:19:41 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_str(char **str, int ct)
{
	int	i;

	i = 0;
	while (i < ct)
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	ft_free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	ft_check_num(char *str, t_stack *stack, int flag, char **start)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			if (flag == 0)
				ft_free_str(start, stack->a_size);
			ft_free_stack(stack);
			exit (1);
		}
		i++;
	}
}

void	check_repti(t_stack *stack, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[i] == stack->a[j])
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_stack (stack);
				exit (1);
			}
			j++;
		}
		i++;
	}
}
