/*
  Name:		  SOFIAdatatypes.h
  Created:	07/02/2025 19:20:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo donde se declaran los tipos de dato y estructuras
            para el manejo de los canales PWM de drivers PCA9685.
*/

#ifndef SOFIAdatatypes_H
#define SOFIAdatatypes_H

#include <Adafruit_PWMServoDriver.h>

// Degree settings for servos
#define DEGREE_STEPS      30    // Allow movement of servos by steps of 30 degrees
#define MID_DEGREE        90
#define MIN_DEGREE        MID_DEGREE - DEGREE_STEPS
#define MAX_DEGREE        MID_DEGREE + DEGREE_STEPS
#define DEGREE_TOLERANCE  10    // Degree tolerance when attempting to move at higher or lower than MAX_DEGREE or MIN_DEGREE respectively

// Values of PWM duty cycle for PCA9685 drivers
#define DEGREE_0_DC          95
#define DEGREE_90_DC         185
#define DEGREE_180_DC        275

// Number of rows and columns in the structure
#define N_ROWS              16
#define N_COLUMNS           15

// Number of drivers and channels each ESP controls
#define NO_ID               255   // ID of tile for indicating no connection
#define N_DRIVERS_ESP       4
#define N_CHANNELS_DRIVER   16
#define TILES_PER_ESP       N_DRIVERS_ESP * N_CHANNELS_DRIVER

// Addresses for PCA9685
#define PCA9685_0         0x40
#define PCA9685_1         0x41
#define PCA9685_2         0x42
#define PCA9685_3         0x43
#define PCA9685_4         0x44
#define PCA9685_5         0x45
#define PCA9685_6         0x46
#define PCA9685_7         0x47
#define PCA9685_8         0x48
#define PCA9685_9         0x49
#define PCA9685_10        0x4A
#define PCA9685_11        0x4B
#define PCA9685_12        0x4C
#define PCA9685_13        0x4D
#define PCA9685_14        0x4E
#define PCA9685_15        0x4F

// Frequency to set PWMs
#define PWM_FREQUENCY     50

// Value to activate channel of driver
#define CHANNEL_ON        0


/////////////////////////////////////////////
/////// Creation of data types to use ///////
/////////////////////////////////////////////

// This system has only 16 drivers PCA9685
typedef enum
{
  driver_0,
  driver_1,
  driver_2,
  driver_3,
  driver_4,
  driver_5,
  driver_6,
  driver_7,
  driver_8,
  driver_9,
  driver_10,
  driver_11,
  driver_12,
  driver_13,
  driver_14,
  driver_15,
} drivers_t;

// Every driver has only 16 channels
typedef enum
{
  channel_0,
  channel_1,
  channel_2,
  channel_3,
  channel_4,
  channel_5,
  channel_6,
  channel_7,
  channel_8,
  channel_9,
  channel_10,
  channel_11,
  channel_12,
  channel_13,
  channel_14,
  channel_15
} channels_t;

// Type for identifying column of system
typedef enum
{
  column_0,
  column_1,
  column_2,
  column_3,
  column_4,
  column_5,
  column_6,
  column_7,
  column_8,
  column_9,
  column_10,
  column_11,
  column_12,
  column_13,
  column_14,
} columns_t;

// Type for identifying row of system
typedef enum
{
  row_0,
  row_1,
  row_2,
  row_3,
  row_4,
  row_5,
  row_6,
  row_7,
  row_8,
  row_9,
  row_10,
  row_11,
  row_12,
  row_13,
  row_14,
  row_15,
} rows_t;

// Every driver needs to be declared as found or not found
typedef struct
{
  bool driver_0_found : 1;
  bool driver_1_found : 1;
  bool driver_2_found : 1;
  bool driver_3_found : 1;
  bool driver_4_found : 1;
  bool driver_5_found : 1;
  bool driver_6_found : 1;
  bool driver_7_found : 1;
  bool driver_8_found : 1;
  bool driver_9_found : 1;
  bool driver_10_found : 1;
  bool driver_11_found : 1;
  bool driver_12_found : 1;
  bool driver_13_found : 1;
  bool driver_14_found : 1;
  bool driver_15_found : 1;
} driver_found_t;

// Every tile of the piece has an id and is controlled by a specific driver and a specific channel
typedef struct
{
  uint8_t tile_id;
  drivers_t driver;
  channels_t channel;
} tile_t;

// The system is conformed by tiles which are given an id and are tied to a specific driver and a specific channel
typedef struct
{
  tile_t tile;
} art_t;


////////////////////////////////////////////
///// Initialization of global objects /////
////////////////////////////////////////////

