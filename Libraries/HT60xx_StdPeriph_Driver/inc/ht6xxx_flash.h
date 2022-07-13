/*
*********************************************************************************************************
*                                              HT6XXX
*                                          Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_flash.h
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
**********************************************************************************************************
*/

#ifndef __HT6XXX_FLASH_H__
#define __HT6XXX_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "ht6xxx_lib.h"

/*
*********************************************************************************************************
*                                           Global Macro/Structure
*********************************************************************************************************
*/
#define FLASH_MIN_ADDRESS       (HT_FLASH_BASE)                  
#define FLASH_MAX_ADDRESS       (HT_FLASH_BASE+HT_FLASH_SIZE)
#define INFO_MIN_ADDRESS        (HT_INFO_BASE)
#define INFO_MAX_ADDRESS        (HT_INFO_BASE+HT_INFO_SIZE)
#define BUF_MIN_ADDRESS         (HT_RAM_BASE)
#define BUF_MAX_ADDRESS         (HT_RAM_BASE+HT_RAM_SIZE)

#define   FLASH_EWR_KEY         (FLASH_EWR_KEY_4 | FLASH_EWR_KEY_3 | FLASH_EWR_KEY_2 | FLASH_EWR_KEY_1)
#define   FLASH_EWR_KEY_1       (0x000000B4U)			/*!< Flash Erase    */
#define   FLASH_EWR_KEY_1_AREA  (0x000000FFU)			/*!< location of FLASH_EWR_KEY_1 on parameter 'Key'   */
#define   FLASH_EWR_KEY_2       (0x0000C300U)   	/*!< parameter 'Key' is valid only when include FLASH_EWR_KEY_2 in it   */
#define   FLASH_EWR_KEY_2_AREA  (0x0000FF00U)			/*!< location of FLASH_EWR_KEY_2 on parameter 'Key'   */
#define   FLASH_EWR_KEY_3       (0x00A50000U)			/*!< Flash Write    */
#define   FLASH_EWR_KEY_3_AREA  (0x00FF0000U)			/*!< location of FLASH_EWR_KEY_3 on parameter 'Key'   */
#define   FLASH_EWR_KEY_4       (0x96000000U)			/*!< Flash Read     */
#define   FLASH_EWR_KEY_4_AREA  (0xFF000000U)			/*!< location of FLASH_EWR_KEY_4 on parameter 'Key'   */

typedef enum
{
    FlashSucc    = 1,                               /*!< success status                       */
    FlashNone    = 0,                               /*!< no error status                      */
    FlashErrKey  = -1,                              /*!< input key error status               */
    FlashErrAddr = -2,                              /*!< input address error status           */
    FlashErrMod  = -3,                              /*!< input work method error status       */
    FlashErrNum  = -4,                              /*!< input number of buffer status        */
    FlashErrBuf  = -5                               /*!< input address of buffer status       */
}FLASH_RetStaTypeDef;                               /*!< end of group FLASH_RetStaTypeDef     */

typedef enum
{
    FlashErase   = 0x3CU,                            /*!< erase flash                          */
    FlashWrite   = 0x5AU,                            /*!< write flash                          */
    FlashRead    = 0x69U,                            /*!< read  flash                          */
}FLASH_WorkMethodTypeDef;                           /*!< end of group FLASH_WorkMethodTypeDef */


/**
* @brief  flash H256K and L256K block (only H603x)
*/
typedef enum
{
    FlashBlock1   = 0U,                           /*!< First  256k byte                 */
    FlashBlock2   = 1U,                           /*!< Second 256k byte                 */
}FLASH_BlockEraseTypeDef;                        /*!< end of group FLASH_BlockEraseTypeDef      */


#ifdef  USE_FLASH_FLASHCON2
    #define SET_FLASH_READ          HT_CMU->FLASHCON2 = CMU_FLASHCON2_FOP_READ                   /*!< Flash read               */
    #define SET_FLASH_WRITE         HT_CMU->FLASHCON2 = CMU_FLASHCON2_FOP_WRITE                  /*!< Flash write              */
    #define SET_FLASH_PAGEERASE     HT_CMU->FLASHCON2 = CMU_FLASHCON2_FOP_PAGEERASE              /*!< Flash page erase         */
