/*
*********************************************************************************************************
*                                              HT6XXX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : ht6xxx_flash.c
* By           : Hitrendtech_SD
* Version      : V2.0.0
* Description  :
*********************************************************************************************************
*/

#define  __HT6XXX_FLASH_C
#include "ht6xxx_lib.h"


/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/
#define M8(adr)     (*((volatile uint8_t *)  (adr)))
#define M16(adr)    (*((volatile uint16_t *) (adr)))
#define M32(adr)    (*((volatile uint32_t *) (adr)))

static const uint32_t RegisterWriteProtect[]={CMU_WPREG_Protected, CMU_WPREG_UnProtected};


/*
*********************************************************************************************************
*                                             Local Variables
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                           Local Function Declaration
*********************************************************************************************************
*/


/**
*********************************************************************************************************
*                                         FLASH BYTE WRITE
* @brief:   Flash Byte Write
*
* @param:   pWriteByte    pointer to the first address of the data to be written
* @param:   Address       the first address where the data will be written to Flash
* @param:   Num           data length(bytes)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Flash_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;

  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    HT_MAIN_FLASH_UNLOCK;
    SET_FLASH_WRITE;

    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+i));
      if ((Address+i) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M8(Address+i) = pWriteByte[i];                                             /*!< Flash write                                  */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    HT_MAIN_FLASH_LOCK;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */
  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_FLASH_BWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_FLASH_BWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_FLASH_BWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_FLASH_BWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_FLASH_BWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_FLASH_BWR_END\n"
"IAR_FLASH_BWR_LOOP:\n"
    "LDRB   R5, [R0]\n"
    "NOP\n"
    "STRB   R5, [R1]\n"
"IAR_FLASH_BWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_FLASH_BWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #1\n"
    "ADDS   R1, R1, #1\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_FLASH_BWR_LOOP\n"
"IAR_FLASH_BWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
"data\n"
"IAR_FLASH_BWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_FLASH_BWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_FLASH_BWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
  );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Flash_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_FLASH_BWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_FLASH_BWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_FLASH_BWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_FLASH_BWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_FLASH_BWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_FLASH_BWR_END
KEIL_FLASH_BWR_LOOP
    LDRB    R5, [R0]
    NOP
    STRB    R5, [R1]
KEIL_FLASH_BWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_FLASH_BWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #1
    ADDS    R1, R1, #1
    SUBS    R2, R2, #1
    BNE     KEIL_FLASH_BWR_LOOP
KEIL_FLASH_BWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
|KEIL_FLASH_BWR_WPREG_REG_ADDR| DCD    0x4000F000
|KEIL_FLASH_BWR_WPREG_UL_VAL|   DCD    0x0000A55A
|KEIL_FLASH_BWR_CONFIG_UL_VAL|  DCD    0x00007A68
}
#endif

/**
*********************************************************************************************************
*                                         FLASH BYTE READ
* @brief:   Flash Byte Read
*
* @param:   pReadByte    pointer to the first address where read data is stored
* @param:   Address      the first address of the Flash that is read
* @param:   Num          data length(bytes)
*
* @retval:  None
*
* @Note:    Users should be careful not to read data beyond the scope of saving
            Adresses that exceed flash capacity will not return data
*********************************************************************************************************
*/
void HT_Flash_ByteRead(uint8_t *pReadByte, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;

  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                        /*!< Disable write protection                     */
    SET_FLASH_READ;

    HT_CMU->WPREG = writeProtect;                                                 /*!< Restore previous write protection settings   */

    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+i));
      if ((Address+i) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      pReadByte[i] = M8(Address+i);                                               /*!< Flash read                                   */
    }
  }
}

/**
*********************************************************************************************************
*                                         FLASH HALF WORD WRITE
* @brief:   Flash Half Word Write
*
* @param:   pWriteHalfWord  pointer to the first address of the data to be written
* @param:   Address         the first address where the data will be written to Flash
* @param:   Num             data length(half word)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
            Ensure that the address is halfword aligned
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Flash_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;

  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    HT_MAIN_FLASH_UNLOCK;
    SET_FLASH_WRITE;

    Address &= FLASH_HALFWORD_MASK;                                             /*!< Make sure halfwords are aligned              */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+(i<<FLASH_HALFWORD_SHIFT)));
      if ((Address+(i<<FLASH_HALFWORD_SHIFT)) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M16(Address+(i<<FLASH_HALFWORD_SHIFT)) = pWriteHalfWord[i];               /*!< Flash write                                  */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    HT_MAIN_FLASH_LOCK;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */
  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_FLASH_HWWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_FLASH_HWWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_FLASH_HWWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_FLASH_HWWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_FLASH_HWWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_FLASH_HWWR_END\n"
    "MOVS   R5, #1\n"
    "BICS   R1, R1, R5\n"
"IAR_FLASH_HWWR_LOOP:\n"
    "LDRH   R5, [R0]\n"
    "NOP\n"
    "STRH   R5, [R1]\n"
"IAR_FLASH_HWWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_FLASH_HWWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #2\n"
    "ADDS   R1, R1, #2\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_FLASH_HWWR_LOOP\n"
"IAR_FLASH_HWWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
"data\n"
"IAR_FLASH_HWWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_FLASH_HWWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_FLASH_HWWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
      );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Flash_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_FLASH_HWWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_FLASH_HWWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_FLASH_HWWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_FLASH_HWWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_FLASH_HWWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_FLASH_HWWR_END
    MOVS    R5, #1
    BICS    R1, R1, R5
KEIL_FLASH_HWWR_LOOP
    LDRH    R5, [R0]
    NOP
    STRH    R5, [R1]
KEIL_FLASH_HWWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_FLASH_HWWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #2
    ADDS    R1, R1, #2
    SUBS    R2, R2, #1
    BNE     KEIL_FLASH_HWWR_LOOP
KEIL_FLASH_HWWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
|KEIL_FLASH_HWWR_WPREG_REG_ADDR| DCD    0x4000F000
|KEIL_FLASH_HWWR_WPREG_UL_VAL|   DCD    0x0000A55A
|KEIL_FLASH_HWWR_CONFIG_UL_VAL|  DCD    0x00007A68
}
#endif

/**
*********************************************************************************************************
*                                         FLASH HALF WORD READ
* @brief:   Flash Half Word Read
*
* @param:   pReadHalfWord    pointer to the first address where read data is stored
* @param:   Address          the first address of the Flash that is read
* @param:   Num              data length(half word)
*
* @retval:  None
*
* @Note:    Users should be careful not to read data beyond the scope of saving
            Adresses that exceed flash capacity will not return data
*********************************************************************************************************
*/
void HT_Flash_HalfWordRead(uint16_t *pReadHalfWord, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  
  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    SET_FLASH_READ;

    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */

    Address &= FLASH_HALFWORD_MASK;                                             /*!< Make sure halfwords are aligned              */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+(i<<FLASH_HALFWORD_SHIFT)));
      if ((Address+(i<<FLASH_HALFWORD_SHIFT)) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      pReadHalfWord[i] = M16(Address+(i<<FLASH_HALFWORD_SHIFT));                                      /*!< Flash read                                   */
    }
  }
}