// Create an object for every PCA9685
Adafruit_PWMServoDriver pca9685_0 = Adafruit_PWMServoDriver(PCA9685_0);
Adafruit_PWMServoDriver pca9685_1 = Adafruit_PWMServoDriver(PCA9685_1);
Adafruit_PWMServoDriver pca9685_2 = Adafruit_PWMServoDriver(PCA9685_2);
Adafruit_PWMServoDriver pca9685_3 = Adafruit_PWMServoDriver(PCA9685_3);
Adafruit_PWMServoDriver pca9685_4 = Adafruit_PWMServoDriver(PCA9685_4);
Adafruit_PWMServoDriver pca9685_5 = Adafruit_PWMServoDriver(PCA9685_5);
Adafruit_PWMServoDriver pca9685_6 = Adafruit_PWMServoDriver(PCA9685_6);
Adafruit_PWMServoDriver pca9685_7 = Adafruit_PWMServoDriver(PCA9685_7);
Adafruit_PWMServoDriver pca9685_8 = Adafruit_PWMServoDriver(PCA9685_8);
Adafruit_PWMServoDriver pca9685_9 = Adafruit_PWMServoDriver(PCA9685_9);
Adafruit_PWMServoDriver pca9685_10 = Adafruit_PWMServoDriver(PCA9685_10);
Adafruit_PWMServoDriver pca9685_11 = Adafruit_PWMServoDriver(PCA9685_11);
Adafruit_PWMServoDriver pca9685_12 = Adafruit_PWMServoDriver(PCA9685_12);
Adafruit_PWMServoDriver pca9685_13 = Adafruit_PWMServoDriver(PCA9685_13);
Adafruit_PWMServoDriver pca9685_14 = Adafruit_PWMServoDriver(PCA9685_14);
Adafruit_PWMServoDriver pca9685_15 = Adafruit_PWMServoDriver(PCA9685_15);


////////////////////////////////////////////////////////////////////////////
//// Mapping of drivers and their channel to specific tile of structure ////
////////////////////////////////////////////////////////////////////////////

