/*
  Name:		  SOFIAsymbols.h
  Created:	06/03/2025 12:19:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de figuras símbolo. 
            Cada figura símbolo tiene un arreglo con los identificadores 
            de servomotores que se deben mover para crear la figura.
            Las funciones utilizan un ciclo 'for' para realizar los 
            movimientos de todo el contenido de los arreglos.
*/

#ifndef SOFIAsymbols_H
#define SOFIAsymbols_H

#include "SOFIAdatatypes.h"

// For identifying symbol to execute
typedef enum
{
  amperson,
  money,
  wrong,
  correct,
  question_start,
  question_end,
  exclamation_start,
  exclamation_end,
  number,
  arroba,
  up_arrow,
  down_arrow,
  right_arrow,
  left_arrow,
  percentage,
  division,
  multiplication,
  add,
  substract,
  equals,
  greater_than,
  lesser_than,
  wifi,
} symbols_t;


/////////////////////////////////////////////////////////////
////////////// Symbol amperson move tiles data //////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_AMPERSON_SIZE                86

// Array with the tiles to move for making Symbol '&'
static const uint8_t Symbol_Amperson[SYMBOL_AMPERSON_SIZE] = {
                                                              132, 133, 147, 148, 162, 163, 177, 178, 192, 176, 191, 206, 221, 190, 205, 
                                                              220, 189, 204, 203, 218, 202, 217, 201, 216, 185, 200, 184, 199, 183, 
                                                              182, 168, 167, 153, 152, 138, 137, 123, 122, 108, 109, 110, 174, 
                                                              173, 159, 158, 142, 143, 127, 126, 112, 96, 111, 82, 97, 83, 
                                                              98, 69, 84, 70, 85, 41, 56, 71, 40, 55, 24, 39, 23, 38, 7, 
                                                              22, 21, 36, 20, 35, 33, 34, 48, 49, 63, 64, 78, 79, 94, 
                                                              80, 95
                                                              };


//////////////////////////////////////////////////////////
////////////// Symbol money move tiles data //////////////
//////////////////////////////////////////////////////////

#define SYMBOL_MONEY_SIZE                   83

// Array with the tiles to move for making Symbol '$'
static const uint8_t Symbol_Money[SYMBOL_MONEY_SIZE] = {
                                                        6, 7, 21, 22, 36, 37, 51, 52, 66, 67, 81, 82, 96, 97, 111, 112, 126, 127, 141, 
                                                        142, 156, 157, 171, 172, 186, 187, 201, 202, 216, 217, 231, 72, 87, 56, 71, 
                                                        55, 70, 39, 54, 38, 53, 35, 50, 49, 64, 62, 77, 92, 48, 63, 78, 93, 94, 
                                                        109, 95, 110, 113, 128, 114, 129, 130, 145, 147, 162, 177, 131, 146, 
                                                        161, 176, 175, 190, 174, 189, 188, 203, 170, 185, 169, 184, 
                                                        153, 168, 152, 167
                                                        };


//////////////////////////////////////////////////////////
////////////// Symbol wrong move tiles data //////////////
//////////////////////////////////////////////////////////

#define SYMBOL_WRONG_SIZE                   65

// Array with the tiles to move for making Symbol wrong
static const uint8_t Symbol_Wrong[SYMBOL_WRONG_SIZE] = {
                                                        61, 76, 136, 151, 62, 77, 92, 137, 152, 167, 63, 78, 93, 123, 138, 153, 79, 94, 
                                                        109, 124, 139, 154, 80, 95, 110, 125, 140, 96, 111, 126, 141, 97, 112, 127, 
                                                        98, 113, 128, 143, 84, 99, 114, 129, 144, 85, 100, 115, 130, 145, 160, 71, 
                                                        86, 101, 131, 146, 161, 72, 87, 102, 147, 162, 177, 73, 88, 148, 163
                                                        };


