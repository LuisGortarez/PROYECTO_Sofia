/*
  Name:		  SOFIAanimations.h
  Created:	07/02/2025 19:20:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de animaciones.
            Cada animación tiene un arreglo con los identificadores
            de servomotores que se deben mover en un determinado 
            orden. Las funciones utilizan ciclos 'for' y delays 
            para realizar los movimientos de forma secuencial o
            sincronizada.
*/

#ifndef SOFIAanimations_H
#define SOFIAanimations_H

#include "SOFIAdatatypes.h"

// For identifying animation to execute
typedef enum
{
  expansion,
  heart,
  greeting,
  rock,
  sleepy,
  zigzag,
  forks,
  inverse,
  boom,
  spiral,
} animations_t;


////////////////////////////////////////////////////////
////////////// Expansion move tiles data ///////////////
////////////////////////////////////////////////////////

#define EXPANSION_MAX_SIZES       10
#define EXPANSION_SIZE            228
#define EXPANSION_UP_DEGREE       110
#define EXPANSION_DOWN_DEGREE     70
#define EXPANSION_DELAY           200

// Array with the amount of tiles to move in each cycle for Expansion shape
static const uint8_t Expansion_sizes[EXPANSION_MAX_SIZES] = {6, 12, 18, 24, 30, 36, 42, 28, 20, 12};

// Array with the tiles to move for making Expansion shape. Each line holds the tiles to move in each cycle
static const uint8_t Expansion[EXPANSION_SIZE] = {
                                111, 97, 113, 128, 127, 126, 
                                // Change cycle
                                110, 95, 96, 82, 98, 99, 114, 129, 143, 142, 141, 125, 
                                // Change cycle
                                109, 94, 80, 81, 67, 83, 84, 100, 115, 130, 145, 144, 158, 157, 156, 140, 139, 124, 
                                // Change cycle
                                108, 93, 78, 79, 65, 66, 52, 68, 69, 85, 86, 101, 116, 131, 146, 160, 159, 173, 172, 171, 155, 154, 138, 123, 
                                // Change cycle
                                107, 92, 77, 63, 64, 50, 51, 37, 53, 54, 70, 71, 87, 102, 117, 132, 147, 162, 161, 175, 174, 188, 187, 186, 170, 169, 153, 152, 137, 122, 
                                // Change cycle
                                106, 91, 76, 61, 62, 48, 49, 35, 36, 22, 38, 39, 55, 56, 72, 73, 88, 103, 118, 133, 148, 163, 177, 176, 190, 189, 203, 202, 201, 185, 184, 168, 167, 151, 136, 121, 
                                // Change cycle
                                105, 90, 75, 60, 46, 47, 33, 34, 20, 21, 7, 23, 24, 40, 41, 57, 58, 74, 89, 104, 119, 134, 149, 164, 179, 178, 192, 191, 205, 204, 218, 217, 216, 200, 199, 183, 182, 166, 165, 150, 135, 120, 
                                // Change cycle
                                45, 31, 32, 18, 19, 5, 6, 8, 9, 25, 26, 42, 43, 59, 194, 193, 207, 206, 220, 219, 233, 231, 215, 214, 198, 197, 181, 180, 
                                // Change cycle
                                30, 16, 17, 3, 4, 10, 11, 27, 28, 44, 209, 208, 222, 221, 235, 229, 213, 212, 196, 195, 
                                // Change cycle
                                15, 1, 2, 12, 13, 29, 224, 223, 237, 227, 211, 210
                                };


////////////////////////////////////////////////////////
//////////////// Heart move tiles data /////////////////
////////////////////////////////////////////////////////

#define HEART_MAX_SIZES         8
#define HEART_SIZE              408
#define HEART_STOP_1            1
#define HEART_STOP_2            5
#define HEART_DELAY             1000

// Array with the amount of tiles to move in each cycle for Heart shape
static const uint8_t Heart_sizes[HEART_MAX_SIZES] = {17, 17, 17, 17, 85, 85, 85, 85};

// Array with the degrees at which tiles move in each cycle for Heart shape
static const uint8_t Heart_DegreePositions[HEART_MAX_SIZES] = {MAX_DEGREE, MIN_DEGREE, MID_DEGREE, MID_DEGREE, MAX_DEGREE, MIN_DEGREE, MID_DEGREE, MID_DEGREE};

// Array with the tiles to move for making Heart shape
static const uint8_t Heart[HEART_SIZE] = {
                                          94, 109, 80, 95, 81, 96, 111, 67, 82, 97, 83, 98, 113, 84, 99, 100, 115,                                // Move to MAX_DEGREE
                                          // Change cycle
                                          124, 139, 125, 140, 126, 141, 156, 127, 142, 157, 128, 143, 158, 129, 144, 130, 145,                    // Move to MIN_DEGREE
                                          // Change cycle
                                          94, 109, 80, 95, 81, 96, 111, 67, 82, 97, 83, 98, 113, 84, 99, 100, 115,                                // Move to MID_DEGREE
                                          // Change cycle
                                          124, 139, 125, 140, 126, 141, 156, 127, 142, 157, 128, 143, 158, 129, 144, 130, 145,                    // Move to MID_DEGREE
                                          // Change cycle
                                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,               // Move to MAX_DEGREE
                                            25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 
                                            48, 49, 50, 51, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 70, 71, 72, 73, 74, 75, 76, 
                                            77, 90, 91, 92, 105, 107, 87, 88, 89, 102, 103, 104, 117, 119, 
                                          // Change cycle
                                          120, 121, 122, 132, 133, 134, 135, 136, 137, 147, 148, 149, 150, 151, 152, 153, 161, 162, 163, 164,     // Move to MIN_DEGREE
                                            165, 166, 167, 168, 169, 170, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 
                                            188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 
                                            208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 227, 229, 
                                            231, 233, 235, 237, 239, 
                                          // Change cycle
                                          0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,               // Move to MID_DEGREE
                                            25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 
                                            48, 49, 50, 51, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 70, 71, 72, 73, 74, 75, 76, 
                                            77, 90, 91, 92, 105, 107, 87, 88, 89, 102, 103, 104, 117, 119, 
                                          // Change cycle
                                          120, 121, 122, 132, 133, 134, 135, 136, 137, 147, 148, 149, 150, 151, 152, 153, 161, 162, 163, 164,     // Move to MID_DEGREE
                                            165, 166, 167, 168, 169, 170, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 
                                            188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 
                                            208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 227, 229, 
                                            231, 233, 235, 237, 239
                                          };

