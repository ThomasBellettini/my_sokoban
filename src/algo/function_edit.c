/*
** EPITECH PROJECT, 2021
** function_edit.c
** File description:
** Function for map editing
*/

#include "../../include/sokoban.h"

void check_error(char *map)
{
    int player = 0;

    for (int i = 0; map[i] != '\0' ; ++i) {
        if (map[i] != ' ' && map[i] != '#' && map[i] != 'P' && map[i] != 'X') {
            if (map[i] != 'O' && map[i] != '\n') {
                exit(84);
            }
        }
        if (map[i] == 'P') {
            player++;
            if (player > 1)
                exit(84);
        }
    }
}

void check_resize(game *g, char *map)
{
    int max = 0;
    int col = 0;

    for (int i = 0, l = 0; map[i] != '\0'; ++i, l++) {
        if (map[i] == '\n') {
            col++;
            if (l > max) {
                max = l;
            }
            l = -1;
        }
    }
    if (LINES < col)
        g->small = 1;
    if (COLS < max)
        g->small = 1;
    if (g->small == 1 && COLS >= max && LINES >= col) {
        g->small = 0;
    }
}

int y_up(linked_entity *linked, linked_entity *entity, game *g)
{
    entity_type t = linked->type;

    if (t == BOX_LOCKED || t == WALL || t == POINT_LOCKED) {
        if (second_condition(g, entity) == 1) {
            entity->type = BOX_LOCKED;
            g->can_loose--;
            check_loose(g);
        }
    }
}

int y_down(linked_entity *linked, linked_entity *entity, game *g)
{
    entity_type t = linked->type;

    if (t == BOX_LOCKED || t == WALL || t == POINT_LOCKED) {
        if (second_condition(g, entity) == 1) {
            entity->type = BOX_LOCKED;
            g->can_loose--;
            check_loose(g);
        }
    }
}

void check_loose(game *g)
{
    if (g->can_loose <= 0) {
        g->is_loose = 1;
    }
}