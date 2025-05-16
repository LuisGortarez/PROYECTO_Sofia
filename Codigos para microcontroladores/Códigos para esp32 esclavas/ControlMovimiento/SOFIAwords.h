/*
  Name:		  SOFIAwords.h
  Created:	13/03/2025 11:29:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de figuras palabra 
            Cada figura palabra tiene un arreglo con los identificadores 
            de servomotores que se deben mover para crear la figura.
            Las funciones utilizan un ciclo 'for' para realizar los 
            movimientos de todo el contenido de los arreglos.
*/

#ifndef SOFIAwords_H
#define SOFIAwords_H

#include "SOFIAdatatypes.h"

// For identifying number to execute
typedef enum
{
  yes,
  no,
  iteso,
  sofia,
} words_t;


///////////////////////////////////////////////////////
////////////// Word yes move tiles data ///////////////
///////////////////////////////////////////////////////

#define WORD_YES_SIZE             98

// Array with the tiles to move for making Word yes
static const uint8_t Word_yes[WORD_YES_SIZE] = {
                                                 // Letter S
                                                 20, 34, 36, 33, 37, 47, 53, 35, 49, 51, 48, 52, 62, 68, 50, 64, 66, 63, 67, 77, 83, 
                                                 78, 92, 107, 94, 93, 108, 95, 109, 124, 111, 110, 125, 112, 126, 141, 128, 127, 
                                                 142, 143, 170, 169, 171, 153, 157, 152, 158, 185, 184, 186, 168, 172, 167, 173, 
                                                 200, 199, 201, 183, 187, 182, 188, 
                                                 // Letter I
                                                 26, 40, 42, 41, 55, 57, 56, 70, 72, 71, 85, 87, 86, 100, 102, 101, 115, 117, 116, 
                                                 130, 132, 131, 145, 147, 146, 160, 162, 161, 175, 177, 176, 190, 192, 191, 205, 
                                                 207, 206
                                                 };

//////////////////////////////////////////////////////
////////////// Word no move tiles data ///////////////
//////////////////////////////////////////////////////

#define WORD_NO_SIZE              102

// Array with the tiles to move for making Word no
static const uint8_t Word_no[WORD_NO_SIZE] = {
                                               // Letter N
                                               45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 181, 166, 151, 136, 121, 106, 91, 
                                               76, 61, 46, 77, 92, 107, 93, 108, 123, 138, 139, 154, 169, 185, 170, 155, 140, 125, 
                                               110, 95, 80, 65, 50, 51, 66, 81, 96, 111, 126, 141, 156, 171, 186, 201, 41, 
                                               // Letter O
                                               55, 57, 54, 58, 68, 74, 56, 70, 72, 69, 73, 83, 89, 98, 84, 88, 104, 99, 113, 103, 
                                               119, 114, 128, 118, 134, 129, 143, 133, 149, 144, 158, 148, 164, 159, 173, 163, 
                                               179, 174, 188, 178, 194, 190, 189, 192, 193, 191, 205, 207, 206
                                               };

/////////////////////////////////////////////////////////
////////////// Word iteso move tiles data ///////////////
/////////////////////////////////////////////////////////

#define WORD_ITESO_SIZE           119

// Array with the tiles to move for making Word iteso
static const uint8_t Word_iteso[WORD_ITESO_SIZE] = {
                                                     // Letter I
                                                     0, 1, 15, 16, 30, 31, 45, 46, 60, 61, 75, 76, 90, 91, 
                                                     // Letter T
                                                     3, 18, 8, 23, 4, 19, 7, 22, 5, 6, 20, 21, 35, 36, 50, 51, 65, 66, 80, 81, 96, 
                                                     // Letter E
                                                     10, 12, 14, 25, 11, 27, 13, 29, 40, 26, 55, 41, 57, 43, 70, 56, 58, 85, 71, 100, 86, 
                                                     87, 102, 88, 89, 104, 
                                                     // Letter S
                                                     124, 123, 125, 137, 141, 139, 138, 140, 152, 156, 167, 153, 168, 169, 184, 170, 185, 186, 
                                                     214, 198, 200, 197, 201, 229, 213, 215, 212, 216, 
                                                     // Letter O
                                                     130, 129, 131, 143, 147, 145, 144, 146, 158, 162, 159, 161, 173, 177, 174, 176, 188, 192, 
                                                     189, 191, 203, 207, 204, 206, 220, 235, 219, 221, 218, 222
                                                    };

