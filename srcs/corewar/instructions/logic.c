/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:10:01 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 12:10:02 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes two registers / directs / indirects, applies a logical AND
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_and(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
    unsigned int    src[2];
    unsigned int    dst;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    ft_bzero(&src, sizeof(src));
    if (args->first->type == REG_CODE)
        ft_memcpy(&src[0], &(proc->reg[args->first->val]), REG_SIZE);
    else
        src[0] = args->first->val;
    if (args->first->next->type == REG_CODE)
        ft_memcpy(&src[1], &(proc->reg[args->first->next->val]), REG_SIZE);
    else
        src[1] = args->first->next->val;
    dst = args->first->next->next->val;
    vm->print("and %u, %u, %u | ", src[0], src[1], dst);
    load(vm, dst, src[0] & src[1]);
}

/*
**		Takes two registers / directs / indirects, applies a logical OR
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_or(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
    unsigned int    src[2];
    unsigned int    dst;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    ft_bzero(&src, sizeof(src));
    if (args->first->type == REG_CODE)
        ft_memcpy(&src[0], &(proc->reg[args->first->val]), REG_SIZE);
    else
        src[0] = args->first->val;
    if (args->first->next->type == REG_CODE)
        ft_memcpy(&src[1], &(proc->reg[args->first->next->val]), REG_SIZE);
    else
        src[1] = args->first->next->val;
    dst = args->first->next->next->val;
    vm->print("and %u, %u, %u | ", src[0], src[1], dst);
    load(vm, dst, src[0] | src[1]);
}

/*
**		Takes two registers / directs / indirects, applies a logical XOR
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_xor(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
    unsigned int    src[2];
    unsigned int    dst;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    ft_bzero(&src, sizeof(src));
    if (args->first->type == REG_CODE)
        ft_memcpy(&src[0], &(proc->reg[args->first->val]), REG_SIZE);
    else
        src[0] = args->first->val;
    if (args->first->next->type == REG_CODE)
        ft_memcpy(&src[1], &(proc->reg[args->first->next->val]), REG_SIZE);
    else
        src[1] = args->first->next->val;
    dst = args->first->next->next->val;
    vm->print("and %u, %u, %u | ", src[0], src[1], dst);
    load(vm, dst, src[0] ^ src[1]);
}