#else
    #define SET_FLASH_READ          HT_CMU->FLASHCON  = CMU_FLASHCON_FOP_READ                    /*!< Flash read               */
    #define SET_FLASH_WRITE         HT_CMU->FLASHCON = CMU_FLASHCON_FOP_WRITE                    /*!< Flash write              */
    #define SET_FLASH_PAGEERASE     HT_CMU->FLASHCON = CMU_FLASHCON_FOP_PAGEERASE                /*!< Flash page erase         */
#endif

#ifdef  USE_FLASH_INFOLOCK_A 
    #define UNLOCK_INFO             HT_CMU->INFOLOCK_A = CMU_INFOLOCK_UnLocked                   /* Info Unlock                   */
    #define LOCK_INFO               HT_CMU->INFOLOCK_A = CMU_INFOLOCK_Locked                     /* Info Lock                     */
#else
    #define UNLOCK_INFO             HT_CMU->INFOLOCK = CMU_INFOLOCK_UnLocked                     /* Info Unlock                   */
    #define LOCK_INFO               HT_CMU->INFOLOCK = CMU_INFOLOCK_Locked                       /* Info Lock                     */
#endif

/*	lock/unlock all main flash	*/
#define HT_MAIN_FLASH_LOCK     (HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked)
#define HT_MAIN_FLASH_UNLOCK   (HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked)

