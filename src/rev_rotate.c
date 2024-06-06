/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:02:15 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/06 16:02:35 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool output)
{
	rev_rotate(a);
	if (output)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool output)
{
	rev_rotate(b);
	if (output)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool output)
{
	rev_rotate(a);
	rev_rotate(b);
	if (output)
		ft_printf("rrr\n");
}