/**
*********************************************************************************************************
*                                         FLASH WORD WRITE
* @brief:   Flash Word Write
*
* @param:   pWriteWord  pointer to the first address of the data to be written
* @param:   Address         the first address where the data will be written to Flash
* @param:   Num             data length(word)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
            Ensure that the address is word aligned
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Flash_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;

  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    HT_MAIN_FLASH_UNLOCK;
    SET_FLASH_WRITE;

    Address &= FLASH_WORD_MASK;                                                 /*!< Make sure word are aligned                   */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+(i<<FLASH_WORD_SHIFT)));
      if ((Address+(i<<FLASH_WORD_SHIFT)) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M32(Address+(i<<FLASH_WORD_SHIFT)) = pWriteWord[i];                       /*!< Flash write                                  */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    HT_MAIN_FLASH_LOCK;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */

  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_FLASH_WWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_FLASH_WWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_FLASH_WWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_FLASH_WWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_FLASH_WWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_FLASH_WWR_END\n"
    "MOVS   R5, #3\n"
    "BICS   R1, R1, R5\n"
"IAR_FLASH_WWR_LOOP:\n"
    "LDR    R5, [R0]\n"
    "NOP\n"
    "STR    R5, [R1]\n"
"IAR_FLASH_WWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_FLASH_WWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #4\n"
    "ADDS   R1, R1, #4\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_FLASH_WWR_LOOP\n"
"IAR_FLASH_WWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
"data\n"
"IAR_FLASH_WWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_FLASH_WWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_FLASH_WWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
      );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Flash_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_FLASH_WWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_FLASH_WWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_FLASH_WWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_FLASH_WWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_FLASH_WWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_FLASH_WWR_END
    MOVS    R5, #3
    BICS    R1, R1, R5
KEIL_FLASH_WWR_LOOP
    LDR     R5, [R0]
    NOP
    STR     R5, [R1]
KEIL_FLASH_WWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_FLASH_WWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #4
    ADDS    R1, R1, #4
    SUBS    R2, R2, #1
    BNE     KEIL_FLASH_WWR_LOOP
KEIL_FLASH_WWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
|KEIL_FLASH_WWR_WPREG_REG_ADDR| DCD    0x4000F000
|KEIL_FLASH_WWR_WPREG_UL_VAL|   DCD    0x0000A55A
|KEIL_FLASH_WWR_CONFIG_UL_VAL|  DCD    0x00007A68
}
#endif

/**
*********************************************************************************************************
*                                         FLASH WORD READ
* @brief:   Flash Word Read
*
* @param:   pReadWord    pointer to the first address where read data is stored
* @param:   Address      the first address of the Flash that is read
* @param:   Num          data length(word)
*
* @retval:  None
*
* @Note:    Users should be careful not to read data beyond the scope of saving
            Adresses that exceed flash capacity will not return data
*********************************************************************************************************
*/
void HT_Flash_WordRead(uint32_t *pReadWord, uint32_t Address, uint32_t Num)
{
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_FLASH_ADDRESS(Address));
  if (Address >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                        /*!< Disable write protection                     */

    SET_FLASH_READ;

    HT_CMU->WPREG = writeProtect;                                                 /*!< Restore previous write protection settings   */

    Address &= FLASH_WORD_MASK;                                                   /*!< Make sure words are aligned             */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_FLASH_ADDRESS(Address+(i<<FLASH_WORD_SHIFT)));
      if ((Address+(i<<FLASH_WORD_SHIFT)) >= FLASH_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      pReadWord[i] = M32(Address+(i<<FLASH_WORD_SHIFT));                                            /*!< Flash read         */
    }
  }
}

/**
*********************************************************************************************************
*                                         FLASH PAGE ERASE
* @brief:   Flash Page Erase
*
* @param:   EraseAddress    Page erase address
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Flash_PageErase(uint32_t EraseAddress)
{
#if defined USE_HT633x_MEMORY
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_FLASH_ADDRESS(EraseAddress));
  if (EraseAddress >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                        /*!< Disable write protection            */

    HT_MAIN_FLASH_UNLOCK;                                                         /*!< Flash unlock                        */
    SET_FLASH_PAGEERASE;                                                          /*!< Flash PAGE erase                    */
    EraseAddress &= FLASH_WORD_MASK;                                              /*!< Make sure word are aligned          */
    M32(EraseAddress) = FLASH_ERASE_DATA;                                         /*!< Execute flash chip erase            */
    while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                                 /*!< Waiting for programming end         */

    SET_FLASH_READ;                                                               /*!< Flash read                          */
    HT_MAIN_FLASH_LOCK;                                                           /*!< Flash lock                          */

    HT_CMU->WPREG = writeProtect;                                                 /*!< Restore previous write protection settings     */
  }