#ifdef USE_FLASH_SECTORKEY_0

  #define FLASH_SECTOR_A1     0U  /*!< Sector Number 0   */
  #define FLASH_SECTOR_A2     1U  /*!< Sector Number 1   */
  #define FLASH_SECTOR_A3     2U  /*!< Sector Number 2   */
  #define FLASH_SECTOR_A4     3U  /*!< Sector Number 3   */
  #define FLASH_SECTOR_A5     4U  /*!< Sector Number 4   */
  #define FLASH_SECTOR_A6     5U  /*!< Sector Number 5   */
  #define FLASH_SECTOR_A7     6U  /*!< Sector Number 6   */
  #define FLASH_SECTOR_A8     7U  /*!< Sector Number 7   */
  #define FLASH_SECTOR_A9     8U  /*!< Sector Number 8   */
  #define FLASH_SECTOR_AA     9U  /*!< Sector Number 9   */
  #define FLASH_SECTOR_B1    10U /*!< Sector Number 10  */
  #define FLASH_SECTOR_B2    11U /*!< Sector Number 11  */
  #define FLASH_SECTOR_B3    12U /*!< Sector Number 12  */
  #define FLASH_SECTOR_B4    13U /*!< Sector Number 13  */
  #define FLASH_SECTOR_B5    14U /*!< Sector Number 14  */
  #define FLASH_SECTOR_B6    15U /*!< Sector Number 15  */
  #define FLASH_SECTOR_B7    16U /*!< Sector Number 16  */
  #define FLASH_SECTOR_B8    17U /*!< Sector Number 17  */
  #define FLASH_SECTOR_B9    18U /*!< Sector Number 18  */
  #define FLASH_SECTOR_BA    19U /*!< Sector Number 19  */

  #define FLASH_SECTOR_A1_BASE_ADDR        0x00000000U
  #define FLASH_SECTOR_A2_BASE_ADDR        0x00002000U
  #define FLASH_SECTOR_A3_BASE_ADDR        0x00008000U
  #define FLASH_SECTOR_A4_BASE_ADDR        0x00010000U
  #define FLASH_SECTOR_A5_BASE_ADDR        0x00018000U
  #define FLASH_SECTOR_A6_BASE_ADDR        0x00020000U
  #define FLASH_SECTOR_A7_BASE_ADDR        0x00028000U
  #define FLASH_SECTOR_A8_BASE_ADDR        0x00030000U
  #define FLASH_SECTOR_A9_BASE_ADDR        0x00038000U
  #define FLASH_SECTOR_AA_BASE_ADDR        0x0003FC00U
  #define FLASH_SECTOR_B1_BASE_ADDR        0x00040000U
  #define FLASH_SECTOR_B2_BASE_ADDR        0x00042000U
  #define FLASH_SECTOR_B3_BASE_ADDR        0x00048000U
  #define FLASH_SECTOR_B4_BASE_ADDR        0x00050000U
  #define FLASH_SECTOR_B5_BASE_ADDR        0x00058000U
  #define FLASH_SECTOR_B6_BASE_ADDR        0x00060000U
  #define FLASH_SECTOR_B7_BASE_ADDR        0x00068000U
  #define FLASH_SECTOR_B8_BASE_ADDR        0x00070000U
  #define FLASH_SECTOR_B9_BASE_ADDR        0x00078000U
  #define FLASH_SECTOR_BA_BASE_ADDR        0x0007FC00U

  #define GET_FLASH_SECTOR(addr,sector)   { \
                                            if(addr<FLASH_SECTOR_A2_BASE_ADDR)        sector = FLASH_SECTOR_A1;  \
                                            else if(addr<FLASH_SECTOR_A3_BASE_ADDR)   sector = FLASH_SECTOR_A2;  \
                                            else if(addr<FLASH_SECTOR_A4_BASE_ADDR)   sector = FLASH_SECTOR_A3;  \
                                            else if(addr<FLASH_SECTOR_A5_BASE_ADDR)   sector = FLASH_SECTOR_A4;  \
                                            else if(addr<FLASH_SECTOR_A6_BASE_ADDR)   sector = FLASH_SECTOR_A5;  \
                                            else if(addr<FLASH_SECTOR_A7_BASE_ADDR)   sector = FLASH_SECTOR_A6;  \
                                            else if(addr<FLASH_SECTOR_A8_BASE_ADDR)   sector = FLASH_SECTOR_A7;  \
                                            else if(addr<FLASH_SECTOR_A9_BASE_ADDR)   sector = FLASH_SECTOR_A8;  \
                                            else if(addr<FLASH_SECTOR_AA_BASE_ADDR)   sector = FLASH_SECTOR_A9;  \
                                            else if(addr<FLASH_SECTOR_B1_BASE_ADDR)   sector = FLASH_SECTOR_AA;  \
                                            else if(addr<FLASH_SECTOR_B2_BASE_ADDR)   sector = FLASH_SECTOR_B1;  \
                                            else if(addr<FLASH_SECTOR_B3_BASE_ADDR)   sector = FLASH_SECTOR_B2;  \
                                            else if(addr<FLASH_SECTOR_B4_BASE_ADDR)   sector = FLASH_SECTOR_B3;  \
                                            else if(addr<FLASH_SECTOR_B5_BASE_ADDR)   sector = FLASH_SECTOR_B4;  \
                                            else if(addr<FLASH_SECTOR_B6_BASE_ADDR)   sector = FLASH_SECTOR_B5;  \
                                            else if(addr<FLASH_SECTOR_B7_BASE_ADDR)   sector = FLASH_SECTOR_B6;  \
                                            else if(addr<FLASH_SECTOR_B8_BASE_ADDR)   sector = FLASH_SECTOR_B7;  \
                                            else if(addr<FLASH_SECTOR_B9_BASE_ADDR)   sector = FLASH_SECTOR_B8;  \
                                            else if(addr<FLASH_SECTOR_BA_BASE_ADDR)   sector = FLASH_SECTOR_B9;  \
                                            else                                      sector = FLASH_SECTOR_BA;  \
                                          }
                                            
  #define FLASH_SECTOR_KEY_BASE_ADDR      0x4000F088U
  #define FLASH_SECTOR_KEY_ADDR(sector)   FLASH_SECTOR_KEY_BASE_ADDR+(sector<<2)
  #define FLASH_SECTOR_KEY(sector)        (sector<=9U) ?  (0x7161U+0x101U*sector) : (0x8161U+0x101U*(sector-10U))
                                      
  #define FLASH_SECTOR_UNLOCK(sector)     (M32(FLASH_SECTOR_KEY_ADDR(sector))=FLASH_SECTOR_KEY(sector))
  #define FLASH_SECTOR_LOCK(sector)       (M32(FLASH_SECTOR_KEY_ADDR(sector))=CMU_FLASHLOCK_Locked)
#endif

