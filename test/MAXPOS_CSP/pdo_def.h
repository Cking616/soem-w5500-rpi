/* 
 * SOEM EtherCAT exmaple
 * Ported to raspberry pi by Ho Tam - thanhtam.h[at]gmail.com 
 */
 

#ifndef _PDO_DEF_
#define _PDO_DEF_

#include "servo_def.h"

//MAXPOS PDO mapping

typedef union _mapping_obj{
	uint32_t obj;
	struct {
		uint16_t index;
		uint8_t subindex;
		uint8_t size;
	};
} mapping_obj;

//0x1600 RxPDO
typedef struct PACKED
{
	unsigned short control_word; //关节控制字
	int			   target_position; //位置环-目标位置
	int			   target_velocity; //速度环-目标速度
	short		   target_torque;	//力矩环-目标力矩
	char		   mod;				//模式- 8:位置环控制，9:速度环控制，10:力矩环控制
	char		   unused;
}MAXPOS_DRIVE_RxPDO_t;

//0x1A00 TxPDO
typedef struct PACKED
{
	unsigned short status_word;
	int			   actual_position; //光编位置
	int			   actual_velocity;
	int			   actual_external_position; //磁编位置
	short		   actual_torque;
	char		   display_mod;
	char		   unused;
}MAXPOS_DRIVE_TxPDO_t;


typedef struct _MAXPOS_ServoDrive
{
	MAXPOS_DRIVE_RxPDO_t 	OutParam;
	MAXPOS_DRIVE_TxPDO_t 	InParam;
} MAXPOS_ServoDrive_t;

typedef struct _MAXPOS_Drive_pt
{
	MAXPOS_DRIVE_RxPDO_t 	*ptOutParam;
	MAXPOS_DRIVE_TxPDO_t 	*ptInParam;
} MAXPOS_Drive_pt;


#endif //_PDO_DEF_

