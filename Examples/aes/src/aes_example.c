/*
*********************************************************************************************************
*                                              HT60XX
*                                           Library Function
*
*                                   Copyright 2021, Hi-Trend Tech, Corp.
*                                        All Rights Reserved
*
*
* Project      : HT6xxx
* File         : aes_example.c
* By           : Hitrendtech_SD
* Version      : V2.0.7
* Description  :
*********************************************************************************************************
*/

#define  __AES_EXAMPLE_C
//#undef   __AES_EXAMPLE_C

#ifdef   __AES_EXAMPLE_C

#include "ht6xxx_lib.h"
#include "aes_example.h"


#if defined USE_ARG             /* This File Only support for chips used aes&rand Function. */

/*
*********************************************************************************************************
*                                           Local Macro/Structure
*********************************************************************************************************
*/


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
*                                GHASH Parameter H Initilization 
*
* @brief: Initialize GHASH parameter H 
*           Algorithm：  H=E(K,0[128]),    E() is AES encryption，0[128]为128位'0'，K is AES key
* @param:
*           AESKeyMode      AESKeyMode_TypeDef型变量，加密模式
*                           KEY_Mode_128bits
*                           KEY_Mode_192bits
*                           KEY_Mode_256bits
*           pKeyAddr        uint32_t *型变量，其指向对象存储密钥
*           pOutDataAddr    uint32_t *型变量，其指向对象存储H初始值: pIntDataAddr[0]为低位
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void GCM_GhashHeader_init(AESKeyMode_TypeDef AESKeyMode,uint32_t *pKeyAddr,uint32_t *pOutDataAddr)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_ghash_temp;                   /*!< 定义128bits的临时变量        */

    for(i=0;i<4;i++)
    {
        Aes_ghash_temp.u32[i]=0x0000;                           /*!< 临时变量 赋值0x0000        */
    }
    HT_AES_Encrypt(AESKeyMode,pKeyAddr,Aes_ghash_temp.u32);     /*!< E(K,0[128])，aes加密运算     */

    while(HT_AES_Busy_StatusGet());                             /*!< AES加密结束判断              */

    HT_AES_Read(pOutDataAddr);                                  /*!< 加密运算结果写入 *pOutDataAddr */
}

/**
*********************************************************************************************************
*                                GHASH（H,A,C) 认证函数计算
*
* @brief: GHASH（H,A,C) 认证函数计算,
*           算法：  GHASH(H,A,C)  = Xm+n+1,    Xm+n+1为ghash认证结果，m为A的分段数（128bits为1段），n为c的分段数,A为auth data（认证数据），C为ciphertext（密文）
*                   Xi =  0                               ,for i=0
*                      =  (Xi-1 ^ Ai) . H                 ,for i=1,...,m-1
*                      =  (Xm-1 ^ Am||0[128-v]) . H       ,for i=m
*                      =  (Xi-1 ^ Ci-m) . H               ,for i=m+1,...,m+n-1
*                      =  (Xm+n-1 ^ Cn||0[128-u]) . H     ,for i=m+n
*                      =  (Xm+n ^ (len(A)||len(C))) . H   ,for i=m+n+1
*                         注:Am||0[128-v]，为A最后分段不足128bits补零，v为最后分段位长
*                            Cn||0[128-u]，为C最后分段不足128bits补零，u为最后分段位长
*                            len(A),返回一个64-bits 字符串，表示数据A的位长（bit）
* @param:
*           GhashHeaderAddr   uint32_t *型变量，其指向对象存储GhashHeader初值
*           pADataAddr        uint8_t *型变量，其指向对象存储A值
*           LenAData          uint64_t 型变量，表示A值长度（单位byte）
*           *pCtextAddr       uint8_t *型变量，其指向对象存储C值
*           LenCtext          uint64_t 型变量，表示C值长度（单位byte）
*           OutData           Parameter128bits_TypeDef*变量其指向对象存储ghash函数运算结果
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void GCM_GhashAuth(uint32_t *GhashHeaderAddr,uint8_t *pADataAddr,uint64_t LenAData,uint8_t *pCtextAddr,uint64_t LenCtext,Parameter128bits_TypeDef* OutData)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_ghash_temp,LenData_temp;

    for(i=0;i<4;i++)
    {
        OutData->u32[i]=0x0000;                               /*!< OutData变量  赋值0x0000        */
    }

    /*(len(A)||len(C))运算  */
    LenData_temp.u64[0] = LenCtext * 8;                       /*!<(len(A)||len(C))运算结果缓存    */
    LenData_temp.u64[1] = LenAData * 8;

    /*Ai运算部分  */
    for(i=0;i<4;i++)
    {
        OutData->u32[i]=0x0000;                               /*!< OutData变量  赋值0x0000        */
        Aes_ghash_temp.u32[i]=0x0000;                         /*!< 临时变量 赋值0x0000            */
    }
    //(Xi-1 ^ Ai) . H             ,for i=1,...,m-1
    while(LenAData>=16)                                       /*!< A位长判断  16bytes（128bits）  */
    {
        for(i=0;i<16;i++)
        {
            OutData->u8[i] ^= *pADataAddr++;                  /*!< (Xi-1 ^ Ai), 128bits 异或操作  */
        }
        LenAData -= 16;                                       /*!< 下个128bit分段                 */
        HT_GHASH_Multiply(OutData->u32, GhashHeaderAddr);     /*!< （OutData . H）操作            */
        while(HT_GHASH_Busy_StatusGet());                     /*!< Ghash乘法运算完成判断          */
        HT_GHASH_Multiply_Read(OutData->u32);                 /*!< 读取运算结果，存储到 OutData   */
    }
    //(Xm-1 ^ Am||0[128-v]) . H     ,for i=m
    if(LenAData)
    {
        for(i=0;i<4;i++)
        {
            Aes_ghash_temp.u32[i]=0x0000;                     /*!< 临时变量 赋值0x0000            */
        }
        for(i=16-LenAData;i<16;i++)
        {
            Aes_ghash_temp.u8[i] = *pADataAddr++;             /*!< 不足128bits的AData送到Aes_ghash_temp高位 ，低位补零  */
        }
        HT_AES_Xor128bits(OutData->u32,Aes_ghash_temp.u32, OutData->u32);
                                                                                                                    /*!< 补零后的AData最后段与OutData异或运算，结果存于OutData  */
        HT_GHASH_Multiply(OutData->u32, GhashHeaderAddr);     /*!< （OutData . H）操作            */
        while(HT_GHASH_Busy_StatusGet());                     /*!< Ghash乘法运算完成判断          */
        HT_GHASH_Multiply_Read(OutData->u32);                 /*!< 读取运算结果，存储到 OutData   */
    }

/*Ci运算部分*/
    //(Xi-1 ^ Ci-m) . H               ,for i=m+1,...,m+n-1
    while(LenCtext>=16)                                       /*!< C位长判断  16bytes（128bits）  */
    {
        for(i=0;i<16;i++)
        {
            OutData->u8[i] ^= *pCtextAddr++;                  /*!< (Xi-1 ^ Ci-m), 128bits 异或操作  */
        }
        LenCtext -= 16;                                       /*!< 下个128bit分段                 */
        HT_GHASH_Multiply(OutData->u32, GhashHeaderAddr);     /*!< （OutData . H）操作            */
        while(HT_GHASH_Busy_StatusGet());                     /*!< Ghash乘法运算完成判断          */
        HT_GHASH_Multiply_Read(OutData->u32);                 /*!< 读取运算结果，存储到 OutData   */
    }
    //(Xm+n-1 ^ Cn||0[128-u]) . H     ,for i=m+n
    if(LenCtext)
    {
        for(i=0;i<4;i++)
        {
            Aes_ghash_temp.u32[i]=0x0000;                     /*!< 临时变量 赋值0x0000            */
        }
        for(i=16-LenCtext;i<16;i++)
        {
            Aes_ghash_temp.u8[i] = *pCtextAddr++;             /*!< 不足128bits的CData送到Aes_ghash_temp高位 ，低位补零  */
        }
        HT_AES_Xor128bits(OutData->u32,Aes_ghash_temp.u32, OutData->u32);
                                                                                                                    /*!< 补零后的AData最后段与OutData异或运算，结果存于OutData  */
        HT_GHASH_Multiply(OutData->u32, GhashHeaderAddr);     /*!< （OutData . H）操作            */
        while(HT_GHASH_Busy_StatusGet());                     /*!< Ghash乘法运算完成判断          */
        HT_GHASH_Multiply_Read(OutData->u32);                 /*!< 读取运算结果，存储到 OutData   */
    }

/*最后运算部分*/
    //(Xm+n ^ (len(A)||len(C))) . H   ,for i=m+n+1
    HT_AES_Xor128bits(OutData->u32,LenData_temp.u32, OutData->u32);
                                                                                                                        /*!< (len(A)||len(C))与OutData异或运算，结果存于OutData */
    HT_GHASH_Multiply(OutData->u32, GhashHeaderAddr);         /*!< （OutData . H）操作            */
    while(HT_GHASH_Busy_StatusGet());                         /*!< Ghash乘法运算完成判断          */
    HT_GHASH_Multiply_Read(OutData->u32);                     /*!< 读取运算结果，存储到 OutData   */
}

