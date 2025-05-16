/*
  Name:		  SOFIAnumbers.h
  Created:	05/03/2025 12:46:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de figuras número. 
            Cada figura número tiene un arreglo con los identificadores 
            de servomotores que se deben mover para crear la figura.
            Las funciones utilizan un ciclo 'for' para realizar los 
            movimientos de todo el contenido de los arreglos.
*/

#ifndef SOFIAnumbers_H
#define SOFIAnumbers_H

#include "SOFIAdatatypes.h"

// For identifying number to execute
typedef enum
{
  number_0,
  number_1,
  number_2,
  number_3,
  number_4,
  number_5,
  number_6,
  number_7,
  number_8,
  number_9,
} numbers_t;


///////////////////////////////////////////////////////
////////////// Number 0 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_0_SIZE             74

// Array with the tiles to move for making Number 0
static const uint8_t Number_0[NUMBER_0_SIZE] = {
                                                22, 36, 37, 38, 35, 51, 53, 39, 49, 50, 54, 55, 62, 48, 64, 70, 56, 72, 77, 63, 79, 85, 71, 87, 
                                                92, 78, 94, 100, 86, 102, 107, 93, 109, 115, 101, 117, 122, 108, 124, 130, 116, 132, 137, 123, 139, 
                                                145, 131, 147, 152, 138, 154, 160, 146, 162, 167, 153, 169, 175, 161, 177, 168, 184, 170, 174, 190, 
                                                176, 185, 186, 189, 188, 201, 187, 203, 202
                                                };


///////////////////////////////////////////////////////
////////////// Number 1 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_1_SIZE             48

// Array with the tiles to move for making Number 1
static const uint8_t Number_1[NUMBER_1_SIZE] = {
                                                63, 64, 79, 50, 65, 51, 66, 81, 37, 52, 67, 38, 24, 40, 53, 39, 55, 68, 54, 70, 83, 69, 85, 
                                                98, 84, 100, 113, 99, 115, 128, 114, 130, 143, 129, 145, 158, 144, 160, 173, 159, 175, 188, 
                                                174, 190, 203, 189, 205, 204
                                                };


///////////////////////////////////////////////////////
////////////// Number 2 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_2_SIZE             82

// Array with the tiles to move for making Number 2
static const uint8_t Number_2[NUMBER_2_SIZE] = {
                                                62, 77, 48, 63, 78, 49, 64, 79, 35, 50, 65, 36, 51, 66, 22, 37, 52, 23, 38, 53, 24, 39, 54, 
                                                40, 55, 41, 56, 57, 72, 70, 85, 71, 86, 87, 102, 100, 115, 101, 116, 117, 130, 114, 129, 
                                                128, 143, 127, 142, 141, 156, 140, 155, 154, 153, 167, 182, 197, 168, 183, 198, 169, 184, 199, 
                                                170, 185, 200, 186, 201, 172, 187, 202, 188, 203, 174, 189, 204, 190, 205, 176, 191, 206, 
                                                192, 207
                                                };


///////////////////////////////////////////////////////
////////////// Number 3 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_3_SIZE             70

// Array with the tiles to move for making Number 3
static const uint8_t Number_3[NUMBER_3_SIZE] = {
                                                33, 48, 34, 49, 20, 35, 21, 36, 7, 22, 23, 38, 24, 39, 40, 55, 41, 56, 57, 72, 71, 86, 87, 
                                                85, 100, 84, 99, 98, 96, 100, 95, 110, 111, 126, 97, 112, 113, 128, 114, 129, 130, 145, 
                                                131, 146, 147, 162, 148, 163, 178, 177, 192, 161, 176, 191, 190, 205, 189, 204, 203, 218, 
                                                202, 217, 201, 216, 185, 200, 184, 199, 168, 183
                                                };


///////////////////////////////////////////////////////
////////////// Number 4 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_4_SIZE             62

// Array with the tiles to move for making Number 4
static const uint8_t Number_4[NUMBER_4_SIZE] = {
                                                76, 91, 77, 92, 107, 63, 78, 93, 64, 79, 94, 109, 50, 65, 80, 95, 51, 66, 96, 111, 37, 52, 
                                                97, 38, 53, 98, 113, 24, 39, 84, 99, 25, 11, 40, 26, 55, 41, 70, 56, 85, 71, 100, 86, 115, 
                                                101, 102, 130, 116, 117, 103, 145, 131, 160, 146, 175, 161, 190, 176, 205, 191, 220, 206
                                                };


///////////////////////////////////////////////////////
////////////// Number 5 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_5_SIZE             69

// Array with the tiles to move for making Number 5
static const uint8_t Number_5[NUMBER_5_SIZE] = {
                                                42, 57, 26, 41, 40, 55, 24, 39, 38, 53, 22, 37, 36, 51, 20, 35, 18, 34, 33, 49, 48, 64, 63, 79, 
                                                78, 94, 93, 109, 108, 124, 95, 110, 111, 126, 97, 112, 113, 128, 99, 114, 115, 130, 116, 132, 
                                                131, 147, 146, 162, 161, 177, 176, 191, 192, 190, 205, 189, 204, 188, 203, 187, 202, 186, 201, 
                                                185, 200, 184, 199, 168, 183
                                                };


///////////////////////////////////////////////////////
////////////// Number 6 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_6_SIZE             78

// Array with the tiles to move for making Number 6
static const uint8_t Number_6[NUMBER_6_SIZE] = {
                                                41, 56, 40, 55, 24, 39, 23, 38, 7, 22, 21, 36, 20, 35, 34, 49, 33, 48, 47, 62, 63, 78, 62, 
                                                77, 93, 92, 108, 107, 123, 122, 138, 137, 153, 152, 168, 167, 183, 182, 94, 109, 124, 95, 
                                                110, 111, 126, 97, 112, 113, 128, 99, 114, 115, 130, 116, 132, 131, 147, 146, 162, 161, 177, 
                                                176, 192, 191, 190, 205, 189, 204, 188, 203, 187, 202, 186, 201, 185, 200, 184, 199
                                                };


