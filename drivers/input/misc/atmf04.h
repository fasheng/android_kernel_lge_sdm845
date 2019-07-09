#ifndef __ATMF04_EFLASH_H__
#define __ATMF04_EFLASH_H__

#define SZ_PAGE_DATA                64
#ifdef CONFIG_LGE_USE_SAR_CONTROLLER
#define FW_DATA_PAGE               	115
#else
#define FW_DATA_PAGE               	96
#endif

#define ADDR_EFLA_STS               0xFF	//eflash status register
#define ADDR_EFLA_PAGE_L            0xFD	//eflash page
#define ADDR_EFLA_PAGE_H            0xFE	//eflash page
#define ADDR_EFLA_CTRL              0xFC	//eflash control register

#define CMD_EFL_L_WR                0x01	//Eflash Write
#define CMD_EFL_RD                  0x03	//Eflash Read
#define CMD_EFL_ERASE_ALL           0x07	//Eflash All Page Erase

#define CMD_EUM_WR                  0x21	//Extra user memory write
#define CMD_EUM_RD                  0x23	//Extra user memory read
#define CMD_EUM_ERASE               0x25	//Extra user memory erase

#define FLAG_DONE                   0x03
#define FLAG_DONE_ERASE             0x02

#define FLAG_FUSE                   1
#define FLAG_FW                     2

//============================================================//
//[20180327] ADS Change
//[START]=====================================================//
//#define FL_EFLA_TIMEOUT_CNT         200
#define FL_EFLA_TIMEOUT_CNT         20
//[END]======================================================//
#define IC_TIMEOUT_CNT        5 

#define RTN_FAIL                    0
#define RTN_SUCC                    1
#define RTN_TIMEOUT                 2

#define ON                          1
#define OFF                         2

#if 1 // debugging calibration paused
#define SAR_CAL_RESULT_PASS			0 // "1"
#define SAR_CAL_RESULT_FAIL			"0"
#endif

#endif

#if defined(CONFIG_MACH_SDM450_CV7A_LAO_COM) || defined(CONFIG_MACH_SDM845_JUDYLN) || defined(CONFIG_MACH_SDM845_JUDYPN) || defined(CONFIG_MACH_SDM845_BETA)
#define CONFIG_LGE_ATMF04_2CH
#endif

#if defined(CONFIG_LGE_USE_SAR_CONTROLLER) // register init value
#if defined(CONFIG_LGE_ATMF04_2CH)
#define CNT_INITCODE               26
#else
#define CNT_INITCODE               17
#endif
// Each operator use different initcode value
#if defined(CONFIG_MACH_MSM8952_B3_ATT_US) || defined(CONFIG_MACH_MSM8952_B3_BELL_CA) || defined(CONFIG_MACH_MSM8952_B3_RGS_CA)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x6B, 0x68, 0x17, 0x00, 0x14, 0x0F, 0x00, 0x0B, 0x00, 0x07, 0x81, 0x20 }; // High Band ANT , auto cal 15%, sensing 2.5%, LNF filter
#elif defined(CONFIG_MACH_MSM8952_B3_TMO_US)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x71, 0x67, 0x17, 0x00, 0x14, 0x0F, 0x00, 0x0B, 0x00, 0x07, 0x81, 0x20 }; // High Band ANT , auto cal 15%, sensing 2.5%, LNF filter
#elif defined(CONFIG_MACH_MSM8952_B3_JP_KDI)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x6B, 0x68, 0x17, 0x00, 0x14, 0x3F, 0x00, 0x0B, 0x00, 0x07, 0x81, 0x20 }; // High Band ANT , auto cal 15%, sensing 2.5%, LNF filter
#elif defined(CONFIG_MACH_MSM8952_B5_ATT_US)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x6B, 0x68, 0x15, 0x00, 0x0C, 0x7F, 0x00, 0x0B, 0x00, 0x07, 0x81, 0x20 }; // Low Band ANT , auto cal 15%, sensing 1.5%, LNF filter
#elif defined(CONFIG_MACH_MSM8952_B5_USC_US)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x6A, 0x60, 0x15, 0x00, 0x0C, 0x14, 0x00, 0x0F, 0x00, 0x0C, 0x81, 0x20 }; // Low Band ANT , auto cal 15%, sensing 1.5%, LNF filter
#elif defined(CONFIG_MACH_SDM845_JUDYLN)
static unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x09, 0x0A, 0x0B, 0X0C, 0X0D, 0x0E, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
static unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x9A, 0x00, 0x21, 0x33, 0x0B, 0x0B, 0x6E, 0x64, 0x7F, 0x6C, 0x73, 0x83, 0x01, 0x9A, 0x00, 0x19, 0xD0, 0xA4, 0x0B, 0x07, 0x12, 0x07, 0x33, 0x02, 0x13 };
#ifdef  CONFIG_LGE_ONE_BINARY_SKU //for judyln lao(global/eu)model
static unsigned char InitCodeVal_SKU[CNT_INITCODE]     = { 0x00, 0x9A, 0x00, 0x21, 0x33, 0x0B, 0x0B, 0x6E, 0x64, 0x7D, 0x71, 0x73, 0x83, 0x01, 0x9A, 0x00, 0x19, 0xD0, 0xA4, 0x0B, 0x07, 0x12, 0x07, 0x33, 0x02, 0x13 };
#endif
#elif defined(CONFIG_MACH_SDM845_JUDYPN) || defined(CONFIG_MACH_SDM845_BETA)
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x09, 0x0A, 0x0B, 0X0C, 0X0D, 0x0E, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x9A, 0x00, 0x21, 0x33, 0x0B, 0x0B, 0x64, 0x64, 0x64, 0x64, 0x73, 0x83, 0x01, 0x9A, 0x00, 0x14, 0xD0, 0xA4, 0x0B, 0x07, 0x0A, 0x05, 0x33, 0x05, 0x2F };
#else // default
static const unsigned char InitCodeAddr[CNT_INITCODE]    = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0C, 0x0D, 0x0E, 0x1A, 0x1B, 0x1C, 0x1D, 0x20, 0x21 };
static const unsigned char InitCodeVal[CNT_INITCODE]     = { 0x00, 0x7A, 0x33, 0x0B, 0x08, 0x6B, 0x68, 0x17, 0x00, 0x14, 0x7F, 0x00, 0x0B, 0x00, 0x07, 0x81, 0x20 }; // High Band ANT , auto cal 15%, sensing 2.5%, LNF filter 
#endif
#else // defined (CONFIG_LGE_USE_SAR_CONTROLLER)
#define CNT_INITCODE                7
const unsigned char InitCodeAddr[CNT_INITCODE] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
const unsigned char InitCodeVal[CNT_INITCODE] = { 0x00, 0x0A, 0x69, 0x67, 0x0B, 0x33, 0x1E };
#endif // defined (CONFIG_LGE_USE_SAR_CONTROLLER)