#else
asm(
    "PUSH   {R4}\n"
    "LDR    R3, IAR_FLASH_PGES_WPREG_UL_VAL\n"
    "LDR    R1, IAR_FLASH_PGES_WPREG_REG_ADDR\n"
    "LDR    R2, [R1]\n"
    "LSLS   R2, R2, #31\n"
    "BPL    IAR_FLASH_PGES_CLEAR\n"
    "MOVS   R2, R3\n"
    "B      IAR_FLASH_PGES_CONFIG_REG_SET\n"
"IAR_FLASH_PGES_CLEAR:\n"
    "MOVS   R2, #0\n"
"IAR_FLASH_PGES_CONFIG_REG_SET:\n"
    "STR    R3, [R1]\n"
    "LDR    R3, IAR_FLASH_PGES_CONFIG_UL_VAL\n"
    "STR    R3, [R1, #0x38]\n"
    "MOVS   R3, #2\n"
    "STR    R3, [R1, #0x34]\n"
    "MOVS   R3, #255\n"
    "MOVS   R4, #3\n"
    "BICS   R0, R0, R4\n"
    "NOP\n"
    "STR    R3, [R0]\n"
"IAR_FLASH_PGES_FLAG_CHK_LOOP:\n"
    "LDR    R0, [R1, #0x34]\n"
    "LSLS   R0, R0, #29\n"
    "BMI    IAR_FLASH_PGES_FLAG_CHK_LOOP\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R1, #0x34]\n"
    "STR    R0, [R1, #0x38]\n"
    "STR    R2, [R1]\n"
    "POP    {R4}\n"
    "BX     LR\n"
"data\n"
"IAR_FLASH_PGES_WPREG_REG_ADDR: DC32    0x4000f000\n"
"IAR_FLASH_PGES_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_FLASH_PGES_CONFIG_UL_VAL:  DC32    0x00007A68\n"
  );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Flash_PageErase(uint32_t EraseAddress)
{
    PUSH    {R4}
    LDR     R3, |KEIL_FLASH_PGES_WPREG_UL_VAL|
    LDR     R1, |KEIL_FLASH_PGES_WPREG_REG_ADDR|
    LDR     R2, [R1]
    LSLS    R2, R2, #31
    BPL     KEIL_FLASH_PGES_CLEAR
    MOVS    R2, R3
    B       KEIL_FLASH_PGES_CONFIG_REG_SET
KEIL_FLASH_PGES_CLEAR
    MOVS    R2, #0
KEIL_FLASH_PGES_CONFIG_REG_SET
    STR     R3, [R1]
    LDR     R3, |KEIL_FLASH_PGES_CONFIG_UL_VAL|
    STR     R3, [R1, #0x38]
    MOVS    R3, #2
    STR     R3, [R1, #0x34]
    MOVS    R3, #255
    MOVS    R4, #3
    BICS    R0, R0, R4
    NOP
    STR     R3, [R0]
KEIL_FLASH_PGES_FLAG_CHK_LOOP
    LDR     R0, [R1, #0x34]
    LSLS    R0, R0, #29
    BMI     KEIL_FLASH_PGES_FLAG_CHK_LOOP
    MOVS    R0, #0
    STR     R0, [R1, #0x34]
    STR     R0, [R1, #0x38]
    STR     R2, [R1]
    POP     {R4}
    BX      LR
|KEIL_FLASH_PGES_WPREG_REG_ADDR| DCD    0x4000F000
|KEIL_FLASH_PGES_WPREG_UL_VAL|   DCD    0x0000A55A
|KEIL_FLASH_PGES_CONFIG_UL_VAL|  DCD    0x00007A68
}
#endif

/**
*********************************************************************************************************
*                                         FLASH CHIP ERASE
* @brief:   Flash Chip Erase
*
* @param:   None
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Flash_ChipErase(void)
{
  uint32_t writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];    /*!< Save the current write protected status      */
  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection            */

  HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked;                            /*!< Flash unlock                        */
  HT_CMU->FLASHCON = CMU_FLASHCON_FOP_CHIPERASE;                         /*!< Flash erase                         */
  M32(HT_FLASH_BASE) = FLASH_ERASE_DATA;                                 /*!< Execute flash chip erase            */
  while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                          /*!< Waiting for programming end         */

  HT_CMU->FLASHCON = CMU_FLASHCON_FOP_READ;                              /*!< Flash read                          */
  HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked;                              /*!< Flash lock                          */

  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */
}

#if defined(USE_FLASH_BLOCK) 
/**
*********************************************************************************************************
*                                         FLASH BLOCK CHIP ERASE
* @brief:   Flash Block Erase(256K) (Block erase for HT6x3x, Chip erase for other)
*
* @param:   EraseBlock    Block number
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Flash_BlockChipErase(FLASH_BlockEraseTypeDef EraseBlock)
{
  uint32_t writeProtect;
  writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /*!< Disable write protection           */

  assert_param(IS_FLASH_BLOCK(EraseBlock));  
  if (EraseBlock > FlashBlock2)
  {
    return;
  }
  FLASH_BLOCK_UNLOCK(EraseBlock);                                        /*!< Flash unlock                        */

  HT_CMU->FLASHCON = CMU_FLASHCON_FOP_CHIPERASE;                         /*!< Flash erase                         */

  FLASH_BLOCK_ERASE(EraseBlock);
  while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                          /*!< Waiting for programming end         */

  HT_CMU->FLASHCON = CMU_FLASHCON_FOP_READ;                              /*!< Flash read                          */

  FLASH_BLOCK_LOCK(EraseBlock);                                          /*!< Flash lock                          */

  HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */
}
#endif

/**
*********************************************************************************************************
*                                         FLASH PAGE ERASE WITH SECTION UNLOCK
* @brief:   Flash Page Erase        (Section unlock for HT6x3x, HT502x, HT503x, Chip unlock for other)
*
* @param:   EraseAddress            Page erase address
*
* @retval:  None
* 
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Flash_PageEraseWithSectionUnlock(uint32_t EraseAddress)
{
  uint32_t writeProtect;
  uint32_t error = 0U;
#if defined(USE_FLASH_SECTOR)
  uint32_t sectorNum = 0U;
#endif
  assert_param(IS_FLASH_ADDRESS(EraseAddress));
  if (EraseAddress >= FLASH_MAX_ADDRESS)
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];              /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                    /*!< Disable write protection           */
  #if defined(USE_FLASH_SECTOR)
    GET_FLASH_SECTOR(EraseAddress,sectorNum);
    FLASH_SECTOR_UNLOCK(sectorNum);                                           /*!< Flash unlock                            */
  #else  
    HT_MAIN_FLASH_UNLOCK;                               							/*!< Flash unlock                        */
  #endif

    SET_FLASH_PAGEERASE;

    EraseAddress &= FLASH_WORD_MASK;                                        /*!< Make sure words are aligned             */
    M32(EraseAddress) = FLASH_ERASE_DATA;                                   /*!< Execute flash page erase                */
    while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                           /*!< Waiting for programming end             */

    SET_FLASH_READ;
  #if defined(USE_FLASH_SECTOR)
    FLASH_SECTOR_LOCK(sectorNum);                                          /*!< Flash lock                               */
  #else
    HT_MAIN_FLASH_LOCK;                              							 /*!< Flash lock                          */
  #endif

    HT_CMU->WPREG = writeProtect;                                          /*!< Restore previous write protection settings     */
  }
}



/**
*********************************************************************************************************
*                                    FLASH BYTE ERASE/WRITE/READ
* @brief:   Flash PageErase/Write/Read
*
* @param:   Address     Flash address
* @param:   Method      FlashErase/FlashWrite/FlashRead
* @param:   pBuff       the first address pointer to data array(Only for Write/Read)
* @param:   Num         data length(byte) (Only for Write/Read)
* @param:   Key         The check control word that performs the operation
* 
* @retval:  RetSta      FlashSucc      FLASH Operation is successful
*                       FlashNone      FLASH No operation 
*                       FlashErrKey    User entered an incorrect operation code
*                       FlashErrAddr   FLASH address is incorrect
*                       FlashErrMod    FLASH operation mode is incorrect
*                       FlashErrNum    User entered an incorrect buffer range
*                       FlashErrBuf    User entered an incorrect buffer address
*********************************************************************************************************
*/
FLASH_RetStaTypeDef HT_Flash_EWR_Pro(uint32_t Address, FLASH_WorkMethodTypeDef Method, uint8_t *pBuff, uint32_t Num, uint32_t Key)
{
  uint32_t writeProtect, i;
  FLASH_RetStaTypeDef RetSta = FlashNone;

  if ((Key & FLASH_EWR_KEY_2_AREA) == FLASH_EWR_KEY_2)                                      /* Check whether the keywords 2 are valid         */
  {
    Key &= (~FLASH_EWR_KEY_2_AREA);                                                         /* Clears the current process action word         */

    if (Address < FLASH_MAX_ADDRESS)                                                        /* Check the operation address is valid           */
    {
      switch (Method)                                                                       /* Check the Method is valid                      */
      {
        case FlashErase:
          if ((Key & FLASH_EWR_KEY_1_AREA) == FLASH_EWR_KEY_1)                              /* Check whether the keywords 1 are valid         */
          {
            Key &= (~FLASH_EWR_KEY_1_AREA);

            writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];     /* Save the current write protection status       */
            HT_CMU->WPREG = CMU_WPREG_UnProtected;                                          /* Disable write protection                       */
            HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked;                                     /* Flash unlock                */
            SET_FLASH_PAGEERASE;
            HT_CMU->WPREG = CMU_FLASHLOCK_Locked;                                           /* Restore the previous write protection Settings */

            if (((Key & FLASH_EWR_KEY_3_AREA) == FLASH_EWR_KEY_3) 
              && ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4))                         /* Check whether the keywords 3/4 are valid         */
            {
              Key &= (~(FLASH_EWR_KEY_3_AREA | FLASH_EWR_KEY_4_AREA));                      /* Clears the current process action word         */
              M8(Address) = FLASH_ERASE_DATA;                                               /* Execute flash page erase                       */
              while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                                 /* Waiting for programming end                    */
              RetSta = FlashSucc;
            } 
            else
            {
              RetSta = FlashErrKey;
            } 

            HT_CMU->WPREG = CMU_WPREG_UnProtected;                                          /* Disable write protection                       */
            SET_FLASH_READ;
            HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked;                                       /* Flash lock                                     */
            HT_CMU->WPREG = writeProtect;                                                   /* Restore the previous write protection Settings */
          }
          else
          {
            RetSta = FlashErrKey;
          }
        break;
        case FlashWrite:
          if ((Key & FLASH_EWR_KEY_3_AREA) == FLASH_EWR_KEY_3) 
          {
            Key &= (~FLASH_EWR_KEY_3_AREA);                                                 /* Clears the current process action word         */

            if ((Address + Num - 1U) < FLASH_MAX_ADDRESS) 
            {
              if (((uint32_t)pBuff >= BUF_MIN_ADDRESS) && ((uint32_t)pBuff < BUF_MAX_ADDRESS))
              {
                writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];                  /* Save the current write protection status       */
                HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /* Disable write protection                       */
                HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked;                                 /* Flash unlock                                   */
                SET_FLASH_WRITE;
                HT_CMU->WPREG = CMU_FLASHLOCK_Locked;                                       /* Restore the previous write protection Settings */

                if (((Key & FLASH_EWR_KEY_1_AREA) == FLASH_EWR_KEY_1) 
                  && ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4)) 
                {
                  Key &= (~(FLASH_EWR_KEY_1_AREA | FLASH_EWR_KEY_4_AREA));                  /* Clears the current process action word         */
                  for(i = 0U; i < Num; i++) 
                  {
                      M8(Address + i) = *(pBuff + i);                                       /* Execute Flash Write                            */
                      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                         /* Waiting for programming end                    */
                  }
                  RetSta = FlashSucc;
                }
                else
                {
                    RetSta = FlashErrKey;
                }

                HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /* Disable write protection                       */
                SET_FLASH_READ;
                HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked;                                   /* Flash lock                                     */
                HT_CMU->WPREG = writeProtect;                                               /* Restore the previous write protection Settings */
              }
              else
              {
                RetSta = FlashErrBuf;
              }
            } 
            else
            {
              RetSta = FlashErrNum;
            }
          }
          else
          {
            RetSta = FlashErrKey;
          }
        break;
        case FlashRead:
          if ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4) 
          {
            Key &= (~(FLASH_EWR_KEY_1_AREA | FLASH_EWR_KEY_3_AREA | FLASH_EWR_KEY_4_AREA));   /* Clear all process action words                 */
                                                                                               
            if ((Address + Num - 1U) < FLASH_MAX_ADDRESS)
            {
              if (((uint32_t)pBuff >= BUF_MIN_ADDRESS) && ((uint32_t)pBuff < BUF_MAX_ADDRESS))
              {
                SET_FLASH_READ;
                {
                  writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT]; /* Save the current write protection status       */
                  HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /* Disable write protection                       */
                  SET_FLASH_READ;
                  HT_CMU->WPREG = writeProtect;                                               /* Restore the previous write protection Settings */
                }            
                for (i = 0U; i < Num; i++) 
                {
                    *(pBuff + i) = M8(Address + i);                                           /* Execute Flash read                             */
                }
                RetSta = FlashSucc;
              }
              else
              {
                RetSta = FlashErrBuf;
              }
            }
            else
            {
              RetSta = FlashErrNum;
            }
          }
          else
          {
            RetSta = FlashErrKey;
          }
        break;
        default:
          RetSta = FlashErrMod;
        break;
      }
    }
    else
    {
      RetSta = FlashErrAddr;
    }
  }
  else
  {
    RetSta = FlashErrKey;
  }

  return RetSta;
}