#ifdef USE_FLASH_SECTORKEY_1

  #define FLASH_SECTOR_A1     0U  /*!< Sector Number 0   */
  #define FLASH_SECTOR_A2     1U  /*!< Sector Number 1   */
  #define FLASH_SECTOR_A3     2U  /*!< Sector Number 2   */
  #define FLASH_SECTOR_A4     3U  /*!< Sector Number 3   */
  #define FLASH_SECTOR_A5     4U  /*!< Sector Number 4   */
  #define FLASH_SECTOR_A6     5U  /*!< Sector Number 5   */
  #define FLASH_SECTOR_A7     6U  /*!< Sector Number 6   */
  #define FLASH_SECTOR_A8     7U  /*!< Sector Number 7   */
  #define FLASH_SECTOR_A9     8U  /*!< Sector Number 8   */
  #define FLASH_SECTOR_AA     9U  /*!< Sector Number 9   */
  #define FLASH_SECTOR_AB     10U /*!< Sector Number 10  */

  #define FLASH_SECTOR_A1_BASE_ADDR        0x00000000U
  #define FLASH_SECTOR_A2_BASE_ADDR        0x00002000U
  #define FLASH_SECTOR_A3_BASE_ADDR        0x00008000U
  #define FLASH_SECTOR_A4_BASE_ADDR        0x00010000U
  #define FLASH_SECTOR_A5_BASE_ADDR        0x00018000U
  #define FLASH_SECTOR_AA_BASE_ADDR        0x0001FC00U
  #define FLASH_SECTOR_A6_BASE_ADDR        0x00020000U
  #define FLASH_SECTOR_A7_BASE_ADDR        0x00028000U
  #define FLASH_SECTOR_A8_BASE_ADDR        0x00030000U
  #define FLASH_SECTOR_A9_BASE_ADDR        0x00038000U
  #define FLASH_SECTOR_AB_BASE_ADDR        0x0003FC00U

  #define GET_FLASH_SECTOR(addr,sector)    { \
                                            if(addr<FLASH_SECTOR_A2_BASE_ADDR)        sector = FLASH_SECTOR_A1;  \
                                            else if(addr<FLASH_SECTOR_A3_BASE_ADDR)   sector = FLASH_SECTOR_A2;  \
                                            else if(addr<FLASH_SECTOR_A4_BASE_ADDR)   sector = FLASH_SECTOR_A3;  \
                                            else if(addr<FLASH_SECTOR_A5_BASE_ADDR)   sector = FLASH_SECTOR_A4;  \
                                            else if(addr<FLASH_SECTOR_AA_BASE_ADDR)   sector = FLASH_SECTOR_A5;  \
                                            else if(addr<FLASH_SECTOR_A6_BASE_ADDR)   sector = FLASH_SECTOR_AA;  \
                                            else if(addr<FLASH_SECTOR_A7_BASE_ADDR)   sector = FLASH_SECTOR_A6;  \
                                            else if(addr<FLASH_SECTOR_A8_BASE_ADDR)   sector = FLASH_SECTOR_A7;  \
                                            else if(addr<FLASH_SECTOR_A9_BASE_ADDR)   sector = FLASH_SECTOR_A8;  \
                                            else if(addr<FLASH_SECTOR_AB_BASE_ADDR)   sector = FLASH_SECTOR_A9;  \
                                            else                                      sector = FLASH_SECTOR_AB;  \
                                          }
                                            
  #define FLASH_SECTOR_KEY_BASE_ADDR        0x4000F060U
  #define FLASH_SECTOR_KEY_ADDR(sector)     (FLASH_SECTOR_KEY_BASE_ADDR+(sector<<2))
  #define FLASH_SECTOR_KEY(sector)          (0x7161U+0x101U*sector)
                                
  #define FLASH_SECTOR_UNLOCK(sector)       (M32(FLASH_SECTOR_KEY_ADDR(sector))=FLASH_SECTOR_KEY(sector))
  #define FLASH_SECTOR_LOCK(sector)       	(M32(FLASH_SECTOR_KEY_ADDR(sector))=CMU_FLASHLOCK_Locked)
#endif