////////////////////////////////////////////////////////////
////////////// Symbol correct move tiles data //////////////
////////////////////////////////////////////////////////////

#define SYMBOL_CORRECT_SIZE                 52

// Array with the tiles to move for making Symbol correct
static const uint8_t Symbol_Correct[SYMBOL_CORRECT_SIZE] = {
                                                            120, 135, 121, 136, 151, 137, 152, 167, 182, 153, 168, 183, 169, 184, 199, 
                                                            155, 170, 185, 141, 156, 171, 186, 112, 127, 142, 157, 172, 98, 113, 
                                                            128, 143, 158, 84, 99, 114, 129, 70, 85, 100, 115, 56, 71, 86, 
                                                            42, 57, 72, 87, 28, 43, 58, 29, 44
                                                            };


/////////////////////////////////////////////////////////////
////////////// Symbol question start move tiles data ////////
/////////////////////////////////////////////////////////////

#define SYMBOL_QUESTION_START_SIZE          52

// Array with the tiles to move for making Symbol '¿'
static const uint8_t Symbol_QuestionStart[SYMBOL_QUESTION_START_SIZE] = {
                                                                         22, 37, 38, 23, 7, 21, 36, 66, 81, 67, 82, 68, 83, 96, 111, 126, 
                                                                         97, 112, 98, 113, 110, 125, 124, 139, 123, 138, 154, 169, 153, 
                                                                         168, 183, 184, 199, 185, 200, 201, 216, 202, 217, 203, 218, 
                                                                         189, 204, 190, 205, 176, 191, 145, 160, 175, 161, 146
                                                                         };


/////////////////////////////////////////////////////////////
////////////// Symbol question_end move tiles data //////////
/////////////////////////////////////////////////////////////

#define SYMBOL_QUESTION_END_SIZE            53

// Array with the tiles to move for making Symbol '?'
static const uint8_t Symbol_QuestionEnd[SYMBOL_QUESTION_END_SIZE] = {
                                                                     93, 94, 78, 79, 63, 64, 48, 49, 33, 34, 20, 35, 21, 36, 7, 22, 23, 
                                                                     38, 24, 39, 40, 55, 41, 56, 70, 85, 71, 86, 101, 100, 115, 99, 
                                                                     114, 113, 126, 112, 128, 141, 127, 143, 156, 142, 158, 171, 
                                                                     157, 173, 202, 187, 203, 218, 217, 216, 201
                                                                     };


/////////////////////////////////////////////////////////////
////////////// Symbol exclamation start move tiles data /////
/////////////////////////////////////////////////////////////

#define SYMBOL_EXCLAMATION_START_SIZE       38  

// Array with the tiles to move for making Symbol '¡'
static const uint8_t Symbol_ExclamationStart[SYMBOL_EXCLAMATION_START_SIZE] = {
                                                                               216, 217, 218, 201, 202, 203, 186, 187, 188, 171, 172, 173, 
                                                                               156, 157, 158, 141, 142, 143, 126, 127, 128, 111, 112, 113, 
                                                                               96, 97, 98, 81, 82, 83, 67, 22, 37, 38, 23, 7, 21, 36
                                                                               };


/////////////////////////////////////////////////////////////
////////////// Symbol exclamation end move tiles data //////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_EXCLAMATION_END_SIZE         38

// Array with the tiles to move for making Symbol '!'
static const uint8_t Symbol_ExclamationEnd[SYMBOL_EXCLAMATION_END_SIZE] = {
                                                                           21, 7, 23, 36, 22, 38, 51, 37, 53, 66, 52, 68, 81, 67, 83, 96, 
                                                                           82, 98, 111, 97, 113, 126, 112, 128, 141, 127, 143, 156, 
                                                                           142, 158, 157, 202, 187, 203, 218, 217, 216, 201
                                                                           };


///////////////////////////////////////////////////////////
////////////// Symbol number move tiles data //////////////
///////////////////////////////////////////////////////////

