/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:38:11 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 13:59:31 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack, int print)
{
	int	tmp;

	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (print == 1)
		printf("sa\n");
}

void	ra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	tmp = stack->a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	if (print == 1)
		printf("ra\n");
}

void	rra(t_stack *stack, int print)
{
	int	tmp;
	int	i;

	i = stack->a_size - 1;
	tmp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (print == 1)
		printf("rra\n");
}

void	pa(t_stack *stack)
{
	int	i;

	i = stack->a_size - 1;
	while (i >= 0)
	{
		stack->a[i + 1] = stack->a[i];
		i--;
	}
	stack->a[0] = stack->b[0];
	stack->a_size++;
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b_size--;
	printf("pa\n");
}