#ifdef USE_FLASH_SECTORKEY_2
    
  #define FLASH_SECTOR_A1     0U  /*!< Sector Number 0   */
  #define FLASH_SECTOR_A2     1U  /*!< Sector Number 1   */
  #define FLASH_SECTOR_A3     2U  /*!< Sector Number 2   */
  #define FLASH_SECTOR_A4     3U  /*!< Sector Number 3   */
  #define FLASH_SECTOR_A5     4U  /*!< Sector Number 4   */
  #define FLASH_SECTOR_A6     5U  /*!< Sector Number 5   */
  #define FLASH_SECTOR_A7     6U  /*!< Sector Number 6   */
  #define FLASH_SECTOR_A8     7U  /*!< Sector Number 7   */
  #define FLASH_SECTOR_A9     8U  /*!< Sector Number 8   */
  #define FLASH_SECTOR_AA     9U  /*!< Sector Number 9   */
  #define FLASH_SECTOR_AB     10U /*!< Sector Number 10  */
  #define FLASH_SECTOR_B1     11U /*!< Sector Number 11  */
  #define FLASH_SECTOR_B2     12U /*!< Sector Number 12  */
  #define FLASH_SECTOR_B3     13U /*!< Sector Number 13  */
  #define FLASH_SECTOR_B4     14U /*!< Sector Number 14  */
  #define FLASH_SECTOR_B5     15U /*!< Sector Number 15  */
  #define FLASH_SECTOR_B6     16U /*!< Sector Number 16  */
  #define FLASH_SECTOR_B7     17U /*!< Sector Number 17  */
  #define FLASH_SECTOR_B8     18U /*!< Sector Number 18  */
  #define FLASH_SECTOR_B9     19U /*!< Sector Number 19  */
  #define FLASH_SECTOR_BA     20U /*!< Sector Number 20  */
  #define FLASH_SECTOR_BB     21U /*!< Sector Number 21  */

  #define FLASH_SECTOR_A1_BASE_ADDR        0x00000000U
  #define FLASH_SECTOR_A2_BASE_ADDR        0x00002000U
  #define FLASH_SECTOR_A3_BASE_ADDR        0x00008000U
  #define FLASH_SECTOR_A4_BASE_ADDR        0x00010000U
  #define FLASH_SECTOR_A5_BASE_ADDR        0x00018000U
  #define FLASH_SECTOR_AA_BASE_ADDR        0x0001FC00U
  #define FLASH_SECTOR_A6_BASE_ADDR        0x00020000U
  #define FLASH_SECTOR_A7_BASE_ADDR        0x00028000U
  #define FLASH_SECTOR_A8_BASE_ADDR        0x00030000U
  #define FLASH_SECTOR_A9_BASE_ADDR        0x00038000U
  #define FLASH_SECTOR_AB_BASE_ADDR        0x0003FC00U
  #define FLASH_SECTOR_B1_BASE_ADDR        0x00040000U
  #define FLASH_SECTOR_B2_BASE_ADDR        0x00042000U
  #define FLASH_SECTOR_B3_BASE_ADDR        0x00048000U
  #define FLASH_SECTOR_B4_BASE_ADDR        0x00050000U
  #define FLASH_SECTOR_B5_BASE_ADDR        0x00058000U
  #define FLASH_SECTOR_BA_BASE_ADDR        0x0005FC00U
  #define FLASH_SECTOR_B6_BASE_ADDR        0x00060000U
  #define FLASH_SECTOR_B7_BASE_ADDR        0x00068000U
  #define FLASH_SECTOR_B8_BASE_ADDR        0x00070000U
  #define FLASH_SECTOR_B9_BASE_ADDR        0x00078000U
  #define FLASH_SECTOR_BB_BASE_ADDR        0x0007FC00U

  #define GET_FLASH_SECTOR(addr,sector)          { \
                                            if(addr<FLASH_SECTOR_A2_BASE_ADDR)        sector = FLASH_SECTOR_A1;  \
                                            else if(addr<FLASH_SECTOR_A3_BASE_ADDR)   sector = FLASH_SECTOR_A2;  \
                                            else if(addr<FLASH_SECTOR_A4_BASE_ADDR)   sector = FLASH_SECTOR_A3;  \
                                            else if(addr<FLASH_SECTOR_A5_BASE_ADDR)   sector = FLASH_SECTOR_A4;  \
                                            else if(addr<FLASH_SECTOR_AA_BASE_ADDR)   sector = FLASH_SECTOR_A5;  \
                                            else if(addr<FLASH_SECTOR_A6_BASE_ADDR)   sector = FLASH_SECTOR_AA;  \
                                            else if(addr<FLASH_SECTOR_A7_BASE_ADDR)   sector = FLASH_SECTOR_A6;  \
                                            else if(addr<FLASH_SECTOR_A8_BASE_ADDR)   sector = FLASH_SECTOR_A7;  \
                                            else if(addr<FLASH_SECTOR_A9_BASE_ADDR)   sector = FLASH_SECTOR_A8;  \
                                            else if(addr<FLASH_SECTOR_AB_BASE_ADDR)   sector = FLASH_SECTOR_A9;  \
                                            else if(addr<FLASH_SECTOR_B1_BASE_ADDR)   sector = FLASH_SECTOR_AB;  \
                                            else if(addr<FLASH_SECTOR_B2_BASE_ADDR)   sector = FLASH_SECTOR_B1;  \
                                            else if(addr<FLASH_SECTOR_B3_BASE_ADDR)   sector = FLASH_SECTOR_B2;  \
                                            else if(addr<FLASH_SECTOR_B4_BASE_ADDR)   sector = FLASH_SECTOR_B3;  \
                                            else if(addr<FLASH_SECTOR_B5_BASE_ADDR)   sector = FLASH_SECTOR_B4;  \
                                            else if(addr<FLASH_SECTOR_BA_BASE_ADDR)   sector = FLASH_SECTOR_B5;  \
                                            else if(addr<FLASH_SECTOR_B6_BASE_ADDR)   sector = FLASH_SECTOR_BA;  \
                                            else if(addr<FLASH_SECTOR_B7_BASE_ADDR)   sector = FLASH_SECTOR_B6;  \
                                            else if(addr<FLASH_SECTOR_B8_BASE_ADDR)   sector = FLASH_SECTOR_B7;  \
                                            else if(addr<FLASH_SECTOR_B9_BASE_ADDR)   sector = FLASH_SECTOR_B8;  \
                                            else if(addr<FLASH_SECTOR_BB_BASE_ADDR)   sector = FLASH_SECTOR_B9;  \
                                            else    sector = FLASH_SECTOR_BB;  \
                                          }

  #define FLASH_SECTOR_KEY_BASE_ADDR         0x4000F060U
  #define FLASH_SECTOR_KEY_ADDR(sector)      (sector<=10U) ? (FLASH_SECTOR_KEY_BASE_ADDR+(sector<<2)) : (FLASH_SECTOR_KEY_BASE_ADDR+0x40U+((sector-11U)<<2))
                                          
  #define FLASH_SECTOR_KEY(sector)           (sector<=10U) ? (0x7161U+0x101U*sector) : (0x8161U+0x101U*(sector-11U))
                                      
  #define FLASH_SECTOR_UNLOCK(sector)        (M32(FLASH_SECTOR_KEY_ADDR(sector))=FLASH_SECTOR_KEY(sector))
  #define FLASH_SECTOR_LOCK(sector)          (M32(FLASH_SECTOR_KEY_ADDR(sector))=CMU_FLASHLOCK_Locked)
