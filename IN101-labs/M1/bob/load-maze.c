/*
 *
 *    Copyright 2015 Christophe Garion
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <stdlib.h>
#include <stdio.h>
#include "load-maze.h"

static int dim;
char **map;

static void AllocateMap()
{
    int i;

    map = malloc(dim * sizeof(char *));

    if (map == NULL) {
        fprintf(stderr,"malloc : not enough memory !\n"); exit(-1);
    }

    for (i=0; i < dim; i++) {
        map[i] = malloc(dim * sizeof(char));

        if (map[i]==NULL) {
            fprintf(stderr,"malloc : not enough memory !\n");
            exit(-1);
        }
    }
}

void LoadMap(const char * file_name)
{
    FILE * maze_file = fopen(file_name, "r");

    if (maze_file == NULL) {
        fprintf(stderr,"cannot read file %s !\n", file_name);
        exit(-1);
    }

    if (fscanf(maze_file, "%d\n", &dim) == EOF) {
        fprintf(stderr,"the first line of the file must be the maze dimension!\n");
        exit(-1);
    }

    AllocateMap();

    char line[dim];

    for (int i = 0; i < dim; i++) {
        fgets(line, 25, maze_file);

        for (int j = 0; j < dim; j++) {
            map[i][j] = line[j];
        }
    }

    fclose(maze_file);
}

int GetDim()
{
    return dim;
}

char  **GetMatrix()
{
    return map;
}

void PrintMatrix()
{
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%c", map[i][j]);
        }

        printf("\n");
    }
}

void Clean()
{
    int i;
    for (i=0; i < dim; i++)
        free(map[i]);
    free(map);
}