///////////////////////////////////////////////////////
////////////// Greeting move tiles data ///////////////
///////////////////////////////////////////////////////

#define GREETING_MAX_SIZES          7
#define GREETING_DEGREES_SIZE       16
#define TILES_IN_QUADRANT           49
#define GREETING_SIZE               GREETING_DEGREES_SIZE * TILES_IN_QUADRANT
#define GREETING_DELAY              1100

// Array with the amount of tiles to move in each cycle for Greeting shape
static const uint8_t Greeting_sizes[GREETING_MAX_SIZES] = {49, 98, 147, 196, 147, 98, 49};

// Array with the degrees at which tiles move in each cycle for Greeting shape
static const uint8_t Greeting_DegreePositions[GREETING_DEGREES_SIZE] = {MAX_DEGREE, MID_DEGREE, MAX_DEGREE, MIN_DEGREE, MID_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, 
                                                                             MID_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MID_DEGREE, MID_DEGREE, MIN_DEGREE, MID_DEGREE};

// Array with the tiles to move for making Greeting shape. Each line holds the tiles to move in each cycle
static const uint8_t Greeting[GREETING_SIZE] = {
                                                0, 1, 2, 3, 4, 5, 6, 15, 16, 17, 18, 19, 20, 21, 30, 31, 32, 33, 34, 35, 36,              // Move to MAX_DEGREE
                                                  45, 46, 47, 48, 49, 50, 51, 60, 61, 62, 63, 64, 65, 66, 75, 76, 77, 78, 79, 80, 81, 
                                                  90, 91, 92, 93, 94, 95, 96,
                                                // Change cycle
                                                0, 1, 2, 3, 4, 5, 6, 15, 16, 17, 18, 19, 20, 21, 30, 31, 32, 33, 34, 35, 36,              // Move to MID_DEGREE
                                                  45, 46, 47, 48, 49, 50, 51, 60, 61, 62, 63, 64, 65, 66, 75, 76, 77, 78, 79, 80, 81, 
                                                  90, 91, 92, 93, 94, 95, 96,
                                                8, 9, 10, 11, 12, 13, 14, 23, 24, 25, 26, 27, 28, 29, 38, 39, 40, 41, 42, 43, 44,         // Move to MAX_DEGREE
                                                  53, 54, 55, 56, 57, 58, 59, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 
                                                  98, 99, 100, 101, 102, 103, 104,
                                                // Change cycle
                                                0, 1, 2, 3, 4, 5, 6, 15, 16, 17, 18, 19, 20, 21, 30, 31, 32, 33, 34, 35, 36,              // Move to MIN_DEGREE
                                                  45, 46, 47, 48, 49, 50, 51, 60, 61, 62, 63, 64, 65, 66, 75, 76, 77, 78, 79, 80, 81, 
                                                  90, 91, 92, 93, 94, 95, 96,
                                                8, 9, 10, 11, 12, 13, 14, 23, 24, 25, 26, 27, 28, 29, 38, 39, 40, 41, 42, 43, 44,         // Move to MID_DEGREE
                                                  53, 54, 55, 56, 57, 58, 59, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 
                                                  98, 99, 100, 101, 102, 103, 104,
                                                121, 123, 125, 135, 136, 137, 138, 139, 140, 141, 150, 151, 152,                          // Move to MAX_DEGREE
                                                  153, 154, 155, 156, 165, 166, 167, 168, 169, 170, 171, 180, 181, 182, 183, 184, 185, 
                                                  186, 195, 196, 197, 198, 199, 200, 201, 210, 211, 212, 213, 214, 215, 216, 225, 
                                                  227, 229, 231, 
                                                // Change cycle
                                                0, 1, 2, 3, 4, 5, 6, 15, 16, 17, 18, 19, 20, 21, 30, 31, 32, 33, 34, 35, 36,              // Move to MID_DEGREE
                                                  45, 46, 47, 48, 49, 50, 51, 60, 61, 62, 63, 64, 65, 66, 75, 76, 77, 78, 79, 80, 81, 
                                                  90, 91, 92, 93, 94, 95, 96,
                                                8, 9, 10, 11, 12, 13, 14, 23, 24, 25, 26, 27, 28, 29, 38, 39, 40, 41, 42, 43, 44,         // Move to MIN_DEGREE
                                                  53, 54, 55, 56, 57, 58, 59, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 
                                                  98, 99, 100, 101, 102, 103, 104,
                                                121, 123, 125, 135, 136, 137, 138, 139, 140, 141, 150, 151, 152,                          // Move to MID_DEGREE
                                                  153, 154, 155, 156, 165, 166, 167, 168, 169, 170, 171, 180, 181, 182, 183, 184, 185, 
                                                  186, 195, 196, 197, 198, 199, 200, 201, 210, 211, 212, 213, 214, 215, 216, 225, 
                                                  227, 229, 231, 
                                                129, 131, 133, 143, 144, 145, 146, 147, 148, 149, 158, 159,                               // Move to MAX_DEGREE
                                                  160, 161, 162, 163, 164, 173, 174, 175, 176, 177, 178, 179, 188, 189, 190, 191, 
                                                  192, 193, 194, 203, 204, 205, 206, 207, 208, 209, 218, 219, 220, 221, 222, 223, 
                                                  224, 233, 235, 237, 239,
                                                // Change cycle
                                                8, 9, 10, 11, 12, 13, 14, 23, 24, 25, 26, 27, 28, 29, 38, 39, 40, 41, 42, 43, 44,         // Move to MID_DEGREE
                                                  53, 54, 55, 56, 57, 58, 59, 68, 69, 70, 71, 72, 73, 74, 83, 84, 85, 86, 87, 88, 89, 
                                                  98, 99, 100, 101, 102, 103, 104,
                                                121, 123, 125, 135, 136, 137, 138, 139, 140, 141, 150, 151, 152,                          // Move to MIN_DEGREE
                                                  153, 154, 155, 156, 165, 166, 167, 168, 169, 170, 171, 180, 181, 182, 183, 184, 185, 
                                                  186, 195, 196, 197, 198, 199, 200, 201, 210, 211, 212, 213, 214, 215, 216, 225, 
                                                  227, 229, 231, 
                                                129, 131, 133, 143, 144, 145, 146, 147, 148, 149, 158, 159,                               // Move to MID_DEGREE
                                                  160, 161, 162, 163, 164, 173, 174, 175, 176, 177, 178, 179, 188, 189, 190, 191, 
                                                  192, 193, 194, 203, 204, 205, 206, 207, 208, 209, 218, 219, 220, 221, 222, 223, 
                                                  224, 233, 235, 237, 239,
                                                // Change cycle
                                                121, 123, 125, 135, 136, 137, 138, 139, 140, 141, 150, 151, 152,                          // Move to MID_DEGREE
                                                  153, 154, 155, 156, 165, 166, 167, 168, 169, 170, 171, 180, 181, 182, 183, 184, 185, 
                                                  186, 195, 196, 197, 198, 199, 200, 201, 210, 211, 212, 213, 214, 215, 216, 225, 
                                                  227, 229, 231, 
                                                129, 131, 133, 143, 144, 145, 146, 147, 148, 149, 158, 159,                               // Move to MIN_DEGREE
                                                  160, 161, 162, 163, 164, 173, 174, 175, 176, 177, 178, 179, 188, 189, 190, 191, 
                                                  192, 193, 194, 203, 204, 205, 206, 207, 208, 209, 218, 219, 220, 221, 222, 223, 
                                                  224, 233, 235, 237, 239,
                                                // Change cycle
                                                129, 131, 133, 143, 144, 145, 146, 147, 148, 149, 158, 159,                               // Move to MID_DEGREE
                                                  160, 161, 162, 163, 164, 173, 174, 175, 176, 177, 178, 179, 188, 189, 190, 191, 
                                                  192, 193, 194, 203, 204, 205, 206, 207, 208, 209, 218, 219, 220, 221, 222, 223, 
                                                  224, 233, 235, 237, 239
                                                };

