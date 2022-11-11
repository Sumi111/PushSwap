/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:29:41 by sfathima          #+#    #+#             */
/*   Updated: 2022/04/26 15:22:14 by sfathima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_dup(int *tmp, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size)
	{
		tmp[i] = stack->a[i];
		i++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i >= 0)
				ft_swap (&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *tmp, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(tmp, low, high);
		quick_sort(tmp, low, pi - 1);
		quick_sort(tmp, pi + 1, high);
	}
}