#define SYMBOL_NUMBER_SIZE                  78

// Array with the tiles to move for making Symbol '#'
static const uint8_t Symbol_Number[SYMBOL_NUMBER_SIZE] = {
                                                           34, 20, 49, 35, 64, 50, 65, 40, 26, 55, 41, 70, 56, 71, 76, 77, 92, 78, 79, 
                                                           94, 80, 81, 96, 82, 83, 98, 84, 85, 100, 86, 87, 102, 88, 93, 108, 123, 
                                                           138, 109, 124, 139, 99, 114, 129, 144, 115, 130, 145, 151, 152, 167, 
                                                           153, 154, 169, 155, 156, 171, 157, 158, 173, 159, 160, 175, 161, 
                                                           162, 177, 163, 182, 168, 197, 183, 212, 198, 188, 174, 203, 
                                                           189, 218, 204
                                                           };


///////////////////////////////////////////////////////////
////////////// Symbol arroba move tiles data //////////////
///////////////////////////////////////////////////////////

#define SYMBOL_ARROBA_SIZE                  53

// Array with the tiles to move for making Symbol '@'
static const uint8_t Symbol_Arroba[SYMBOL_ARROBA_SIZE] = {
                                                           143, 128, 113, 98, 83, 82, 81, 80, 94, 93, 108, 123, 139, 140, 156, 142, 
                                                           158, 159, 160, 146, 131, 116, 101, 86, 71, 56, 55, 39, 38, 37, 51, 50, 
                                                           64, 43, 77, 76, 91, 106, 121, 136, 152, 153, 169, 170, 186, 187, 203, 
                                                           189, 190, 176, 177, 163, 148
                                                           };


/////////////////////////////////////////////////////////////
////////////// Symbol up arrow move tiles data //////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_UP_ARROW_SIZE                 67

// Array with the tiles to move for making Symbol up arrow
static const uint8_t Symbol_UpArrow[SYMBOL_UP_ARROW_SIZE] = {
                                                             61, 76, 91, 73, 88, 103, 62, 77, 92, 72, 87, 102, 48, 63, 78, 56, 71, 86, 49, 
                                                             64, 79, 55, 70, 85, 35, 50, 65, 39, 54, 69, 36, 22, 38, 51, 37, 53, 66, 52, 
                                                             68, 81, 67, 83, 96, 82, 98, 111, 97, 113, 126, 112, 128, 141, 127, 143, 
                                                             156, 142, 158, 171, 157, 173, 186, 172, 188, 201, 187, 203, 202
                                                             };


/////////////////////////////////////////////////////////////
////////////// Symbol down arrow move tiles data ////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_DOWN_ARROW_SIZE               67

// Array with the tiles to move for making Symbol down arrow
static const uint8_t Symbol_DownArrow[SYMBOL_DOWN_ARROW_SIZE] = {
                                                                 121, 136, 151, 133, 148, 163, 137, 152, 167, 147, 162, 177, 138, 153, 
                                                                 168, 146, 161, 176, 154, 169, 184, 160, 175, 190, 155, 170, 185, 
                                                                 159, 174, 189, 201, 202, 203, 186, 187, 188, 171, 172, 173, 
                                                                 156, 157, 158, 141, 142, 143, 126, 127, 128, 111, 112, 113, 
                                                                 96, 97, 98, 81, 82, 83, 66, 67, 68, 51, 52, 53, 36, 37, 
                                                                 38, 22
                                                                 };


/////////////////////////////////////////////////////////////
////////////// Symbol right arrow move tiles data ///////////
/////////////////////////////////////////////////////////////

#define SYMBOL_RIGHT_ARROW_SIZE               39

// Array with the tiles to move for making Symbol right arrow
static const uint8_t Symbol_RightArrow[SYMBOL_RIGHT_ARROW_SIZE] = {
                                                                   91, 106, 121, 107, 122, 93, 108, 123, 109, 124, 95, 110, 125, 111, 
                                                                   126, 97, 112, 127, 83, 98, 113, 128, 143, 158, 84, 99, 114, 
                                                                   129, 144, 100, 115, 130, 145, 101, 116, 131, 117, 132, 118
                                                                   };


