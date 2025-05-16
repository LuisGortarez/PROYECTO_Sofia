/*
  Name:		  SOFIAmodes.h
  Created:	27/04/2025 15:28:00
  Author:	  Luis Enrique Gortárez Ramírez
  Brief:    Archivo con agrupación de figuras por 
            tipo para ofrecer modos de ejecución.
*/

#ifndef SOFIAmodes_H
#define SOFIAmodes_H

///////////////////////////////////////////
//// Characters that make the commands ////
///////////////////////////////////////////

#define ASCII_TO_INT      48      // Number 0 in ASCII is 48

// Three characters are expected for every command (reset command is the exception, it does not need point 2):
//  1. Mode of operation
//  2. Shape to show
//  3. End of command

// Character changing mode of operation
#define ANIMATION_CMD     'a'
#define COLUMN_CMD        'c'
#define EMOJI_CMD         'e'
#define ROW_CMD           'f'
#define LETTER_CMD        'l'
#define MANUAL_CMD        'm'
#define NUMBER_CMD        'n'
#define RESET_CMD         'r'     // Return all tiles to default position
#define SYMBOL_CMD        's'
#define WORD_CMD          'w'


// Command for indicating end of command
#define END_OF_CMD        '|'

// Character for executing animations
#define EXPANSION_CMD     'a'
#define HEART_CMD         'b'
#define GREETING_CMD      'c'
#define ROCK_CMD          'd'
#define SLEEP_CMD         'e'
#define ZIGZAG_CMD        'f'
#define FORKS_CMD         'g'
#define INVERSE_CMD       'h'
#define BOOM_CMD          'i'
#define SPIRAL_CMD        'j'

// Character for executing numbers
#define NUMBER_0_CMD      '0'
#define NUMBER_1_CMD      '1'
#define NUMBER_2_CMD      '2'
#define NUMBER_3_CMD      '3'
#define NUMBER_4_CMD      '4'
#define NUMBER_5_CMD      '5'
#define NUMBER_6_CMD      '6'
#define NUMBER_7_CMD      '7'
#define NUMBER_8_CMD      '8'
#define NUMBER_9_CMD      '9'

// Character for executing letters
#define LETTER_A_CMD      'a'
#define LETTER_B_CMD      'b'
#define LETTER_C_CMD      'c'
#define LETTER_D_CMD      'd'
#define LETTER_E_CMD      'e'
#define LETTER_F_CMD      'f'
#define LETTER_G_CMD      'g'
#define LETTER_H_CMD      'h'
#define LETTER_I_CMD      'i'
#define LETTER_J_CMD      'j'
#define LETTER_K_CMD      'k'
#define LETTER_L_CMD      'l'
#define LETTER_M_CMD      'm'
#define LETTER_N_CMD      'n'
#define LETTER_O_CMD      'o'
#define LETTER_P_CMD      'p'
#define LETTER_Q_CMD      'q'
#define LETTER_R_CMD      'r'
#define LETTER_S_CMD      's'
#define LETTER_T_CMD      't'
#define LETTER_U_CMD      'u'
#define LETTER_V_CMD      'v'
#define LETTER_W_CMD      'w'
#define LETTER_X_CMD      'x'
#define LETTER_Y_CMD      'y'
#define LETTER_Z_CMD      'z'

// Character for executing symbols
#define SYMBOL_AMP_CMD    'a'
#define SYMBOL_MON_CMD    'b'
#define SYMBOL_WRO_CMD    'c'
#define SYMBOL_COR_CMD    'd'
#define SYMBOL_QUS_CMD    'e'
#define SYMBOL_QUE_CMD    'f'
#define SYMBOL_EXS_CMD    'g'
#define SYMBOL_EXE_CMD    'h'
#define SYMBOL_NUM_CMD    'i'
#define SYMBOL_ARR_CMD    'j'
#define SYMBOL_UPA_CMD    'k'
#define SYMBOL_DOA_CMD    'l'
#define SYMBOL_RIA_CMD    'm'
#define SYMBOL_LEA_CMD    'n'
#define SYMBOL_PER_CMD    'o'
#define SYMBOL_DIV_CMD    'p'
#define SYMBOL_MUL_CMD    'q'
#define SYMBOL_ADD_CMD    'r'
#define SYMBOL_SUB_CMD    's'
#define SYMBOL_EQU_CMD    't'
#define SYMBOL_GTH_CMD    'u'
#define SYMBOL_LTH_CMD    'v'
#define SYMBOL_WIF_CMD    'w'

