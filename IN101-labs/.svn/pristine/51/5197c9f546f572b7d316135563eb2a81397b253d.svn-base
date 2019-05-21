/*
 *
 *    Copyright 1985-2015 Fabrice Frances
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
 * @file maze.h
 * @brief Bob vs The Maze
 *
 * This module exposes both Maze Generator routines,
 * and the interface for Bob the robot.
 *
 * @author Fabrice Frances
 * @date 24 Nov 2015
 */
#include <stdbool.h>

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
 * An enumeration to represent relative directions for the Robot.
 */
enum RelativeDirection {
    /** the "front of" relative direction */
    FRONT,
    /** the "right" relative direction */
    RIGHT,
    /** the "rear" relative direction */
    REAR,
    /** the "left" relative direction */
    LEFT
};

/**
 * This function builds an aesthetic maze
 *
 * @param horizontal_size the number of rooms horizontally
 * @param vertical_size the number of rooms vertically
 * @param corridor_size the width of the corridors (in pixels)
 * @param maze_id a unique identifier number, each identifier gives a different maze
 * @param tree tells if the maze is a logical tree. If false, a circuit will prevent left/right-hand algorithm
 * @param show_build true gives more magical feeling, use false if you are the kind of a hurry guy/girl...
 */
extern void MazeInit(int horizontal_size, int vertical_size, int corridor_size, long maze_id, bool tree, bool show_build);

/**
 * This function terminates the graphical program
 */
extern void MazeEnd(void);

/**
 * This function sets Bob's speed (useful for large mazes...)
 *
 * @param speed speed of Bob, note that this depends on Bob's size (which is equal to the corridor width).
 */
extern void BobSetSpeed(unsigned int speed);

/**
 * This function tells if bob is Out of the maze
 *
 * @return true is Bob is outside the maze
 */
extern bool BobIsOut(void);

/**
 * This function tells if Bob touches a wall on North
 *
 * @return true if Bob touches a wall
 */
extern bool BobHasNorthContact(void);

/**
 * This function tells if Bob touches a wall on South
 *
 * @return true if Bob touches a wall
 */
extern bool BobHasSouthContact(void);

/**
 * This function tells if Bob touches a wall on West
 *
 * @return true if Bob touches a wall
 */
extern bool BobHasWestContact(void);

/**
 * This function tells if Bob touches a wall on East
 *
 * @return true if Bob touches a wall
 */
extern bool BobHasEastContact(void);

/**
 * This function tries to move Bob one step to the North
 * (Bob won't move if there's a wall)
 */
extern void BobGoNorth(void);

/**
 * This function tries to move Bob one step to the South
 * (Bob won't move if there's a wall)
 */
extern void BobGoSouth(void);

/**
 * This function tries to move Bob one step to the West
 * (Bob won't move if there's a wall)
 */
extern void BobGoWest(void);

/**
 * This function tries to move Bob one step to the East
 * (Bob won't move if there's a wall)
 */
extern void BobGoEast(void);

/**
 * This function gives the absolute direction corresponding
 * to a relative direction from a given absolute direction.
 *
 * @param current_dir the current absolute direction
 * @param relative_dir the relativex direction
 *
 * @return the absolute direction corresponding to
 *          the relative direction
 */
extern enum Direction TurnTo(enum Direction current_dir,
                             enum RelativeDirection relative_dir);

/**
 * This function make Bob one step forward using the given
 * absolute direction.
 *
 * @param current_dir the current absolute direction
 */
extern void OneStepForward(enum Direction current_dir);

/**
 * This function checks if there is a wall using a relative
 * direction.
 *
 * @param current_dir the current absolute direction
 * @param relative_dir the relative direction
 *
 * @return a boolean that is true if there is a wall in the
 *         current relative direction
 */
extern bool RelativeContact(enum Direction current_dir,
                            enum RelativeDirection relative_dir);