#endif


#define FLASH_TYPEERASE_PAGEERASE   0x00000002U
#define FLASH_TYPEERASE_MASSERASE   0x00000003U

#define FLASH_HALFWORD_MASK         0xFFFFFFFEU
#define FLASH_HALFWORD_SHIFT        0x00000001U
#define FLASH_WORD_MASK             0xFFFFFFFCU
#define FLASH_WORD_SHIFT            0x00000002U

#define FLASH_BANK0_ADDR            (HT_FLASH_BASE)
#define FLASH_BANK1_ADDR            (HT_FLASH_BASE+0x00040000U)
#define FLASH_ERASE_DATA            0xFFU

#define FLASH_ADDRESS_ERR						0x0000EEEEU

#if defined USE_FLASH_BLOCK
#define FLASH_BLOCK_UNLOCK(block)   ((block) ? (HT_CMU->FLASHLOCK_H256 = CMU_FLASHLOCK_UnLocked) : (HT_CMU->FLASHLOCK_L256 = CMU_FLASHLOCK_UnLocked)) 
#define FLASH_BLOCK_LOCK(block)     ((block) ? (HT_CMU->FLASHLOCK_H256 = CMU_FLASHLOCK_Locked)   : (HT_CMU->FLASHLOCK_L256 = CMU_FLASHLOCK_Locked))
#define FLASH_BLOCK_ERASE(block)    ((block) ? (M32(FLASH_BANK1_ADDR) = FLASH_ERASE_DATA) : (M32(FLASH_BANK0_ADDR) = FLASH_ERASE_DATA))
#endif

