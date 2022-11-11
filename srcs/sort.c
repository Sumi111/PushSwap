/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:08:11 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 12:05:11 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_b(t_stack *stack)
{
	int	size;
	int	max_pos;

	size = stack->b_size - 1;
	while (size >= 0)
	{
		max_pos = ft_max_pos(stack->b, stack->b_size);
		if (max_pos == 0)
		{
			pa(stack);
			size--;
		}
		else if (max_pos <= size / 2)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

int	chunk_present(t_stack *stack, int chunk)
{
	int	i;

	i = 0;
	while (i < stack->a_size)
	{
		if (stack->a[i] <= chunk)
			return (1);
		i++;
	}
	return (0);
}

void	move_chunk(int mid, t_stack *stack, int s)
{
	int	t;

	while (chunk_present(stack, mid) && stack->a_size != 0)
	{
		t = make_way(mid, stack);
		if (t == 1)
			ra(stack, 1);
		else if (t == -1)
			rra(stack, 1);
		else
		{
			pb(stack);
			if (stack->b_size > 1 && stack->b[0] < stack->b[1])
				sb(stack, 1);
			if (stack->b[0] > s && stack->b_size > 1)
				rb(stack, 1);
		}
	}
}

int	ft_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort(t_stack *stack)
{
	if (!ft_sorted(stack))
	{
		if (stack->a_size <= 5)
			small_sort(stack);
		else
			large_sort(stack);
	}
}
