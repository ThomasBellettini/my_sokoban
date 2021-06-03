/*
** EPITECH PROJECT, 2021
** movement.c
** File description:
** CLass for player gravity
*/

#include "../../include/sokoban.h"

void player_up(game *g)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->x != g->p.x || linked_list->y != g->p.y - 1)
            continue;
        if (linked_list->type == WALL || linked_list->type == BOX_LOCKED) {
            return;
        }
        if (linked_list->type == BOX) {
            if (box_up(g, linked_list) == 2)
                return;
            else
                break;
        }
    }
    g->p.y -= 1;
}

void player_down(game *g)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->x != g->p.x || linked_list->y != g->p.y + 1)
            continue;
        if (linked_list->type == WALL || linked_list->type == BOX_LOCKED) {
            return;
        }
        if (linked_list->type == BOX) {
            if (box_down(g, linked_list) == 2)
                return;
            else
                break;
        }
    }
    g->p.y = g->p.y + 1;
}

void player_right(game *g)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->y != g->p.y || linked_list->x != g->p.x + 1) {
            continue;
        }
        if (linked_list->type == WALL || linked_list->type == BOX_LOCKED) {
            return;
        }
        if (linked_list->type == BOX) {
            if (box_right(g, linked_list) == 2)
                return;
            else
                break;
        }
    }
    g->p.x = g->p.x + 1;
}

void player_left(game *g)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->y != g->p.y || linked_list->x != g->p.x - 1)
            continue;
        if (linked_list->type == WALL || linked_list->type == BOX_LOCKED) {
            return;
        }
        if (linked_list->type == BOX) {
            if (box_left(g, linked_list) == 2)
                return;
            else
                break;
        }
    }
    g->p.x -= 1;
}