/*
  Name:		  SOFIAletters.h
  Created:	06/03/2025 9:14:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con funciones para la creación de figuras letra. 
            Cada figura letra tiene un arreglo con los identificadores 
            de servomotores que se deben mover para crear la figura.
            Las funciones utilizan un ciclo 'for' para realizar los 
            movimientos de todo el contenido de los arreglos.
*/

#ifndef SOFIAletters_H
#define SOFIAletters_H

#include "SOFIAdatatypes.h"

// For identifying letter to execute
typedef enum
{
  letter_A,
  letter_B,
  letter_C,
  letter_D,
  letter_E,
  letter_F,
  letter_G,
  letter_H,
  letter_I,
  letter_J,
  letter_K,
  letter_L,
  letter_M,
  letter_N,
  letter_O,
  letter_P,
  letter_Q,
  letter_R,
  letter_S,
  letter_T,
  letter_U,
  letter_V,
  letter_W,
  letter_X,
  letter_Y,
  letter_Z,
} letters_t;


//////////////////////////////////////////////////////
////////////// Letter A move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_A_SIZE             83

// Array with the tiles to move for making Letter A
static const uint8_t Letter_A[LETTER_A_SIZE] = {
                                                22, 37, 52, 36, 51, 66, 38, 53, 68, 35, 39, 48, 49, 50, 54, 55, 56, 63, 64, 65, 69, 70, 71, 
                                                78, 79, 80, 84, 85, 86, 93, 94, 95, 99, 100, 101, 108, 109, 110, 114, 115, 116, 123, 124, 
                                                125, 129, 130, 131, 126, 112, 128, 141, 127, 143, 138, 139, 140, 144, 145, 146, 153, 154, 
                                                155, 159, 160, 161, 168, 169, 170, 174, 175, 176, 183, 184, 185, 189, 190, 191, 198, 199, 
                                                200, 204, 205, 206
                                                };


//////////////////////////////////////////////////////
////////////// Letter B move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_B_SIZE             77

// Array with the tiles to move for making Letter B
static const uint8_t Letter_B[LETTER_B_SIZE] = {
                                                47, 33, 34, 20, 62, 48, 49, 35, 36, 22, 77, 63, 51, 37, 38, 92, 78, 53, 39, 107, 93, 94, 54, 
                                                55, 122, 108, 109, 95, 96, 69, 70, 137, 123, 110, 111, 97, 98, 84, 85, 152, 138, 112, 113, 
                                                99, 167, 153, 114, 115, 182, 168, 130, 116, 183, 184, 170, 131, 132, 199, 185, 186, 172, 
                                                146, 147, 201, 187, 188, 174, 161, 162, 203, 189, 190, 176, 177, 205, 191, 192
                                                };


//////////////////////////////////////////////////////
////////////// Letter C move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_C_SIZE             51

// Array with the tiles to move for making Letter C
static const uint8_t Letter_C[LETTER_C_SIZE] = {
                                                22, 37, 36, 51, 38, 53, 35, 50, 39, 54, 55, 56, 70, 71, 85, 86, 48, 49, 63, 64, 78, 79, 93, 
                                                94, 108, 109, 123, 124, 138, 139, 153, 154, 168, 169, 184, 170, 185, 186, 201, 187, 202, 
                                                188, 203, 174, 189, 160, 146, 175, 161, 190, 176
                                                };


//////////////////////////////////////////////////////
////////////// Letter D move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_D_SIZE             80

// Array with the tiles to move for making Letter D
static const uint8_t Letter_D[LETTER_D_SIZE] = {
                                                20, 35, 36, 51, 22, 37, 38, 53, 39, 54, 55, 70, 56, 32, 18, 34, 47, 33, 49, 62, 48, 64, 77, 
                                                63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 123, 139, 152, 138, 154, 167, 153, 
                                                169, 182, 168, 184, 197,183, 199, 212, 198, 214, 71, 72, 86, 87, 101, 102, 116, 117, 
                                                131, 132, 146, 147, 162, 177, 185, 200, 161, 176, 201, 216, 175, 190, 187, 202, 174, 
                                                189, 188, 203
                                                };


//////////////////////////////////////////////////////
////////////// Letter E move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_E_SIZE             88

