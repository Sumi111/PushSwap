/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:37:53 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 12:05:06 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack *stack)
{
	int	max_index;

	max_index = ft_max_pos(stack->a, stack->a_size);
	if (max_index == 0)
		ra(stack, 1);
	else if (max_index == 1)
		rra(stack, 1);
	if (stack->a[0] > stack->a[1])
		sa(stack, 1);
}

void	sort_5(t_stack *stack)
{
	int	max_pos;
	int	min_pos;
	int	i;

	i = 0;
	max_pos = ft_max_pos(stack->a, stack->a_size);
	push_max_min(stack, max_pos);
	min_pos = ft_min_pos(stack->a, stack->a_size);
	push_max_min(stack, min_pos);
	sort_3(stack);
	while (i < 2)
	{
		pa(stack);
		i++;
	}
	ra(stack, 1);
}

void	small_sort(t_stack *stack)
{
	if (stack->a_size == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, 1);
	}
	else if (stack->a_size == 3)
		sort_3(stack);
	else if (stack->a_size == 4 || stack->a_size == 5)
		sort_5(stack);
}
