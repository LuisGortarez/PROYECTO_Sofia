/*
  Name:		  SOFIAemojis.h
  Created:	05/03/2025 12:46:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de figuras emoji. 
            Cada figura emoji tiene un arreglo con los identificadores 
            de servomotores que se deben mover para crear la figura.
            Las funciones utilizan un ciclo 'for' para realizar los 
            movimientos de todo el contenido de los arreglos.
*/

#ifndef SOFIAemojis_H
#define SOFIAemojis_H

#include "SOFIAdatatypes.h"

// For identifying emoji to execute
typedef enum
{
  staring,
  blush,
  excited,
  angry,
  smiling,
  happy,
  wink,
  disturbed,
  crying,
  dead,
  pain,
  surprised,
  sad,
  uhoh,
  yuck,
} emojis_t;


///////////////////////////////////////////////////////
////////////// Emoji staring move tiles data //////////
///////////////////////////////////////////////////////

#define EMOJI_STARING_SIZE             52

// Array with the tiles to move for making Emoji staring
static const uint8_t Emoji_Staring[EMOJI_STARING_SIZE] = {
                                                          // Head sides
                                                          197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                          104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                          // Face
                                                          79, 85, 78, 80, 84, 86, 93, 95, 99, 101, 109, 115, 138, 146, 154, 160, 140, 155, 
                                                          144, 159, 156, 158, 142, 157
                                                          };

///////////////////////////////////////////////////////
////////////// Emoji blush move tiles data ////////////
///////////////////////////////////////////////////////

#define EMOJI_BLUSH_SIZE               54

// Array with the tiles to move for making Emoji blush
static const uint8_t Emoji_Blush[EMOJI_BLUSH_SIZE] = {
                                                      // Head sides
                                                      197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                      104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                      // Face
                                                      79, 85, 78, 80, 84, 86, 93, 95, 99, 101, 109, 115, 152, 162, 138, 153, 146, 
                                                      161, 154, 160, 142, 158, 173, 172, 171, 156
                                                      };

///////////////////////////////////////////////////////
////////////// Emoji excited move tiles data //////////
///////////////////////////////////////////////////////

#define EMOJI_EXCITED_SIZE              58

// Array with the tiles to move for making Emoji excited
static const uint8_t Emoji_Excited[EMOJI_EXCITED_SIZE] = {
                                                          // Head sides
                                                          197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                          104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                          // Face
                                                          64, 79, 70, 85, 81, 80, 83, 84, 111, 95, 113, 99, 124, 109, 130, 115, 107, 
                                                          93, 117, 101, 77, 78, 87, 86, 142, 158, 173, 172, 171, 156
                                                          };

///////////////////////////////////////////////////////
////////////// Emoji angry move tiles data ////////////
///////////////////////////////////////////////////////

#define EMOJI_ANGRY_SIZE                58

// Array with the tiles to move for making Emoji angry
static const uint8_t Emoji_Angry[EMOJI_ANGRY_SIZE] = {
                                                      // Head sides
                                                      197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                      104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                      // Face
                                                      62, 72, 63, 71, 79, 85, 80, 84, 96, 98, 95, 99, 109, 115, 93, 101, 78, 99, 
                                                      153, 161, 154, 160, 140, 155, 144, 159, 156, 158, 142, 157
                                                      };

///////////////////////////////////////////////////////
////////////// Emoji smiling move tiles data //////////
///////////////////////////////////////////////////////

#define EMOJI_SMILING_SIZE              50

// Array with the tiles to move for making Emoji smiling
static const uint8_t Emoji_Smiling[EMOJI_SMILING_SIZE] = {
                                                          // Head sides
                                                          197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                          104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                          // Face
                                                          92, 102, 78, 86, 79, 85, 80, 84, 96, 98, 138, 146, 154, 160, 140, 155, 144, 
                                                          159, 156, 158, 142, 157
                                                          };

///////////////////////////////////////////////////////
////////////// Emoji happy move tiles data ////////////
///////////////////////////////////////////////////////

#define EMOJI_HAPPY_SIZE                50

// Array with the tiles to move for making Emoji happy
static const uint8_t Emoji_Happy[EMOJI_HAPPY_SIZE] = {
                                                      // Head sides
                                                      197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                      104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                      // Face
                                                      92, 102, 78, 86, 79, 85, 80, 84, 96, 98, 127, 141, 143, 140, 144, 155, 159, 
                                                      170, 174, 186, 188, 187
                                                      };

///////////////////////////////////////////////////////
////////////// Emoji wink move tiles data /////////////
///////////////////////////////////////////////////////

#define EMOJI_WINK_SIZE                 49

// Array with the tiles to move for making Emoji wink
static const uint8_t Emoji_Wink[EMOJI_WINK_SIZE] = {
                                                    // Head sides
                                                    197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                    104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                    // Face
                                                    78, 79, 80, 93, 109, 95, 99, 100, 101, 138, 146, 154, 160, 140, 155, 144, 159, 
                                                    156, 158, 142, 157
                                                    };

