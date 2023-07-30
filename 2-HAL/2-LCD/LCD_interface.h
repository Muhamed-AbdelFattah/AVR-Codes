/**************************************************************/
/**************************************************************/
/*************    Author: Muhamed AbdelFattah    **************/
/*************    Layer: HAL                     **************/
/*************    SWC:lCD                         *************/
/**************************************************************/
/**************************************************************/

#ifndef LCD_H_
#define LCD_H_



#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** LCD DIO *********************************************/
/***************************************************************************************/

#define lcd_DATAPORT          PORT_D
#define lcd_CONTROLPORT       PORT_C
#define lcd_RSPIN       PIN_0
#define lcd_RWPIN       PIN_1
#define lcd_EPIN        PIN_2


/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/


void LCD_vidInit(void);
void LCD_vidSendCommand(u8 u8CmdCpy);
void LCD_vidWriteCharctr(u8 u8DataCpy);
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);
void Gotoxy (u8 u8Y,u8 u8X);
void LCD_vidWriteExtraChar (u8 u8Y,u8 u8X,u8 *Copy_Pu8Pattern,u8 Copy_u8PatternNumber);


void LCD_vidWriteString_1 (u8* pu8StringCpy, u8 u8Index,u8 u8Y,u8 u8X);
void LCD_voidwriteNumber(u32 Copy_u32Number);
#endif /* LCD_H_ */