///////////////////////////////////////////////////////
//////////////// Rock move tiles data /////////////////
///////////////////////////////////////////////////////

#define ROCK_DEGREES_SIZE       31
#define UNEVEN_STRINGS          3
#define EVEN_STRINGS            2
#define ROCK_TILES_PER_STRING   23
#define ROCK_DELAY              100

// Array with the degrees at which tiles move in each cycle for Rock shape
static const uint8_t RockUnevenString_DegreePositions[ROCK_DEGREES_SIZE] = {120, 116, 104, 89, 74, 64, 60, 64, 74, 87, 99, 108, 112, 109, 101, 90, 79, 71, 68, 70, 76, 86, 95, 102, 105, 104, 99, 97, 95, 93, MID_DEGREE};
static const uint8_t RockEvenString_DegreePositions[ROCK_DEGREES_SIZE] = {60, 65, 77, 92, 107, 117, 120, 117, 107, 94, 82, 73, 69, 72, 80, 91, 102, 110, 113, 111, 105, 95, 86, 79, 76, 77, 82, 84, 86, 88, MID_DEGREE};

// Array with the tiles to move for making Rock shape
static const uint8_t Rock[ROCK_TILES_PER_STRING*(UNEVEN_STRINGS+EVEN_STRINGS)] = {
                                                                                  15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 32, 34, 36, 38, 40, 42, 44,                         // Uneven string
                                                                                  105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 122, 124, 126, 128, 130, 132, 134,  // Even string
                                                                                  195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 212, 214, 216, 218, 220, 222, 224,  // Uneven string
                                                                                  60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 77, 79, 81, 83, 85, 87, 89,                         // Even string
                                                                                  150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 167, 169, 171, 173, 175, 177, 179   // Uneven string
                                                                                  };


////////////////////////////////////////////////////////
//////////////// Sleep move tiles data /////////////////
////////////////////////////////////////////////////////

#define SLEEP_DEGREE_STEP       1
#define SLEEP_DELAY             20


/////////////////////////////////////////////////////
////////////// Zigzag move tiles data ///////////////
/////////////////////////////////////////////////////

#define ZIGZAG_DEGREES_SIZE       20
#define ZIGZAG_SIZE               160
#define ZIGZAG_DELAY              80
#define ZIGZAG_POST_DELAY         1000