/**
*********************************************************************************************************
*                                         INFO BYTE WRITE
* @brief:   InfoFlash Byte Write
*
* @param:   pWriteByte    pointer to the first address of the data to be written
* @param:   Address       the first address where the data will be written to InfoFlash
* @param:   Num           data length(bytes)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Info_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    UNLOCK_INFO;
    SET_FLASH_WRITE;

    for(i=0U; i<Num; i++)
    {
      assert_param(IS_INFOFLASH_ADDRESS(Address+i));
      if ((Address+i) >= INFO_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M8(Address+i) = pWriteByte[i];                                            /*!< Flash WRITE         */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    LOCK_INFO;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */
  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_INFO_BWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_INFO_BWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_INFO_BWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_INFO_BWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_INFO_BWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "LDR    R6, IAR_INFO_BWR_CONFIG2_UL_VAL\n"
    "STR    R6, [R3, #0x50]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_INFO_BWR_END\n"
"IAR_INFO_BWR_LOOP:\n"
    "LDRB   R5, [R0]\n"
    "NOP\n"
    "STRB   R5, [R1]\n"
"IAR_INFO_BWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_INFO_BWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #1\n"
    "ADDS   R1, R1, #1\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_INFO_BWR_LOOP\n"
"IAR_INFO_BWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x50]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
    "NOP\n"
"data\n"
"IAR_INFO_BWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_INFO_BWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_INFO_BWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
"IAR_INFO_BWR_CONFIG2_UL_VAL: DC32    0x0000F998\n"
      );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Info_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_INFO_BWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_INFO_BWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_INFO_BWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_INFO_BWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_INFO_BWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    LDR     R6, |KEIL_INFO_BWR_CONFIG2_UL_VAL|
    STR     R6, [R3, #0x50]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_INFO_BWR_END
KEIL_INFO_BWR_LOOP
    LDRB    R5, [R0]
    NOP
    STRB    R5, [R1]
KEIL_INFO_BWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_INFO_BWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #1
    ADDS    R1, R1, #1
    SUBS    R2, R2, #1
    BNE     KEIL_INFO_BWR_LOOP
KEIL_INFO_BWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x50]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
    NOP
|KEIL_INFO_BWR_WPREG_REG_ADDR| DCD     0x4000F000
|KEIL_INFO_BWR_WPREG_UL_VAL|   DCD     0x0000A55A
|KEIL_INFO_BWR_CONFIG_UL_VAL|  DCD     0x00007A68
|KEIL_INFO_BWR_CONFIG2_UL_VAL| DCD     0x0000F998
}
#endif

/**
*********************************************************************************************************
*                                         INFO BYTE READ
* @brief:   InfoFlash Byte Read
*
* @param:   pReadByte    pointer to the first address where read data is stored
* @param:   Address      the first address of the InfoFlash that is read
* @param:   Num          data length(bytes)
*
* @retval:  None
*********************************************************************************************************
*/
void HT_Info_ByteRead(uint8_t *pReadByte, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                  /*!< Disable write protection                     */

    SET_FLASH_READ;
		
    HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */

    for(i=0U; i<Num; i++)
    {
      assert_param(IS_INFOFLASH_ADDRESS(Address+i));
      if ((Address+i) >= INFO_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      pReadByte[i] = M8(Address+i);                                                         /*!< Flash read         */
    }
  }
}

/*
*********************************************************************************************************
*                                         INFO HALF WORD WRITE
* @brief:   InfoFlash Half Word Write
*
* @param:   pWriteHalfWord  pointer to the first address of the data to be written
* @param:   Address         the first address where the data will be written to InfoFlash
* @param:   Num             data length(half word)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
            Ensure that the address is halfword aligned
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Info_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    UNLOCK_INFO;
    SET_FLASH_WRITE;

    Address &= FLASH_HALFWORD_MASK;                                             /*!< Make sure halfwords are aligned              */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_INFOFLASH_ADDRESS(Address+(i<<FLASH_HALFWORD_SHIFT)));
      if ((Address+(i<<FLASH_HALFWORD_SHIFT)) >= INFO_MAX_ADDRESS)
      {
              error = FLASH_ADDRESS_ERR;
              break;
      }
      M16(Address+(i<<FLASH_HALFWORD_SHIFT)) = pWriteHalfWord[i];               /*!< Flash WRITE                             */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    LOCK_INFO;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */
  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_INFO_HWWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_INFO_HWWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_INFO_HWWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_INFO_HWWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_INFO_HWWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "LDR    R6, IAR_INFO_HWWR_CONFIG2_UL_VAL\n"
    "STR    R6, [R3, #0x50]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_INFO_HWWR_END\n"
    "MOVS   R5, #1\n"
    "BICS   R1, R1, R5\n"