/**
*********************************************************************************************************
*                                GCM Counter0(Y0)参数初始化计算
*
* @brief: Counter0(Y0)参数初始化计算
*           算法：Y0 = IV || 0[31]1   ,if len(IV)=96 bits(12 bytes)
*                    = GHASH(H,{},IV) ,otherwise
*                 IV为初始向量，0[31]1为31位'0'和1位'1',GHASH(H,{},IV)为ghash运算函数
* @param:
*           pInitVectorAddr   uint8_t *型变量，其指向对象存储IV初始值: pInitVectorAddr[0]为低位
*           LenIV             uint64_t  初始向量位长，单位byte
*           GhashHeaderAddr   uint32_t *型变量，其指向对象存储GhashHeader（H）值
*           Counter0          Parameter128bits_TypeDef*变量，其指向对象存储ICounter0(y0)初始化结果
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void GCM_Counter0_init(uint8_t *pInitVectorAddr,uint64_t LenIV,uint32_t *GhashHeaderAddr,Parameter128bits_TypeDef* Counter0)
{
    uint8_t i;
    uint8_t *ptemp = NULL;  //此处只是满足函数填充指定的无效值                                            /*!< 临时指针变量               */

    for(i=0;i<4;i++)
    {
        Counter0->u32[i] = 0x0000;                              /*!< counter0 赋值0x0000        */
    }

    //Y0 = IV || 0[31]1       ,if len(IV)=96 bits(12 bytes)
    if(LenIV == 12)                                             /*!< IV长度12 bytes (96 bits)   */
    {
        for(i=4;i<16;i++)
        {
            Counter0->u8[i] = *pInitVectorAddr++;               /*!< IV送到Counter0高96位       */
        }
        Counter0->u32[0]=0x0001;                                /*!< Counter0低32位 补0加1       */
    }
    //Y0 = GHASH(H,{},IV)     ,otherwise
    else
    {
        GCM_GhashAuth(GhashHeaderAddr,ptemp,0x0,pInitVectorAddr,LenIV,Counter0);                                                                                                                    /*!< Ghash认证运算，GHASH(H,{},IV)   */
    }
}

/**
*********************************************************************************************************
*                                GCM Counter(Yi)累加计算
*
* @brief: Counter(Yi)累加计算
*           算法：Yi = Yi-1 + 1   ,i=1,2...n
*               Yi的累加计算，仅对最右边32bits有效
*
* @param:
*           Counter         Parameter128bits_TypeDef*变量，其指向对象存储ICounter(Yi)累加的counter数据
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void GCM_Counter_increase(Parameter128bits_TypeDef* Counter)
{
    Counter->u32[0]++;                          /*!< Yi = Yi-1 + 1  ，最右边32bits有效      */
}

/**
*********************************************************************************************************
*                                GCM_CTR加密/解密计算
*
* @brief: GCM_CTR加密/解密计算
*           加密算法：Ci = Pi ^ E(K,Yi)           ,for i=1,2,...,n-1
*                          Pn ^ MSBu(E(K,Yn))     ,for i=n
*           解密算法：Pi = Ci ^ E(K,Yi)           ,for i=1,2,...,n-1
*                          Cn ^ MSBu(E(K,Yn))     ,for i=n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 E(K,Yi)为对Yi进行AES加密运算
*                 MSBu(S)为返回1字符串，字符串包含S数据的最左边u个bits
* @retval:
*           pInttextAddr    uint8_t *型变量，其指向对象存储待加/解密数据:
*           LenInttext      uint64_t  待加/解密数据位长，单位byte
*           Counter0        Parameter128bits_TypeDef*变量，其指向对象存储Counter0(y0)初值
*           AESKeyMode      枚举变量，选择加密模式
*                           KEY_Mode_128bits
*                           KEY_Mode_192bits
*                           KEY_Mode_256bits
*           pKeyAddr        uint32_t *型变量，其指向对象存储AES key : pKeyAddr[0]为高位
*           pOuttextAddr    uint8_t *型变量，其指向对象存储加/解密完成数据
*
* @retval: 无
*
* @note: 加密操作时，pInttextAddr和LenInttext为明文输入，pOuttextAddr为密文输出
*           解密操作时，pInttextAddr和LenInttext为密文输入，pOuttextAddr为明文输出
*********************************************************************************************************
*/
void GCM_CTR_Encrypt(uint8_t *pInttextAddr,uint64_t LenInttext,Parameter128bits_TypeDef* Counter0,AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr,uint8_t *pOuttextAddr)
{
    uint8_t i;
    Parameter128bits_TypeDef  Counter_temp,Aes_GCM_temp;

    for(i=0;i<4;i++)
    {
        Counter_temp.u32[i] = Counter0->u32[i];               /*!< counter0存到Counter_temp备用   */
    }
//Ci = Pi ^ E(K,Yi)           ,for i=1,2,...,n-1
    while(LenInttext>=16)                                     /*!< P位长判断  16bytes（128bits）  */
    {
        GCM_Counter_increase(&Counter_temp);                  /*!< GCM Counter(Yi)累加计算        */
        HT_AES_Encrypt(AESKeyMode,pKeyAddr,Counter_temp.u32);
                                                                                                                    /*!< 对Counter(Yi)AES加密操作 ， E(K,Yi)      */
        while(HT_AES_Busy_StatusGet());                       /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_GCM_temp.u32);                        /*!< 读取运算结果，存储到 Aes_GCM_temp    */
        for(i=0;i<16;i++)
        {
            *pOuttextAddr++ = Aes_GCM_temp.u8[i] ^ *pInttextAddr++;                                                                                                          /*!< Pi ^ E(K,Yi)运算                */
        }
        LenInttext -= 16;                                     /*!< 下个128bit分段                 */
    }
//Cn = Pn ^ MSBu(E(K,Yn))     ,for i=n
    if(LenInttext)
    {
        GCM_Counter_increase(&Counter_temp);                  /*!< GCM Counter(Yi)累加计算        */
        HT_AES_Encrypt(AESKeyMode,pKeyAddr,Counter_temp.u32);
                                                                                                                    /*!< 对Counter(Yn)AES加密操作 ， E(K,Yn)  */
        while(HT_AES_Busy_StatusGet());                       /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_GCM_temp.u32);                        /*!< 读取运算结果，存储到 Aes_GCM_temp1   */
        for(i=16-LenInttext;i<16;i++)
        {
            *pOuttextAddr++ = Aes_GCM_temp.u8[i] ^ *pInttextAddr++;                                                                                                                /*!< Pn ^ MSBu(E(K,Yn))运算          */
        }
    }
}

/**
*********************************************************************************************************
*                                GCM 认证标签计算
*
* @brief: GCM 认证标签计算
*           加密算法：T = MSBt(GHASH(H,A,C) ^ E(K,Y0))
*
*                 Ai为认证数据分段，每段128 bits，最后段v bits，总位长 (m-1)*128+v bits，1<= v <=128
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 E(K,Y0)为对Y0进行AES加密运算
*                 MSBu(S)为返回1字符串，字符串包含S数据的最左边u个bits
* @param:
*           GhashAuthData   Parameter128bits_TypeDef*变量，其指向对象存储GHASH(H,A,C)运算结果
*           Counter0        Parameter128bits_TypeDef*变量，其指向对象存储Counter0(y0)初值
*           AESKeyMode      枚举变量，选择加密模式
*                           KEY_Mode_128bits
*                           KEY_Mode_192bits
*                           KEY_Mode_256bits
*           pKeyAddr        uint32_t *型变量，其指向对象存储AES key : pKeyAddr[0]为高位
*           AuthTag         Parameter128bits_TypeDef*变量，其指向对象存储认证标签数据
*
* @retval: 无
*
* @note: 加密操作时，pInttextAddr和LenInttext为明文输入，pOuttextAddr为密文输出
*           解密操作时，pInttextAddr和LenInttext为密文输入，pOuttextAddr为明文输出
*********************************************************************************************************
*/
void GCM_TagAuth(Parameter128bits_TypeDef* GhashAuthData,Parameter128bits_TypeDef* Counter0,AESKeyMode_TypeDef AESKeyMode, uint32_t *pKeyAddr,Parameter128bits_TypeDef* AuthTag)
{
    Parameter128bits_TypeDef  Aes_GCM_temp;

    HT_AES_Encrypt(AESKeyMode,pKeyAddr,Counter0->u32);        /*!< 对Counter(Y0)AES加密操作 ， E(K,Y0)          */
    while(HT_AES_Busy_StatusGet());                           /*!< AES加密运算完成判断                          */
    HT_AES_Read(Aes_GCM_temp.u32);                            /*!< 读取运算结果，存储到 Aes_GCM_temp            */

    HT_AES_Xor128bits(Aes_GCM_temp.u32,GhashAuthData->u32, AuthTag->u32);                                                           /*!< GHASH(H,A,C) ^ E(K,Y0)运算，结果存于AuthTag  */
}