/////////////////////////////////////////////////////////////
////////////// Symbol left arrow move tiles data ////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_LEFT_ARROW_SIZE                35

// Array with the tiles to move for making Symbol ''
static const uint8_t Symbol_LeftArrow[SYMBOL_LEFT_ARROW_SIZE] = {
                                                                 103, 118, 133, 117, 132, 101, 116, 131, 115, 130, 99, 114, 129, 113, 
                                                                 128, 97, 112, 127, 111, 126, 80, 95, 110, 125, 140, 94, 109, 124, 
                                                                 139, 93, 108, 123, 107, 122, 106
                                                                 };


/////////////////////////////////////////////////////////////
////////////// Symbol percentage move tiles data ////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_PERCENTAGE_SIZE                64

// Array with the tiles to move for making Symbol '%'
static const uint8_t Symbol_Percentage[SYMBOL_PERCENTAGE_SIZE] = {
                                                                  47, 62, 77, 33, 48, 63, 78, 34, 49, 79, 94, 35, 50, 65, 80, 51, 66, 81, 
                                                                  166, 181, 167, 182, 153, 168, 139, 154, 169, 125, 140, 126, 141, 112, 
                                                                  127, 98, 113, 128, 84, 99, 85, 100, 71, 86, 72, 87, 58, 73, 158, 
                                                                  173, 188, 144, 159, 174, 189, 145, 160, 190, 205, 146, 161, 
                                                                  176, 191, 162, 177, 192
                                                                  };


/////////////////////////////////////////////////////////////
////////////// Symbol division move tiles data //////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_DIVISION_SIZE                  57

// Array with the tiles to move for making Symbol division
static const uint8_t Symbol_Division[SYMBOL_DIVISION_SIZE] = {
                                                              20, 35, 50, 66, 67, 68, 54, 39, 24, 23, 7, 21, 170, 185, 200, 216, 217, 218, 
                                                              204, 189, 174, 173, 157, 171, 91, 106, 121, 107, 122, 93, 108, 123, 109, 
                                                              124, 95, 110, 125, 111, 126, 97, 112, 127, 113, 128, 99, 114, 129, 
                                                              115, 130, 101, 116, 131, 117, 132, 103, 118, 133
                                                              };


/////////////////////////////////////////////////////////////
////////////// Symbol multiplication move tiles data ////////
/////////////////////////////////////////////////////////////

#define SYMBOL_MULTIPLICATION_SIZE            31

// Array with the tiles to move for making Symbol multiplication
static const uint8_t Symbol_Multiplication[SYMBOL_MULTIPLICATION_SIZE] = {
                                                                          37, 52, 67, 82, 97, 112, 127, 142, 157, 172, 187, 152, 138, 139, 
                                                                          125, 126, 113, 99, 100, 86, 87, 77, 78, 94, 95, 111, 128, 
                                                                          129, 145, 146, 162
                                                                          };


////////////////////////////////////////////////////////
////////////// Symbol add move tiles data //////////////
////////////////////////////////////////////////////////

#define SYMBOL_ADD_SIZE                       63

// Array with the tiles to move for making Symbol '+'
static const uint8_t Symbol_Add[SYMBOL_ADD_SIZE] = {
                                                    91, 106, 121, 103, 118, 133, 107, 122, 117, 132, 93, 108, 123, 101, 116, 131, 109, 124, 
                                                    115, 130, 95, 110, 125, 99, 114, 129, 36, 51, 66, 81, 96, 111, 126, 141, 156, 171, 
                                                    186, 201, 38, 53, 68, 83, 98, 113, 128, 143, 158, 173, 188, 203, 22, 37, 52, 
                                                    67, 82, 97, 112, 127, 142, 157, 172, 187, 202
                                                    };


