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

/**
 * @file load-maze.h
 * @brief Bob vs The Maze
 *
 * This module exposes a maze loader. It allows to load a maze from a text file.
 *
 * @author Christophe Garion
 * @date 24 Nov 2015
 */


/**
 * An enumeration to represent absolute directions on the map.
 */
enum Direction {
    /** the east direction */
    EAST,
    /** the south direction */
    SOUTH,
    /** the west direction */
    WEST,
   /** the north direction */
    NORTH
};

/**
 * The map loaded from the file. You should not use it without having
 * called LoadMap successfully!
 */
extern char **map;

/**
 * This function loads a map from a text file.
 *
 * @param file_name the name of the file containing the maze
 */
void LoadMap(const char * file_name);

/**
 * This function returns the dimension of the currently loaded maze.
 *
 * @returns the dimension of the maze
 */
int GetDim();

/**
 * This function returns an matrix of chars representing the maze.
 *
 * @returns a matrix of chars representing the maze
 */
char **GetMatrix();

/**
 * This function prints the matrix.
 *
 */
void PrintMatrix();

/**
 * This function cleans the matrix. It should be used at the end of your program.
 *
 */
void Clean();