/**
*********************************************************************************************************
*                                GCM 加密函数
*
* @brief: GCM 加密函数
*
* @param: GCM_InputStruct    GCM加密输入变量结构体指针，主要包含8个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pInitVectorAddr  : 初始向量地址指针
*                              4) LenIV             : 初始向量数据长度（byte）
*                              5) *pPtextAddr       : 明文数据地址指针
*                              6) LenPtext          : 明文数据长度（byte）
*                              7) *pAdataAddr       : 附加认证数据地址指针
*                              8) LenAdata          : 附加认证数据长度（byte）
*           GCM_OutputStruct   GCM加密输出变量结构体指针，主要包含3个参数:
*                              1) *pCtextAddr       : 已加密数据密文地址指针
*                              2) LenCtext          : 已加密数据密文长度（byte）
*                              3) AuthTag           : 认证标签数据地址指针
*
* @retval: 无
*
* @note:无
*********************************************************************************************************
*/
void GCM_Encrypt(GCM_Encrypt_InputTypedef* GCM_InputStruct, GCM_Encrypt_OutputTypedef* GCM_OutputStruct)
{
    Parameter128bits_TypeDef  Header;                                     //H值
    Parameter128bits_TypeDef  Counter0;                                   //Counter0值
    Parameter128bits_TypeDef  Ghash_HAC;                                  //GHASH(H,A,C)运算结果

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);                 /*打开AES模块时钟       */

    GCM_GhashHeader_init(GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,Header.u32);
                                                                                                                                                /*!< 计算Header初值     */
    GCM_Counter0_init(GCM_InputStruct->pInitVectorAddr,GCM_InputStruct->LenIV,Header.u32,&Counter0);
                                                                                                                                                /*!< 计算Counter0初值   */
    GCM_CTR_Encrypt(GCM_InputStruct->pPtextAddr,GCM_InputStruct->LenPtext,&Counter0,GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,GCM_OutputStruct->pCtextAddr);
                                                                                                                                                /*!< gcm CTR加密        */
    GCM_OutputStruct->LenCtext = GCM_InputStruct->LenPtext;
    GCM_GhashAuth(Header.u32,GCM_InputStruct->pAdataAddr,GCM_InputStruct->LenAdata,GCM_OutputStruct->pCtextAddr,GCM_OutputStruct->LenCtext,&Ghash_HAC);
                                                                                                                                                /*!< GHASH(H.A.C)运算     */
    GCM_TagAuth(&Ghash_HAC,&Counter0,GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,GCM_OutputStruct->AuthTag);
                                                                                                                                                /*!< 认证标签运算         */
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);                  /*关闭AES模块时钟       */
}

/**
*********************************************************************************************************
*                                GCM 解密函数
*
* @brief:  GCM 解密函数
*
* @param: GCM_InputStruct    GCM加密输入变量结构体指针，主要包含8个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pInitVectorAddr  : 初始向量地址指针
*                              4) LenIV             : 初始向量数据长度（byte）
*                              5) *pCtextAddr       : 数据密文地址指针
*                              6) LenCtext          : 数据密文长度（byte?
*                              7) *pAdataAddr       : 附加认证数据地址指针
*                              8) LenAdata          : 附加认证数据长度（byte）
*                              9) AuthTag           : 认证标签数据地址指针
*           GCM_OutputStruct   GCM加密输出变量结构体指针，主要包含3个参数:
*                              1) *pPtextAddr       : 明文数据地址指针
*                              2) LenPtext          : 明文数据长度（byte）
*
* @retval: Bool    = TRUE：  认证成功
*                   = FALSE： 认证失败
*
* @note:无
*********************************************************************************************************
*/
Bool GCM_Decrypt(GCM_Decrypt_InputTypedef* GCM_InputStruct, GCM_Decrypt_OutputTypedef* GCM_OutputStruct)
{
    Parameter128bits_TypeDef  Header;                                     //H值
    Parameter128bits_TypeDef  Counter0;                                   //Counter0值
    Parameter128bits_TypeDef  Ghash_HAC;                                  //GHASH(H,A,C)运算结果
    Parameter128bits_TypeDef  AuthTag_Temp;
    uint8_t i;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);                 /*打开AES模块时钟       */

    GCM_GhashHeader_init(GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,Header.u32);
                                                                                                                                                /*!< 计算Header初值     */
    GCM_Counter0_init(GCM_InputStruct->pInitVectorAddr,GCM_InputStruct->LenIV,Header.u32,&Counter0);
                                                                                                                                                /*!< 计算Counter0初值   */
    GCM_GhashAuth(Header.u32,GCM_InputStruct->pAdataAddr,GCM_InputStruct->LenAdata,GCM_InputStruct->pCtextAddr,GCM_InputStruct->LenCtext,&Ghash_HAC);
                                                                                                                                                /*!< GHASH(H.A.C)运算     */
    GCM_TagAuth(&Ghash_HAC,&Counter0,GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,&AuthTag_Temp);
                                                                                                                                                /*!< 认证标签运算         */
    for(i=0;i<4;i++)
    {
        if(AuthTag_Temp.u32[i] != GCM_InputStruct->AuthTag->u32[i] )
        {
            return  FALSE;                                                /*!< 认证失败，返回 FALSE */
        }
    }

    GCM_CTR_Encrypt(GCM_InputStruct->pCtextAddr,GCM_InputStruct->LenCtext,&Counter0,GCM_InputStruct->AESKeyMode,GCM_InputStruct->pKeyAddr,GCM_OutputStruct->pPtextAddr);
                                                                                                                                                /*!< gcm CTR解密        */
    GCM_OutputStruct->LenPtext = GCM_InputStruct->LenCtext;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);                /*关闭AES模块时钟       */

    return  TRUE;                                                         /*!< 解密成功，返回 TRUE  */
}

/**
*********************************************************************************************************
*                                ECB 加密计算
*
* @brief: ECB 加密计算
*
*           加密算法：Ci = E(K,Pi)                ,for i=1,2,...,n-1
*                          E(K,Pn||0[128-u]))     ,for i=n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 E(K,Pi)为对Pi进行AES加密运算
*                 Pn||0[128-u]，为P最后分段不足128bits补零，u为最后分段位长
*
* @param: ECB_InputStruct    ECB加密输入变量结构体指针，主要包含4个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pPtextAddr       : 明文数据地址指针
*                              4) LenPtext          : 明文数据长度（byte）
*           ECB_OutputStruct   ECB加密输出变量结构体指针，主要包含2个参数:
*                              1) *pCtextAddr       : 已加密数据密文地址指针
*                              2) LenCtext          : 已加密数据密文长度（byte）
*
* @retval: 无
*
* @note:
*********************************************************************************************************
*/
void ECB_Encrypt(ECB_Encrypt_InputTypedef* ECB_InputStruct,ECB_Encrypt_OutputTypedef* ECB_OutputStruct)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_ECB_temp;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);           /*打开AES模块时钟           */

    if(ECB_InputStruct->LenPtext%16 == 0)                           /*!< 计算密文长度           */
    {
        ECB_OutputStruct->LenCtext = ECB_InputStruct->LenPtext;
    }
    else
    {
        ECB_OutputStruct->LenCtext = ECB_InputStruct->LenPtext - (ECB_InputStruct->LenPtext%16) +16;
    }

  //Ci =  E(K,Pi)           ,for i=1,2,...,n-1
    while(ECB_InputStruct->LenPtext>=16)                            /*!< P位长判断  16bytes（128bits）  */
    {
        for(i=0;i<16;i++)
        {
            Aes_ECB_temp.u8[i] = *ECB_InputStruct->pPtextAddr++;    /*!< Pi存入临时变量Aes_ECB_temp     */
        }
        HT_AES_Encrypt(ECB_InputStruct->AESKeyMode,ECB_InputStruct->pKeyAddr,Aes_ECB_temp.u32);
                                                                    /*!< 对Pi AES加密操作 ， E(K,Pi)      */
        while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_ECB_temp.u32);                              /*!< 读取运算结果，存储到 Aes_ECB_temp  */
        for(i=0;i<16;i++)
        {
            *ECB_OutputStruct->pCtextAddr++ = Aes_ECB_temp.u8[i];
                                                                    /*!< 将密文保存                     */
        }
        ECB_InputStruct->LenPtext -= 16;                            /*!< 下个128bit分段                 */
    }
  //Cn = E(K,Pn||0[128-u])      ,for i=n
    if(ECB_InputStruct->LenPtext)
    {
        for(i=0;i<4;i++)
        {
            Aes_ECB_temp.u32[i] = 0x0000;                           /*!< Aes_ECB_temp清零               */
        }
        for(i=16-ECB_InputStruct->LenPtext;i<16;i++)
        {
            Aes_ECB_temp.u8[i] = *ECB_InputStruct->pPtextAddr++;    /*!< Pi存入临时变量Aes_ECB_temp     */
        }
        HT_AES_Encrypt(ECB_InputStruct->AESKeyMode,ECB_InputStruct->pKeyAddr,Aes_ECB_temp.u32);
                                                                    /*!< 对Pi AES加密操作 ， E(K,Pi)    */
        while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_ECB_temp.u32);                              /*!< 读取运算结果，存储到 Aes_ECB_temp    */
        for(i=0;i<16;i++)
        {
            *ECB_OutputStruct->pCtextAddr++ = Aes_ECB_temp.u8[i];
        }                                                           /*!< 将密文保存                     */
    }

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);          /*关闭AES模块时钟                   */
}