/////////////////////////////////////////////////////////////
////////////// Symbol substract move tiles data /////////////
/////////////////////////////////////////////////////////////

#define SYMBOL_SUBSTRACT_SIZE                 33

// Array with the tiles to move for making Symbol '-'
static const uint8_t Symbol_Substract[SYMBOL_SUBSTRACT_SIZE] = {
                                                                91, 106, 121, 107, 122, 93, 108, 123, 109, 124, 95, 110, 125, 111, 126, 
                                                                97, 112, 127, 113, 128, 99, 114, 129, 115, 130, 101, 116, 131, 117, 
                                                                132, 103, 118, 133
                                                                };


///////////////////////////////////////////////////////////
////////////// Symbol equals move tiles data //////////////
///////////////////////////////////////////////////////////

#define SYMBOL_EQUALS_SIZE                    40

// Array with the tiles to move for making Symbol '='
static const uint8_t Symbol_Equals[SYMBOL_EQUALS_SIZE] = {
                                                          61, 76, 77, 63, 78, 79, 65, 80, 81, 67, 82, 83, 69, 84, 85, 71, 86, 87, 73, 88, 
                                                          136, 151, 152, 138, 153, 154, 140, 155, 156, 142, 157, 158, 144, 159, 160, 
                                                          146, 161, 162, 148, 163
                                                          };


/////////////////////////////////////////////////////////////
////////////// Symbol greater than move tiles data //////////
/////////////////////////////////////////////////////////////

#define SYMBOL_GREATER_THAN_SIZE              46

// Array with the tiles to move for making Symbol '>'
static const uint8_t Symbol_GreaterThan[SYMBOL_GREATER_THAN_SIZE] = {
                                                                     16, 31, 32, 47, 33, 48, 49, 64, 50, 65, 66, 81, 67, 82, 83, 98, 84, 
                                                                     99, 100, 115, 130, 145, 101, 116, 131, 117, 132, 118, 129, 144, 
                                                                     143, 158, 142, 157, 156, 171, 155, 170, 169, 184, 168, 183, 
                                                                     182, 197, 181, 196
                                                                     };


/////////////////////////////////////////////////////////////
////////////// Symbol lesser than move tiles data ///////////
/////////////////////////////////////////////////////////////

#define SYMBOL_LESSER_THAN_SIZE               46

// Array with the tiles to move for making Symbol '<'
static const uint8_t Symbol_LesserThan[SYMBOL_LESSER_THAN_SIZE] = {
                                                                   28, 43, 42, 57, 41, 56, 55, 70, 54, 69, 68, 83, 67, 82, 81, 96, 80, 95, 
                                                                   94, 109, 124, 139, 93, 108, 123, 107, 122, 106, 125, 140, 141, 156, 
                                                                   142, 157, 158, 173, 159, 174, 175, 190, 176, 191, 192, 207, 
                                                                   193, 208
                                                                   };


/////////////////////////////////////////////////////////
////////////// Symbol wifi move tiles data //////////////
/////////////////////////////////////////////////////////

#define SYMBOL_WIFI_SIZE                      40