/////////////////////////////////////////////////////////
////////////// Word sofia move tiles data ///////////////
/////////////////////////////////////////////////////////

#define WORD_SOFIA_SIZE           133

// Array with the tiles to move for making Word sofia
static const uint8_t Word_sofia[WORD_SOFIA_SIZE] = {
                                                     // Letter S
                                                     4, 3, 5, 17, 21, 19, 18, 20, 32, 36, 47, 33, 48, 49, 64, 50, 65, 66, 94, 78, 80, 
                                                     77, 81, 109, 93, 95, 92, 96, 
                                                     // Letter O
                                                     10, 9, 11, 23, 27, 25, 24, 26, 38, 42, 39, 41, 53, 57, 54, 56, 68, 72, 69, 71, 
                                                     83, 87, 100, 84, 86, 115, 99, 101, 98, 102, 
                                                     // Letter F
                                                     135, 150, 165, 180, 195, 210, 225, 121, 136, 151, 166, 181, 196, 211, 137, 123, 
                                                     139, 152, 138, 154, 182, 168, 183, 
                                                     // Letter I
                                                     141, 127, 143, 156, 142, 158, 171, 157, 173, 186, 172, 188, 201, 187, 203, 202, 
                                                     216, 218, 217, 231, 233, 
                                                     // Letter A
                                                     132, 131, 133, 145, 149, 147, 146, 148, 160, 164, 161, 163, 175, 179, 176, 190, 
                                                     178, 194, 192, 191, 193, 205, 209, 206, 208, 220, 224, 221, 223, 235, 239
                                                     };

///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void WordExecute(words_t word, uint16_t delay_in_ms, uint8_t degree);
void Word_yes_Shape(uint16_t delay_in_ms, uint8_t degree);
void Word_no_Shape(uint16_t delay_in_ms, uint8_t degree);
void Word_iteso_Shape(uint16_t delay_in_ms, uint8_t degree);
void Word_sofia_Shape(uint16_t delay_in_ms, uint8_t degree);


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void WordExecute(words_t word, uint16_t delay_in_ms, uint8_t degree)
{ // Select the word to display, amount of time in which the shape will be displayed and degree at which tiles will be moved
  if(yes == word)
    Word_yes_Shape(delay_in_ms, degree);
  else if(no == word)
    Word_no_Shape(delay_in_ms, degree);
  else if(iteso == word)
    Word_iteso_Shape(delay_in_ms, degree);
  else if(sofia == word)
    Word_sofia_Shape(delay_in_ms, degree);
  else
    ;
}

void Word_yes_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < WORD_YES_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Word_yes[move_tile_index]].tile.tile_id, g_art[Word_yes[move_tile_index]].tile.driver, g_art[Word_yes[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Word_no_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < WORD_NO_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Word_no[move_tile_index]].tile.tile_id, g_art[Word_no[move_tile_index]].tile.driver, g_art[Word_no[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Word_iteso_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < WORD_ITESO_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Word_iteso[move_tile_index]].tile.tile_id, g_art[Word_iteso[move_tile_index]].tile.driver, g_art[Word_iteso[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Word_sofia_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < WORD_SOFIA_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Word_sofia[move_tile_index]].tile.tile_id, g_art[Word_sofia[move_tile_index]].tile.driver, g_art[Word_sofia[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


#endif