// Array with the tiles to move for making Letter E
static const uint8_t Letter_E[LETTER_E_SIZE] = {
                                                20, 35, 50, 36, 51, 22, 37, 52, 38, 53, 24, 39, 54, 40, 55, 26, 41, 56, 95, 110, 125, 111, 126, 
                                                141, 97, 112, 127, 113, 128, 143, 99, 114, 129, 170, 185, 200, 186, 201, 172, 187, 202, 188, 
                                                203, 174, 189, 204, 190, 205, 176, 191, 206, 32, 18, 34, 47, 33, 49, 62, 48, 64, 77, 63, 
                                                79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 123, 139, 152, 138, 154, 167, 153, 
                                                169, 182, 168, 184, 197, 183, 199, 198
                                                };


//////////////////////////////////////////////////////
////////////// Letter F move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_F_SIZE             77

// Array with the tiles to move for making Letter F
static const uint8_t Letter_F[LETTER_F_SIZE] = {
                                                20, 35, 50, 36, 51, 22, 37, 52, 38, 53, 24, 39, 54, 40, 55, 26, 41, 56, 42, 47, 95, 110, 125, 
                                                111, 126, 141, 97, 112, 127, 113, 128, 143, 99, 114, 129, 115, 130, 145, 32, 18, 34, 47, 33, 
                                                49, 62, 48, 64, 77, 63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 123, 139, 152, 
                                                138, 154, 167, 153, 169, 182, 168, 184, 197, 183, 199, 212, 198, 214
                                                };


//////////////////////////////////////////////////////
////////////// Letter G move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_G_SIZE             60

// Array with the tiles to move for making Letter G
static const uint8_t Letter_G[LETTER_G_SIZE] = {
                                                22, 37, 36, 51, 38, 53, 35, 50, 39, 54, 55, 56, 70, 71, 85, 86, 48, 49, 63, 64, 78, 79, 93, 94, 
                                                108, 109, 123, 124, 138, 139, 153, 154, 168, 169, 184, 170, 185, 186, 201, 187, 202, 188, 203, 
                                                174, 189, 160, 146, 175, 161, 190, 176, 145, 131, 130, 129, 144, 128, 143, 127, 142
                                                };


//////////////////////////////////////////////////////
////////////// Letter H move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_H_SIZE             95

// Array with the tiles to move for making Letter H
static const uint8_t Letter_H[LETTER_H_SIZE] = {
                                                17, 18, 19, 25, 26, 27, 32, 33, 34, 40, 41, 42, 47, 48, 49, 55, 56, 57, 62, 63, 64, 70, 71, 72, 
                                                77, 78, 79, 85, 86, 87, 92, 93, 94, 100, 101, 102, 107, 108, 109, 115, 116, 117, 122, 123, 124, 
                                                130, 131, 132, 137, 138, 139, 145, 146, 147, 152, 153, 154, 160, 161, 162, 167, 168, 169, 175, 
                                                176, 177, 182, 183, 184, 190, 191, 192, 197, 198, 199, 205, 206, 207, 212, 214, 220, 222, 95, 
                                                110, 125, 99, 114, 129, 111, 126, 113, 128, 97, 112, 127
                                                };


//////////////////////////////////////////////////////
////////////// Letter I move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_I_SIZE             73

// Array with the tiles to move for making Letter I
static const uint8_t Letter_I[LETTER_I_SIZE] = {
                                                17, 32, 27, 42, 18, 33, 26, 41, 19, 34, 25, 40, 20, 35, 24, 39, 197, 212, 207, 222, 183, 198, 
                                                191, 206, 199, 214, 205, 220, 185, 200, 189, 204, 21, 23, 36, 22, 38, 51, 37, 53, 66, 52, 68, 
                                                81, 67, 83, 96, 82, 98, 111, 97, 113, 126, 112, 128, 141, 127, 143, 156, 142, 158, 171, 157, 
                                                173, 186, 172, 188, 201, 187, 203, 216, 202, 218
                                                };


//////////////////////////////////////////////////////
////////////// Letter J move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_J_SIZE             71

// Array with the tiles to move for making Letter J
static const uint8_t Letter_J[LETTER_J_SIZE] = {
                                                20, 36, 22, 38, 24, 40, 26, 42, 28, 35, 51, 37, 53, 39, 55, 41, 57, 43, 68, 54, 70, 83, 69, 85, 
                                                98, 84, 100, 113, 99, 115, 128, 114, 130, 143, 129, 145, 158, 144, 160, 173, 159, 175, 188, 
                                                174, 190, 189, 203, 187, 202, 186, 201, 170, 185, 184, 168, 169, 153, 154, 138, 139, 121, 
                                                136, 122, 137, 108, 123, 109, 124, 95, 110, 111
                                                };


