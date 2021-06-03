/*
** EPITECH PROJECT, 2021
** sokoban.c
** File description:
** TODO: add description
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "../include/sokoban.h"

int m_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; ++i);
    return i;
}

void help()
{
    char *help = "USAGE\n";
    char *second = "     ./my_sokoban map\n";
    char *third = "DESCRIPTION\n";
    char *four = "     map  file representing the warehouse map,";
    char *five = "containing ‘#’ for walls,\n";
    char *six = "          ‘P’ for the player, ‘X’ for boxes and ‘O’";
    char *seven = " for storage locations.";

    write(1, help, m_strlen(help));
    write(1, second, m_strlen(second));
    write(1, third, m_strlen(third));
    write(1, four, m_strlen(four));
    write(1, five, m_strlen(five));
    write(1, six, m_strlen(six));
    write(1, seven, m_strlen(seven));
}

int main(int size, char **arg)
{
    struct stat st_stats;
    char *buffer;
    int file_id;

    if (size == 2 && arg[1][0] == '-' && arg[1][1] == 'h') {
        help();
        return 0;
    }
    if (size != 2)
        return 84;
    stat(arg[1], &stats);
    buffer = malloc(st_stats.st_size + 2);
    buffer[0] = '\0';
    file_id = read_file(arg[1], buffer, st_stats.st_size);
    if (file_id == 84 || buffer[0] == '\0')
        return 84;
    check_error(buffer);
    graphic_setup(buffer);
    free(buffer);
    close(file_id);
}