/**
*********************************************************************************************************
*                                ECB 解密计算
*
* @brief: ECB 解密计算
*
*           解密算法：Pi = E'(K,Ci)                 ,for i=1,2,...,n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 E'(K,Pi)为对Pi进行AES解密运算
*
* @param: ECB_InputStruct    ECB解密输入变量结构体指针，主要包含4个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pCtextAddr       : 密文数据地址指针
*                              4) LenCtext          : 密文数据长度（byte）
*           ECB_OutputStruct   ECB解密输出变量结构体指针，主要包含2个参数:
*                              1) *pPtextAddr       : 已解密明文地址指针
*                              2) LenPtext          : 已解密明文长度（byte）
*
* @retval: Bool    = TRUE：  解密成功
*                   = FALSE： 解密失败，密文有误
*
* @note:
*********************************************************************************************************
*/
Bool ECB_Decrypt(ECB_Decrypt_InputTypedef* ECB_InputStruct,ECB_Decrypt_OutputTypedef* ECB_OutputStruct)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_ECB_temp;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);           /*打开AES模块时钟           */

    if(ECB_InputStruct->LenCtext%16 != 0 || ECB_InputStruct->LenCtext == 0)
    {
        return  FALSE;                                              /*!< 密文位长错误                   */
    }
    ECB_OutputStruct->LenPtext = ECB_InputStruct->LenCtext;         /*!< LenPtext = LenCtext            */

//Pi = E'(K,Ci)                 ,for i=1,2,...,n
    while(ECB_InputStruct->LenCtext >= 16)                          /*!< P位长判断  16bytes（128bits）  */
    {
        for(i=0;i<16;i++)
        {
            Aes_ECB_temp.u8[i] = *ECB_InputStruct->pCtextAddr++;    /*!< Pi存入临时变量Aes_ECB_temp     */
        }
        HT_AES_Decrypt(ECB_InputStruct->AESKeyMode,ECB_InputStruct->pKeyAddr,Aes_ECB_temp.u32);
                                                                                                                                /*!< 对Pi AES加密操作 ， E(K,Pi)    */
        while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_ECB_temp.u32);                              /*!< 读取运算结果，存储到 Aes_ECB_temp  */
        for(i=0;i<16;i++)
        {
            *ECB_OutputStruct->pPtextAddr++ = Aes_ECB_temp.u8[i];                                                                                                                    /*!< 将密文保存                      */
        }
        ECB_InputStruct->LenCtext -= 16;                            /*!< 下个128bit分段                 */
    }

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);          /*关闭AES模块时钟                   */

    return TRUE;                                                    /*!< 解密成功                       */
}

/**
*********************************************************************************************************
*                                CBC 加密计算
*
* @brief: CBC 加密计算
*
*           加密算法：Ci = E(K,(P1 ^ IV))                 ,for i=1
*                        = E(K,(Pi ^  Ci-1))              ,for i=2,3,...,n-1
*                        = E(K,((Pn||0[128-u])^Cn-1))     ,for i=n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 IV为初始向量，0~128 bits
*                 E(K,P)为对P进行AES加密运算
*                 Pn||0[128-u]，为P最后分段不足128bits补零，u为最后分段位长
*
* @param: CBC_InputStruct    CBC加密输入变量结构体指针，主要包含4个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pPtextAddr       : 明文数据地址指针
*                              4) LenPtext          : 明文数据长度（byte）
*                              5) *pInitVectorAddr  : 初始向量地址指针
*           CBC_OutputStruct   CBC加密输出变量结构体指针，主要包含2个参数:
*                              1) *pCtextAddr       : 已加密数据密文地址指针
*                              2) LenCtext          : 已加密数据密文长度（byte）
*
* @retval: 无
*
* @note:
*********************************************************************************************************
*/
void CBC_Encrypt(CBC_Encrypt_InputTypedef* CBC_InputStruct,CBC_Encrypt_OutputTypedef* CBC_OutputStruct)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_CBC_temp;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);           /*打开AES模块时钟           */

    if(CBC_InputStruct->LenPtext%16 == 0)                           /*!< 计算密文长度           */
    {
        CBC_OutputStruct->LenCtext = CBC_InputStruct->LenPtext;
    }
    else
    {
        CBC_OutputStruct->LenCtext = CBC_InputStruct->LenPtext - (CBC_InputStruct->LenPtext%16) +16;
    }

/* LenPtext>=16 */
    if(CBC_InputStruct->LenPtext>=16)                               /*!< P位长判断  16bytes（128bits）  */
    {
//Ci = E(K,(P1 ^ IV))                 ,for i=1
        for(i=0;i<16;i++)
        {
            Aes_CBC_temp.u8[i] = *CBC_InputStruct->pPtextAddr++ ^ CBC_InputStruct->pInitVectorAddr->u8[i];                                                                                                                    /*!< (P1 ^ IV)运算，结果存于Aes_CBC_temp      */
        }
        HT_AES_Encrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                                /*!< 对(P1 ^ IV) AES加密操作，E(K,(P1 ^ IV))  */
        while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_CBC_temp.u32);                              /*!< 读取运算结果，存储到 Aes_CBC_temp  */
        for(i=0;i<16;i++)
        {
            *CBC_OutputStruct->pCtextAddr++ = Aes_CBC_temp.u8[i];                                                                                                                 /*!< 将密文C1保存                   */
        }
        CBC_InputStruct->LenPtext -= 16;                            /*!< 下个128bit分段                 */
        CBC_OutputStruct->pCtextAddr -= 16;                         /*!< 指针指向C1                     */

//Ci =  E(K,(Pi ^ Ci-1))          ,for i=2,3,...,n-1
        while(CBC_InputStruct->LenPtext>=16)                        /*!< P位长判断  16bytes（128bits）  */
        {
            for(i=0;i<16;i++)
            {
                Aes_CBC_temp.u8[i] = *CBC_InputStruct->pPtextAddr++ ^ *CBC_OutputStruct->pCtextAddr++;                                                                                                              /*!< (Pi ^ Ci-1)运算，结果存于Aes_CBC_temp      */
            }
            HT_AES_Encrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                            /*!< 对(Pi ^ Ci-1) AES加密操作，E(K,(Pi ^ Ci-1))  */
            while(HT_AES_Busy_StatusGet());                         /*!< AES加密运算完成判断            */
            HT_AES_Read(Aes_CBC_temp.u32);                          /*!< 读取运算结果，存储到 Aes_CBC_temp  */
            for(i=0;i<16;i++)
            {
                *CBC_OutputStruct->pCtextAddr++ = Aes_CBC_temp.u8[i];                                                                                                      /*!< 将密文保存                      */
            }
            CBC_InputStruct->LenPtext -= 16;                        /*!< 下个128bit分段                 */
            CBC_OutputStruct->pCtextAddr-=16;                       /*!< 指针指向Ci-1                   */
        }
//E(K,((Pn||0[128-u])^Cn-1))      ,for i=n
        if(CBC_InputStruct->LenPtext)
        {
            for(i=0;i<4;i++)
            {
                Aes_CBC_temp.u32[i] = 0x0000;                           /*!< Aes_CBC_temp清零               */
            }
            for(i=16-CBC_InputStruct->LenPtext;i<16;i++)
            {
                Aes_CBC_temp.u8[i] = *CBC_InputStruct->pPtextAddr++;    /*!< Pi存入临时变量Aes_CBC_temp，补零 */
            }
            for(i=0;i<16;i++)
            {
                Aes_CBC_temp.u8[i] = Aes_CBC_temp.u8[i] ^ *CBC_OutputStruct->pCtextAddr++;                                                                                                                        /*!< ((Pn||0[128-u])^Cn-1)运算，结果存于Aes_CBC_temp      */
            }
            HT_AES_Encrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                                    /*!< 对((Pn||0[128-u])^Ci-1) AES加密操作  ， E(K,Pi)    */
            while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
            HT_AES_Read(Aes_CBC_temp.u32);                              /*!< 读取运算结果，存储到 Aes_CBC_temp    */
            for(i=0;i<16;i++)
            {
                *CBC_OutputStruct->pCtextAddr++ = Aes_CBC_temp.u8[i];
            }                                                           /*!< 将密文保存                     */
        }
    }
/* LenPtext<16 且!=0  */
    else if(CBC_InputStruct->LenPtext)
    {
//Ci = E(K,((P1||0[128-U]) ^ IV))                 ,for i=n=1
        for(i=0;i<4;i++)
        {
            Aes_CBC_temp.u32[i] = 0x0000;                           /*!< Aes_CBC_temp清零               */
        }
        for(i=16-CBC_InputStruct->LenPtext;i<16;i++)
        {
            Aes_CBC_temp.u8[i] = *CBC_InputStruct->pPtextAddr++;    /*!< Pi存入临时变量Aes_CBC_temp,补零*/
        }
        for(i=0;i<16;i++)
        {
            Aes_CBC_temp.u8[i] = Aes_CBC_temp.u8[i] ^ CBC_InputStruct->pInitVectorAddr->u8[i];                                                                                                                         /*!< (P1 ^ IV)运算，结果存于Aes_CBC_temp     */
        }
        HT_AES_Encrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                                /*!< 对(P1 ^ IV)AES加密操作 ， E(K,(P1 ^ IV))     */
        while(HT_AES_Busy_StatusGet());                             /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_CBC_temp.u32);                              /*!< 读取运算结果，存储到 Aes_CBC_temp    */
        for(i=0;i<16;i++)
        {
            *CBC_OutputStruct->pCtextAddr++ = Aes_CBC_temp.u8[i];
        }                                                           /*!< 将密文保存                     */
    }

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);          /*关闭AES模块时钟                   */
}