// Array with all tiles that make the system
static art_t g_art[N_ROWS*N_COLUMNS] = {
                                       {{0, driver_0, channel_0}}, {{1, driver_0, channel_1}}, {{2, driver_0, channel_2}}, {{3, driver_0, channel_3}}, {{4, driver_1, channel_0}}, {{5, driver_1, channel_1}}, {{6, driver_1, channel_2}}, {{7, driver_1, channel_3}}, {{8, driver_2, channel_0}}, {{9, driver_2, channel_1}}, {{10, driver_2, channel_2}}, {{11, driver_2, channel_3}}, {{12, driver_3, channel_0}}, {{13, driver_3, channel_1}}, {{14, driver_3, channel_2}},
                                       {{15, driver_0, channel_4}}, {{16, driver_0, channel_5}}, {{17, driver_0, channel_6}}, {{18, driver_0, channel_7}}, {{19, driver_1, channel_4}}, {{20, driver_1, channel_5}}, {{21, driver_1, channel_6}}, {{22, driver_1, channel_7}}, {{23, driver_2, channel_4}}, {{24, driver_2, channel_5}}, {{25, driver_2, channel_6}}, {{26, driver_2, channel_7}}, {{27, driver_3, channel_4}}, {{28, driver_3, channel_5}}, {{29, driver_3, channel_6}},
                                       {{30, driver_0, channel_8}}, {{31, driver_0, channel_9}}, {{32, driver_0, channel_10}}, {{33, driver_0, channel_11}}, {{34, driver_1, channel_8}}, {{35, driver_1, channel_9}}, {{36, driver_1, channel_10}}, {{37, driver_1, channel_11}}, {{38, driver_2, channel_8}}, {{39, driver_2, channel_9}}, {{40, driver_2, channel_10}}, {{41, driver_2, channel_11}}, {{42, driver_3, channel_8}}, {{43, driver_3, channel_9}}, {{44, driver_3, channel_10}},
                                       {{45, driver_0, channel_12}}, {{46, driver_0, channel_13}}, {{47, driver_0, channel_14}}, {{48, driver_0, channel_15}}, {{49, driver_1, channel_12}}, {{50, driver_1, channel_13}}, {{51, driver_1, channel_14}}, {{52, driver_1, channel_15}}, {{53, driver_2, channel_12}}, {{54, driver_2, channel_13}}, {{55, driver_2, channel_14}}, {{56, driver_2, channel_15}}, {{57, driver_3, channel_12}}, {{58, driver_3, channel_13}}, {{59, driver_3, channel_14}},
                                       {{60, driver_4, channel_0}}, {{61, driver_4, channel_1}}, {{62, driver_4, channel_2}}, {{63, driver_4, channel_3}}, {{64, driver_5, channel_0}}, {{65, driver_5, channel_1}}, {{66, driver_5, channel_2}}, {{67, driver_5, channel_3}}, {{68, driver_6, channel_0}}, {{69, driver_6, channel_1}}, {{70, driver_6, channel_2}}, {{71, driver_6, channel_3}}, {{72, driver_7, channel_0}}, {{73, driver_7, channel_1}}, {{74, driver_7, channel_2}},
                                       {{75, driver_4, channel_4}}, {{76, driver_4, channel_5}}, {{77, driver_4, channel_6}}, {{78, driver_4, channel_7}}, {{79, driver_5, channel_4}}, {{80, driver_5, channel_5}}, {{81, driver_5, channel_6}}, {{82, driver_5, channel_7}}, {{83, driver_6, channel_4}}, {{84, driver_6, channel_5}}, {{85, driver_6, channel_6}}, {{86, driver_6, channel_7}}, {{87, driver_7, channel_4}}, {{88, driver_7, channel_5}}, {{89, driver_7, channel_6}},
                                       {{90, driver_4, channel_8}}, {{91, driver_4, channel_9}}, {{92, driver_4, channel_10}}, {{93, driver_4, channel_11}}, {{94, driver_5, channel_8}}, {{95, driver_5, channel_9}}, {{96, driver_5, channel_10}}, {{97, driver_5, channel_11}}, {{98, driver_6, channel_8}}, {{99, driver_6, channel_9}}, {{100, driver_6, channel_10}}, {{101, driver_6, channel_11}}, {{102, driver_7, channel_8}}, {{103, driver_7, channel_9}}, {{104, driver_7, channel_10}},
                                       {{105, driver_4, channel_12}}, {{106, driver_4, channel_13}}, {{107, driver_4, channel_14}}, {{108, driver_4, channel_15}}, {{109, driver_5, channel_12}}, {{110, driver_5, channel_13}}, {{111, driver_5, channel_14}}, {{112, driver_5, channel_15}}, {{113, driver_6, channel_12}}, {{114, driver_6, channel_13}}, {{115, driver_6, channel_14}}, {{116, driver_6, channel_15}}, {{117, driver_7, channel_12}}, {{118, driver_7, channel_13}}, {{119, driver_7, channel_14}},
                                       {{120, driver_8, channel_0}}, {{121, driver_8, channel_1}}, {{122, driver_8, channel_2}}, {{123, driver_8, channel_3}}, {{124, driver_9, channel_0}}, {{125, driver_9, channel_1}}, {{126, driver_9, channel_2}}, {{127, driver_9, channel_3}}, {{128, driver_10, channel_0}}, {{129, driver_10, channel_1}}, {{130, driver_10, channel_2}}, {{131, driver_10, channel_3}}, {{132, driver_11, channel_0}}, {{133, driver_11, channel_1}}, {{134, driver_11, channel_2}},
                                       {{135, driver_8, channel_4}}, {{136, driver_8, channel_5}}, {{137, driver_8, channel_6}}, {{138, driver_8, channel_7}}, {{139, driver_9, channel_4}}, {{140, driver_9, channel_5}}, {{141, driver_9, channel_6}}, {{142, driver_9, channel_7}}, {{143, driver_10, channel_4}}, {{144, driver_10, channel_5}}, {{145, driver_10, channel_6}}, {{146, driver_10, channel_7}}, {{147, driver_11, channel_4}}, {{148, driver_11, channel_5}}, {{149, driver_11, channel_6}},
                                       {{150, driver_8, channel_8}}, {{151, driver_8, channel_9}}, {{152, driver_8, channel_10}}, {{153, driver_8, channel_11}}, {{154, driver_9, channel_8}}, {{155, driver_9, channel_9}}, {{156, driver_9, channel_10}}, {{157, driver_9, channel_11}}, {{158, driver_10, channel_8}}, {{159, driver_10, channel_9}}, {{160, driver_10, channel_10}}, {{161, driver_10, channel_11}}, {{162, driver_11, channel_8}}, {{163, driver_11, channel_9}}, {{164, driver_11, channel_10}},
                                       {{165, driver_8, channel_12}}, {{166, driver_8, channel_13}}, {{167, driver_8, channel_14}}, {{168, driver_8, channel_15}}, {{169, driver_9, channel_12}}, {{170, driver_9, channel_13}}, {{171, driver_9, channel_14}}, {{172, driver_9, channel_15}}, {{173, driver_10, channel_12}}, {{174, driver_10, channel_13}}, {{175, driver_10, channel_14}}, {{176, driver_10, channel_15}}, {{177, driver_11, channel_12}}, {{178, driver_11, channel_13}}, {{179, driver_11, channel_14}},
                                       {{180, driver_12, channel_0}}, {{181, driver_12, channel_1}}, {{182, driver_12, channel_2}}, {{183, driver_12, channel_3}}, {{184, driver_13, channel_0}}, {{185, driver_13, channel_1}}, {{186, driver_13, channel_2}}, {{187, driver_13, channel_3}}, {{188, driver_14, channel_0}}, {{189, driver_14, channel_1}}, {{190, driver_14, channel_2}}, {{191, driver_14, channel_3}}, {{192, driver_15, channel_0}}, {{193, driver_15, channel_1}}, {{194, driver_15, channel_2}},
                                       {{195, driver_12, channel_4}}, {{196, driver_12, channel_5}}, {{197, driver_12, channel_6}}, {{198, driver_12, channel_7}}, {{199, driver_13, channel_4}}, {{200, driver_13, channel_5}}, {{201, driver_13, channel_6}}, {{202, driver_13, channel_7}}, {{203, driver_14, channel_4}}, {{204, driver_14, channel_5}}, {{205, driver_14, channel_6}}, {{206, driver_14, channel_7}}, {{207, driver_15, channel_4}}, {{208, driver_15, channel_5}}, {{209, driver_15, channel_6}},
                                       {{210, driver_12, channel_8}}, {{211, driver_12, channel_9}}, {{212, driver_12, channel_10}}, {{213, driver_12, channel_11}}, {{214, driver_13, channel_8}}, {{215, driver_13, channel_9}}, {{216, driver_13, channel_10}}, {{217, driver_13, channel_11}}, {{218, driver_14, channel_8}}, {{219, driver_14, channel_9}}, {{220, driver_14, channel_10}}, {{221, driver_14, channel_11}}, {{222, driver_15, channel_8}}, {{223, driver_15, channel_9}}, {{224, driver_15, channel_10}},
                                       {{225, driver_12, channel_12}}, {{226, driver_12, channel_13}}, {{227, driver_12, channel_14}}, {{228, driver_12, channel_15}}, {{229, driver_13, channel_12}}, {{230, driver_13, channel_13}}, {{231, driver_13, channel_14}}, {{232, driver_13, channel_15}}, {{233, driver_14, channel_12}}, {{234, driver_14, channel_13}}, {{235, driver_14, channel_14}}, {{236, driver_14, channel_15}}, {{237, driver_15, channel_12}}, {{238, driver_15, channel_13}}, {{239, driver_15, channel_15}},
                                       };