///////////////////////////////////////////////////////
////////////// Emoji disturbed move tiles data ////////
///////////////////////////////////////////////////////

#define EMOJI_DISTURBED_SIZE             57

// Array with the tiles to move for making Emoji disturbed
static const uint8_t Emoji_Disturbed[EMOJI_DISTURBED_SIZE] = {
                                                              // Head sides
                                                              197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                              104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                              // Face
                                                              108, 122, 124, 137, 138, 139, 98, 84, 85, 86, 102, 117, 132, 131, 145, 129, 
                                                              128, 113, 169, 184, 175, 190, 170, 174, 171, 186, 173, 188, 172
                                                              };

///////////////////////////////////////////////////////
////////////// Emoji crying move tiles data ///////////
///////////////////////////////////////////////////////

#define EMOJI_CRYING_SIZE                 50

// Array with the tiles to move for making Emoji crying
static const uint8_t Emoji_Crying[EMOJI_CRYING_SIZE] = {
                                                        // Head sides
                                                        197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                        104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                        // Face
                                                        92, 78, 87, 86, 100, 94, 80, 81, 98, 84, 127, 143, 144, 159, 174, 188, 187, 
                                                        186, 170, 155, 140, 141
                                                        };

///////////////////////////////////////////////////////
////////////// Emoji dead move tiles data /////////////
///////////////////////////////////////////////////////

#define EMOJI_DEAD_SIZE                   49

// Array with the tiles to move for making Emoji dead
static const uint8_t Emoji_Dead[EMOJI_DEAD_SIZE] = {
                                                    // Head sides
                                                    197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                    104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                    // Face
                                                    77, 78, 87, 86, 81, 80, 83, 84, 94, 100, 109, 115, 108, 122, 116, 132, 110, 
                                                    126, 114, 128, 157
                                                    };

///////////////////////////////////////////////////////
////////////// Emoji pain move tiles data /////////////
///////////////////////////////////////////////////////

#define EMOJI_PAIN_SIZE                   52

// Array with the tiles to move for making Emoji pain
static const uint8_t Emoji_Pain[EMOJI_PAIN_SIZE] = {
                                                    // Head sides
                                                    197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                    104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                    // Face
                                                    77, 78, 94, 87, 86, 100, 122, 108, 109, 95, 132, 116, 115, 99, 154, 160, 
                                                    140, 155, 144, 159, 156, 158, 142, 157
                                                    };

///////////////////////////////////////////////////////
////////////// Emoji surprised move tiles data ////////
///////////////////////////////////////////////////////

#define EMOJI_SURPRISED_SIZE              52

// Array with the tiles to move for making Emoji surprised
static const uint8_t Emoji_Surprised[EMOJI_SURPRISED_SIZE] = {
                                                              // Head sides
                                                              197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                              104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                              // Face
                                                              79, 85, 78, 86, 93, 101, 109, 115, 95, 99, 80, 84, 127, 141, 143, 140, 144, 
                                                              155, 159, 170, 174, 186, 188, 187
                                                              };

///////////////////////////////////////////////////////
////////////// Emoji sad move tiles data //////////////
///////////////////////////////////////////////////////

#define EMOJI_SAD_SIZE                     50

// Array with the tiles to move for making Emoji sad
static const uint8_t Emoji_Sad[EMOJI_SAD_SIZE] = {
                                                  // Head sides
                                                  197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                  104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                  // Face
                                                  92, 102, 78, 86, 79, 85, 80, 84, 96, 98, 153, 161, 154, 160, 140, 155, 144, 159, 
                                                  156, 158, 142, 157
                                                  };

///////////////////////////////////////////////////////
////////////// Emoji uhoh move tiles data /////////////
///////////////////////////////////////////////////////

#define EMOJI_UHOH_SIZE                     37

// Array with the tiles to move for making Emoji uhoh
static const uint8_t Emoji_Uhoh[EMOJI_UHOH_SIZE] = {
                                                    // Head sides
                                                    197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                    104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                    // Face
                                                    124, 132, 156, 160, 142, 157, 144, 159, 158
                                                    };

///////////////////////////////////////////////////////
////////////// Emoji yuck move tiles data /////////////
///////////////////////////////////////////////////////

#define EMOJI_YUCK_SIZE                      54