#define IS_FLASH_ADDRESS(ADDRESS)       ((ADDRESS)<FLASH_MAX_ADDRESS)	/* do not check (>=0x00000000) */

#if defined(USE_INFOFLASH_SECTOR_12)
    #define IS_INFOFLASH_ADDRESS(ADDRESS)   		((((ADDRESS)>=INFO_MIN_ADDRESS) && ((ADDRESS)<INFO_MAX_ADDRESS)) || (((ADDRESS)>=INFO_ADDL_MIN_ADDRESS)&&((ADDRESS)<INFO_ADDL_MAX_ADDRESS)))
    #define IS_ADDL_INFOFLASH_ADDRESS(ADDRESS)	     (((ADDRESS)>=INFO_ADDL_MIN_ADDRESS)&&((ADDRESS)<INFO_ADDL_MAX_ADDRESS))

    #define INFOFLASH_ADDL_SECTOR_D     0U  /*!< Additional Sector Number 0   */
    #define INFOFLASH_ADDL_SECTOR_E     1U  /*!< Additional Sector Number 1   */
    #define INFOFLASH_ADDL_SECTOR_F     2U  /*!< Additional Sector Number 2   */
    #define INFOFLASH_ADDL_SECTOR_G     3U  /*!< Additional Sector Number 3   */
    #define INFOFLASH_ADDL_SECTOR_H     4U  /*!< Additional Sector Number 4   */
    #define INFOFLASH_ADDL_SECTOR_I     5U  /*!< Additional Sector Number 5   */
    #define INFOFLASH_ADDL_SECTOR_J     6U  /*!< Additional Sector Number 6   */
    #define INFOFLASH_ADDL_SECTOR_K     7U  /*!< Additional Sector Number 7   */
    #define INFOFLASH_ADDL_SECTOR_L     8U  /*!< Additional Sector Number 8   */
    #define INFOFLASH_ADDL_SECTOR_M     9U  /*!< Additional Sector Number 9   */
    #define INFOFLASH_ADDL_SECTOR_N    10U  /*!< Additional Sector Number 10  */

    #define INFOFLASH_ADDL_SECTOR_D_BASE_ADDR        (0x1FFFCC00U + 0x0000U)
    #define INFOFLASH_ADDL_SECTOR_E_BASE_ADDR        (0x1FFFCC00U + 0x0400U)
    #define INFOFLASH_ADDL_SECTOR_F_BASE_ADDR        (0x1FFFCC00U + 0x0800U)
    #define INFOFLASH_ADDL_SECTOR_G_BASE_ADDR        (0x1FFFCC00U + 0x0C00U)
    #define INFOFLASH_ADDL_SECTOR_H_BASE_ADDR        (0x1FFFCC00U + 0x1000U)
    #define INFOFLASH_ADDL_SECTOR_I_BASE_ADDR        (0x1FFFCC00U + 0x1400U)
    #define INFOFLASH_ADDL_SECTOR_J_BASE_ADDR        (0x1FFFCC00U + 0x1800U)
    #define INFOFLASH_ADDL_SECTOR_K_BASE_ADDR        (0x1FFFCC00U + 0x1C00U)
    #define INFOFLASH_ADDL_SECTOR_L_BASE_ADDR        (0x1FFFCC00U + 0x2000U)
    #define INFOFLASH_ADDL_SECTOR_M_BASE_ADDR        (0x1FFFCC00U + 0x2400U)
    #define INFOFLASH_ADDL_SECTOR_N_BASE_ADDR        (0x1FFFCC00U + 0x2800U)

    #define GET_ADDL_INFOFLASH_SECTOR(addr,sector)   { \
                                            if(addr<INFOFLASH_ADDL_SECTOR_E_BASE_ADDR)        sector = INFOFLASH_ADDL_SECTOR_D;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_F_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_E;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_G_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_F;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_H_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_G;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_I_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_H;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_J_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_I;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_K_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_J;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_L_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_K;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_M_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_L;  \
                                            else if(addr<INFOFLASH_ADDL_SECTOR_N_BASE_ADDR)   sector = INFOFLASH_ADDL_SECTOR_M;  \
                                            else                                              sector = INFOFLASH_ADDL_SECTOR_N;  \
                                          }
   
    #define INFOFLASH_ADDL_MIN_ADDR(sector)	(0x1FFFCC00U + sector*0x0400U)
    #define INFOFLASH_ADDL_MAX_ADDR(sector)	(0x1FFFD000U + sector*0x0400U)
																					
    #define INFOFLASH_ADDL_SECTOR_KEY_BASE_ADDR      0x4000F110U
    #define INFOFLASH_ADDL_SECTOR_KEY_ADDR(sector)   INFOFLASH_ADDL_SECTOR_KEY_BASE_ADDR+(sector<<2)
    #define INFOFLASH_ADDL_SECTOR_KEY(sector)        (0xF996U-sector)
                                      
    #define INFOFLASH_ADDL_SECTOR_UNLOCK(sector)     (M32(INFOFLASH_ADDL_SECTOR_KEY_ADDR(sector))=INFOFLASH_ADDL_SECTOR_KEY(sector))
    #define INFOFLASH_ADDL_SECTOR_LOCK(sector)       (M32(INFOFLASH_ADDL_SECTOR_KEY_ADDR(sector))=CMU_FLASHLOCK_Locked)

