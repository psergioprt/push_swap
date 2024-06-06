/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:07:52 by pauldos-          #+#    #+#             */
/*   Updated: 2024/06/06 16:07:54 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node	**a, bool output)
{
	swap(a);
	if (output)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool output)
{
	swap(b);
	if (output)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool output)
{
	swap(a);
	swap(b);
	if (output)
		ft_printf("ss\n");
}
