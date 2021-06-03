/*
** EPITECH PROJECT, 2021
** files.c
** File description:
** CLass for files managing
*/

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int read_file(char *path, char *read_buffer, int size)
{
    int rd;
    int files;

    files = open(path, O_RDONLY);
    if (files == -1)
        return 84;
    read_buffer[size + 1] = '\0';
    rd = read(files, read_buffer, size);
    if (rd == -1)
        return 84;
    return files;
}