#else
#define IS_INFOFLASH_ADDRESS(ADDRESS)   (((ADDRESS)>=INFO_MIN_ADDRESS) && ((ADDRESS)<=INFO_MAX_ADDRESS))
#endif

#define IS_FLASH_TYPEERASE(VALUE)       (((VALUE)==FLASH_TYPEERASE_PAGEERASE) || ((VALUE)==FLASH_TYPEERASE_MASSERASE))

#define IS_FLASH_BLOCK(BLOCK)           (((BLOCK)==FlashBlock1) || ((BLOCK)==FlashBlock2))

/*
*********************************************************************************************************
*                                             Global Variable
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           Global Function Declaration
*********************************************************************************************************
*/

void HT_Flash_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num);
void HT_Flash_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num);
void HT_Flash_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num);
void HT_Flash_ByteRead(uint8_t *pReadByte, uint32_t Address, uint32_t Num);
void HT_Flash_HalfWordRead(uint16_t *pReadHalfWord, uint32_t Address, uint32_t Num);
void HT_Flash_WordRead(uint32_t *pReadWord, uint32_t Address, uint32_t Num);
void HT_Flash_PageErase(uint32_t EraseAddress);
void HT_Flash_ChipErase(void);
#if defined(USE_FLASH_BLOCK) 
void HT_Flash_BlockChipErase(FLASH_BlockEraseTypeDef EraseBlock);
#endif
void HT_Flash_PageEraseWithSectionUnlock(uint32_t EraseAddress);

FLASH_RetStaTypeDef HT_Flash_EWR_Pro(uint32_t Address, FLASH_WorkMethodTypeDef Method, uint8_t *pBuff, uint32_t Num, uint32_t Key);

void HT_Info_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num);
void HT_Info_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num);
void HT_Info_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num);
void HT_Info_ByteRead(uint8_t *pReadByte, uint32_t Address, uint32_t Num);
void HT_Info_HalfWordRead(uint16_t *pReadHalfWord, uint32_t Address, uint32_t Num);
void HT_Info_WordRead(uint32_t *pReadWord, uint32_t Address, uint32_t Num);
void HT_Info_PageErase(uint32_t EraseAddress);

FLASH_RetStaTypeDef HT_Info_EWR_Pro(uint32_t Address, FLASH_WorkMethodTypeDef Method, uint8_t *pBuff, uint32_t Num, uint32_t Key);

#ifdef USE_HT503x_MEMORY
	void HT_Info_Additional_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num);
	void HT_Info_Additional_HalfWordWrite(const uint16_t *pWriteByte, uint32_t Address, uint32_t Num);
	void HT_Info_Additional_WordWrite(const uint32_t *pWriteByte, uint32_t Address, uint32_t Num);
	void HT_Info_Additional_PageErase(uint32_t EraseAddress);
#endif
	
    
#ifdef __cplusplus
}
#endif

#endif /* __HT60xx_FLASH_H__ */