//////////////////////////////////////////////////////
////////////// Letter K move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_K_SIZE             79

// Array with the tiles to move for making Letter K
static const uint8_t Letter_K[LETTER_K_SIZE] = {
                                                32, 34, 47, 33, 49, 62, 48, 64, 77, 63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 123, 
                                                139, 152, 138, 154, 167, 153, 169, 182, 168, 184, 197, 183, 199, 80, 95, 110, 125, 140, 155, 
                                                81, 96, 111, 126, 141, 156, 171, 67, 82, 97, 142, 157, 172, 68, 83, 98, 158, 173, 188, 54, 
                                                69, 84, 159, 174, 189, 55, 70, 85, 175, 190, 205, 41, 56, 71, 176, 191, 57, 72
                                                };


//////////////////////////////////////////////////////
////////////// Letter L move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_L_SIZE             57

// Array with the tiles to move for making Letter L
static const uint8_t Letter_L[LETTER_L_SIZE] = {
                                                32, 18, 34, 47, 33, 49, 62, 48, 64, 77, 63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 
                                                123, 139, 152, 138, 154, 167, 153, 169, 182, 168, 184, 197, 183, 199, 198, 170, 185, 200, 
                                                186, 201, 172, 187, 202, 188, 203, 174, 189, 204, 190, 205, 176, 191, 206, 192, 207
                                                };


//////////////////////////////////////////////////////
////////////// Letter M move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_M_SIZE             107

// Array with the tiles to move for making Letter M
static const uint8_t Letter_M[LETTER_M_SIZE] = {
                                                16, 31, 46, 61, 76, 91, 106, 121, 136, 151, 166, 181, 196, 28, 43, 58, 73, 88, 103, 118, 133, 
                                                148, 163, 178, 193, 208, 32, 47, 62, 77, 92, 107, 122, 137, 152, 167, 182, 197, 212, 42, 57, 
                                                72, 87, 102, 117, 132, 147, 162, 177, 192, 207, 222, 33, 48, 63, 78, 93, 108, 123, 138, 153, 
                                                168, 183, 198, 41, 56, 71, 86, 101, 116, 131, 146, 161, 176, 191, 206, 49, 64, 79, 94, 55, 
                                                70, 85, 100, 50, 65, 80, 95, 54, 69, 84, 99, 66, 81, 96, 111, 126, 68, 83, 98, 113, 128, 
                                                67, 82, 97, 112, 127
                                                };


//////////////////////////////////////////////////////
////////////// Letter N move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_N_SIZE             111

// Array with the tiles to move for making Letter N
static const uint8_t Letter_N[LETTER_N_SIZE] = {
                                                16, 17, 18, 31, 32, 33, 46, 47, 48, 61, 62, 63, 76, 77, 78, 91, 92, 93, 106, 107, 108, 121, 122, 
                                                123, 136, 137, 138, 151, 152, 153, 166, 167, 168, 181, 182, 183, 196, 197, 198, 212, 26, 27, 
                                                28, 41, 42, 43, 56, 57, 58, 71, 72, 73, 86, 87, 88, 101, 102, 103, 116, 117, 118, 131, 132, 
                                                133, 146, 147, 148, 161, 162, 163, 176, 177, 178, 191, 192, 193, 206, 207, 208, 222, 34, 
                                                49, 64, 79, 160, 175, 190, 205, 50, 65, 80, 95, 129, 144, 159, 174, 66, 81, 96, 111, 
                                                126, 113, 128, 143, 158, 173, 82, 97, 112, 127, 142
                                                };


//////////////////////////////////////////////////////
////////////// Letter O move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_O_SIZE             62

// Array with the tiles to move for making Letter O
static const uint8_t Letter_O[LETTER_O_SIZE] = {
                                                22, 37, 36, 51, 38, 53, 35, 50, 39, 54, 49, 64, 55, 70, 62, 48, 56, 72, 77, 63, 71, 87, 92, 78, 
                                                86, 102, 107, 93, 101, 117, 122, 108, 116, 132, 137, 123, 131, 147, 152, 138, 146, 162, 167, 
                                                153, 168, 161, 177, 176, 169, 184, 175, 190, 170, 185, 174, 189, 186, 201, 188, 203, 187, 202
                                                };


