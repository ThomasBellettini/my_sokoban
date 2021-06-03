/*
** EPITECH PROJECT, 2021
** graphic.c
** File description:
** graphic manager
*/

#include "../../include/sokoban.h"

void reset_game(game *g)
{
    linked_entity *tmp = NULL;

    g->can_loose = 0;
    g->score = 0;
    g->linked = tmp;
    g->max = 0;
    g->small = 0;
}

void analyse(game *g, const char *map)
{
    for (int i = 0, c = 0, l = 0; map[i] != '\0' ; ++i, ++l) {
        if (map[i] == 'P') {
            g->p.x = l;
            g->p.y = c;
            continue;
        }
        if (map[i] == '#')
            add(WALL, l, c, g);
        if (map[i] == 'X') {
            g->can_loose += 1;
            add(BOX, l, c, g);
        }
        if (map[i] == 'O') {
            g->max += 1;
            add(POINT, l, c, g);
        }
        if (map[i] == '\n') {
            c++;
            l = -1;
        }
    }
}

static int analyse_keyboard(int keyboard, game *g, char *map)
{
    switch (keyboard) {
        case KEY_RIGHT:
            player_right(g);
            return 0;
        case KEY_LEFT:
            player_left(g);
            return 0;
        case KEY_UP:
            player_up(g);
            return 0;
        case KEY_DOWN:
            player_down(g);
            return 0;
        case 32:
            restart(g, map);
            return 0;
    }
}

static int loop(game *g, char *map)
{
    int keyboard;

    clear();
    if (g->small == 1) {
        mvprintw(0, 0, "Error, terminal is too small !");
    } else {
        draw(g);
    }
    refresh();
    keyboard = getch();
    if (keyboard == 410) {
        check_resize(g, map);
    } else if (keyboard == 27) {
        endwin();
        exit(0);
    } else if (g->small == 0) {
        analyse_keyboard(keyboard, g, map);
    }
    return 0;
}

void graphic_setup(char *map)
{
    game g;
    WINDOW *windows = initscr();

    curs_set(0);
    keypad(windows, TRUE);
    reset_game(&g);
    analyse(&g, map);
    if (g.max != g.can_loose) {
        endwin();
        exit(84);
    }
    while (1) {
        if (g.is_loose == 1) {
            finish(&g, 1);
        } else if (g.is_won == 1) {
            finish(&g, 0);
        }
        if (loop(&g, map) != 0)
            break;
    }
    endwin();
}

