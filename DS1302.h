/*
 * 	��� ������������:
 * 		1. �������� ������������ ���� "stm32f3xx_hal.h" � ������������ � ������������ ������������. � ��������� STM32F303VCT.
 * 		2. ������������� ���� � ������, � ������� ���������� ���������� (DS1302_GPIO, DS1302_SCLK, DS1302_SDA, DS1302_RST).
 * 		3. � ������� main ��������� DS1302_Init();.
 * 		4. ����� ������������.
 */

#ifndef _DS1302_H
#define _DS1302_H

#include "stm32f3xx_hal.h"
#include "dwt_delay.h"

//----------------------------------------------------------------------------------
//���� ����������� ���� � ������ ������������� �� ����
//----------------------------------------------------------------------------------
#define DS1302_GPIO				GPIOD
#define DS1302_SCLK				DS1302_CLK_Pin
#define DS1302_SDA				DS1302_IO_Pin
#define DS1302_RST				DS1302_RST_Pin


/* ������������� */
/* ��������� ������� STM32, ������ ������� ����������� � ����� ����� �� ������ ���������������� */
void DS1302_Init(void);

/* Reads time byte by byte to 'buf' */
void DS1302_ReadTime(uint8_t *buf);

/* Writes time byte by byte from 'buf' */
void DS1302_WriteTime(uint8_t *buf); 

/* Writes 'val' to ram address 'addr' */
/* Ram addresses range from 0 to 30 */
void DS1302_WriteRam(uint8_t addr, uint8_t val);

/* ������ �� RAM �� ������ 'addr' */
uint8_t DS1302_ReadRam(uint8_t addr);

/* ������� RAM ������ */
void DS1302_ClearRam(void);

/* Reads time in burst mode, includes control byte */
void DS1302_ReadTimeBurst(uint8_t * temp);

/* Writes time in burst mode, includes control byte */
void DS1302_WriteTimeBurst(uint8_t * buf);

/* Reads ram in burst mode 'len' bytes into 'buf' */
void DS1302_ReadRamBurst(uint8_t len, uint8_t * buf);

/* Writes ram in burst mode 'len' bytes from 'buf' */
void DS1302_WriteRamBurst(uint8_t len, uint8_t * buf);

//������ �����.
void DS1302_ClockStart(void);

//��������� �����.
void DS1302_ClockStop(void);

//����� �����
void DS1302_ClockClear(void);

#endif //_DS1302_H
