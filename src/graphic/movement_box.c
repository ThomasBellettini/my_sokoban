/*
** EPITECH PROJECT, 2021
** movement_box.c
** File description:
** Box gravity
*/

#include "../../include/sokoban.h"

static void win(game *g)
{
    if (g->score >= g->max) {
        g->is_won = 1;
    }
}

int box_right(game *g, linked_entity *entity)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->y != entity->y || linked_list->x != entity->x + 1) {
            continue;
        }
        if (linked_list->type != POINT) {
            return 2;
        }
        if (linked_list->type == POINT) {
            entity->type = BOX_LOCKED;
            linked_list->type = POINT_LOCKED;
            g->score += 1;
        }
    }
    entity->x += 1;
    loose(g, entity);
    win(g);
    return 0;
}

int box_up(game *g, linked_entity *entity)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->x != entity->x || linked_list->y != entity->y - 1) {
            continue;
        }
        if (linked_list->type != POINT) {
            return 2;
        }
        if (linked_list->type == POINT) {
            entity->type = BOX_LOCKED;
            linked_list->type = POINT_LOCKED;
            g->score += 1;
        }
    }
    entity->y -= 1;
    loose(g, entity);
    win(g);
    return 0;
}

int box_down(game *g, linked_entity *entity)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->x != entity->x || linked_list->y != entity->y + 1) {
            continue;
        }
        if (linked_list->type != POINT) {
            return 2;
        }
        if (linked_list->type == POINT) {
            entity->type = BOX_LOCKED;
            linked_list->type = POINT_LOCKED;
            g->score += 1;
        }
    }
    entity->y += 1;
    loose(g, entity);
    win(g);
    return 0;
}

int box_left(game *g, linked_entity *entity)
{
    linked_entity *linked_list = g->linked;

    for (; linked_list != NULL; linked_list = linked_list->next) {
        if (linked_list->y != entity->y || linked_list->x != entity->x - 1) {
            continue;
        }
        if (linked_list->type != POINT) {
            return 2;
        }
        if (linked_list->type == POINT) {
            entity->type = BOX_LOCKED;
            linked_list->type = POINT_LOCKED;
            g->score += 1;
        }
    }
    entity->x -= 1;
    loose(g, entity);
    win(g);
    return 0;
}