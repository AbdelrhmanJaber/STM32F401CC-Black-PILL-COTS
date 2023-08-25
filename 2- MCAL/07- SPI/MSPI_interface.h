/*
 * MSPI_interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Abdelrahman Ibrahim
 */

#ifndef SRC_MCAL_MSPI_MSPI_INTERFACE_H_
#define SRC_MCAL_MSPI_MSPI_INTERFACE_H_

void MSPI_vMasterInit(u8 copy_u8MasterNumber);

void MSPI_vSlaveInit(u8 copy_u8SlaveNumber);

u16 MSPI1_u16Transeive(u16 A_u16Data);

u16 MSPI2_u16Transeive(u16 A_u16Data);

u16 MSPI3_u16Transeive(u16 A_u16Data);

u16 MSPI4_u16Transeive(u16 A_u16Data);


#define MASTER_1              1
#define MASTER_2              2
#define MASTER_3              3
#define MASTER_4              4


#define SLAVE_1               1
#define SLAVE_2               2
#define SLAVE_3               3
#define SLAVE_4               4


#define SPI1_INTERRUPT        0
#define SPI2_INTERRUPT        1
#define SPI3_INTERRUPT        2
#define SPI4_INTERRUPT        3


#endif /* SRC_MCAL_MSPI_MSPI_INTERFACE_H_ */