// Character for executing emojis
#define EMOJI_STARING_CMD    'a'
#define EMOJI_BLUSH_CMD      'b'
#define EMOJI_EXCITED_CMD    'c'
#define EMOJI_ANGRY_CMD      'd'
#define EMOJI_SMILING_CMD    'e'
#define EMOJI_HAPPY_CMD      'f'
#define EMOJI_WINK_CMD       'g'
#define EMOJI_DISTURBED_CMD  'h'
#define EMOJI_CRYING_CMD     'i'
#define EMOJI_DEAD_CMD       'j'
#define EMOJI_PAIN_CMD       'k'
#define EMOJI_SURPRISED_CMD  'l'
#define EMOJI_SAD_CMD        'm'
#define EMOJI_UHOH_CMD       'n'
#define EMOJI_YUCK_CMD       'o'

// Character for executing words
#define WORD_YES_CMD         'a'
#define WORD_NO_CMD          'b'
#define WORD_ITESO_CMD       'c'
#define WORD_SOFIA_CMD       'd'


// Flag for setting system mode
typedef enum
{
  standby,
  reset_mode,
  column_mode,
  row_mode,
  manual_mode,
  animation_mode,
  sleep_mode,
  number_mode,
  letter_mode,
  symbol_mode,
  emoji_mode,
  word_mode,
} system_mode_t;

static system_mode_t g_mode = standby;


////////////////////////////////////////
//// Function definitions for modes ////
////////////////////////////////////////

void ResetMode(uint8_t character);
void ColumnMode(uint8_t character);
void RowMode(uint8_t character);
void ManualMode(uint8_t character);
void AnimationMode(uint8_t character);
void NumberMode(uint8_t character);
void LetterMode(uint8_t character);
void SymbolMode(uint8_t character);
void EmojiMode(uint8_t character);
void WordMode(uint8_t character);
void SetMode(system_mode_t mode);
system_mode_t GetMode();


/////////////////////////////////////////////
////////////// Code functions ///////////////
/////////////////////////////////////////////

void ResetMode(uint8_t character)
{
  if(END_OF_CMD == character)
  {
    ResetTiles();
    SetMode(standby);
  }
}


void ColumnMode(uint8_t character)
{
  static String number;
  static columns_t column = column_0;

  if(END_OF_CMD == character)
  {
    column = (columns_t) number.toInt();  // Convert String to int
    number.clear();                       // Clear string for next number
    Column_Move(column, MAX_DEGREE);
    SetMode(standby);
  }
  else
  {
    number += (character - ASCII_TO_INT);
  }
}

void RowMode(uint8_t character)
{
  static String number;
  static rows_t row = row_0;

  if(END_OF_CMD == character)
  {
    row = (rows_t) number.toInt();  // Convert String to int
    number.clear();                 // Clear string for next number
    Row_Move(row, MAX_DEGREE);
    SetMode(standby);
  }
  else
  {
    number += (character - ASCII_TO_INT);
  }
}


void ManualMode(uint8_t character)
{ // Save characters on string as they come until char indicated end of cmd is received
  static String number;
  static uint16_t tile_to_move = 0;

  if(END_OF_CMD == character)
  {
    tile_to_move = number.toInt();  // Convert String to int
    number.clear();                 // Clear string for next number
    Manual_Move(tile_to_move);
    SetMode(standby);              // Manual mode is done
  }
  else
  { // Convert ASCII character to int and add it to string
    number += (character - ASCII_TO_INT);
  }
}


