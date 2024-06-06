/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:02:51 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/06 16:10:46 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool output)
{
	rotate(a);
	if (output)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool output)
{
	rotate(b);
	if (output)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool output)
{
	rotate(a);
	rotate(b);
	if (output)
		ft_printf("rr\n");
}