/**
*********************************************************************************************************
*                                CBC 解密计算
*
* @brief: CBC 解密计算
*
*           加密算法：Pi = E'(K,C1) ^ IV                  ,for i=1
*                        = E'(K,Ci) ^ Ci-1                ,for i=2,3,...,n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n)*128 bits
*                 IV为初始向量，0~128 bits
*                 E'(K,C)为对C进行AES解密运算
*
* @param: CBC_InputStruct    CBC解密输入变量结构体指针，主要包含4个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pCtextAddr       : 密文数据地址指针
*                              4) LenCtext          : 密文数据长度（byte）
*                              5) *pInitVectorAddr  : 初始向量地址指针
*           CBC_OutputStruct   CBC解密输出变量结构体指针，主要包含2个参数:
*                              1) *pPtextAddr       : 已解密明文地址指针
*                              2) LenPtext          : 已解密明文长度（byte）
*
* @retval: Bool    = TRUE：  解密成功
*                   = FALSE： 解密失败，密文有误
* @note:
*********************************************************************************************************
*/
Bool CBC_Decrypt(CBC_Decrypt_InputTypedef* CBC_InputStruct,CBC_Decrypt_OutputTypedef* CBC_OutputStruct)
{
    uint8_t i;
    Parameter128bits_TypeDef  Aes_CBC_temp;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);           /*打开AES模块时钟           */

    if(CBC_InputStruct->LenCtext%16 != 0 || CBC_InputStruct->LenCtext == 0)
    {
        return  FALSE;                                              /*!< 密文位长错误                   */
    }
    CBC_OutputStruct->LenPtext = CBC_InputStruct->LenCtext;         /*!< LenPtext = LenCtext            */

//Pi = E'(K,C1) ^ IV                  ,for i=1
    for(i=0;i<16;i++)
    {
        Aes_CBC_temp.u8[i] = *CBC_InputStruct->pCtextAddr++;        /*!< C1存入临时变量Aes_CBC_temp     */
    }
    HT_AES_Decrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                                    /*!< 对C1 AES解密操作，E'(K,C1)     */
    while(HT_AES_Busy_StatusGet());                                 /*!< AES解密运算完成判断            */
    HT_AES_Read(Aes_CBC_temp.u32);                                  /*!< 读取运算结果，存储到 Aes_CBC_temp  */
    for(i=0;i<16;i++)
    {
        *CBC_OutputStruct->pPtextAddr++ = Aes_CBC_temp.u8[i] ^ CBC_InputStruct->pInitVectorAddr->u8[i];                                                                                                                         /*!< 将明文P1保存                   */
    }
    CBC_InputStruct->LenCtext -= 16;                                /*!< 下个128bit分段                 */

//Pi = E'(K,Ci) ^ Ci-1                ,for i=2,3,...,n
    while(CBC_InputStruct->LenCtext>=16)                            /*!< P位长判断  16bytes（128bits）  */
    {
        for(i=0;i<16;i++)
        {
            Aes_CBC_temp.u8[i] = *CBC_InputStruct->pCtextAddr++;    /*!< Ci存入临时变量Aes_CBC_temp     */
        }
        CBC_InputStruct->pCtextAddr -= 32;                            /*!< 指针指向Ci-1                   */
        HT_AES_Decrypt(CBC_InputStruct->AESKeyMode,CBC_InputStruct->pKeyAddr,Aes_CBC_temp.u32);
                                                                                                                                /*!< 对Ci AES解密操作，E'(K,Ci)     */
        while(HT_AES_Busy_StatusGet());                             /*!< AES解密运算完成判断            */
        HT_AES_Read(Aes_CBC_temp.u32);                              /*!< 读取运算结果，存储到 Aes_CBC_temp  */
        for(i=0;i<16;i++)
        {
            *CBC_OutputStruct->pPtextAddr++ = Aes_CBC_temp.u8[i] ^ *CBC_InputStruct->pCtextAddr++;                                                                                                                 /*!< 将明文P1保存,Pi = E'(K,Ci) ^  Ci-1  */
        }
        CBC_InputStruct->pCtextAddr += 16;                          /*!< 指针指向Ci+1                   */
        CBC_InputStruct->LenCtext -= 16;                            /*!< 下个128bit分段                 */
    }

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);          /*关闭AES模块时钟                   */

    return TRUE;                                                    /*!< 解密成功                       */
}

/**
*********************************************************************************************************
*                                CTR加密/解密计算
*
* @biref: CTR加密/解密计算
*           加密算法：Ci = Pi ^ E(K,Yi)           ,for i=1,2,...,n-1
*                          Pn ^ MSBu(E(K,Yn))     ,for i=n
*           解密算法：Pi = Ci ^ E(K,Yi)           ,for i=1,2,...,n-1
*                          Cn ^ MSBu(E(K,Yn))     ,for i=n
*                 Pi为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 Ci为明文分段，每段128 bits，最后段u bits，总位长 (n-1)*128+u bits，1<= u <=128
*                 E(K,Yi)为对Yi进行AES加密运算
*                 MSBu(S)为返回1字符串，字符串包含S数据的最左边u个bits
*
* @param: CTR_InputStruct    CTR加密输入变量结构体指针，主要包含5个参数:
*                              1) AESKeyMode        : 加密解密模式选择
*                              2) *pKeyAddr         : 密钥地址指针
*                              3) *pInttextAddr     : 待加解密数据地址指针
*                              4) LenInttext        : 待加解密数据长度（byte）
*                              5) *Counter0         : Counter0地址指针
*           CTR_OutputStruct   CTR加密输出变量结构体指针，主要包含2个参数:
*                              1) *pOuttextAddr     : 已加/解密数据地址指针
*                              2) LenOuttext        : 已加/解密数据长度（byte）
*
* @retval: 无
*
* @note: 加密操作时，pInttextAddr和LenInttext为明文输入，pOuttextAddr为密文输出
*           解密操作时，pInttextAddr和LenInttext为密文输入，pOuttextAddr为明文输出
*********************************************************************************************************
*/
void CTR_Encrypt(CTR_Encrypt_InputTypedef* CTR_InputStruct,CTR_Encrypt_OutputTypedef* CTR_OutputStruct)
{
    uint8_t i;
    Parameter128bits_TypeDef  Counter_temp,Aes_GCM_temp;

    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,ENABLE);           /*打开AES模块时钟           */

    CTR_OutputStruct->LenOuttext = CTR_InputStruct->LenInttext;
                                                                                                                        /*!< LenOuttext = LenInttext        */
    for(i=0;i<4;i++)
    {
        Counter_temp.u32[i] = CTR_InputStruct->Counter0->u32[i];                                                                                                               /*!< counter0存到Counter_temp备用    */
    }
//Ci = Pi ^ E(K,Yi)           ,for i=1,2,...,n-1
    while(CTR_InputStruct->LenInttext>=16)                    /*!< P位长判断  16bytes（128bits）  */
    {
        GCM_Counter_increase(&Counter_temp);                  /*!< GCM Counter(Yi)累加计算        */
        HT_AES_Encrypt(CTR_InputStruct->AESKeyMode,CTR_InputStruct->pKeyAddr,Counter_temp.u32);
                                                                                                                    /*!< 对Counter(Yi)AES加密操作 ， E(K,Yi)      */
        while(HT_AES_Busy_StatusGet());                       /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_GCM_temp.u32);                        /*!< 读取运算结果，存储到 Aes_GCM_temp*/
        for(i=0;i<16;i++)
        {
            *CTR_OutputStruct->pOuttextAddr++ = Aes_GCM_temp.u8[i] ^ *CTR_InputStruct->pInttextAddr++;                                                                                                      /*!< Pi ^ E(K,Yi)运算               */
        }
        CTR_InputStruct->LenInttext -= 16;                    /*!< 下个128bit分段                 */
    }
//Cn = Pn ^ MSBu(E(K,Yn))     ,for i=n
    if(CTR_InputStruct->LenInttext)
    {
        GCM_Counter_increase(&Counter_temp);                  /*!< GCM Counter(Yi)累加计算        */
        HT_AES_Encrypt(CTR_InputStruct->AESKeyMode,CTR_InputStruct->pKeyAddr,Counter_temp.u32);
                                                                                                                    /*!< 对Counter(Yn)AES加密操作 ， E(K,Yn)  */
        while(HT_AES_Busy_StatusGet());                       /*!< AES加密运算完成判断            */
        HT_AES_Read(Aes_GCM_temp.u32);                        /*!< 读取运算结果，存储到 Aes_GCM_temp1   */
        for(i=16-CTR_InputStruct->LenInttext;i<16;i++)
        {
            *CTR_OutputStruct->pOuttextAddr++ = Aes_GCM_temp.u8[i] ^ *CTR_InputStruct->pInttextAddr++;                                                                                                                     /*!< Pn ^ MSBu(E(K,Yn))运算          */
        }
    }
    HT_CMU_ClkCtrl0Config(CMU_CLKCTRL0_ADESRADEN,DISABLE);    /*关闭AES模块时钟           */
}