// Array with the degrees at which tiles move. Every degree is used in every cycle
static const uint8_t Zigzag_DegreePositions[ZIGZAG_DEGREES_SIZE] = {MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, 
                                                                    MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE};

// Array with the tiles to move for making Zigzag shape
static const uint8_t Zigzag[ZIGZAG_SIZE] = {
                                            0, 0, 0, 15, 1, 17, 3, 19, 5, 21, 7, 23, 9, 25, 11, 27, 13, 29, 29, 29, 
                                            // Change cycle
                                            44, 44, 44, 59, 43, 57, 41, 55, 39, 53, 37, 51, 35, 49, 33, 47, 31, 45, 45, 45, 
                                            // Change cycle
                                            60, 60, 60, 75, 61, 77, 63, 79, 65, 81, 67, 83, 69, 85, 71, 87, 73, 89, 89, 89, 
                                            // Change cycle
                                            104, 104, 104, 119, 103, 117, 101, 115, 99, 113, 97, 111, 95, 109, 93, 107, 91, 105, 105, 105, 
                                            // Change cycle
                                            120, 120, 120, 135, 121, 137, 123, 139, 125, 141, 127, 143, 129, 145, 131, 147, 133, 149, 149, 149, 
                                            // Change cycle
                                            164, 164, 164, 179, 163, 177, 161, 175, 159, 173, 157, 171, 155, 169, 153, 167, 151, 165, 165, 165, 
                                            // Change cycle
                                            180, 180, 180, 195, 181, 197, 183, 199, 185, 201, 187, 203, 189, 205, 191, 207, 193, 209, 209, 209, 
                                            // Change cycle
                                            224, 224, 224, 239, 223, 237, 221, 235, 219, 233, 217, 231, 215, 229, 213, 227, 211, 225, 225, 225,
                                            };


//////////////////////////////////////////////////
///////////// Forks move tiles data //////////////
//////////////////////////////////////////////////

#define FORKS_MAX_SIZES    4
#define FORKS_SIZE         69
#define FORKS_DEGREE       MAX_DEGREE
#define FORKS_DELAY        200
#define FORKS_POST_DELAY   1000


// Array with the amount of tiles to move in each cycle for Forks shape
static const uint8_t Forks_sizes[FORKS_MAX_SIZES] = {3, 7, 5, 4};

// Array with the number of tiles to move at a time in each cycle for Forks shape
static const uint8_t Forks_sizes_ensync[FORKS_MAX_SIZES] = {1, 2, 4, 8};

// Array with the tiles to move for making Forks shape. Each line holds the tiles to move in each cycle
static const uint8_t Forks[FORKS_SIZE] = {
                                        7, 22, 37,
                                        // Change cycle
                                        51, 53, 50, 54, 64, 70, 63, 71, 78, 86, 93, 101, 108, 116, 
                                        // Change cycle
                                        122, 124, 130, 132, 121, 125, 129, 133, 136, 140, 144, 148, 151, 155, 159, 163, 166, 170, 174, 178, 
                                        // Change cycle
                                        180, 182, 184, 186, 188, 190, 192, 194, 195, 197, 199, 201, 203, 205, 207, 209, 210, 212, 214, 216, 218, 220, 222, 224, 225, 227, 229, 231, 233, 235, 237, 239
                                        };


/////////////////////////////////////////////////////
////////////// Inverse move tiles data ///////////////
/////////////////////////////////////////////////////

#define INVERSE_MAX_SIZES         14
#define INVERSE_SIZE              140
#define INVERSE_DELAY             500
#define INVERSE_POST_DELAY        1000

// Array with the amount of tiles to move in each cycle for Inverse shape
static const uint8_t Inverse_sizes_forward[INVERSE_MAX_SIZES] = {16, 16, 14, 14, 12, 12, 10, 10, 8, 8, 6, 6, 4, 4};
static const uint8_t Inverse_sizes_backward[INVERSE_MAX_SIZES] = {4, 4, 6, 6, 8, 8, 10, 10, 12, 12, 14, 14, 16, 16};

// Array with the degrees at which tiles move in each cycle for Inverse shape
static const uint8_t Inverse_DegreePositions[INVERSE_MAX_SIZES] = {MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, 
                                                                 MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE, MIN_DEGREE, MAX_DEGREE};

// Array with the tiles to move for making Inverse shape. Each line holds the tiles to move in each cycle
static const uint8_t Inverse[INVERSE_SIZE] = {
                                            0, 15, 30, 45, 60, 75, 90, 105, 134, 149, 164, 179, 194, 209, 224, 239,           // Move to MIN_DEGREE
                                            // Change cycle
                                            14, 29, 44, 59, 74, 89, 104, 119, 120, 135, 150, 165, 180, 195, 210, 225,         // Move to MAX_DEGREE
                                            // Change cycle
                                            1, 16, 31, 46, 61, 76, 91, 133, 148, 163, 178, 193, 208, 223,                     // Move to MIN_DEGREE
                                            // Change cycle
                                            13, 28, 43, 58, 73, 88, 103, 121, 136, 151, 166, 181, 196, 211,                   // Move to MAX_DEGREE
                                            // Change cycle
                                            17, 32, 47, 62, 77, 92, 147, 162, 177, 192, 207, 222,                             // Move to MIN_DEGREE
                                            // Change cycle
                                            27, 42, 57, 72, 87, 102, 137, 152, 167, 182, 197, 212,                            // Move to MAX_DEGREE
                                            // Change cycle
                                            18, 33, 48, 63, 78, 146, 161, 176, 191, 206,                                      // Move to MIN_DEGREE
                                            // Change cycle
                                            26, 41, 56, 71, 86, 138, 153, 168, 183, 198,                                      // Move to MAX_DEGREE
                                            // Change cycle
                                            34, 49, 64, 79, 160, 175, 190, 205,                                               // Move to MIN_DEGREE
                                            // Change cycle
                                            40, 55, 70, 85, 154, 169, 184, 199,                                               // Move to MAX_DEGREE
                                            // Change cycle
                                            35, 50, 65, 159, 174, 189,                                                        // Move to MIN_DEGREE
                                            // Change cycle
                                            39, 54, 69, 155, 170, 185,                                                        // Move to MAX_DEGREE
                                            // Change cycle
                                            51, 66, 173, 188,                                                                 // Move to MIN_DEGREE
                                            // Change cycle
                                            53, 68, 171, 186,                                                                 // Move to MAX_DEGREE
                                            };


