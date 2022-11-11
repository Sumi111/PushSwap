/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:38:45 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 12:05:24 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(int *a, int size)
{
	int	max;
	int	i;

	max = a[0];
	i = 0;
	while (i < size)
	{
		if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}

int	ft_max_pos(int *a, int a_size)
{
	int	i;
	int	pos;
	int	max;

	i = 0;
	max = a[0];
	pos = 0;
	while (i < a_size)
	{
		if (max < a[i])
		{
			max = a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	ft_min_pos(int *a, int a_size)
{
	int	i;
	int	pos;
	int	min;

	i = 0;
	min = a[i];
	pos = 0;
	while (i < a_size)
	{
		if (min > a[i])
		{
			min = a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

void	push_max_min(t_stack *stack, int pos)
{
	if (pos <= 2)
	{
		while (pos != 0)
		{
			ra(stack, 1);
			pos--;
		}
	}
	else
	{
		if (pos == stack->a_size - 2)
			rra(stack, 1);
		rra(stack, 1);
	}
	pb(stack);
}

int	make_way(int chunk, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->a_size - 1;
	if (stack->a[0] <= chunk)
		return (0);
	if (stack->a[1] <= chunk)
	{
		sa(stack, 1);
		return (0);
	}
	while (stack->a[i] > chunk)
		i++;
	while (stack->a[j] > chunk)
		j--;
	if (i > stack->a_size / 2)
		return (-1);
	return (1);
}