void AnimationMode(uint8_t character)
{
  static animations_t animation = expansion;

  if(END_OF_CMD == character)
  {
    AnimationExecute(animation);
    if(sleepy != animation)
      SetMode(standby);
    else
      SetMode(sleep_mode);
  }
  else if(EXPANSION_CMD == character)
    animation = expansion;
  else if(HEART_CMD == character)
    animation = heart;
  else if(GREETING_CMD == character)
    animation = greeting;
  else if(ROCK_CMD == character)
    animation = rock;
  else if(SLEEP_CMD == character)
    animation = sleepy;
  else if(ZIGZAG_CMD == character)
    animation = zigzag;
  else if(FORKS_CMD == character)
    animation = forks;
  else if(INVERSE_CMD == character)
    animation = inverse;
  else if(BOOM_CMD == character)
    animation = boom;
  else if(SPIRAL_CMD == character)
    animation = spiral;
  else
    Serial.println("COMMAND NOT FOUND");
}


void NumberMode(uint8_t character)
{
  static numbers_t number = number_0;

  if(END_OF_CMD == character)
  {
    NumberExecute(number, 3000, MAX_DEGREE);
    SetMode(standby);
  }
  else if(NUMBER_0_CMD == character)
    number = number_0;
  else if(NUMBER_1_CMD == character)
    number = number_1;
  else if(NUMBER_2_CMD == character)
    number = number_2;
  else if(NUMBER_3_CMD == character)
    number = number_3;
  else if(NUMBER_4_CMD == character)
    number = number_4;
  else if(NUMBER_5_CMD == character)
    number = number_5;
  else if(NUMBER_6_CMD == character)
    number = number_6;
  else if(NUMBER_7_CMD == character)
    number = number_7;
  else if(NUMBER_8_CMD == character)
    number = number_8;
  else if(NUMBER_9_CMD == character)
    number = number_9;
  else
    Serial.println("COMMAND NOT FOUND");
}


void LetterMode(uint8_t character)
{
  static letters_t letter = letter_A;

  if(END_OF_CMD == character)
  {
    LetterExecute(letter, 3000, MAX_DEGREE);
    SetMode(standby);
  }
  else if(LETTER_A_CMD == character)
    letter = letter_A;
  else if(LETTER_B_CMD == character)
    letter = letter_B;
  else if(LETTER_C_CMD == character)
    letter = letter_C;
  else if(LETTER_D_CMD == character)
    letter = letter_D;
  else if(LETTER_E_CMD == character)
    letter = letter_E;
  else if(LETTER_F_CMD == character)
    letter = letter_F;
  else if(LETTER_G_CMD == character)
    letter = letter_G;
  else if(LETTER_H_CMD == character)
    letter = letter_H;
  else if(LETTER_I_CMD == character)
    letter = letter_I;
  else if(LETTER_J_CMD == character)
    letter = letter_J;
  else if(LETTER_K_CMD == character)
    letter = letter_K;
  else if(LETTER_L_CMD == character)
    letter = letter_L;
  else if(LETTER_M_CMD == character)
    letter = letter_M;
  else if(LETTER_N_CMD == character)
    letter = letter_N;
  else if(LETTER_O_CMD == character)
    letter = letter_O;
  else if(LETTER_P_CMD == character)
    letter = letter_P;
  else if(LETTER_Q_CMD == character)
    letter = letter_Q;
  else if(LETTER_R_CMD == character)
    letter = letter_R;
  else if(LETTER_S_CMD == character)
    letter = letter_S;
  else if(LETTER_T_CMD == character)
    letter = letter_T;
  else if(LETTER_U_CMD == character)
    letter = letter_U;
  else if(LETTER_V_CMD == character)
    letter = letter_V;
  else if(LETTER_W_CMD == character)
    letter = letter_W;
  else if(LETTER_X_CMD == character)
    letter = letter_X;
  else if(LETTER_Y_CMD == character)
    letter = letter_Y;
  else if(LETTER_Z_CMD == character)
    letter = letter_Z;
  else
    Serial.println("COMMAND NOT FOUND");
}