"IAR_INFO_HWWR_LOOP:\n"
    "LDRH   R5, [R0]\n"
    "NOP\n"
    "STRH   R5, [R1]\n"
"IAR_INFO_HWWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_INFO_HWWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #2\n"
    "ADDS   R1, R1, #2\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_INFO_HWWR_LOOP\n"
"IAR_INFO_HWWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x50]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
    "NOP\n"
"data\n"
"IAR_INFO_HWWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_INFO_HWWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_INFO_HWWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
"IAR_INFO_HWWR_CONFIG2_UL_VAL: DC32    0x0000F998\n"
      );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Info_HalfWordWrite(const uint16_t *pWriteHalfWord, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_INFO_HWWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_INFO_HWWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_INFO_HWWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_INFO_HWWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_INFO_HWWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    LDR     R6, |KEIL_INFO_HWWR_CONFIG2_UL_VAL|
    STR     R6, [R3, #0x50]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_INFO_HWWR_END
    MOVS    R5, #1
    BICS    R1, R1, R5
KEIL_INFO_HWWR_LOOP
    LDRH    R5, [R0]
    NOP
    STRH    R5, [R1]
KEIL_INFO_HWWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_INFO_HWWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #2
    ADDS    R1, R1, #2
    SUBS    R2, R2, #1
    BNE     KEIL_INFO_HWWR_LOOP
KEIL_INFO_HWWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x50]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
    NOP
|KEIL_INFO_HWWR_WPREG_REG_ADDR| DCD     0x4000F000
|KEIL_INFO_HWWR_WPREG_UL_VAL|   DCD     0x0000A55A
|KEIL_INFO_HWWR_CONFIG_UL_VAL|  DCD     0x00007A68
|KEIL_INFO_HWWR_CONFIG2_UL_VAL| DCD     0x0000F998
}
#endif

/*
*********************************************************************************************************
*                                         INFO HALF WORD READ
* @brief:   InfoFlash Half Word Read
*
* @param:   pReadHalfWord    pointer to the first address where read data is stored
* @param:   Address          the first address of the InfoFlash that is read
* @param:   Num              data length(half word)
*
* @retval:  None
*
* @Note:    Users should be careful not to read data beyond the scope of saving
            Adresses that exceed flash capacity will not return data
*********************************************************************************************************
*/
void HT_Info_HalfWordRead(uint16_t *pReadHalfWord, uint32_t Address, uint32_t Num)
{
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
	if(error != FLASH_ADDRESS_ERR)
	{
		writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
		HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                  /*!< Disable write protection                     */

		SET_FLASH_READ;

		HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */

		Address &= FLASH_HALFWORD_MASK;                                                         /*!< Make sure halfwords are aligned              */
		for(i=0U; i<Num; i++)
		{
			assert_param(IS_INFOFLASH_ADDRESS(Address+(i<<FLASH_HALFWORD_SHIFT)));
			if ((Address+(i<<FLASH_HALFWORD_SHIFT)) >= INFO_MAX_ADDRESS)
			{
				error = FLASH_ADDRESS_ERR;
				break;
			}
			pReadHalfWord[i] = M16(Address+(i<<FLASH_HALFWORD_SHIFT));                            /*!< Flash read                                   */
		}
	}
}

/*
*********************************************************************************************************
*                                         INFO WORD WRITE
* @brief:   InfoFlash Word Write
*
* @param:   pWriteWord      pointer to the first address of the data to be written
* @param:   Address         the first address where the data will be written to InfoFlash
* @param:   Num             data length(word)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
            Ensure that the address is word aligned
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Info_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num)
{
#if defined USE_HT633x_MEMORY
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection                     */
    UNLOCK_INFO;
    SET_FLASH_WRITE;
    
    Address &= FLASH_WORD_MASK;                                                 /*!< Make sure words are aligned                  */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_INFOFLASH_ADDRESS(Address+(i<<FLASH_WORD_SHIFT)));
      if ((Address+(i<<FLASH_WORD_SHIFT)) >= INFO_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M32(Address+(i<<FLASH_WORD_SHIFT)) = pWriteWord[i];                       /*!< Flash WRITE                             */
      while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                             /*!< Waiting for programming end             */
    }
    SET_FLASH_READ;
    LOCK_INFO;
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings   */
  }