// Array with the tiles to move for making Symbol wifi
static const uint8_t Symbol_Wifi[SYMBOL_WIFI_SIZE] = {
                                                      187, 186, 172, 188, 201, 202, 203, 154, 140, 141, 127, 143, 144, 160, 
                                                      122, 108, 109, 95, 96, 82, 98, 99, 115, 116, 132, 90, 76, 77, 63, 
                                                      64, 50, 51, 37, 53, 54, 70, 71, 87, 88, 104
                                                      };


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void SymbolExecute(symbols_t symbol, uint16_t delay_in_ms, uint8_t degree);
void Symbol_Amperson_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Money_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Wrong_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Correct_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_QuestionStart_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_QuestionEnd_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_ExclamationStart_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_ExclamationEnd_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Number_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Arroba_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_UpArrow_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_DownArrow_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_RightArrow_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_LeftArrow_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Percentage_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Division_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Multiplication_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Add_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Substract_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Equals_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_GreaterThan_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_LesserThan_Shape(uint16_t delay_in_ms, uint8_t degree);
void Symbol_Wifi_Shape(uint16_t delay_in_ms, uint8_t degree);


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void SymbolExecute(symbols_t symbol, uint16_t delay_in_ms, uint8_t degree)
{ // Select the symbol to display, amount of time in which the shape will be displayed and degree at which tiles will be moved
  if(amperson == symbol)
    Symbol_Amperson_Shape(delay_in_ms, degree);
  else if(money == symbol)
    Symbol_Money_Shape(delay_in_ms, degree);
  else if(wrong == symbol)
    Symbol_Wrong_Shape(delay_in_ms, degree);
  else if(correct == symbol)
    Symbol_Correct_Shape(delay_in_ms, degree);
  else if(question_start == symbol)
    Symbol_QuestionStart_Shape(delay_in_ms, degree);
  else if(question_end == symbol)
    Symbol_QuestionEnd_Shape(delay_in_ms, degree);
  else if(exclamation_start == symbol)
    Symbol_ExclamationStart_Shape(delay_in_ms, degree);
  else if(exclamation_end == symbol)
    Symbol_ExclamationEnd_Shape(delay_in_ms, degree);
  else if(number == symbol)
    Symbol_Number_Shape(delay_in_ms, degree);
  else if(arroba == symbol)
    Symbol_Arroba_Shape(delay_in_ms, degree);
  else if(up_arrow == symbol)
    Symbol_UpArrow_Shape(delay_in_ms, degree);
  else if(down_arrow == symbol)
    Symbol_DownArrow_Shape(delay_in_ms, degree);
  else if(right_arrow == symbol)
    Symbol_RightArrow_Shape(delay_in_ms, degree);
  else if(left_arrow == symbol)
    Symbol_LeftArrow_Shape(delay_in_ms, degree);
  else if(percentage == symbol)
    Symbol_Percentage_Shape(delay_in_ms, degree);
  else if(division == symbol)
    Symbol_Division_Shape(delay_in_ms, degree);
  else if(multiplication == symbol)
    Symbol_Multiplication_Shape(delay_in_ms, degree);
  else if(add == symbol)
    Symbol_Add_Shape(delay_in_ms, degree);
  else if(substract == symbol)
    Symbol_Substract_Shape(delay_in_ms, degree);
  else if(equals == symbol)
    Symbol_Equals_Shape(delay_in_ms, degree);
  else if(greater_than == symbol)
    Symbol_GreaterThan_Shape(delay_in_ms, degree);
  else if(lesser_than == symbol)
    Symbol_LesserThan_Shape(delay_in_ms, degree);
  else if(wifi == symbol)
    Symbol_Wifi_Shape(delay_in_ms, degree);
  else
    ;
}