void SymbolMode(uint8_t character)
{
  static symbols_t symbol = amperson;

  if(END_OF_CMD == character)
  {
    SymbolExecute(symbol, 3000, MAX_DEGREE);
    SetMode(standby);
  }
  else if(SYMBOL_AMP_CMD == character)
    symbol = amperson;
  else if(SYMBOL_MON_CMD == character)
    symbol = money;
  else if(SYMBOL_WRO_CMD == character)
    symbol = wrong;
  else if(SYMBOL_COR_CMD == character)
    symbol = correct;
  else if(SYMBOL_QUS_CMD == character)
    symbol = question_start;
  else if(SYMBOL_QUE_CMD == character)
    symbol = question_end;
  else if(SYMBOL_EXS_CMD == character)
    symbol = exclamation_start;
  else if(SYMBOL_EXE_CMD == character)
    symbol = exclamation_end;
  else if(SYMBOL_NUM_CMD == character)
    symbol = number;
  else if(SYMBOL_ARR_CMD == character)
    symbol = arroba;
  else if(SYMBOL_UPA_CMD == character)
    symbol = up_arrow;
  else if(SYMBOL_DOA_CMD == character)
    symbol = down_arrow;
  else if(SYMBOL_RIA_CMD == character)
    symbol = right_arrow;
  else if(SYMBOL_LEA_CMD == character)
    symbol = left_arrow;
  else if(SYMBOL_PER_CMD == character)
    symbol = percentage;
  else if(SYMBOL_DIV_CMD == character)
    symbol = division;
  else if(SYMBOL_MUL_CMD == character)
    symbol = multiplication;
  else if(SYMBOL_ADD_CMD == character)
    symbol = add;
  else if(SYMBOL_SUB_CMD == character)
    symbol = substract;
  else if(SYMBOL_EQU_CMD == character)
    symbol = equals;
  else if(SYMBOL_GTH_CMD == character)
    symbol = greater_than;
  else if(SYMBOL_LTH_CMD == character)
    symbol = lesser_than;
  else if(SYMBOL_WIF_CMD == character)
    symbol = wifi;
  else
    Serial.println("COMMAND NOT FOUND");
}


void EmojiMode(uint8_t character)
{
  static emojis_t emoji = staring;

  if(END_OF_CMD == character)
  {
    EmojiExecute(emoji, 3000, MAX_DEGREE);
    SetMode(standby);
  }
  else if(EMOJI_STARING_CMD == character)
    emoji = staring;
  else if(EMOJI_BLUSH_CMD == character)
    emoji = blush;
  else if(EMOJI_EXCITED_CMD == character)
    emoji = excited;
  else if(EMOJI_ANGRY_CMD == character)
    emoji = angry;
  else if(EMOJI_SMILING_CMD == character)
    emoji = smiling;
  else if(EMOJI_HAPPY_CMD == character)
    emoji = happy;
  else if(EMOJI_WINK_CMD == character)
    emoji = wink;
  else if(EMOJI_DISTURBED_CMD == character)
    emoji = disturbed;
  else if(EMOJI_CRYING_CMD == character)
    emoji = crying;
  else if(EMOJI_DEAD_CMD == character)
    emoji = dead;
  else if(EMOJI_PAIN_CMD == character)
    emoji = pain;
  else if(EMOJI_SURPRISED_CMD == character)
    emoji = surprised;
  else if(EMOJI_SAD_CMD == character)
    emoji = sad;
  else if(EMOJI_UHOH_CMD == character)
    emoji = uhoh;
  else if(EMOJI_YUCK_CMD == character)
    emoji = yuck;
  else
    Serial.println("COMMAND NOT FOUND");
}


void WordMode(uint8_t character)
{
  static words_t word = yes;

  if(END_OF_CMD == character)
  {
    WordExecute(word, 3000, MAX_DEGREE);
    SetMode(standby);
  }
  else if(WORD_YES_CMD == character)
    word = yes;
  else if(WORD_NO_CMD == character)
    word = no;
  else if(WORD_ITESO_CMD == character)
    word = iteso;
  else if(WORD_SOFIA_CMD == character)
    word = sofia;
  else
    Serial.println("COMMAND NOT FOUND");
}


void SetMode(system_mode_t mode)
{ // Function for setting the mode of operation
  g_mode = mode;
}


system_mode_t GetMode()
{ // Function for getting the mode of operation
  return(g_mode);
}

#endif