// Array where ESP specific tiles will be stored
static art_t g_art_quadrant[TILES_PER_ESP];

// Array with quadrant 1 specific tiles
static art_t g_art_q1[TILES_PER_ESP] = {
                                        {{0, driver_0, channel_0}}, {{1, driver_0, channel_1}}, {{2, driver_0, channel_2}}, {{3, driver_0, channel_3}}, {{4, driver_1, channel_0}}, {{5, driver_1, channel_1}}, {{6, driver_1, channel_2}}, {{7, driver_1, channel_3}},
                                        {{15, driver_0, channel_4}}, {{16, driver_0, channel_5}}, {{17, driver_0, channel_6}}, {{18, driver_0, channel_7}}, {{19, driver_1, channel_4}}, {{20, driver_1, channel_5}}, {{21, driver_1, channel_6}}, {{22, driver_1, channel_7}},
                                        {{30, driver_0, channel_8}}, {{31, driver_0, channel_9}}, {{32, driver_0, channel_10}}, {{33, driver_0, channel_11}}, {{34, driver_1, channel_8}}, {{35, driver_1, channel_9}}, {{36, driver_1, channel_10}}, {{37, driver_1, channel_11}},
                                        {{45, driver_0, channel_12}}, {{46, driver_0, channel_13}}, {{47, driver_0, channel_14}}, {{48, driver_0, channel_15}}, {{49, driver_1, channel_12}}, {{50, driver_1, channel_13}}, {{51, driver_1, channel_14}}, {{52, driver_1, channel_15}},
                                        {{60, driver_4, channel_0}}, {{61, driver_4, channel_1}}, {{62, driver_4, channel_2}}, {{63, driver_4, channel_3}}, {{64, driver_5, channel_0}}, {{65, driver_5, channel_1}}, {{66, driver_5, channel_2}}, {{67, driver_5, channel_3}},
                                        {{75, driver_4, channel_4}}, {{76, driver_4, channel_5}}, {{77, driver_4, channel_6}}, {{78, driver_4, channel_7}}, {{79, driver_5, channel_4}}, {{80, driver_5, channel_5}}, {{81, driver_5, channel_6}}, {{82, driver_5, channel_7}},
                                        {{90, driver_4, channel_8}}, {{91, driver_4, channel_9}}, {{92, driver_4, channel_10}}, {{93, driver_4, channel_11}}, {{94, driver_5, channel_8}}, {{95, driver_5, channel_9}}, {{96, driver_5, channel_10}}, {{97, driver_5, channel_11}},
                                        {{105, driver_4, channel_12}}, {{106, driver_4, channel_13}}, {{107, driver_4, channel_14}}, {{108, driver_4, channel_15}}, {{109, driver_5, channel_12}}, {{110, driver_5, channel_13}}, {{111, driver_5, channel_14}}, {{112, driver_5, channel_15}},
                                        };