//////////////////////////////////////////////////////
////////////// Letter P move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_P_SIZE             71

// Array with the tiles to move for making Letter P
static const uint8_t Letter_P[LETTER_P_SIZE] = {
                                                32, 18, 34, 47, 33, 49, 62, 48, 64, 77, 63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 
                                                123, 139, 152, 138, 154, 167, 153, 169, 182, 168, 184, 197, 183, 199, 20, 35, 95, 110, 36, 
                                                51, 111, 126, 22, 37, 97, 112, 38, 53, 113, 128, 39, 54, 99, 114, 40, 55, 115, 130, 41, 
                                                56, 57, 72, 71, 86, 87, 102, 101, 116, 117
                                                };


//////////////////////////////////////////////////////
////////////// Letter Q move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_Q_SIZE             74

// Array with the tiles to move for making Letter Q
static const uint8_t Letter_Q[LETTER_Q_SIZE] = {
                                                22, 37, 36, 51, 38, 53, 35, 50, 39, 54, 49, 64, 55, 70, 62, 48, 56, 72, 77, 63, 71, 87, 92, 78, 
                                                86, 102, 107, 93, 101, 117, 122, 108, 116, 132, 137, 123, 131, 147, 152, 138, 146, 162, 167, 
                                                153, 168, 161, 177, 176, 169, 184, 175, 190, 170, 185, 174, 189, 186, 201, 188, 203, 187, 
                                                202, 172, 216, 217, 218, 233, 219, 220, 206, 207, 235, 221, 222
                                                };


//////////////////////////////////////////////////////
////////////// Letter R move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_R_SIZE             89

// Array with the tiles to move for making Letter R
static const uint8_t Letter_R[LETTER_R_SIZE] = {
                                                32, 18, 34, 47, 33, 49, 62, 48, 64, 77, 63, 79, 92, 78, 94, 107, 93, 109, 122, 108, 124, 137, 123, 
                                                139, 152, 138, 154, 167, 153, 169, 182, 168, 184, 197, 183, 199, 212, 198, 214, 20, 35, 110, 125, 
                                                36, 51, 126, 141, 22, 37, 112, 127, 142, 38, 53, 128, 143, 158, 24, 39, 114, 129, 144, 159, 174, 
                                                40, 55, 115, 130, 160, 175, 190, 205, 220, 41, 56, 71, 86, 101, 116, 176, 191, 206, 57, 72, 87, 
                                                102, 117, 207, 222
                                                };


//////////////////////////////////////////////////////
////////////// Letter S move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_S_SIZE             71

// Array with the tiles to move for making Letter S
static const uint8_t Letter_S[LETTER_S_SIZE] = {
                                                72, 87, 56, 71, 55, 70, 39, 54, 38, 53, 22, 37, 36, 51, 35, 50, 49, 62, 77, 92, 48, 63, 78, 93, 
                                                64, 79, 94, 109, 80, 95, 110, 96, 111, 126, 97, 112, 127, 113, 128, 143, 114, 129, 144, 130, 
                                                145, 160, 175, 131, 146, 161, 176, 147, 162, 177, 190, 174, 189, 188, 203, 187, 202, 186, 
                                                201, 170, 185, 169, 184, 153, 168, 152, 167
                                                };


//////////////////////////////////////////////////////
////////////// Letter T move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_T_SIZE             69

// Array with the tiles to move for making Letter T
static const uint8_t Letter_T[LETTER_T_SIZE] = {
                                                16, 31, 46, 32, 47, 62, 18, 33, 48, 34, 49, 64, 20, 35, 50, 28, 43, 58, 42, 57, 72, 26, 41, 56, 
                                                40, 55, 70, 24, 39, 54, 36, 22, 38, 51, 37, 53, 66, 52, 68, 81, 67, 83, 96, 82, 98, 111, 97, 
                                                113, 126, 112, 128, 141, 127, 143, 156, 142, 158, 171, 157, 173, 186, 172, 188, 201, 187, 
                                                203, 216, 202, 218
                                                };


//////////////////////////////////////////////////////
////////////// Letter U move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_U_SIZE             82

