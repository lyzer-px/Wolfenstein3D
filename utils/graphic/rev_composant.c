/*
** EPITECH PROJECT, 2024
** Wolfenstein3D
** File description:
** rev_linkedlist.c
*/

#include "struct.h"

void rev_composant(composant_t **begin)
{
    composant_t *new_begin = NULL;
    composant_t *next_begin = NULL;

    while ((*begin) != NULL) {
        next_begin = (*begin)->next;
        (*begin)->next = new_begin;
        new_begin = (*begin);
        (*begin) = next_begin;
    }
    *begin = new_begin;
    return;
}