/**
*********************************************************************************************************
*                                GCM_AES EXAMPLES FOR HT6x2x/HT501x
*
* @brief: 利用库函数实现GCM_AES加/解密
*
* @param: 无
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
/*变量定义*/
    Parameter256bits_TypeDef  AesKey;             //密钥
    AESKeyMode_TypeDef  AESKeyMode;               //加密方式
    Parameter512bits_TypeDef  Plaintext;          //明文
    uint64_t  LenPtext;                           //明文位长
    Parameter512bits_TypeDef  Ciphertext;         //密文
    uint64_t  LenCtext;                           //密文位长
    Parameter256bits_TypeDef  AddAuthData;        //附加认证数据
    uint64_t  LenAdata;                           //附加认证数据位长
    Parameter512bits_TypeDef  InitVector;         //初始向量
    uint64_t  LenIV;                              //初始向量位长
    Parameter128bits_TypeDef  AuthTag;            //认证标签
    Bool DecryptSta;                              //解密成功状态

    Parameter128bits_TypeDef  CTR_Counter0;       //CTR初始计数器值

void AES_GCM_Example(uint8_t TestCase)
{
    CMU_InitTypeDef  CMU_InitStructure;
    GCM_Encrypt_InputTypedef GCM_Encrypt_InputStruct;
    GCM_Encrypt_OutputTypedef GCM_Encrypt_OutputStruct;
    GCM_Decrypt_InputTypedef GCM_Decrypt_InputStruct;
    GCM_Decrypt_OutputTypedef GCM_Decrypt_OutputStruct;
    uint8_t i;

/*输入参数初始化*/
    GCM_TestCase_Init(TestCase);
/*设置系统时钟*/
    CMU_InitStructure.SysClkSel = SysPLL;
    CMU_InitStructure.CPUDiv = CPUDiv1;
    HT_CMU_Init(&CMU_InitStructure);


/*加密输入结构体初始化*/
    for(i=0;i<16;i++)
    {
        Ciphertext.u32[i] = 0x0000;
        AuthTag.u8[i] = 0x00;
    }
    GCM_Encrypt_InputStruct.AESKeyMode = AESKeyMode;
    GCM_Encrypt_InputStruct.pKeyAddr = AesKey.u32;
    GCM_Encrypt_InputStruct.pInitVectorAddr = InitVector.u8;
    GCM_Encrypt_InputStruct.LenIV = LenIV;
    GCM_Encrypt_InputStruct.pPtextAddr = Plaintext.u8;
    GCM_Encrypt_InputStruct.LenPtext = LenPtext;
    GCM_Encrypt_InputStruct.pAdataAddr = AddAuthData.u8;
    GCM_Encrypt_InputStruct.LenAdata = LenAdata;
    GCM_Encrypt_OutputStruct.AuthTag = &AuthTag;
    GCM_Encrypt_OutputStruct.pCtextAddr = Ciphertext.u8;
    GCM_Encrypt(&GCM_Encrypt_InputStruct,&GCM_Encrypt_OutputStruct);                    /*!< gcm 加密 */

/*解密输入结构体初始化*/
    for(i=0;i<16;i++)
    {
        Plaintext.u32[i] = 0x0000;
    }
    GCM_Decrypt_InputStruct.AESKeyMode = AESKeyMode;
    GCM_Decrypt_InputStruct.pKeyAddr = AesKey.u32;
    GCM_Decrypt_InputStruct.pInitVectorAddr = InitVector.u8;
    GCM_Decrypt_InputStruct.LenIV = LenIV;
    GCM_Decrypt_InputStruct.pCtextAddr = GCM_Encrypt_OutputStruct.pCtextAddr;
    GCM_Decrypt_InputStruct.LenCtext = GCM_Encrypt_OutputStruct.LenCtext;
    GCM_Decrypt_InputStruct.pAdataAddr = AddAuthData.u8;
    GCM_Decrypt_InputStruct.LenAdata = LenAdata;
    GCM_Decrypt_InputStruct.AuthTag = &AuthTag;
    GCM_Decrypt_OutputStruct.pPtextAddr = Plaintext.u8;
    DecryptSta = GCM_Decrypt(&GCM_Decrypt_InputStruct, &GCM_Decrypt_OutputStruct);      /*!< gcm 解密 */
}

/**
*********************************************************************************************************
*                                CTR_AES EXAMPLES FOR HT6x2x/HT501x
*
* @brief: 利用库函数实现CTR_AES加/解密
*
* @param: 无
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void AES_CTR_Example(void)
{
    CMU_InitTypeDef  CMU_InitStructure;
    CTR_Encrypt_InputTypedef CTR_Encrypt_InputStruct;
    CTR_Encrypt_OutputTypedef CTR_Encrypt_OutputStruct;
    uint8_t i;

/*输入参数初始化*/
    CTR_TestCase_Init();
/*设置系统时钟*/
    CMU_InitStructure.SysClkSel = SysPLL;
    CMU_InitStructure.CPUDiv = CPUDiv1;
    HT_CMU_Init(&CMU_InitStructure);

/*加密输入结构体初始化*/
    for(i=0;i<16;i++)
    {
            Ciphertext.u32[i] = 0x0000;
    }
    CTR_Encrypt_InputStruct.AESKeyMode = AESKeyMode;
    CTR_Encrypt_InputStruct.pKeyAddr = AesKey.u32;
    CTR_Encrypt_InputStruct.pInttextAddr = Plaintext.u8;
    CTR_Encrypt_InputStruct.LenInttext= LenPtext;
    CTR_Encrypt_InputStruct.Counter0 = &CTR_Counter0;
    CTR_Encrypt_OutputStruct.pOuttextAddr = Ciphertext.u8;
    CTR_Encrypt(&CTR_Encrypt_InputStruct,&CTR_Encrypt_OutputStruct);                    /*!< CTR 加密 */

/*解密输入结构体初始化*/
    LenCtext = CTR_Encrypt_OutputStruct.LenOuttext;
    for(i=0;i<16;i++)
    {
            Plaintext.u32[i] = 0x0000;
    }
    CTR_Encrypt_InputStruct.AESKeyMode = AESKeyMode;
    CTR_Encrypt_InputStruct.pKeyAddr = AesKey.u32;
    CTR_Encrypt_InputStruct.pInttextAddr = Ciphertext.u8;
    CTR_Encrypt_InputStruct.LenInttext= LenCtext;
    CTR_Encrypt_InputStruct.Counter0 = &CTR_Counter0;
    CTR_Encrypt_OutputStruct.pOuttextAddr = Plaintext.u8;
    CTR_Encrypt(&CTR_Encrypt_InputStruct,&CTR_Encrypt_OutputStruct);                    /*!< CTR 解密 */
}
/**
*********************************************************************************************************
*                                CBC_AES EXAMPLES FOR HT6x2x/HT501x
*
* @brief: 利用库函数实现CBC_AES加/解密
*
* @param: 无
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void AES_CBC_Example(void)
{
    CMU_InitTypeDef  CMU_InitStructure;
    CBC_Encrypt_InputTypedef CBC_Encrypt_InputStruct;
    CBC_Encrypt_OutputTypedef CBC_Encrypt_OutputStruct;
    CBC_Decrypt_InputTypedef CBC_Decrypt_InputStruct;
    CBC_Decrypt_OutputTypedef CBC_Decrypt_OutputStruct;
    uint8_t i;

/*输入参数初始化*/
    CBC_TestCase_Init();
/*设置系统时钟*/
    CMU_InitStructure.SysClkSel = SysPLL;
    CMU_InitStructure.CPUDiv = CPUDiv1;
    HT_CMU_Init(&CMU_InitStructure);

/*加密输入结构体初始化*/
    for(i=0;i<16;i++)
    {
        Ciphertext.u32[i] = 0x0000;
    }
    CBC_Encrypt_InputStruct.AESKeyMode = AESKeyMode;
    CBC_Encrypt_InputStruct.pKeyAddr = AesKey.u32;
    CBC_Encrypt_InputStruct.pPtextAddr = Plaintext.u8;
    CBC_Encrypt_InputStruct.LenPtext= LenPtext;
    CBC_Encrypt_InputStruct.pInitVectorAddr = &CTR_Counter0;
    CBC_Encrypt_OutputStruct.pCtextAddr = Ciphertext.u8;
    CBC_Encrypt(&CBC_Encrypt_InputStruct,&CBC_Encrypt_OutputStruct);                    /*!< CBC 加密 */