// Array with the tiles to move for making Letter U
static const uint8_t Letter_U[LETTER_U_SIZE] = {
                                                32, 47, 62, 77, 92, 107, 122, 137, 152, 167, 182, 42, 57, 72, 87, 102, 117, 132, 147, 162, 177, 192, 
                                                33, 48, 63, 78, 93, 108, 123, 138, 153, 168, 183, 41, 56, 71, 86, 101, 116, 131, 146, 161, 176, 
                                                191, 34, 49, 64, 79, 94, 109, 124, 139, 154, 169, 184, 199, 40, 55, 70, 85, 100, 115, 130, 145, 
                                                160, 175, 190, 205, 170, 185, 200, 174, 189, 204, 186, 201, 216, 188, 203, 218, 187, 202
                                                };


//////////////////////////////////////////////////////
////////////// Letter V move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_V_SIZE             76

// Array with the tiles to move for making Letter V
static const uint8_t Letter_V[LETTER_V_SIZE] = {
                                                16, 31, 46, 61, 76, 91, 106, 121, 28, 43, 58, 73, 88, 103, 118, 133, 32, 47, 62, 77, 92, 107, 122, 
                                                137, 152, 42, 57, 72, 87, 102, 117, 32, 147, 162, 78, 93, 108, 123, 138, 153, 86, 101, 116, 131, 
                                                146, 161, 109, 124, 139, 154, 169, 115, 130, 145, 160, 175, 125, 140, 155, 170, 129, 144, 159, 
                                                174, 141, 156, 171, 186, 143, 158, 173, 188, 142, 157, 172, 187
                                                };


//////////////////////////////////////////////////////
////////////// Letter W move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_W_SIZE             111

// Array with the tiles to move for making Letter W
static const uint8_t Letter_W[LETTER_W_SIZE] = {
                                                16, 31, 46, 61, 76, 91, 106, 121, 136, 151, 166, 181, 196, 28, 43, 58, 73, 88, 103, 118, 133, 148,
                                                163, 178, 193, 208, 17, 32, 47, 62, 77, 92, 107, 122, 137, 152, 167, 182, 197, 212, 27, 42, 57, 
                                                72, 87, 102, 117, 132, 147, 162, 177, 192, 207, 222, 18, 33, 48, 63, 78, 93, 108, 123, 138, 
                                                153, 168, 183, 198, 26, 41, 56, 71, 86, 101, 116, 131, 146, 161, 176, 191, 206, 154, 169, 
                                                184, 199, 160, 175, 190, 205, 140, 155, 170, 185, 144, 159, 174, 189, 126, 141, 156, 
                                                171, 186, 128, 143, 158, 173, 188, 112, 127, 142, 157, 172
                                                };


//////////////////////////////////////////////////////
////////////// Letter X move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_X_SIZE             80

// Array with the tiles to move for making Letter X
static const uint8_t Letter_X[LETTER_X_SIZE] = {
                                                18, 33, 48, 63, 78, 138, 153, 168, 183, 198, 26, 41, 56, 71, 86, 146, 161, 176, 191, 206, 19, 34, 
                                                49, 64, 79, 94, 109, 139, 154, 169, 184, 199, 214, 25, 40, 55, 70, 85, 100, 115, 145, 160, 175, 
                                                190, 205, 220, 20, 35, 50, 65, 80, 95, 110, 125, 140, 155, 170, 185, 200, 24, 39, 54, 69, 84, 
                                                99, 114, 129, 144, 159, 174, 189, 204, 111, 126, 141, 113, 128, 143, 112, 127
                                                };


//////////////////////////////////////////////////////
////////////// Letter Y move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_Y_SIZE             69

// Array with the tiles to move for making Letter Y
static const uint8_t Letter_Y[LETTER_Y_SIZE] = {
                                                16, 31, 46, 61, 76, 91, 28, 43, 58, 73, 88, 103, 17, 32, 47, 62, 77, 92, 107, 27, 42, 57, 72, 87, 
                                                102, 117, 18, 33, 48, 63, 78, 93, 108, 26, 41, 56, 71, 86, 101, 116, 109, 124, 115, 130, 110, 
                                                125, 114, 129, 126, 127, 128, 141, 142, 143, 156, 157, 158, 171, 172, 173, 186, 187, 188, 
                                                201, 202, 203, 216, 217, 218
                                                };


//////////////////////////////////////////////////////
////////////// Letter Z move tiles data //////////////
//////////////////////////////////////////////////////