// Array with the tiles to move for making Emoji yuck
static const uint8_t Emoji_Yuck[EMOJI_YUCK_SIZE] = {
                                                    // Head sides
                                                    197, 207, 181, 193, 180, 194, 165, 179, 150, 164, 135, 149, 120, 134, 105, 119, 90, 
                                                    104, 75, 89, 60, 74, 45, 59, 31, 43, 32, 42, 
                                                    // Face
                                                    77, 78, 94, 87, 86, 100, 95, 109, 108, 122, 99, 115, 116, 132, 127, 141, 143, 
                                                    140, 144, 155, 159, 170, 174, 186, 188, 187
                                                    };


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void EmojiExecute(emojis_t emoji, uint16_t delay_in_ms, uint8_t degree);
void Emoji_Staring_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Blush_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Excited_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Angry_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Smiling_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Happy_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Wink_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Disturbed_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Crying_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Dead_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Pain_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Surprised_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Sad_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Uhoh_Shape(uint16_t delay_in_ms, uint8_t degree);
void Emoji_Yuck_Shape(uint16_t delay_in_ms, uint8_t degree);


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void EmojiExecute(emojis_t emoji, uint16_t delay_in_ms, uint8_t degree)
{ // Select the emoji to display, amount of time in which the shape will be displayed and degree at which tiles will be moved
  if(staring == emoji)
    Emoji_Staring_Shape(delay_in_ms, degree);
  else if(blush == emoji)
    Emoji_Blush_Shape(delay_in_ms, degree);
  else if(excited == emoji)
    Emoji_Excited_Shape(delay_in_ms, degree);
  else if(angry == emoji)
    Emoji_Angry_Shape(delay_in_ms, degree);
  else if(smiling == emoji)
    Emoji_Smiling_Shape(delay_in_ms, degree);
  else if(happy == emoji)
    Emoji_Happy_Shape(delay_in_ms, degree);
  else if(wink == emoji)
    Emoji_Wink_Shape(delay_in_ms, degree);
  else if(disturbed == emoji)
    Emoji_Disturbed_Shape(delay_in_ms, degree);
  else if(crying == emoji)
    Emoji_Crying_Shape(delay_in_ms, degree);
  else if(dead == emoji)
    Emoji_Dead_Shape(delay_in_ms, degree);
  else if(pain == emoji)
    Emoji_Pain_Shape(delay_in_ms, degree);
  else if(surprised == emoji)
    Emoji_Surprised_Shape(delay_in_ms, degree);
  else if(sad == emoji)
    Emoji_Sad_Shape(delay_in_ms, degree);
  else if(uhoh == emoji)
    Emoji_Uhoh_Shape(delay_in_ms, degree);
  else if(yuck == emoji)
    Emoji_Yuck_Shape(delay_in_ms, degree);
  else
    ;
}

void Emoji_Staring_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_STARING_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Staring[move_tile_index]].tile.tile_id, g_art[Emoji_Staring[move_tile_index]].tile.driver, g_art[Emoji_Staring[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Blush_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_BLUSH_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Blush[move_tile_index]].tile.tile_id, g_art[Emoji_Blush[move_tile_index]].tile.driver, g_art[Emoji_Blush[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Excited_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_EXCITED_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Excited[move_tile_index]].tile.tile_id, g_art[Emoji_Excited[move_tile_index]].tile.driver, g_art[Emoji_Excited[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Angry_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_ANGRY_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Angry[move_tile_index]].tile.tile_id, g_art[Emoji_Angry[move_tile_index]].tile.driver, g_art[Emoji_Angry[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Smiling_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_SMILING_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Smiling[move_tile_index]].tile.tile_id, g_art[Emoji_Smiling[move_tile_index]].tile.driver, g_art[Emoji_Smiling[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Happy_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_HAPPY_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Happy[move_tile_index]].tile.tile_id, g_art[Emoji_Happy[move_tile_index]].tile.driver, g_art[Emoji_Happy[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Wink_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_WINK_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Wink[move_tile_index]].tile.tile_id, g_art[Emoji_Wink[move_tile_index]].tile.driver, g_art[Emoji_Wink[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Disturbed_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_DISTURBED_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Disturbed[move_tile_index]].tile.tile_id, g_art[Emoji_Disturbed[move_tile_index]].tile.driver, g_art[Emoji_Disturbed[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Crying_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_CRYING_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Crying[move_tile_index]].tile.tile_id, g_art[Emoji_Crying[move_tile_index]].tile.driver, g_art[Emoji_Crying[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Dead_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_DEAD_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Dead[move_tile_index]].tile.tile_id, g_art[Emoji_Dead[move_tile_index]].tile.driver, g_art[Emoji_Dead[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Pain_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_PAIN_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Pain[move_tile_index]].tile.tile_id, g_art[Emoji_Pain[move_tile_index]].tile.driver, g_art[Emoji_Pain[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Surprised_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_SURPRISED_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Surprised[move_tile_index]].tile.tile_id, g_art[Emoji_Surprised[move_tile_index]].tile.driver, g_art[Emoji_Surprised[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Sad_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_SAD_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Sad[move_tile_index]].tile.tile_id, g_art[Emoji_Sad[move_tile_index]].tile.driver, g_art[Emoji_Sad[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Uhoh_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_UHOH_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Uhoh[move_tile_index]].tile.tile_id, g_art[Emoji_Uhoh[move_tile_index]].tile.driver, g_art[Emoji_Uhoh[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Emoji_Yuck_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < EMOJI_YUCK_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Emoji_Yuck[move_tile_index]].tile.tile_id, g_art[Emoji_Yuck[move_tile_index]].tile.driver, g_art[Emoji_Yuck[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


#endif