/*解密输入结构体初始化*/
    LenCtext = CBC_Encrypt_OutputStruct.LenCtext;
    for(i=0;i<16;i++)
    {
        Plaintext.u32[i] = 0x0000;
    }
    CBC_Decrypt_InputStruct.AESKeyMode = AESKeyMode;
    CBC_Decrypt_InputStruct.pKeyAddr = AesKey.u32;
    CBC_Decrypt_InputStruct.pCtextAddr = Ciphertext.u8;
    CBC_Decrypt_InputStruct.LenCtext= LenCtext;
    CBC_Decrypt_InputStruct.pInitVectorAddr= &CTR_Counter0;
    CBC_Decrypt_OutputStruct.pPtextAddr = Plaintext.u8;
    DecryptSta = CBC_Decrypt(&CBC_Decrypt_InputStruct,&CBC_Decrypt_OutputStruct);                   /*!< CBC 解密 */
}

/**
*********************************************************************************************************
*                                ECB_AES EXAMPLES FOR HT6x2x/HT501x
*
* @brief: 利用库函数实现ECB_AES加/解密
*
* @param: 无
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void AES_ECB_Example(void)
{
    CMU_InitTypeDef  CMU_InitStructure;
    ECB_Encrypt_InputTypedef ECB_Encrypt_InputStruct;
    ECB_Encrypt_OutputTypedef ECB_Encrypt_OutputStruct;
    ECB_Decrypt_InputTypedef ECB_Decrypt_InputStruct;
    ECB_Decrypt_OutputTypedef ECB_Decrypt_OutputStruct;
    uint8_t i;

/*输入参数初始化*/
    ECB_TestCase_Init();
/*设置系统时钟*/
    CMU_InitStructure.SysClkSel = SysPLL;
    CMU_InitStructure.CPUDiv = CPUDiv1;
    HT_CMU_Init(&CMU_InitStructure);

/*加密输入结构体初始化*/
    for(i=0;i<16;i++)
    {
        Ciphertext.u32[i] = 0x0000;
    }
    ECB_Encrypt_InputStruct.AESKeyMode = AESKeyMode;
    ECB_Encrypt_InputStruct.pKeyAddr = AesKey.u32;
    ECB_Encrypt_InputStruct.pPtextAddr = Plaintext.u8;
    ECB_Encrypt_InputStruct.LenPtext= LenPtext;
    ECB_Encrypt_OutputStruct.pCtextAddr = Ciphertext.u8;
    ECB_Encrypt(&ECB_Encrypt_InputStruct,&ECB_Encrypt_OutputStruct);                    /*!< ECB 加密 */

/*解密输入结构体初始化*/
    LenCtext = ECB_Encrypt_OutputStruct.LenCtext;
    for(i=0;i<16;i++)
    {
        Plaintext.u32[i] = 0x0000;
    }
    ECB_Decrypt_InputStruct.AESKeyMode = AESKeyMode;
    ECB_Decrypt_InputStruct.pKeyAddr = AesKey.u32;
    ECB_Decrypt_InputStruct.pCtextAddr = Ciphertext.u8;
    ECB_Decrypt_InputStruct.LenCtext= LenCtext;
    ECB_Decrypt_OutputStruct.pPtextAddr = Plaintext.u8;
    DecryptSta = ECB_Decrypt(&ECB_Decrypt_InputStruct,&ECB_Decrypt_OutputStruct);                   /*!< ECB 解密 */
}

/**
*********************************************************************************************************
*                                TEST CASE INITIAL
*
* @brief: 各加密算法验证testcase初始化
*
* @param: 无
*
* @retval: 无
*
* @note: 此函数默认不参与工程编译
*********************************************************************************************************
*/
void GCM_TestCase_Init(uint8_t TestCase)
{
switch(TestCase)
{
    case 1:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;

        LenPtext  =  0;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;

        break;

    case 2:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;

        LenPtext  =  16;
        Plaintext.u32[0]  =   0x00000000;
        Plaintext.u32[1]  =   0x00000000;
        Plaintext.u32[2]  =   0x00000000;
        Plaintext.u32[3]    =   0x00000000;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;
        break;

    case 3:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0]   =   0xfeffe992;
        AesKey.u32[1]   =   0x8665731c;
        AesKey.u32[2]   =   0x6d6a8f94;
        AesKey.u32[3]   =   0x67308308;

        LenPtext  =  16*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
        Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[13]   =   0xba637b39;
        Plaintext.u32[14]   =   0xaa0de657;
        Plaintext.u32[15]   =   0xb16aedf5;

        LenIV = 12;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;

        LenAdata = 0;
        break;

    case 4:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0]   =   0xfeffe992;
        AesKey.u32[1]   =   0x8665731c;
        AesKey.u32[2]   =   0x6d6a8f94;
        AesKey.u32[3]   =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;


        LenIV = 3*4;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;
        break;

    case 5:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 2*4;
//      InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[0] = 0xfacedbad;
        InitVector.u32[1] = 0xcafebabe;
        break;

    case 6:
        AESKeyMode = KEY_Mode_128bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 15*4;
        InitVector.u32[0] = 0xff5269aa;
        InitVector.u32[1] = 0x55909c5a;
        InitVector.u32[2] = 0xf88406e5;
        InitVector.u32[3] = 0x9313225d;
        InitVector.u32[4] = 0xa318a728;
        InitVector.u32[5] = 0xe4c303d2;
        InitVector.u32[6] = 0x534f7da1;
        InitVector.u32[7] = 0x6a7a9538;
        InitVector.u32[8] = 0x9a6b5254;
        InitVector.u32[9] = 0xfcf0e242;
        InitVector.u32[10] = 0x56809539;
        InitVector.u32[11] = 0xc3c0c951;
        InitVector.u32[12] = 0xa637b39b;
        InitVector.u32[13] = 0xa0de6a57;
        InitVector.u32[14] = 0x16aedbf5;
        break;

    case 7:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;
        AesKey.u32[4] =   0x00000000;
        AesKey.u32[5] =   0x00000000;

        LenPtext  =  0;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;
        break;

    case 8:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;
        AesKey.u32[4] =   0x00000000;
        AesKey.u32[5] =   0x00000000;

        LenPtext  =  16;
        Plaintext.u32[0]    =   0x00000000;
        Plaintext.u32[1]  =   0x00000000;
        Plaintext.u32[2]  =   0x00000000;
        Plaintext.u32[3]  =   0x00000000;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;
        break;

    case 9:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4]   =   0xfeffe992;
        AesKey.u32[5]   =   0x8665731c;

        LenPtext  =  16*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
        Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[13]   =   0xba637b39;
        Plaintext.u32[14]   =   0xaa0de657;
        Plaintext.u32[15]   =   0xb16aedf5;

        LenAdata = 0;

        LenIV = 3*4;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;
        break;

    case 10:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4]   =   0xfeffe992;
        AesKey.u32[5]   =   0x8665731c;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 3*4;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;
        break;

    case 11:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4]   =   0xfeffe992;
        AesKey.u32[5]   =   0x8665731c;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 2*4;
//      InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[0] = 0xfacedbad;
        InitVector.u32[1] = 0xcafebabe;
        break;

    case 12:
        AESKeyMode = KEY_Mode_192bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4]   =   0xfeffe992;
        AesKey.u32[5]   =   0x8665731c;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 15*4;
        InitVector.u32[0] = 0xff5269aa;
        InitVector.u32[1] = 0x55909c5a;
        InitVector.u32[2] = 0xf88406e5;
        InitVector.u32[3] = 0x9313225d;
        InitVector.u32[4] = 0xa318a728;
        InitVector.u32[5] = 0xe4c303d2;
        InitVector.u32[6] = 0x534f7da1;
        InitVector.u32[7] = 0x6a7a9538;
        InitVector.u32[8] = 0x9a6b5254;
        InitVector.u32[9] = 0xfcf0e242;
        InitVector.u32[10] = 0x56809539;
        InitVector.u32[11] = 0xc3c0c951;
        InitVector.u32[12] = 0xa637b39b;
        InitVector.u32[13] = 0xa0de6a57;
        InitVector.u32[14] = 0x16aedbf5;
        break;

    case 13:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;
        AesKey.u32[4] =   0x00000000;
        AesKey.u32[5] =   0x00000000;
        AesKey.u32[6] =   0x00000000;
        AesKey.u32[7] =   0x00000000;

        LenPtext  =  0;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;
        break;

    case 14:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0x00000000;
        AesKey.u32[1] =   0x00000000;
        AesKey.u32[2] =   0x00000000;
        AesKey.u32[3] =   0x00000000;
        AesKey.u32[4] =   0x00000000;
        AesKey.u32[5] =   0x00000000;
        AesKey.u32[6] =   0x00000000;
        AesKey.u32[7] =   0x00000000;

        LenPtext  =  16;
        Plaintext.u32[0]  =   0x00000000;
        Plaintext.u32[1]  =   0x00000000;
        Plaintext.u32[2]  =   0x00000000;
        Plaintext.u32[3]  =   0x00000000;

        LenIV = 12;
        InitVector.u32[0] = 0x00000000;
        InitVector.u32[1] = 0x00000000;
        InitVector.u32[2] = 0x00000000;

        LenAdata = 0;
        break;

    case 15:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4] =   0xfeffe992;
        AesKey.u32[5] =   0x8665731c;
        AesKey.u32[6] =   0x6d6a8f94;
        AesKey.u32[7] =   0x67308308;

        LenPtext  =  16*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
        Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[13]   =   0xba637b39;
        Plaintext.u32[14]   =   0xaa0de657;
        Plaintext.u32[15]   =   0xb16aedf5;

        LenAdata = 0;

        LenIV = 3*4;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;
        break;

    case 16:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4] =   0xfeffe992;
        AesKey.u32[5] =   0x8665731c;
        AesKey.u32[6] =   0x6d6a8f94;
        AesKey.u32[7] =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 3*4;
        InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[1] = 0xfacedbad;
        InitVector.u32[2] = 0xcafebabe;
        break;

    case 17:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4] =   0xfeffe992;
        AesKey.u32[5] =   0x8665731c;
        AesKey.u32[6] =   0x6d6a8f94;
        AesKey.u32[7] =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 2*4;