#define LETTER_Z_SIZE             105

// Array with the tiles to move for making Letter Z
static const uint8_t Letter_Z[LETTER_Z_SIZE] = {
                                                16, 31, 17, 32, 47, 18, 33, 19, 34, 49, 20, 35, 21, 36, 51, 22, 37, 23, 38, 53, 24, 39, 25, 40, 55, 26, 
                                                41, 27, 42, 57, 28, 43, 56, 72, 58, 71, 87, 73, 86, 102, 88, 101, 85, 100, 115, 84, 99, 114, 98, 113, 
                                                128, 97, 112, 127, 111, 126, 141, 110, 125, 140, 124, 139, 154, 123, 136, 137, 138, 151, 152, 153, 
                                                166, 167, 168, 181, 182, 183, 196, 197, 198, 212, 184, 199, 214, 185, 200, 186, 201, 216, 187, 
                                                202, 188, 203, 218, 189, 204, 190, 205, 220, 191, 206, 192, 207, 222, 193, 208
                                                };


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void LetterExecute(letters_t letter, uint16_t delay_in_ms, uint8_t degree);
void Letter_A_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_B_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_C_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_D_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_E_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_F_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_G_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_H_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_I_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_J_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_K_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_L_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_M_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_N_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_O_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_P_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_Q_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_R_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_S_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_T_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_U_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_V_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_W_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_X_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_Y_Shape(uint16_t delay_in_ms, uint8_t degree);
void Letter_Z_Shape(uint16_t delay_in_ms, uint8_t degree);


/////////////////////////////////////////
//// Functions for making the shapes ////
/////////////////////////////////////////

void LetterExecute(letters_t letter, uint16_t delay_in_ms, uint8_t degree)
{ // Select the letter to display, amount of time in which the shape will be displayed and degree at which tiles will be moved
  if(letter_A == letter)
    Letter_A_Shape(delay_in_ms, degree);
  else if(letter_B == letter)
    Letter_B_Shape(delay_in_ms, degree);
  else if(letter_C == letter)
    Letter_C_Shape(delay_in_ms, degree);
  else if(letter_D == letter)
    Letter_D_Shape(delay_in_ms, degree);
  else if(letter_E == letter)
    Letter_E_Shape(delay_in_ms, degree);
  else if(letter_F == letter)
    Letter_F_Shape(delay_in_ms, degree);
  else if(letter_G == letter)
    Letter_G_Shape(delay_in_ms, degree);
  else if(letter_H == letter)
    Letter_H_Shape(delay_in_ms, degree);
  else if(letter_I == letter)
    Letter_I_Shape(delay_in_ms, degree);
  else if(letter_J == letter)
    Letter_J_Shape(delay_in_ms, degree);
  else if(letter_K == letter)
    Letter_K_Shape(delay_in_ms, degree);
  else if(letter_L == letter)
    Letter_L_Shape(delay_in_ms, degree);
  else if(letter_M == letter)
    Letter_M_Shape(delay_in_ms, degree);
  else if(letter_N == letter)
    Letter_N_Shape(delay_in_ms, degree);
  else if(letter_O == letter)
    Letter_O_Shape(delay_in_ms, degree);
  else if(letter_P == letter)
    Letter_P_Shape(delay_in_ms, degree);
  else if(letter_Q == letter)
    Letter_Q_Shape(delay_in_ms, degree);
  else if(letter_R == letter)
    Letter_R_Shape(delay_in_ms, degree);
  else if(letter_S == letter)
    Letter_S_Shape(delay_in_ms, degree);
  else if(letter_T == letter)
    Letter_T_Shape(delay_in_ms, degree);
  else if(letter_U == letter)
    Letter_U_Shape(delay_in_ms, degree);
  else if(letter_V == letter)
    Letter_V_Shape(delay_in_ms, degree);
  else if(letter_W == letter)
    Letter_W_Shape(delay_in_ms, degree);
  else if(letter_X == letter)
    Letter_X_Shape(delay_in_ms, degree);
  else if(letter_Y == letter)
    Letter_Y_Shape(delay_in_ms, degree);
  else if(letter_Z == letter)
    Letter_Z_Shape(delay_in_ms, degree);
  else
    ;
}