///////////////////////////////////////////////////////
////////////// Number 7 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_7_SIZE             53

// Array with the tiles to move for making Number 7
static const uint8_t Number_7[NUMBER_7_SIZE] = {
                                                17, 32, 18, 33, 19, 34, 20, 35, 21, 36, 22, 37, 23, 38, 24, 39, 25, 40, 26, 41, 27, 28, 42, 43, 
                                                57, 58, 72, 73, 71, 87, 86, 102, 100, 101, 115, 116, 114, 130, 129, 145, 143, 144, 158, 159, 
                                                157, 173, 172, 188, 186, 187, 201, 202, 216
                                                };


///////////////////////////////////////////////////////
////////////// Number 8 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_8_SIZE             80

// Array with the tiles to move for making Number 8
static const uint8_t Number_8[NUMBER_8_SIZE] = {
                                                7, 21, 22, 23, 20, 36, 38, 24, 34, 35, 39, 40, 33, 49, 55, 41, 48, 63, 56, 71, 64, 79, 70, 85, 
                                                65, 80, 69, 84, 81, 96, 83, 98, 82, 97, 95, 111, 113, 99, 109, 110, 114, 115, 108, 124, 130, 116, 
                                                122, 123, 131, 132, 137, 138, 146, 147, 152, 153, 161, 162, 167, 168, 176, 177, 182, 183, 191, 192, 
                                                184, 199, 190, 205, 185, 200, 189, 204, 201, 216, 203, 218, 202, 217
                                                };


///////////////////////////////////////////////////////
////////////// Number 9 move tiles data ///////////////
///////////////////////////////////////////////////////

#define NUMBER_9_SIZE             83

// Array with the tiles to move for making Number 9
static const uint8_t Number_9[NUMBER_9_SIZE] = {
                                                6, 7, 8, 19, 5, 21, 23, 9, 25, 18, 34, 20, 24, 40, 26, 32, 33, 47, 48, 62, 62, 77, 78, 92, 93, 
                                                107, 108, 41, 42, 56, 57, 71, 72, 86, 87, 101, 102, 116, 117, 109, 124, 115, 130, 110, 125, 114, 
                                                129, 126, 141, 128, 143, 127, 131, 132, 146, 147, 161, 162, 176, 177, 167, 168, 192, 207, 182, 
                                                197, 191, 206, 183, 198, 205, 220, 199, 214, 204, 219, 200, 215, 218, 233, 216, 231, 217
                                                };


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void NumberExecute(numbers_t number, uint16_t delay_in_ms, uint8_t degree);
void Number_0_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_1_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_2_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_3_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_4_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_5_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_6_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_7_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_8_Shape(uint16_t delay_in_ms, uint8_t degree);
void Number_9_Shape(uint16_t delay_in_ms, uint8_t degree);


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void NumberExecute(numbers_t number, uint16_t delay_in_ms, uint8_t degree)
{ // Select the number to display, amount of time in which the shape will be displayed and degree at which tiles will be moved
  if(number_0 == number)
    Number_0_Shape(delay_in_ms, degree);
  else if(number_1 == number)
    Number_1_Shape(delay_in_ms, degree);
  else if(number_2 == number)
    Number_2_Shape(delay_in_ms, degree);
  else if(number_3 == number)
    Number_3_Shape(delay_in_ms, degree);
  else if(number_4 == number)
    Number_4_Shape(delay_in_ms, degree);
  else if(number_5 == number)
    Number_5_Shape(delay_in_ms, degree);
  else if(number_6 == number)
    Number_6_Shape(delay_in_ms, degree);
  else if(number_7 == number)
    Number_7_Shape(delay_in_ms, degree);
  else if(number_8 == number)
    Number_8_Shape(delay_in_ms, degree);
  else if(number_9 == number)
    Number_9_Shape(delay_in_ms, degree);
  else
    ;
}

void Number_0_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_0_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_0[move_tile_index]].tile.tile_id, g_art[Number_0[move_tile_index]].tile.driver, g_art[Number_0[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_1_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_1_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_1[move_tile_index]].tile.tile_id, g_art[Number_1[move_tile_index]].tile.driver, g_art[Number_1[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_2_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_2_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_2[move_tile_index]].tile.tile_id, g_art[Number_2[move_tile_index]].tile.driver, g_art[Number_2[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_3_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_3_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_3[move_tile_index]].tile.tile_id, g_art[Number_3[move_tile_index]].tile.driver, g_art[Number_3[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_4_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_4_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_4[move_tile_index]].tile.tile_id, g_art[Number_4[move_tile_index]].tile.driver, g_art[Number_4[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_5_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_5_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_5[move_tile_index]].tile.tile_id, g_art[Number_5[move_tile_index]].tile.driver, g_art[Number_5[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_6_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_6_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_6[move_tile_index]].tile.tile_id, g_art[Number_6[move_tile_index]].tile.driver, g_art[Number_6[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_7_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_7_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_7[move_tile_index]].tile.tile_id, g_art[Number_7[move_tile_index]].tile.driver, g_art[Number_7[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_8_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_8_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_8[move_tile_index]].tile.tile_id, g_art[Number_8[move_tile_index]].tile.driver, g_art[Number_8[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Number_9_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < NUMBER_9_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Number_9[move_tile_index]].tile.tile_id, g_art[Number_9[move_tile_index]].tile.driver, g_art[Number_9[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


#endif