//      InitVector.u32[0] = 0xdecaf888;
        InitVector.u32[0] = 0xfacedbad;
        InitVector.u32[1] = 0xcafebabe;
        break;

    case 18:
        AESKeyMode = KEY_Mode_256bits;
        AesKey.u32[0] =   0xfeffe992;
        AesKey.u32[1] =   0x8665731c;
        AesKey.u32[2] =   0x6d6a8f94;
        AesKey.u32[3] =   0x67308308;
        AesKey.u32[4]   =   0xfeffe992;
        AesKey.u32[5]   =   0x8665731c;
        AesKey.u32[6] =   0x6d6a8f94;
        AesKey.u32[7] =   0x67308308;

        LenPtext  =  15*4;
        Plaintext.u32[0]  =   0xaff5269a;
        Plaintext.u32[1]  =   0xa55909c5;
        Plaintext.u32[2]  =   0xf88406e5;
        Plaintext.u32[3]  =   0xd9313225;
        Plaintext.u32[4]  =   0x8a318a72;
        Plaintext.u32[5]  =   0x2e4c303d;
        Plaintext.u32[6]  =   0x1534f7da;
        Plaintext.u32[7]  =   0x86a7a953;
        Plaintext.u32[8]  =   0x49a6b525;
        Plaintext.u32[9]  =   0x2fcf0e24;
        Plaintext.u32[10]   =   0x95680953;
        Plaintext.u32[11]   =   0x1c3c0c95;
//      Plaintext.u32[12]   =   0x1aafd255;
        Plaintext.u32[12]   =   0xba637b39;
        Plaintext.u32[13]   =   0xaa0de657;
        Plaintext.u32[14]   =   0xb16aedf5;

        LenAdata = 5*4;
        AddAuthData.u32[0]  =   0xdeadbeef;
        AddAuthData.u32[1]  =   0xfeedface;
        AddAuthData.u32[2]  =   0xdeadbeef;
        AddAuthData.u32[3]  =   0xfeedface;
        AddAuthData.u32[4]  =   0xabaddad2;

        LenIV = 15*4;
        InitVector.u32[0] = 0xff5269aa;
        InitVector.u32[1] = 0x55909c5a;
        InitVector.u32[2] = 0xf88406e5;
        InitVector.u32[3] = 0x9313225d;
        InitVector.u32[4] = 0xa318a728;
        InitVector.u32[5] = 0xe4c303d2;
        InitVector.u32[6] = 0x534f7da1;
        InitVector.u32[7] = 0x6a7a9538;
        InitVector.u32[8] = 0x9a6b5254;
        InitVector.u32[9] = 0xfcf0e242;
        InitVector.u32[10] = 0x56809539;
        InitVector.u32[11] = 0xc3c0c951;
        InitVector.u32[12] = 0xa637b39b;
        InitVector.u32[13] = 0xa0de6a57;
        InitVector.u32[14] = 0x16aedbf5;
        break;
    default:
        break;
    }
}

void CTR_TestCase_Init(void)
{
    AESKeyMode = KEY_Mode_256bits;
    AesKey.u32[0] =   0xfeffe992;
    AesKey.u32[1] =   0x8665731c;
    AesKey.u32[2] =   0x6d6a8f94;
    AesKey.u32[3] =   0x67308308;
    AesKey.u32[4] =   0xfeffe992;
    AesKey.u32[5] =   0x8665731c;
    AesKey.u32[6] =   0x6d6a8f94;
    AesKey.u32[7] =   0x67308308;

    LenPtext  =  15*4;
    Plaintext.u32[0]  =   0xaff5269a;
    Plaintext.u32[1]  =   0xa55909c5;
    Plaintext.u32[2]  =   0xf88406e5;
    Plaintext.u32[3]  =   0xd9313225;
    Plaintext.u32[4]  =   0x8a318a72;
    Plaintext.u32[5]  =   0x2e4c303d;
    Plaintext.u32[6]  =   0x1534f7da;
    Plaintext.u32[7]  =   0x86a7a953;
    Plaintext.u32[8]  =   0x49a6b525;
    Plaintext.u32[9]  =   0x2fcf0e24;
    Plaintext.u32[10]   =   0x95680953;
    Plaintext.u32[11]   =   0x1c3c0c95;
//  Plaintext.u32[12]   =   0x1aafd255;
    Plaintext.u32[12]   =   0xba637b39;
    Plaintext.u32[13]   =   0xaa0de657;
    Plaintext.u32[14]   =   0xb16aedf5;

    CTR_Counter0.u32[0] = 0x06bc8eb4;
    CTR_Counter0.u32[1] = 0x079f8e24;
    CTR_Counter0.u32[2] = 0x140a5976;
    CTR_Counter0.u32[3] = 0x0cd953e2;
}

void CBC_TestCase_Init(void)
{
    AESKeyMode = KEY_Mode_256bits;
    AesKey.u32[0] =   0xfeffe992;
    AesKey.u32[1] =   0x8665731c;
    AesKey.u32[2] =   0x6d6a8f94;
    AesKey.u32[3] =   0x67308308;
    AesKey.u32[4] =   0xfeffe992;
    AesKey.u32[5] =   0x8665731c;
    AesKey.u32[6] =   0x6d6a8f94;
    AesKey.u32[7] =   0x67308308;

    LenPtext  =  15*4;
    Plaintext.u32[0]  =   0xaff5269a;
    Plaintext.u32[1]  =   0xa55909c5;
    Plaintext.u32[2]  =   0xf88406e5;
    Plaintext.u32[3]  =   0xd9313225;
    Plaintext.u32[4]  =   0x8a318a72;
    Plaintext.u32[5]  =   0x2e4c303d;
    Plaintext.u32[6]  =   0x1534f7da;
    Plaintext.u32[7]  =   0x86a7a953;
    Plaintext.u32[8]  =   0x49a6b525;
    Plaintext.u32[9]  =   0x2fcf0e24;
    Plaintext.u32[10]   =   0x95680953;
    Plaintext.u32[11]   =   0x1c3c0c95;
//  Plaintext.u32[12]   =   0x1aafd255;
    Plaintext.u32[12]   =   0xba637b39;
    Plaintext.u32[13]   =   0xaa0de657;
    Plaintext.u32[14]   =   0xb16aedf5;

    CTR_Counter0.u32[0] = 0xca6b0cba;
    CTR_Counter0.u32[1] = 0x52047196;
    CTR_Counter0.u32[2] = 0xf41a5514;
    CTR_Counter0.u32[3] = 0x83bcdd0a;
}
void ECB_TestCase_Init(void)
{
    AESKeyMode = KEY_Mode_256bits;
    AesKey.u32[0] =   0xfeffe992;
    AesKey.u32[1] =   0x8665731c;
    AesKey.u32[2] =   0x6d6a8f94;
    AesKey.u32[3] =   0x67308308;
    AesKey.u32[4] =   0xfeffe992;
    AesKey.u32[5] =   0x8665731c;
    AesKey.u32[6] =   0x6d6a8f94;
    AesKey.u32[7] =   0x67308308;

    LenPtext  =  16*4;
    Plaintext.u32[0]  =   0x06bc8eb4;
    Plaintext.u32[1]  =   0x079f8e24;
    Plaintext.u32[2]  =   0x140a5976;
    Plaintext.u32[3]  =   0x0cd953e2;
    Plaintext.u32[4]  =   0x06bc8eb5;
    Plaintext.u32[5]  =   0x079f8e24;
    Plaintext.u32[6]  =   0x140a5976;
    Plaintext.u32[7]  =   0x0cd953e2;
    Plaintext.u32[8]  =   0x06bc8eb6;
    Plaintext.u32[9]  =   0x079f8e24;
    Plaintext.u32[10]   =   0x140a5976;
    Plaintext.u32[11]   =   0x0cd953e2;
    Plaintext.u32[12]   =   0x06bc8eb7;
    Plaintext.u32[13]   =   0x079f8e24;
    Plaintext.u32[14]   =   0x140a5976;
    Plaintext.u32[15]   =   0x0cd953e2;
}

#endif                                        /* This File Only support HT6x2x, HT6x3x, HT501x and HT502x */


#endif  /* __EXAMPLE_C */