// Array with quadrant 2 specific tiles
static art_t g_art_q2[TILES_PER_ESP] = {
                                        {{8, driver_2, channel_0}}, {{9, driver_2, channel_1}}, {{10, driver_2, channel_2}}, {{11, driver_2, channel_3}}, {{12, driver_3, channel_0}}, {{13, driver_3, channel_1}}, {{14, driver_3, channel_2}}, {{NO_ID, driver_3, channel_3}},
                                        {{23, driver_2, channel_4}}, {{24, driver_2, channel_5}}, {{25, driver_2, channel_6}}, {{26, driver_2, channel_7}}, {{27, driver_3, channel_4}}, {{28, driver_3, channel_5}}, {{29, driver_3, channel_6}}, {{NO_ID, driver_3, channel_7}},
                                        {{38, driver_2, channel_8}}, {{39, driver_2, channel_9}}, {{40, driver_2, channel_10}}, {{41, driver_2, channel_11}}, {{42, driver_3, channel_8}}, {{43, driver_3, channel_9}}, {{44, driver_3, channel_10}}, {{NO_ID, driver_3, channel_11}},
                                        {{53, driver_2, channel_12}}, {{54, driver_2, channel_13}}, {{55, driver_2, channel_14}}, {{56, driver_2, channel_15}}, {{57, driver_3, channel_12}}, {{58, driver_3, channel_13}}, {{59, driver_3, channel_14}}, {{NO_ID, driver_3, channel_15}},
                                        {{68, driver_6, channel_0}}, {{69, driver_6, channel_1}}, {{70, driver_6, channel_2}}, {{71, driver_6, channel_3}}, {{72, driver_7, channel_0}}, {{73, driver_7, channel_1}}, {{74, driver_7, channel_2}}, {{NO_ID, driver_7, channel_3}},
                                        {{83, driver_6, channel_4}}, {{84, driver_6, channel_5}}, {{85, driver_6, channel_6}}, {{86, driver_6, channel_7}}, {{87, driver_7, channel_4}}, {{88, driver_7, channel_5}}, {{89, driver_7, channel_6}}, {{NO_ID, driver_7, channel_7}},
                                        {{98, driver_6, channel_8}}, {{99, driver_6, channel_9}}, {{100, driver_6, channel_10}}, {{101, driver_6, channel_11}}, {{102, driver_7, channel_8}}, {{103, driver_7, channel_9}}, {{104, driver_7, channel_10}}, {{NO_ID, driver_7, channel_11}},
                                        {{113, driver_6, channel_12}}, {{114, driver_6, channel_13}}, {{115, driver_6, channel_14}}, {{116, driver_6, channel_15}}, {{117, driver_7, channel_12}}, {{118, driver_7, channel_13}}, {{119, driver_7, channel_14}}, {{NO_ID, driver_7, channel_15}},
                                        };

// Array with quadrant 3 specific tiles
static art_t g_art_q3[TILES_PER_ESP] = {
                                        {{120, driver_8, channel_0}}, {{121, driver_8, channel_1}}, {{122, driver_8, channel_2}}, {{123, driver_8, channel_3}}, {{124, driver_9, channel_0}}, {{125, driver_9, channel_1}}, {{126, driver_9, channel_2}}, {{127, driver_9, channel_3}},
                                        {{135, driver_8, channel_4}}, {{136, driver_8, channel_5}}, {{137, driver_8, channel_6}}, {{138, driver_8, channel_7}}, {{139, driver_9, channel_4}}, {{140, driver_9, channel_5}}, {{141, driver_9, channel_6}}, {{142, driver_9, channel_7}},
                                        {{150, driver_8, channel_8}}, {{151, driver_8, channel_9}}, {{152, driver_8, channel_10}}, {{153, driver_8, channel_11}}, {{154, driver_9, channel_8}}, {{155, driver_9, channel_9}}, {{156, driver_9, channel_10}}, {{157, driver_9, channel_11}},
                                        {{165, driver_8, channel_12}}, {{166, driver_8, channel_13}}, {{167, driver_8, channel_14}}, {{168, driver_8, channel_15}}, {{169, driver_9, channel_12}}, {{170, driver_9, channel_13}}, {{171, driver_9, channel_14}}, {{172, driver_9, channel_15}},
                                        {{180, driver_12, channel_0}}, {{181, driver_12, channel_1}}, {{182, driver_12, channel_2}}, {{183, driver_12, channel_3}}, {{184, driver_13, channel_0}}, {{185, driver_13, channel_1}}, {{186, driver_13, channel_2}}, {{187, driver_13, channel_3}},
                                        {{195, driver_12, channel_4}}, {{196, driver_12, channel_5}}, {{197, driver_12, channel_6}}, {{198, driver_12, channel_7}}, {{199, driver_13, channel_4}}, {{200, driver_13, channel_5}}, {{201, driver_13, channel_6}}, {{202, driver_13, channel_7}},
                                        {{210, driver_12, channel_8}}, {{211, driver_12, channel_9}}, {{212, driver_12, channel_10}}, {{213, driver_12, channel_11}}, {{214, driver_13, channel_8}}, {{215, driver_13, channel_9}}, {{216, driver_13, channel_10}}, {{217, driver_13, channel_11}},
                                        {{225, driver_12, channel_12}}, {{226, driver_12, channel_13}}, {{227, driver_12, channel_14}}, {{228, driver_12, channel_15}}, {{229, driver_13, channel_12}}, {{230, driver_13, channel_13}}, {{231, driver_13, channel_14}}, {{232, driver_13, channel_15}},
                                        };