//////////////////////////////////////////////////////////
////////////// Boom move tiles data ///////////////
//////////////////////////////////////////////////////////

#define BOOM_LAUNCH_SIZE      22
#define BOOM_MAX_SIZES        6
#define BOOM_BLAST_SIZE       72
#define BOOM_LAUNCH_DELAY     200
#define BOOM_BLAST_DELAY      150
#define BOOM_POST_DELAY       800
#define BOOM_BURNOUT_DELAY    500

// Array with the degrees at which tiles move for Boom shape's launch phase
static const uint8_t Boom_Launch_DegreePositions[BOOM_LAUNCH_SIZE] = {
                                                                       MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, 
                                                                       MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE, MAX_DEGREE, MID_DEGREE, MIN_DEGREE
                                                                       };

// Array with the tiles to move for making Boom shape's launch phase
static const uint8_t Boom_Launch[BOOM_LAUNCH_SIZE] = {
                                                       217, 202, 217, 202, 187, 202, 187, 172, 187, 172, 157, 172, 157, 142, 157, 142, 127, 142, 127, 112, 127, 112
                                                       };

// Array with the amount of tiles to move in each cycle for Boom shape's blast phase
static const uint8_t Boom_Blast_sizes[BOOM_MAX_SIZES] = {6, 6, 18, 18, 18, 6};

// Array with the tiles to move for making Boom shape's blast phase. Each line holds the tiles to move in each cycle
static const uint8_t Boom_Blast[BOOM_BLAST_SIZE] = {
                                                     126, 111, 127, 97, 128, 113,                                                           // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     // Change cycle
                                                     125, 95, 142, 82, 129, 99,                                                             // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     // Change cycle
                                                     124, 109, 139, 94, 140, 80, 156, 81, 157, 67, 158, 83, 144, 84, 145, 100, 130, 115,    // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     // Change cycle
                                                     123, 93, 138, 78, 154, 79, 171, 66, 172, 52, 173, 68, 160, 85, 146, 86, 131, 101,      // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     // Change cycle
                                                     137, 92, 152, 77, 153, 63, 186, 51, 187, 37, 188, 53, 161, 71, 162, 87, 147, 102,      // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     // Change cycle
                                                     151, 61, 202, 22, 163, 73                                                              // Move MIN_DEGREE then MAX_DEGREE then MIN_DEGREE...
                                                     };


/////////////////////////////////////////////////////
////////////// Spiral move tiles data ///////////////
/////////////////////////////////////////////////////

#define OUTER_SPIRAL_SIZE               32
#define SPIRAL_SIZE                     84
#define SPIRAL_TOP_CORNERS_DEGREE       MAX_DEGREE
#define SPIRAL_BOTTOM_CORNERS_DEGREE    MIN_DEGREE
#define SPIRAL_TOP_DEGREE               MAX_DEGREE
#define SPIRAL_BOTTOM_DEGREE            MIN_DEGREE
#define SPIRAL_FORWARD_DELAY            90
#define SPIRAL_RETURN_DELAY             1500
#define SPIRAL_BACKWARD_DELAY           60

// Array with the tiles to move outer corners in Spiral shape (top)
static const uint8_t Spiral_OuterTop[OUTER_SPIRAL_SIZE] = {
                                                          0, 15, 30, 45, 1, 16, 31, 2, 17, 32, 3, 18, 4, 19, 5, 6,
                                                          14, 29, 44, 59, 13, 28, 43, 12, 27, 42, 11, 26, 10, 25, 9, 8
                                                          };

// Array with the tiles to move outer corners in Spiral shape (bottom)
static const uint8_t Spiral_OuterBottom[OUTER_SPIRAL_SIZE] = {
                                                             225, 210, 195, 180, 181, 196, 211, 227, 212, 197, 198, 213, 229, 214, 215, 231, 
                                                             239, 224, 209, 194, 193, 208, 223, 237, 222, 207, 206, 221, 235, 220, 219, 233
                                                             };

// Array with the tiles to move for making Spiral shape (top)
static const uint8_t Spiral_Top[SPIRAL_SIZE] = {
                                               7, 21, 20, 34, 33, 47, 46, 60, 75, 90, 105, 120, 135, 150, 165, 166, 182, 183, 199, 200, 216, 202, 203, 189, 190, 176, 177, 163, 148, 133, 118, 103, 88, 73, 
                                               72, 56, 55, 39, 38, 37, 51, 50, 64, 63, 77, 92, 107, 122, 137, 152, 153, 169, 170, 186, 172, 173, 159, 160, 146, 131, 116, 101, 86, 85, 69, 68, 67, 81, 80, 
                                               94, 109, 124, 139, 140, 156, 142, 143, 129, 114, 99, 98, 97, 111, 126
                                               };

