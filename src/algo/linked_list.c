/*
** EPITECH PROJECT, 2021
** linked_list.c
** File description:
** Managing Linked List and Drawing frame
*/

#include "../../include/sokoban.h"

void draw(game *g)
{
    linked_entity *linked = g->linked;

    while (linked != NULL) {
        if (linked->type == WALL) {
            mvaddch(linked->y, linked->x, '#');
        } else if (linked->type == POINT) {
            mvaddch(linked->y, linked->x, 'O');
        } else if (linked->type == BOX || linked->type == BOX_LOCKED) {
            mvaddch(linked->y, linked->x, 'X');
        }
        linked = linked->next;
    }
    mvaddch(g->p.y, g->p.x, 'P');
}

void add(entity_type type, int x, int y, game *g)
{
    linked_entity *origin = g->linked;
    linked_entity *tmp = NULL;
    linked_entity *bypass = NULL;

    tmp = malloc(sizeof(linked_entity));
    tmp->x = x;
    tmp->y = y;
    tmp->type = type;
    tmp->next = NULL;
    if (origin == NULL) {
        g->linked = tmp;
    } else {
        bypass = g->linked;
        while (bypass->next != NULL)
            bypass = bypass->next;
        bypass->next = tmp;
    }
}

void restart(game *g, char *map)
{
    linked_entity *link = g->linked;

    while (link != NULL) {
        linked_entity *tmp = link->next;
        free(link);
        link = tmp;
    }
    g->linked = NULL;
    reset_game(g);
    analyse(g, map);
}

int second_condition(game *g, linked_entity *entity)
{
    linked_entity *linked = g->linked;

    for (; linked != NULL; linked = linked->next) {
        if (linked->x == entity->x - 1 && linked->y == entity->y) {
            entity_type  t = linked->type;
            if (t == BOX_LOCKED || t == WALL || t == POINT_LOCKED || t == BOX) {
                return 1;
            }
        } else if (linked->x == entity->x + 1 && linked->y == entity->y) {
            entity_type  t = linked->type;
            if (t == BOX_LOCKED || t == WALL || t == POINT_LOCKED || t == BOX) {
                return 1;;
            }
        }
    }
    return 0;
}

void loose(game *g, linked_entity *entity)
{
    linked_entity *linked = g->linked;

    if (pre_error_check(g, entity) == 10)
        return;
    for (; linked != NULL; linked = linked->next) {
        if (linked->y == entity->y - 1 && linked->x == entity->x) {
            y_up(linked, entity, g);
        } else if (linked->y == entity->y + 1 && linked->x == entity->x) {
            y_down(linked, entity, g);
        }
    }
}