// Array with quadrant 4 specific tiles
static art_t g_art_q4[TILES_PER_ESP] = {
                                        {{128, driver_10, channel_0}}, {{129, driver_10, channel_1}}, {{130, driver_10, channel_2}}, {{131, driver_10, channel_3}}, {{132, driver_11, channel_0}}, {{133, driver_11, channel_1}}, {{134, driver_11, channel_2}}, {{NO_ID, driver_11, channel_3}},
                                        {{143, driver_10, channel_4}}, {{144, driver_10, channel_5}}, {{145, driver_10, channel_6}}, {{146, driver_10, channel_7}}, {{147, driver_11, channel_4}}, {{148, driver_11, channel_5}}, {{149, driver_11, channel_6}}, {{NO_ID, driver_11, channel_7}},
                                        {{158, driver_10, channel_8}}, {{159, driver_10, channel_9}}, {{160, driver_10, channel_10}}, {{161, driver_10, channel_11}}, {{162, driver_11, channel_8}}, {{163, driver_11, channel_9}}, {{164, driver_11, channel_10}}, {{NO_ID, driver_11, channel_11}},
                                        {{173, driver_10, channel_12}}, {{174, driver_10, channel_13}}, {{175, driver_10, channel_14}}, {{176, driver_10, channel_15}}, {{177, driver_11, channel_12}}, {{178, driver_11, channel_13}}, {{179, driver_11, channel_14}}, {{NO_ID, driver_11, channel_15}},
                                        {{188, driver_14, channel_0}}, {{189, driver_14, channel_1}}, {{190, driver_14, channel_2}}, {{191, driver_14, channel_3}}, {{192, driver_15, channel_0}}, {{193, driver_15, channel_1}}, {{194, driver_15, channel_2}}, {{NO_ID, driver_15, channel_3}},
                                        {{203, driver_14, channel_4}}, {{204, driver_14, channel_5}}, {{205, driver_14, channel_6}}, {{206, driver_14, channel_7}}, {{207, driver_15, channel_4}}, {{208, driver_15, channel_5}}, {{209, driver_15, channel_6}}, {{NO_ID, driver_15, channel_7}},
                                        {{218, driver_14, channel_8}}, {{219, driver_14, channel_9}}, {{220, driver_14, channel_10}}, {{221, driver_14, channel_11}}, {{222, driver_15, channel_8}}, {{223, driver_15, channel_9}}, {{224, driver_15, channel_10}}, {{NO_ID, driver_15, channel_11}},
                                        {{233, driver_14, channel_12}}, {{234, driver_14, channel_13}}, {{235, driver_14, channel_14}}, {{236, driver_14, channel_15}}, {{237, driver_15, channel_12}}, {{238, driver_15, channel_13}}, {{239, driver_15, channel_15}}, {{NO_ID, driver_15, channel_14}},
                                        };

// Array with direction for positioning tile in manual mode
static uint8_t tile_direction[N_ROWS*N_COLUMNS] = {
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, MID_DEGREE, 
                                                    };

/////////////////////////////////////
//// Global variables and arrays ////
/////////////////////////////////////