#else
asm(
    "PUSH   {R4-R6}\n"
    "LDR    R6, IAR_INFO_WWR_WPREG_UL_VAL\n"
    "MOVS   R5, #1\n"
    "LDR    R3, IAR_INFO_WWR_WPREG_REG_ADDR\n"
    "LDR    R4, [R3]\n"
    "ANDS   R4, R4, R5\n"
    "BEQ    IAR_INFO_WWR_CONFIG_REG_SET\n"
    "MOVS   R4, R6\n"
"IAR_INFO_WWR_CONFIG_REG_SET:\n"
    "STR    R6, [R3]\n"
    "LDR    R6, IAR_INFO_WWR_CONFIG_UL_VAL\n"
    "STR    R6, [R3, #0x38]\n"
    "LDR    R6, IAR_INFO_WWR_CONFIG2_UL_VAL\n"
    "STR    R6, [R3, #0x50]\n"
    "STR    R5, [R3, #0x34]\n"
    "CMP    R2, #0\n"
    "BEQ    IAR_INFO_WWR_END\n"
    "MOVS   R5, #3\n"
    "BICS   R1, R1, R5\n"
"IAR_INFO_WWR_LOOP:\n"
    "LDR    R5, [R0]\n"
    "NOP\n"
    "STR    R5, [R1]\n"
"IAR_INFO_WWR_FLAG_CHK_LOOP:\n"
    "LDR    R5, [R3, #0x34]\n"
    "LSLS   R5, R5, #29\n"
    "BMI    IAR_INFO_WWR_FLAG_CHK_LOOP\n"
    "ADDS   R0, R0, #4\n"
    "ADDS   R1, R1, #4\n"
    "SUBS   R2, R2, #1\n"
    "BNE    IAR_INFO_WWR_LOOP\n"
"IAR_INFO_WWR_END:\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R3, #0x34]\n"
    "STR    R0, [R3, #0x50]\n"
    "STR    R0, [R3, #0x38]\n"
    "STR    R4, [R3]\n"
    "POP    {R4-R6}\n"
    "BX     LR\n"
    "NOP\n"
"data\n"
"IAR_INFO_WWR_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_INFO_WWR_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_INFO_WWR_CONFIG_UL_VAL:  DC32    0x00007A68\n"
"IAR_INFO_WWR_CONFIG2_UL_VAL: DC32    0x0000F998\n"
      );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Info_WordWrite(const uint32_t *pWriteWord, uint32_t Address, uint32_t Num)
{
    PUSH    {R4-R6}
    LDR     R6, |KEIL_INFO_WWR_WPREG_UL_VAL|
    MOVS    R5, #1
    LDR     R3, |KEIL_INFO_WWR_WPREG_REG_ADDR|
    LDR     R4, [R3]
    ANDS    R4, R4, R5
    BEQ     KEIL_INFO_WWR_CONFIG_REG_SET
    MOVS    R4, R6
KEIL_INFO_WWR_CONFIG_REG_SET
    STR     R6, [R3]
    LDR     R6, |KEIL_INFO_WWR_CONFIG_UL_VAL|
    STR     R6, [R3, #0x38]
    LDR     R6, |KEIL_INFO_WWR_CONFIG2_UL_VAL|
    STR     R6, [R3, #0x50]
    STR     R5, [R3, #0x34]
    CMP     R2, #0
    BEQ     KEIL_INFO_WWR_END
    MOVS    R5, #3
    BICS    R1, R1, R5
KEIL_INFO_WWR_LOOP
    LDR     R5, [R0]
    NOP
    STR     R5, [R1]
KEIL_INFO_WWR_FLAG_CHK_LOOP
    LDR     R5, [R3, #0x34]
    LSLS    R5, R5, #29
    BMI     KEIL_INFO_WWR_FLAG_CHK_LOOP
    ADDS    R0, R0, #4
    ADDS    R1, R1, #4
    SUBS    R2, R2, #1
    BNE     KEIL_INFO_WWR_LOOP
KEIL_INFO_WWR_END
    MOVS    R0, #0
    STR     R0, [R3, #0x34]
    STR     R0, [R3, #0x50]
    STR     R0, [R3, #0x38]
    STR     R4, [R3]
    POP     {R4-R6}
    BX      LR
    NOP
|KEIL_INFO_WWR_WPREG_REG_ADDR| DCD     0x4000F000
|KEIL_INFO_WWR_WPREG_UL_VAL|   DCD     0x0000A55A
|KEIL_INFO_WWR_CONFIG_UL_VAL|  DCD     0x00007A68
|KEIL_INFO_WWR_CONFIG2_UL_VAL| DCD     0x0000F998
}
#endif

/*
*********************************************************************************************************
*                                         FLASH WORD READ
* @brief:   InfoFlash Word Read
*
* @param:   pReadWord    pointer to the first address where read data is stored
* @param:   Address      the first address of the InfoFlash that is read
* @param:   Num          data length(word)
*
* @retval:  None
*
* @Note:    Users should be careful not to read data beyond the scope of saving
            Adresses that exceed flash capacity will not return data
*********************************************************************************************************
*/
void HT_Info_WordRead(uint32_t *pReadWord, uint32_t Address, uint32_t Num)
{
  uint32_t i;
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_MIN_ADDRESS) || (Address >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                  /*!< Disable write protection                     */

    SET_FLASH_READ;

    HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */

    Address &= FLASH_WORD_MASK;                                                             /*!< Make sure words are aligned                  */
    for(i=0U; i<Num; i++)
    {
      assert_param(IS_INFOFLASH_ADDRESS(Address+(i<<FLASH_WORD_SHIFT)));
      if ((Address+(i<<FLASH_WORD_SHIFT)) >= INFO_MAX_ADDRESS)
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      pReadWord[i] = M32(Address+(i<<FLASH_WORD_SHIFT));                                    /*!< Flash read                                   */
    }
  }
}

/*
*********************************************************************************************************
*                                         INFO PAGE ERASE
* @brief:   InfoFlash Page Erase
*
* @param:   EraseAddress    Page erase address
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*             HT501x :512 bytes - 256 bytes/page
*             HT502x :1k  bytes - 1k  bytes/page
*             HT503x :1k  bytes - 1k  bytes/page
*             HT6x1x :512 bytes - 256 bytes/page
*             HT6x2x :1k  bytes - 1k  bytes/page
*             HT6x3x :1k  bytes - 1k  bytes/page
*********************************************************************************************************
*/
#if defined ( __ICCARM__ )
void HT_Info_PageErase(uint32_t EraseAddress)
{
#if defined USE_HT633x_MEMORY
  uint32_t writeProtect;
  uint32_t error = 0U;
  assert_param(IS_INFOFLASH_ADDRESS(EraseAddress));
  if ((EraseAddress < INFO_MIN_ADDRESS) || (EraseAddress >= INFO_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];   /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                      /*!< Disable write protection            */

    UNLOCK_INFO;                                                                /*!< Info Flash unlock                   */
    SET_FLASH_PAGEERASE;                                                        /*!< Flash PAGE erase                    */
    EraseAddress &= FLASH_WORD_MASK;                                            /*!< Make sure word are aligned          */
    M32(EraseAddress) = FLASH_ERASE_DATA;                                       /*!< Execute flash page erase            */
    while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                               /*!< Waiting for programming end         */

    SET_FLASH_READ;                                                             /*!< Flash read                          */
    LOCK_INFO;                                                                  /*!< Info Flash lock                     */
    HT_CMU->WPREG = writeProtect;                                               /*!< Restore previous write protection settings     */
  }
#else
asm(
    "PUSH   {R4}\n"
    "LDR    R3, IAR_INFO_PGES_WPREG_UL_VAL\n"
    "LDR    R1, IAR_INFO_PGES_WPREG_REG_ADDR\n"
    "LDR    R2, [R1]\n"
    "LSLS   R2, R2, #31\n"
    "BPL    IAR_INFO_PGES_CLEAR\n"
    "MOVS   R2, R3\n"
    "B      IAR_INFO_PGES_CONFIG_REG_SET\n"
"IAR_INFO_PGES_CLEAR:\n"
    "MOVS   R2, #0\n"
"IAR_INFO_PGES_CONFIG_REG_SET:\n"
    "STR    R3, [R1]\n"
    "LDR    R3, IAR_INFO_PGES_CONFIG_UL_VAL\n"
    "STR    R3, [R1, #0x38]\n"
    "LDR    R3, IAR_INFO_PGES_CONFIG2_UL_VAL\n"
    "STR    R3, [R1, #0x50]\n"
    "MOVS   R3, #2\n"
    "STR    R3, [R1, #0x34]\n"
    "MOVS   R3, #255\n"
    "MOVS   R4, #3\n"
    "BICS   R0, R0, R4\n"
    "NOP\n"
    "STR    R3, [R0]\n"
"IAR_INFO_PGES_FLAG_CHK_LOOP:\n"
    "LDR    R0, [R1, #0x34]\n"
    "LSLS   R0, R0, #29\n"
    "BMI    IAR_INFO_PGES_FLAG_CHK_LOOP\n"
    "MOVS   R0, #0\n"
    "STR    R0, [R1, #0x34]\n"
    "STR    R0, [R1, #0x50]\n"
    "STR    R0, [R1, #0x38]\n"
    "STR    R2, [R1]\n"
    "POP    {R4}\n"
    "BX     LR\n"
    "NOP\n"
"data\n"
"IAR_INFO_PGES_WPREG_REG_ADDR: DC32    0x4000F000\n"
"IAR_INFO_PGES_WPREG_UL_VAL:   DC32    0x0000A55A\n"
"IAR_INFO_PGES_CONFIG_UL_VAL:  DC32    0x00007A68\n"
"IAR_INFO_PGES_CONFIG2_UL_VAL: DC32    0x0000F998\n"
  );
#endif
}

#elif defined ( __CC_ARM )
__ASM void HT_Info_PageErase(uint32_t EraseAddress)
{
    PUSH    {R4}
    LDR     R3, |KEIL_INFO_PGES_WPREG_UL_VAL|
    LDR     R1, |KEIL_INFO_PGES_WPREG_REG_ADDR|
    LDR     R2, [R1]
    LSLS    R2, R2, #31
    BPL     KEIL_INFO_PGES_CLEAR
    MOVS    R2, R3
    B       KEIL_INFO_PGES_CONFIG_REG_SET
KEIL_INFO_PGES_CLEAR
    MOVS    R2, #0
KEIL_INFO_PGES_CONFIG_REG_SET
    STR     R3, [R1]
    LDR     R3, |KEIL_INFO_PGES_CONFIG_UL_VAL|
    STR     R3, [R1, #0x38]
    LDR     R3, |KEIL_INFO_PGES_CONFIG2_UL_VAL|
    STR     R3, [R1, #0x50]
    MOVS    R3, #2
    STR     R3, [R1, #0x34]
    MOVS    R3, #255
    MOVS    R4, #3
    BICS    R0, R0, R4
    NOP
    STR     R3, [R0]
KEIL_INFO_PGES_FLAG_CHK_LOOP
    LDR     R0, [R1, #0x34]
    LSLS    R0, R0, #29
    BMI     KEIL_INFO_PGES_FLAG_CHK_LOOP
    MOVS    R0, #0
    STR     R0, [R1, #0x34]
    STR     R0, [R1, #0x50]
    STR     R0, [R1, #0x38]
    STR     R2, [R1]
    POP     {R4}
    BX      LR
    NOP
|KEIL_INFO_PGES_WPREG_REG_ADDR| DCD    0x4000F000
|KEIL_INFO_PGES_WPREG_UL_VAL|   DCD    0x0000A55A
|KEIL_INFO_PGES_CONFIG_UL_VAL|  DCD    0x00007A68
|KEIL_INFO_PGES_CONFIG2_UL_VAL| DCD    0x0000F998
}
#endif

/*
*********************************************************************************************************
*                                    INFO BYTE ERASE/WRITE/READ
* @brief:   InfoFlash PageErase/Write/Read
*
* @param:   Address     InfoFlash address
* @param:   Method      FlashErase/FlashWrite/FlashRead
* @param:   pBuff       the first address pointer to data array(Only for Write/Read)
* @param:   Num         data length(byte) (Only for Write/Read)
* @param:   Key         The check control word that performs the operation
* 
* @retval:  RetSta      FlashSucc      FLASH Operation is successful
*                       FlashNone      FLASH No operation 
*                       FlashErrKey    User entered an incorrect operation code
*                       FlashErrAddr   FLASH address is incorrect
*                       FlashErrMod    FLASH operation mode is incorrect
*                       FlashErrNum    User entered an incorrect buffer range
*                       FlashErrBuf    User entered an incorrect buffer address
*********************************************************************************************************
*/
FLASH_RetStaTypeDef HT_Info_EWR_Pro (uint32_t Address, FLASH_WorkMethodTypeDef Method, uint8_t *pBuff, uint32_t Num, uint32_t Key)
{
  uint32_t writeProtect, i;
  FLASH_RetStaTypeDef RetSta = FlashNone;

  if ((Key & FLASH_EWR_KEY_2_AREA) == FLASH_EWR_KEY_2)                                      /* Check whether the keywords 2 are valid         */
  {
    Key &= (~FLASH_EWR_KEY_2_AREA);                                                         /* Clears the current process action word         */

    if ((Address >= INFO_MIN_ADDRESS) && (Address < INFO_MAX_ADDRESS))                      /* Check the operation address is valid           */
    {
      switch (Method)                                                                       /* Check the operation address is valid           */
      {
        case FlashErase:
          if ((Key & FLASH_EWR_KEY_1_AREA) == FLASH_EWR_KEY_1)                              /* Check whether the keywords 1 are valid         */
          {
            Key &= (~FLASH_EWR_KEY_1_AREA);                                                 /* Clears the current process action word         */

            writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];     /* Save the current write protection status       */
            HT_CMU->WPREG = CMU_WPREG_UnProtected;                                          /* Disable write protection                       */
            HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked;                                     /* Flash unlock                                   */
            UNLOCK_INFO;
            SET_FLASH_PAGEERASE;
            HT_CMU->WPREG = CMU_FLASHLOCK_Locked;                                           /* Restore the previous write protection Settings */

            if (((Key & FLASH_EWR_KEY_3_AREA) == FLASH_EWR_KEY_3) 
              && ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4))                         /* Check whether the keywords 3/4 are valid       */
            {
              Key &= (~(FLASH_EWR_KEY_3_AREA | FLASH_EWR_KEY_4_AREA));                      /* Clears the current process action word         */
              M8(Address) = FLASH_ERASE_DATA;                                               /* Execute flash page erase                       */
              while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                                 /* Waiting for programming end                    */
              RetSta = FlashSucc;
            } 
            else
            {
              RetSta = FlashErrKey;
            } 

            HT_CMU->WPREG = CMU_WPREG_UnProtected;                                 /* Disable write protection             */
            SET_FLASH_READ;
            LOCK_INFO;
            HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked;                              /* Flash lock                 */
            HT_CMU->WPREG = writeProtect;                                          /* Restore the previous write protection Settings         */
          }
          else
          {
            RetSta = FlashErrKey;
          }
        break;
        case FlashWrite:
          if ((Key & FLASH_EWR_KEY_3_AREA) == FLASH_EWR_KEY_3) 
          {
            Key &= (~FLASH_EWR_KEY_3_AREA);                                        /* Clears the current process action word         */

            if ((Address + Num - 1U) < INFO_MAX_ADDRESS) 
            {
              if (((uint32_t)pBuff >= BUF_MIN_ADDRESS) && ((uint32_t)pBuff < BUF_MAX_ADDRESS))
              {
                writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];     /* Save the current write protection status         */
                HT_CMU->WPREG = CMU_WPREG_UnProtected;                         /* Disable write protection             */
                HT_CMU->FLASHLOCK = CMU_FLASHLOCK_UnLocked;                    /* Flash unlock                 */
                UNLOCK_INFO;
                SET_FLASH_WRITE;

                HT_CMU->WPREG = CMU_FLASHLOCK_Locked;                          /* Restore the previous write protection Settings         */
      
                if (((Key & FLASH_EWR_KEY_1_AREA) == FLASH_EWR_KEY_1) 
                  && ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4)) 
                {
                  Key &= (~(FLASH_EWR_KEY_1_AREA | FLASH_EWR_KEY_4_AREA));   /* Clears the current process action word         */
                  for(i = 0U; i < Num; i++) 
                  {
                    M8(Address + i) = *(pBuff + i);                        /* Execute Flash Write               */
                    while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}          /* Waiting for programming end                */
                  }
                  RetSta = FlashSucc;
                }
                else
                {
                  RetSta = FlashErrKey;
                }

                HT_CMU->WPREG = CMU_WPREG_UnProtected;                         /* Disable write protection            */
                SET_FLASH_READ;
                LOCK_INFO;
                HT_CMU->FLASHLOCK = CMU_FLASHLOCK_Locked;                      /* Flash lock                */
                HT_CMU->WPREG = writeProtect;                                  /* Restore the previous write protection Settings        */
              }
              else
              {
                RetSta = FlashErrBuf;
              }
            }
            else
            {
              RetSta = FlashErrNum;
            }
          }
          else
          {
            RetSta = FlashErrKey;
          }
        break;
        case FlashRead:
          if ((Key & FLASH_EWR_KEY_4_AREA) == FLASH_EWR_KEY_4) 
          {
            Key &= (~(FLASH_EWR_KEY_1_AREA | FLASH_EWR_KEY_3_AREA | FLASH_EWR_KEY_4_AREA)); /* Clear all process action words        */
                                                                                               
            if ((Address + Num - 1U) < INFO_MAX_ADDRESS)
            {
              if (((uint32_t)pBuff >= BUF_MIN_ADDRESS) && ((uint32_t)pBuff < BUF_MAX_ADDRESS))
              {
                SET_FLASH_READ;
                {
                  writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT]; /* Save the current write protection status        */
                  HT_CMU->WPREG = CMU_WPREG_UnProtected;                     /* Disable write protection            */
                  SET_FLASH_READ;
                  HT_CMU->WPREG = writeProtect;                              /* Restore the previous write protection Settings        */
                }
       
                for (i = 0U; i < Num; i++) 
                {
                  *(pBuff + i) = M8(Address + i);                            /* Execute Flash read              */
                }
                RetSta = FlashSucc;
              }
              else
              {
                RetSta = FlashErrBuf;
              }
            }
            else
            {
              RetSta = FlashErrNum;
            }
          }
          else
          {
            RetSta = FlashErrKey;
          }
          break;
          default:
            RetSta = FlashErrMod;
          break;
      }
    }
    else
    {
      RetSta = FlashErrAddr;
    }
  }
  else
  {
    RetSta = FlashErrKey;
  }
  return RetSta;
}

#ifdef USE_HT503x_MEMORY
/**
*********************************************************************************************************
*                                      ADDITIONAL INFO BYTE WRITE
* @brief:   Additional InfoFlash Byte Write Additional
*
* @param:   pWriteByte    pointer to the first address of the data to be written
* @param:   Address       the first address where the data will be written to Additional InfoFlash
* @param:   Num           data length(bytes)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Info_Additional_ByteWrite(const uint8_t *pWriteByte, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
	uint32_t sectorNum = 0U;
  uint32_t error = 0U;
	
  assert_param(IS_ADDL_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_ADDL_MIN_ADDRESS) || (Address >= INFO_ADDL_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                 /*!< Disable write protection                     */
		
		GET_ADDL_INFOFLASH_SECTOR(Address,sectorNum); 
		INFOFLASH_ADDL_SECTOR_UNLOCK(sectorNum);
    
		SET_FLASH_WRITE;
		for(i=0U; i<Num; i++)
    {
      if ((Address+i) >= INFOFLASH_ADDL_MAX_ADDR(sectorNum))
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M8(Address+i) = pWriteByte[i];                                          /*!< Flash read         */
			while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                           /*!< Waiting for programming end             */
		}
		
		INFOFLASH_ADDL_SECTOR_LOCK(sectorNum);
    HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */
    
  }
}

/**
*********************************************************************************************************
*                                    ADDITIONAL INFO HALFWORD WRITE
* @brief:   Additional InfoFlash HalfWord Write Additional
*
* @param:   pWriteByte    pointer to the first address of the data to be written
* @param:   Address       the first address where the data will be written to Additional InfoFlash
* @param:   Num           data length(HalfWord)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Info_Additional_HalfWordWrite(const uint16_t *pWriteByte, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
	uint32_t sectorNum = 0U;
  uint32_t error = 0U;
	
  assert_param(IS_ADDL_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_ADDL_MIN_ADDRESS) || (Address >= INFO_ADDL_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                 /*!< Disable write protection                     */
		
		GET_ADDL_INFOFLASH_SECTOR(Address,sectorNum); 
		INFOFLASH_ADDL_SECTOR_UNLOCK(sectorNum);
    
		SET_FLASH_WRITE;
		Address &= FLASH_HALFWORD_MASK;                                                         /*!< Make sure halfwords are aligned              */
		for(i=0U; i<Num; i++)
    {
      if ((Address+i) >= INFOFLASH_ADDL_MAX_ADDR(sectorNum))
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M16(Address+(i<<FLASH_HALFWORD_SHIFT)) = pWriteByte[i];                                          /*!< Flash read         */
			while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                           /*!< Waiting for programming end             */
		}
		
		INFOFLASH_ADDL_SECTOR_LOCK(sectorNum);
    HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */
    
  }
}
/**
*********************************************************************************************************
*                                    ADDITIONAL INFO WORD WRITE
* @brief:   Additional InfoFlash Word Write Additional
*
* @param:   pWriteByte    pointer to the first address of the data to be written
* @param:   Address       the first address where the data will be written to Additional InfoFlash
* @param:   Num           data length(Word)
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*********************************************************************************************************
*/
void HT_Info_Additional_WordWrite(const uint32_t *pWriteByte, uint32_t Address, uint32_t Num)
{
  /*  assert_param  */
  uint32_t i;
  uint32_t writeProtect;
	uint32_t sectorNum = 0U;
  uint32_t error = 0U;
	
  assert_param(IS_ADDL_INFOFLASH_ADDRESS(Address));
  if ((Address < INFO_ADDL_MIN_ADDRESS) || (Address >= INFO_ADDL_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                 /*!< Disable write protection                     */
		
		GET_ADDL_INFOFLASH_SECTOR(Address,sectorNum); 
		INFOFLASH_ADDL_SECTOR_UNLOCK(sectorNum);
    
		SET_FLASH_WRITE;
		Address &= FLASH_WORD_MASK;                                                         /*!< Make sure halfwords are aligned              */
		for(i=0U; i<Num; i++)
    {
      if ((Address+i) >= INFOFLASH_ADDL_MAX_ADDR(sectorNum))
      {
        error = FLASH_ADDRESS_ERR;
        break;
      }
      M32(Address+(i<<FLASH_WORD_SHIFT)) = pWriteByte[i];                                          /*!< Flash read         */
			while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                           /*!< Waiting for programming end             */
		}
		
		INFOFLASH_ADDL_SECTOR_LOCK(sectorNum);
    HT_CMU->WPREG = writeProtect;                                                           /*!< Restore previous write protection settings   */
    
  }
}

/*
*********************************************************************************************************
*                                ADDITIONAL INFO PAGE ERASE
* @brief:   Additional InfoFlash Page Erase
*
* @param:   EraseAddress    Page erase address
*
* @retval:  None
*
* @Note:    Ensure that the write protection and flash unlock status remain unchanged during execution
*             HT503x :1k  bytes - 1k  bytes/page
*********************************************************************************************************
*/
void HT_Info_Additional_PageErase(uint32_t EraseAddress)
{
  /*  assert_param  */
  uint32_t writeProtect;
	uint32_t sectorNum = 0U;
  uint32_t error = 0U;
	
  assert_param(IS_ADDL_INFOFLASH_ADDRESS(EraseAddress));
  if ((EraseAddress < INFO_ADDL_MIN_ADDRESS) || (EraseAddress >= INFO_ADDL_MAX_ADDRESS))
  {
    error = FLASH_ADDRESS_ERR;
  }
  if(error != FLASH_ADDRESS_ERR)
  {
    writeProtect = RegisterWriteProtect[HT_CMU->WPREG & CMU_WPSTA_UNPROTECT];             /*!< Save the current write protected status      */
    HT_CMU->WPREG = CMU_WPREG_UnProtected;                                                 /*!< Disable write protection                     */
		
    GET_ADDL_INFOFLASH_SECTOR(EraseAddress,sectorNum); 
    INFOFLASH_ADDL_SECTOR_UNLOCK(sectorNum);

    SET_FLASH_PAGEERASE;
		
    EraseAddress &= FLASH_WORD_MASK;                                        /*!< Make sure words are aligned             */
    M32(EraseAddress) = FLASH_ERASE_DATA;                                   /*!< Execute flash page erase                */
    while(HT_CMU->FLASHCON & CMU_FLASHCON_BUSY){}                           /*!< Waiting for programming end             */
		
		INFOFLASH_ADDL_SECTOR_LOCK(sectorNum);
    HT_CMU->WPREG = writeProtect;                                           /*!< Restore previous write protection settings   */   
  }	
}
	
	
#endif

