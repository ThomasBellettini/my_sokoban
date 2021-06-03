/*
** EPITECH PROJECT, 2021
** security.c
** File description:
** TODO: add description
*/

#include "../../include/sokoban.h"

int pre_error_check(game *g, linked_entity *entity)
{
    linked_entity *linked = g->linked;

    for (; linked != NULL ; linked = linked->next) {
        if (linked->y == entity->y && linked->x == entity->x) {
            if (linked->type == POINT_LOCKED || linked->type == POINT) {
                return 10;
            }
        }
    }
    return 0;
}

void finish(game *g, int code_return)
{
    clear();
    draw(g);
    refresh();
    usleep(250000);
    endwin();
    exit(code_return);
}