// Array with the tiles to move for making Spiral shape (bottom)
static const uint8_t Spiral_Bottom[SPIRAL_SIZE] = {
                                                  217, 218, 204, 205, 191, 192, 178, 179, 164, 149, 134, 119, 104, 89, 74, 58, 57, 41, 40, 24, 23, 22, 36, 35, 49, 48, 62, 61, 76, 91, 106, 121, 136, 151, 167, 
                                                  168, 184, 185, 201, 187, 188, 174, 175, 161, 162, 147, 132, 117, 102, 87, 71, 70, 54, 53, 52, 66, 65, 79, 78, 93, 108, 123, 138, 154, 155, 171, 157, 158, 
                                                  144, 145, 130, 115, 100, 84, 83, 82, 96, 95, 110, 125, 141, 127, 128, 113
                                                  };


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void AnimationExecute(animations_t animation);
void Expansion_Shape();
void Heart_Shape();
void Greeting_Shape();
void Rock_Shape();
void Sleep_Shape();
void Zigzag_Shape();
void Forks_Shape();
void Inverse_Shape();
void Boom_Shape();
void Spiral_Shape();


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void AnimationExecute(animations_t animation)
{
  if(expansion == animation)
    Expansion_Shape();
  else if(heart == animation)
    Heart_Shape();
  else if(greeting == animation)
    Greeting_Shape();
  else if(rock == animation)
    Rock_Shape();
  else if(sleepy == animation)
    Sleep_Shape();
  else if(zigzag == animation)
    Zigzag_Shape();
  else if(forks == animation)
    Forks_Shape();
  else if(inverse == animation)
    Inverse_Shape();
  else if(boom == animation)
    Boom_Shape();
  else if(spiral == animation)
    Spiral_Shape();
  else
    ;
}