void Letter_A_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_A_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_A[move_tile_index]].tile.tile_id, g_art[Letter_A[move_tile_index]].tile.driver, g_art[Letter_A[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_B_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_B_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_B[move_tile_index]].tile.tile_id, g_art[Letter_B[move_tile_index]].tile.driver, g_art[Letter_B[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_C_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_C_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_C[move_tile_index]].tile.tile_id, g_art[Letter_C[move_tile_index]].tile.driver, g_art[Letter_C[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_D_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_D_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_D[move_tile_index]].tile.tile_id, g_art[Letter_D[move_tile_index]].tile.driver, g_art[Letter_D[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_E_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_E_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_E[move_tile_index]].tile.tile_id, g_art[Letter_E[move_tile_index]].tile.driver, g_art[Letter_E[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_F_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_F_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_F[move_tile_index]].tile.tile_id, g_art[Letter_F[move_tile_index]].tile.driver, g_art[Letter_F[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_G_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_G_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_G[move_tile_index]].tile.tile_id, g_art[Letter_G[move_tile_index]].tile.driver, g_art[Letter_G[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_H_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_H_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_H[move_tile_index]].tile.tile_id, g_art[Letter_H[move_tile_index]].tile.driver, g_art[Letter_H[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_I_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_I_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_I[move_tile_index]].tile.tile_id, g_art[Letter_I[move_tile_index]].tile.driver, g_art[Letter_I[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_J_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_J_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_J[move_tile_index]].tile.tile_id, g_art[Letter_J[move_tile_index]].tile.driver, g_art[Letter_J[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_K_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_K_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_K[move_tile_index]].tile.tile_id, g_art[Letter_K[move_tile_index]].tile.driver, g_art[Letter_K[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_L_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_L_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_L[move_tile_index]].tile.tile_id, g_art[Letter_L[move_tile_index]].tile.driver, g_art[Letter_L[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_M_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_M_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_M[move_tile_index]].tile.tile_id, g_art[Letter_M[move_tile_index]].tile.driver, g_art[Letter_M[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_N_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_N_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_N[move_tile_index]].tile.tile_id, g_art[Letter_N[move_tile_index]].tile.driver, g_art[Letter_N[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_O_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_O_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_O[move_tile_index]].tile.tile_id, g_art[Letter_O[move_tile_index]].tile.driver, g_art[Letter_O[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_P_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_P_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_P[move_tile_index]].tile.tile_id, g_art[Letter_P[move_tile_index]].tile.driver, g_art[Letter_P[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_Q_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_Q_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_Q[move_tile_index]].tile.tile_id, g_art[Letter_Q[move_tile_index]].tile.driver, g_art[Letter_Q[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_R_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_R_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_R[move_tile_index]].tile.tile_id, g_art[Letter_R[move_tile_index]].tile.driver, g_art[Letter_R[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_S_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_S_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_S[move_tile_index]].tile.tile_id, g_art[Letter_S[move_tile_index]].tile.driver, g_art[Letter_S[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_T_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_T_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_T[move_tile_index]].tile.tile_id, g_art[Letter_T[move_tile_index]].tile.driver, g_art[Letter_T[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_U_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_U_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_U[move_tile_index]].tile.tile_id, g_art[Letter_U[move_tile_index]].tile.driver, g_art[Letter_U[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_V_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_V_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_V[move_tile_index]].tile.tile_id, g_art[Letter_V[move_tile_index]].tile.driver, g_art[Letter_V[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_W_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_W_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_W[move_tile_index]].tile.tile_id, g_art[Letter_W[move_tile_index]].tile.driver, g_art[Letter_W[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_X_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_X_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_X[move_tile_index]].tile.tile_id, g_art[Letter_X[move_tile_index]].tile.driver, g_art[Letter_X[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_Y_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_Y_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_Y[move_tile_index]].tile.tile_id, g_art[Letter_Y[move_tile_index]].tile.driver, g_art[Letter_Y[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}

void Letter_Z_Shape(uint16_t delay_in_ms, uint8_t degree)
{
  static uint16_t move_tile_index = 0;
  
  move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < LETTER_Z_SIZE; move_tile_index++)
  {
    PCA_ServoMove(g_art[Letter_Z[move_tile_index]].tile.tile_id, g_art[Letter_Z[move_tile_index]].tile.driver, g_art[Letter_Z[move_tile_index]].tile.channel, degree);
  }

  delay(delay_in_ms);
  ResetTiles();               // Make every tile return to MID_DEGREE
}


#endif