// Array with offset degree values for positioning servos in perfect degree 0 (0s without sign indicate no connection in system)
static const int8_t g_servo_degree_offset[N_ROWS*N_COLUMNS] = {
                                                                +3, +0, +5, -7, +6, -3, -6, +2,    -5, -7, +0, +3, +0, +0, +2, 
                                                                -6, +6, +5, -7, +6, -2, -3, +3,    -1, +0, +8, +7, +2, -2, +0, 
                                                                -5, -6, +4, +4, +4, +2, +4, +5,    -4, -7, +4, +9, -4, -6, +0, 
                                                                -2, +7, -3, -1, -6, -3, -4, +8,    +2, -1, +8, -6, -1, +4, -5, 
                                                                +7, -1, +9, +6, -3, +5, -3, +9,    +3, +2, -8, -1, -6, +0, +0, 
                                                                +9, +9, +0, +3, -3, +3, +0, +5,    +7, -7, +0, -5, -2, -4, -5, 
                                                                -7, +7, +7, -4, -4, +6, -5, +8,    +3, +0, +8, -6, -7, +3, -1, 
                                                                +5, +1, +0, -3, +2, -9, +4, -3,    -6, +7, +9, +3, -5, +3, -7, 

                                                                +4, -5, +6, +0, +4, +0, +0, +2,    -4, +4, -1, -2, +0, -5, -2, 
                                                                +4, +7, +4, -7, -7, -2, +2, +5,    -7, +2, -1, +5, -1, +3, +3, 
                                                                +2, +8, -6, -7, -7, +1, +5, -4,    -3, +2, -5, +4, +3, +0, +2, 
                                                                +2, +2, +6, +0, -2, +6, +4, +0,    -2, +0, -8, -1, +3, +8, +0, 
                                                                +6, -6, +2, -2, -6, -9, +5, +8,    +1, +2, +6, -2, -1, +7, +2, 
                                                                -4, +1, -4, -4, -5, +2, +7, +8,    +6, -2, +2, -2, +2, +6, -4, 
                                                                +1, +4, -3, +7, -6, +7, +6, +5,    +2, -5, -2, -2, +8, +2, +5, 
                                                                +3,  0, +4,  0, -1,  0, -5,  0,    +8,  0, +1,  0, -2,  0, -1, 
                                                                };

// Structure for containing the drivers found to be connected to ESP
static driver_found_t g_drivers_found = {false};


///////////////////////////////////////////////
//// Function definitions for moving tiles ////
///////////////////////////////////////////////

void SetQuadrants();
void Column_Move(columns_t column, uint8_t degree);
void Row_Move(rows_t row, uint8_t degree);
void Manual_Move(uint16_t tile_to_move, uint8_t degree);
void ResetTiles();
void PCA_ServoMove(uint8_t tile_id, drivers_t driver, channels_t channel, uint8_t degree);


/////////////////////////////////////////////////////
//// Functions for setting ESP specific quadrant ////
/////////////////////////////////////////////////////

void SetQuadrants()
{ // Save in g_art_quadrant array all the tiles that current ESP can move
  static uint8_t tile = 0;

  if(true == g_drivers_found.driver_0_found)
  { // If driver 0 has been found, it means ESP controls quadrant 1
    for(tile = 0; tile < TILES_PER_ESP; tile++)
    {
      g_art_quadrant[tile].tile.driver = g_art_q1[tile].tile.driver;
      g_art_quadrant[tile].tile.channel = g_art_q1[tile].tile.channel;
      g_art_quadrant[tile].tile.tile_id = g_art_q1[tile].tile.tile_id;
    }
  }
  else if(true == g_drivers_found.driver_2_found)
  { // If driver 2 has been found, it means ESP controls quadrant 2
    for(tile = 0; tile < TILES_PER_ESP; tile++)
    {
      g_art_quadrant[tile].tile.driver = g_art_q2[tile].tile.driver;
      g_art_quadrant[tile].tile.channel = g_art_q2[tile].tile.channel;
      g_art_quadrant[tile].tile.tile_id = g_art_q2[tile].tile.tile_id;
    }
  }
  else if(true == g_drivers_found.driver_8_found)
  { // If driver 8 has been found, it means ESP controls quadrant 3
    for(tile = 0; tile < TILES_PER_ESP; tile++)
    {
      g_art_quadrant[tile].tile.driver = g_art_q3[tile].tile.driver;
      g_art_quadrant[tile].tile.channel = g_art_q3[tile].tile.channel;
      g_art_quadrant[tile].tile.tile_id = g_art_q3[tile].tile.tile_id;
    }
  }
  else if(true == g_drivers_found.driver_10_found)
  { // If driver 10 has been found, it means ESP controls quadrant 4
    for(tile = 0; tile < TILES_PER_ESP; tile++)
    {
      g_art_quadrant[tile].tile.driver = g_art_q4[tile].tile.driver;
      g_art_quadrant[tile].tile.channel = g_art_q4[tile].tile.channel;
      g_art_quadrant[tile].tile.tile_id = g_art_q4[tile].tile.tile_id;
    }
  }
  else
  {
    for(tile = 0; tile < TILES_PER_ESP; tile++)
    {
      g_art_quadrant[tile].tile.driver = g_art_q1[tile].tile.driver;
      g_art_quadrant[tile].tile.channel = g_art_q1[tile].tile.channel;
      g_art_quadrant[tile].tile.tile_id = g_art_q1[tile].tile.tile_id;
    }
  }
}