void Expansion_Shape()
{
  static uint16_t sizes_index = 0;
  static uint16_t i = 0;
  static uint16_t move_tile_index = 0;
  static uint16_t reset_tile_index = 0;
  
  move_tile_index = 0;
  reset_tile_index = 0;

  for(sizes_index = 0; sizes_index < EXPANSION_MAX_SIZES; sizes_index++)
  {
    for(i = 0; i < Expansion_sizes[sizes_index]; i++)
    {
      if(i < (Expansion_sizes[sizes_index] / 2))
      { // Move the first half of the tiles in this cycle up
        PCA_ServoMove(g_art[Expansion[move_tile_index]].tile.tile_id, g_art[Expansion[move_tile_index]].tile.driver, g_art[Expansion[move_tile_index]].tile.channel, EXPANSION_UP_DEGREE);
      }
      else
      { // Move the second half of the tiles in this cycle down
        PCA_ServoMove(g_art[Expansion[move_tile_index]].tile.tile_id, g_art[Expansion[move_tile_index]].tile.driver, g_art[Expansion[move_tile_index]].tile.channel, EXPANSION_DOWN_DEGREE);
      }

      move_tile_index++;      // Change tile to be moved
    }

    delay(EXPANSION_DELAY);

    for(i = 0; i < Expansion_sizes[sizes_index]; i++)
    { // Return moved tiles to default position before starting next cycle
      PCA_ServoMove(g_art[Expansion[move_tile_index]].tile.tile_id, g_art[Expansion[reset_tile_index]].tile.driver, g_art[Expansion[reset_tile_index]].tile.channel, MID_DEGREE);
      reset_tile_index++;     // Change tile to be moved
    }
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Heart_Shape()
{
  static uint16_t sizes_index = 0;
  static uint16_t i = 0;
  static uint16_t move_tile_index = 0;

  move_tile_index = 0;
  
  for(sizes_index = 0; sizes_index < HEART_MAX_SIZES; sizes_index++)
  {
    for(i = 0; i < Heart_sizes[sizes_index]; i++)
    {
      PCA_ServoMove(g_art[Heart[move_tile_index]].tile.tile_id, g_art[Heart[move_tile_index]].tile.driver, g_art[Heart[move_tile_index]].tile.channel, Heart_DegreePositions[sizes_index]);
      move_tile_index++;      // Change tile to be moved
      delay(1);
    }

    if((HEART_STOP_1 == sizes_index) || (HEART_STOP_2 == sizes_index))
    { // Delay after second and fifth cycles
      delay(HEART_DELAY);
    }
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Greeting_Shape()
{
  static uint16_t sizes_index = 0;
  static uint16_t i = 0;
  static uint16_t move_tile_index = 0;
  static uint16_t degree_index = 0;

  degree_index = 0;
  move_tile_index = 0;
  
  for(sizes_index = 0; sizes_index < GREETING_MAX_SIZES; sizes_index++)
  {
    for(i = 0; i < Greeting_sizes[sizes_index]; i++)
    {
      PCA_ServoMove(g_art[Greeting[move_tile_index]].tile.tile_id, g_art[Greeting[move_tile_index]].tile.driver, g_art[Greeting[move_tile_index]].tile.channel, Greeting_DegreePositions[degree_index]);
      move_tile_index++;      // Change tile to be moved
      degree_index = (0 == ((i+1) % TILES_IN_QUADRANT)) ? degree_index+1 : degree_index;      // Continue to next degree position when all tiles of 
      delay(1);                                                                               // the quadrant have been moved 
    }
    
    delay(GREETING_DELAY);
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Rock_Shape()
{
  static uint16_t degree_index = 0;
  static uint16_t unevenstring_tile = 0;
  static uint16_t evenstring_tile = 0;
  
  for(degree_index = 0; degree_index < ROCK_DEGREES_SIZE; degree_index++)
  {
    for(unevenstring_tile = 0; unevenstring_tile < ROCK_TILES_PER_STRING*(UNEVEN_STRINGS); unevenstring_tile++)
    { // Move Uneven strings
      PCA_ServoMove(g_art[Rock[unevenstring_tile]].tile.tile_id, g_art[Rock[unevenstring_tile]].tile.driver, g_art[Rock[unevenstring_tile]].tile.channel, RockUnevenString_DegreePositions[degree_index]);
    }
    for(evenstring_tile = unevenstring_tile; evenstring_tile < ROCK_TILES_PER_STRING*(UNEVEN_STRINGS+EVEN_STRINGS); evenstring_tile++)
    { // Move Even strings
      PCA_ServoMove(g_art[Rock[evenstring_tile]].tile.tile_id, g_art[Rock[evenstring_tile]].tile.driver, g_art[Rock[evenstring_tile]].tile.channel, RockEvenString_DegreePositions[degree_index]);
    }
    
    delay(ROCK_DELAY);
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Sleep_Shape()
{
  static uint16_t degree = MIN_DEGREE;
  static uint16_t move_tile_index = 0;
  static bool upwards_move = false;

  if(upwards_move)
  { // If we are moving up
    for(degree = MAX_DEGREE; degree <= MID_DEGREE; degree += SLEEP_DEGREE_STEP)
    { // Going from MIN_DEGREE to MID_DEGREE, down -> up
      for(move_tile_index = 0; move_tile_index < TILES_PER_ESP; move_tile_index++)
      { // Move all tiles in quadrant
        PCA_ServoMove(g_art_quadrant[move_tile_index].tile.tile_id, g_art_quadrant[move_tile_index].tile.driver, g_art_quadrant[move_tile_index].tile.channel, degree);
        delay(1);
      }
      delay(SLEEP_DELAY);
    }

    upwards_move = false;   // Now that we are up, next time move down
  }
  else
  {
    for(degree = MID_DEGREE; degree >= MAX_DEGREE; degree -= SLEEP_DEGREE_STEP)
    { // Going from MID DEGREE to MIN_DEGREE, up -> down
      for(move_tile_index = 0; move_tile_index < TILES_PER_ESP; move_tile_index++)
      { // Move all tiles in quadrant
        PCA_ServoMove(g_art_quadrant[move_tile_index].tile.tile_id, g_art_quadrant[move_tile_index].tile.driver, g_art_quadrant[move_tile_index].tile.channel, degree);
        delay(1);
      }
      delay(SLEEP_DELAY);
    }

    upwards_move = true;   // Now that we are down, next time move up
  }
}


void Zigzag_Shape()
{
  static uint16_t move_tile_index = 0;
  static uint16_t degree_index = 0;

  degree_index = 0;

  for(move_tile_index = 0; move_tile_index < ZIGZAG_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Zigzag[move_tile_index]].tile.tile_id, g_art[Zigzag[move_tile_index]].tile.driver, g_art[Zigzag[move_tile_index]].tile.channel, Zigzag_DegreePositions[degree_index]);
    degree_index = (degree_index >= ZIGZAG_DEGREES_SIZE-1) ? 0 : degree_index+1;  // When we have used every degree, start from the beginning
    delay(ZIGZAG_DELAY);
  }

  delay(ZIGZAG_POST_DELAY);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Forks_Shape()
{
  static uint16_t sizes_index = 0;
  static uint8_t i = 0;
  static uint8_t j = 0;
  static uint16_t move_tile_index = 0;

  move_tile_index = 0;

  for(sizes_index = 0; sizes_index < FORKS_MAX_SIZES; sizes_index++)
  {
    for(i = 0; i < Forks_sizes[sizes_index]; i++)
    {
      for(j = 0; j < Forks_sizes_ensync[sizes_index]; j++)
      {
        PCA_ServoMove(g_art[Forks[move_tile_index]].tile.tile_id, g_art[Forks[move_tile_index]].tile.driver, g_art[Forks[move_tile_index]].tile.channel, FORKS_DEGREE);
        move_tile_index++;
      }

      delay(FORKS_DELAY);
    }
  }

  delay(FORKS_POST_DELAY);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Inverse_Shape()
{
  static uint16_t sizes_index = 0;
  static uint16_t i = 0;
  static uint16_t move_tile_index = 0;

  move_tile_index = 0;              // Start from the beginning
  
  for(sizes_index = 0; sizes_index < INVERSE_MAX_SIZES; sizes_index++)
  {
    if(0 == (sizes_index % 2))
    { // Delay every even cycle
      delay(INVERSE_DELAY);
    }
    for(i = 0; i < Inverse_sizes_forward[sizes_index]; i++)
    { // Move to degree in forward phase
      PCA_ServoMove(g_art[Inverse[move_tile_index]].tile.tile_id, g_art[Inverse[move_tile_index]].tile.driver, g_art[Inverse[move_tile_index]].tile.channel, Inverse_DegreePositions[sizes_index]);
      move_tile_index++;
    }
  }

  move_tile_index = INVERSE_SIZE-1;  // Start from the end

  for(sizes_index = 0; sizes_index < INVERSE_MAX_SIZES; sizes_index++)
  {
    if(0 == (sizes_index % 2))
    { // Delay every even cycle
      delay(INVERSE_DELAY);
    }
    for(i = 0; i < Inverse_sizes_backward[sizes_index]; i++)
    { // Move to degree in backward phase
      PCA_ServoMove(g_art[Inverse[move_tile_index]].tile.tile_id, g_art[Inverse[move_tile_index]].tile.driver, g_art[Inverse[move_tile_index]].tile.channel, Inverse_DegreePositions[sizes_index]);
      move_tile_index--;
    }
  }

  delay(INVERSE_POST_DELAY);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Boom_Shape()
{
  static uint16_t sizes_index = 0;
  static uint16_t i = 0;
  static uint16_t move_tile_index = 0;
  
  for(move_tile_index = 0; move_tile_index < BOOM_LAUNCH_SIZE; move_tile_index++)
  { // Execute launch phase
    if(MID_DEGREE == Boom_Launch_DegreePositions[move_tile_index])
    { // If the next tile will be moved to MID_DEGREE, wait a moment
      delay(BOOM_LAUNCH_DELAY);
    }
    PCA_ServoMove(g_art[Boom_Launch[move_tile_index]].tile.tile_id, g_art[Boom_Launch[move_tile_index]].tile.driver, g_art[Boom_Launch[move_tile_index]].tile.channel, Boom_Launch_DegreePositions[move_tile_index]);
  }

  move_tile_index = 0;

  for(sizes_index = 0; sizes_index < BOOM_MAX_SIZES; sizes_index++)
  { // Execute blast phase
    for(i = 0; i < Boom_Blast_sizes[sizes_index]; i++)
    {
      if(0 == (move_tile_index % 2))
      { // Alternate moving tiles between MIN_DEGREE and MAX_DEGREE
        PCA_ServoMove(g_art[Boom_Blast[move_tile_index]].tile.tile_id, g_art[Boom_Blast[move_tile_index]].tile.driver, g_art[Boom_Blast[move_tile_index]].tile.channel, MAX_DEGREE);
      }
      else
      {
        PCA_ServoMove(g_art[Boom_Blast[move_tile_index]].tile.tile_id, g_art[Boom_Blast[move_tile_index]].tile.driver, g_art[Boom_Blast[move_tile_index]].tile.channel, MIN_DEGREE);
      }
      move_tile_index++;
    }
    delay(BOOM_BLAST_DELAY);
  }

  move_tile_index = 0;
  delay(BOOM_POST_DELAY);

  for(sizes_index = 0; sizes_index < BOOM_MAX_SIZES; sizes_index++)
  { // Return blast phase tiles to MID_DEGREE
    for(i = 0; i < Boom_Blast_sizes[sizes_index]; i++)
    {
      PCA_ServoMove(g_art[Boom_Blast[move_tile_index]].tile.tile_id, g_art[Boom_Blast[move_tile_index]].tile.driver, g_art[Boom_Blast[move_tile_index]].tile.channel, MID_DEGREE);
      move_tile_index++;
    }
    delay(BOOM_BURNOUT_DELAY);
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}


void Spiral_Shape()
{
  static int16_t move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < OUTER_SPIRAL_SIZE; move_tile_index++)
  { // Move the tiles of the corners of the spiral
    PCA_ServoMove(g_art[Spiral_OuterTop[move_tile_index]].tile.tile_id, g_art[Spiral_OuterTop[move_tile_index]].tile.driver, g_art[Spiral_OuterTop[move_tile_index]].tile.channel, SPIRAL_TOP_CORNERS_DEGREE);
    PCA_ServoMove(g_art[Spiral_OuterBottom[move_tile_index]].tile.tile_id, g_art[Spiral_OuterBottom[move_tile_index]].tile.driver, g_art[Spiral_OuterBottom[move_tile_index]].tile.channel, SPIRAL_BOTTOM_CORNERS_DEGREE);
  }

  for(move_tile_index = 0; move_tile_index < SPIRAL_SIZE; move_tile_index++)
  { // Move the tiles of the spiral in forwards order
    PCA_ServoMove(g_art[Spiral_Top[move_tile_index]].tile.tile_id, g_art[Spiral_Top[move_tile_index]].tile.driver, g_art[Spiral_Top[move_tile_index]].tile.channel, SPIRAL_TOP_DEGREE);
    PCA_ServoMove(g_art[Spiral_Bottom[move_tile_index]].tile.tile_id, g_art[Spiral_Bottom[move_tile_index]].tile.driver, g_art[Spiral_Bottom[move_tile_index]].tile.channel, SPIRAL_BOTTOM_DEGREE);
    delay(SPIRAL_FORWARD_DELAY);
  }

  delay(SPIRAL_RETURN_DELAY);

  for(move_tile_index = SPIRAL_SIZE-1; move_tile_index >= 0; move_tile_index--)
  { // Reset the tiles of the spiral in backwards order
    PCA_ServoMove(g_art[Spiral_Top[move_tile_index]].tile.tile_id, g_art[Spiral_Top[move_tile_index]].tile.driver, g_art[Spiral_Top[move_tile_index]].tile.channel, MID_DEGREE);
    PCA_ServoMove(g_art[Spiral_Bottom[move_tile_index]].tile.tile_id, g_art[Spiral_Bottom[move_tile_index]].tile.driver, g_art[Spiral_Bottom[move_tile_index]].tile.channel, MID_DEGREE);
    delay(SPIRAL_BACKWARD_DELAY);
  }

  for(move_tile_index = 0; move_tile_index < OUTER_SPIRAL_SIZE; move_tile_index++)
  { // Reset the tiles of the corners of the spiral
    PCA_ServoMove(g_art[Spiral_OuterTop[move_tile_index]].tile.tile_id, g_art[Spiral_OuterTop[move_tile_index]].tile.driver, g_art[Spiral_OuterTop[move_tile_index]].tile.channel, MID_DEGREE);
    PCA_ServoMove(g_art[Spiral_OuterBottom[move_tile_index]].tile.tile_id, g_art[Spiral_OuterBottom[move_tile_index]].tile.driver, g_art[Spiral_OuterBottom[move_tile_index]].tile.channel, MID_DEGREE);
  }

  ResetTiles();               // Make every tile return to MID_DEGREE
}

#endif