void Symbol_Amperson_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_AMPERSON_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Amperson[move_tile_index]].tile.tile_id, g_art[Symbol_Amperson[move_tile_index]].tile.driver, g_art[Symbol_Amperson[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Money_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_MONEY_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Money[move_tile_index]].tile.tile_id, g_art[Symbol_Money[move_tile_index]].tile.driver, g_art[Symbol_Money[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Wrong_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_WRONG_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Wrong[move_tile_index]].tile.tile_id, g_art[Symbol_Wrong[move_tile_index]].tile.driver, g_art[Symbol_Wrong[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Correct_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_CORRECT_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Correct[move_tile_index]].tile.tile_id, g_art[Symbol_Correct[move_tile_index]].tile.driver, g_art[Symbol_Correct[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_QuestionStart_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_QUESTION_START_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_QuestionStart[move_tile_index]].tile.tile_id, g_art[Symbol_QuestionStart[move_tile_index]].tile.driver, g_art[Symbol_QuestionStart[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_QuestionEnd_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_QUESTION_END_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_QuestionEnd[move_tile_index]].tile.tile_id, g_art[Symbol_QuestionEnd[move_tile_index]].tile.driver, g_art[Symbol_QuestionEnd[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_ExclamationStart_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_EXCLAMATION_START_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_ExclamationStart[move_tile_index]].tile.tile_id, g_art[Symbol_ExclamationStart[move_tile_index]].tile.driver, g_art[Symbol_ExclamationStart[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_ExclamationEnd_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_EXCLAMATION_END_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_ExclamationEnd[move_tile_index]].tile.tile_id, g_art[Symbol_ExclamationEnd[move_tile_index]].tile.driver, g_art[Symbol_ExclamationEnd[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Number_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_NUMBER_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Number[move_tile_index]].tile.tile_id, g_art[Symbol_Number[move_tile_index]].tile.driver, g_art[Symbol_Number[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Arroba_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_ARROBA_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Arroba[move_tile_index]].tile.tile_id, g_art[Symbol_Arroba[move_tile_index]].tile.driver, g_art[Symbol_Arroba[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_UpArrow_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_UP_ARROW_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_UpArrow[move_tile_index]].tile.tile_id, g_art[Symbol_UpArrow[move_tile_index]].tile.driver, g_art[Symbol_UpArrow[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_DownArrow_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_DOWN_ARROW_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_DownArrow[move_tile_index]].tile.tile_id, g_art[Symbol_DownArrow[move_tile_index]].tile.driver, g_art[Symbol_DownArrow[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_RightArrow_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_RIGHT_ARROW_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_RightArrow[move_tile_index]].tile.tile_id, g_art[Symbol_RightArrow[move_tile_index]].tile.driver, g_art[Symbol_RightArrow[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_LeftArrow_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_LEFT_ARROW_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_LeftArrow[move_tile_index]].tile.tile_id, g_art[Symbol_LeftArrow[move_tile_index]].tile.driver, g_art[Symbol_LeftArrow[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Percentage_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_PERCENTAGE_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Percentage[move_tile_index]].tile.tile_id, g_art[Symbol_Percentage[move_tile_index]].tile.driver, g_art[Symbol_Percentage[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Division_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_DIVISION_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Division[move_tile_index]].tile.tile_id, g_art[Symbol_Division[move_tile_index]].tile.driver, g_art[Symbol_Division[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Multiplication_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_MULTIPLICATION_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Multiplication[move_tile_index]].tile.tile_id, g_art[Symbol_Multiplication[move_tile_index]].tile.driver, g_art[Symbol_Multiplication[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Add_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_ADD_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Add[move_tile_index]].tile.tile_id, g_art[Symbol_Add[move_tile_index]].tile.driver, g_art[Symbol_Add[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Substract_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_SUBSTRACT_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Substract[move_tile_index]].tile.tile_id, g_art[Symbol_Substract[move_tile_index]].tile.driver, g_art[Symbol_Substract[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Equals_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_EQUALS_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Equals[move_tile_index]].tile.tile_id, g_art[Symbol_Equals[move_tile_index]].tile.driver, g_art[Symbol_Equals[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_GreaterThan_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_GREATER_THAN_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_GreaterThan[move_tile_index]].tile.tile_id, g_art[Symbol_GreaterThan[move_tile_index]].tile.driver, g_art[Symbol_GreaterThan[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_LesserThan_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_LESSER_THAN_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_LesserThan[move_tile_index]].tile.tile_id, g_art[Symbol_LesserThan[move_tile_index]].tile.driver, g_art[Symbol_LesserThan[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Symbol_Wifi_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < SYMBOL_WIFI_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Symbol_Wifi[move_tile_index]].tile.tile_id, g_art[Symbol_Wifi[move_tile_index]].tile.driver, g_art[Symbol_Wifi[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


#endif
