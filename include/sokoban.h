/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** main header
*/

#ifndef SOKOBAN_SOKOBAN_H
#define SOKOBAN_SOKOBAN_H

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum _ENUM_ENTITY_TYPE_ {
    WALL,
    BOX,
    BOX_LOCKED,
    POINT,
    POINT_LOCKED
} entity_type;

typedef struct _LINKED_LIST_BLOCK_ {
    int x;
    int y;

    entity_type type;
    struct _LINKED_LIST_BLOCK_ *next;
} linked_entity;

typedef struct _PLAYER_ {
    int x;
    int y;
}player;

typedef struct _GAME_ {
    player p;
    linked_entity *linked;

    int score;
    int max;
    int can_loose;
    int small;

    int is_loose;
    int is_won;
} game;

int     read_file(char *path, char *read_buffer, int size);
void    graphic_setup(char *map);

void    player_down(game *g);
void    player_right(game *g);
void    player_left(game *g);
void    player_up(game *g);
void    draw(game *g);
void    add(entity_type type, int x, int y, game *g);
int     box_right(game *g, linked_entity *entity);
int     box_up(game *g, linked_entity *entity);
int     box_left(game *g, linked_entity *entity);
int     box_down(game *g, linked_entity *entity);
void    restart(game *g, char *map);
void    analyse(game *g, const char *map);
void    reset_game(game *g);
void    loose(game *g, linked_entity *entity);
void    check_loose(game *g);
void    check_resize(game *g, char *map);
int     second_condition(game *g, linked_entity *entity);
int     y_up(linked_entity *linked, linked_entity *entity, game *g);
int     y_down(linked_entity *linked, linked_entity *entity, game *g);
void    check_error(char *map);
int     pre_error_check(game *g, linked_entity *entity);
void    finish(game *g, int code_return);

#endif