void Column_Move(columns_t column, uint8_t degree)
{
  static uint16_t tile = 0;
  static uint8_t i = 0;

  if(column < N_COLUMNS)
  { // Validate the existance of the desired column to move before attempting to do so
    tile = (uint16_t) column;

    for(i = 0; i < N_ROWS; i++)
    {
      PCA_ServoMove(g_art[tile].tile.tile_id, g_art[tile].tile.driver, g_art[tile].tile.channel, degree);
      tile += N_COLUMNS;
    }
  }
  else
  {
    Serial.println("COLUMN NON EXISTANT");
  }
}


void Row_Move(rows_t row, uint8_t degree)
{
  static uint16_t tile = 0;
  static uint8_t i = 0;

  if(row < N_ROWS)
  { // Validate the existance of the desired row to move before attempting to do so
    tile = row * N_COLUMNS;

    for(i = 0; i < N_COLUMNS; i++)
    {
      PCA_ServoMove(g_art[tile].tile.tile_id, g_art[tile].tile.driver, g_art[tile].tile.channel, degree);
      tile++;
    }
  }
  else
  {
    Serial.println("ROW NON EXISTANT");
  }
}


void Manual_Move(uint16_t tile_to_move)
{ // Function for moving a specific tile to a specific degree
  if((tile_to_move >= 0) && (tile_to_move < N_ROWS*N_COLUMNS))
  { // Validate the existance of the desired tile to move before attempting to do so
    tile_direction[tile_to_move] = (tile_direction[tile_to_move] == MID_DEGREE) ? MIN_DEGREE : MID_DEGREE;
    PCA_ServoMove(g_art[tile_to_move].tile.tile_id, g_art[tile_to_move].tile.driver, g_art[tile_to_move].tile.channel, tile_direction[tile_to_move]);
  }
  else
  {
    Serial.println("TILE NON EXISTANT");
  }
}


void ResetTiles()
{ // Function for positioning every tile in default position
  static uint16_t move_tile_index = 0;

  for(move_tile_index = 0; move_tile_index < TILES_PER_ESP; move_tile_index++)
  { // Move every tile back to MID DEGREE
    PCA_ServoMove(g_art_quadrant[move_tile_index].tile.tile_id, g_art_quadrant[move_tile_index].tile.driver, g_art_quadrant[move_tile_index].tile.channel, MID_DEGREE);
  }

  for(move_tile_index = 0; move_tile_index < N_ROWS*N_COLUMNS; move_tile_index++)
  { // Reset every manual tile direction to MID DEGREE
    tile_direction[move_tile_index] = MID_DEGREE;
  }
}


void PCA_ServoMove(uint8_t tile_id, drivers_t driver, channels_t channel, uint8_t degree)
{ // Move the servo based on the driver, the channel and the degree at which to be moved
  static uint16_t duty = 0;

  if((MAX_DEGREE+DEGREE_TOLERANCE < degree) || (MIN_DEGREE-DEGREE_TOLERANCE > degree))
  { // If desired degree is higher than the max degree with added tolerance or less than min degree with substracted tolerance, set degree at MAX_DEGREE
    degree = MID_DEGREE;
  }

  degree += g_servo_degree_offset[tile_id];   // Adjust the position of servomotor by adding the offset vector

  duty = map(degree, MIN_DEGREE, MAX_DEGREE, DEGREE_0_DC, DEGREE_180_DC);   // Verify if degree is between MIN_DEGREE & MAX_DEGREE and map degree
                                                                            // at the correlating value between DEGREE_0_DC & DEGREE_180_DC which are the 
                                                                            // limit values for our tile's movements

  if((true == g_drivers_found.driver_0_found) && (driver_0 == driver))
    pca9685_0.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_1_found) && (driver_1 == driver))
    pca9685_1.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_2_found) && (driver_2 == driver))
    pca9685_2.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_3_found) && (driver_3 == driver))
    pca9685_3.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_4_found) && (driver_4 == driver))
    pca9685_4.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_5_found) && (driver_5 == driver))
    pca9685_5.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_6_found) && (driver_6 == driver))
    pca9685_6.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_7_found) && (driver_7 == driver))
    pca9685_7.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_8_found) && (driver_8 == driver))
    pca9685_8.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_9_found) && (driver_9 == driver))
    pca9685_9.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_10_found) && (driver_10 == driver))
    pca9685_10.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_11_found) && (driver_11 == driver))
    pca9685_11.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_12_found) && (driver_12 == driver))
    pca9685_12.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_13_found) && (driver_13 == driver))
    pca9685_13.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_14_found) && (driver_14 == driver))
    pca9685_14.setPWM(channel, CHANNEL_ON, duty);
  else if((true == g_drivers_found.driver_15_found) && (driver_15 == driver))
    pca9685_15.setPWM(channel, CHANNEL_ON, duty);
  else 
    ;
}

#endif
