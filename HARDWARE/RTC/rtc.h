#ifndef __RTC_H
#define __RTC_H	 
#include "sys.h" 
#include "led.h"
#include "delay.h"
#include "usart.h" 
#include <time.h>
#include "sys.h"
#include "stm32f4xx_rtc.h"

struct timeval {
        long    tv_sec;         /* seconds */
        long   tv_usec;        /* and microseconds */
};
 //////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//RTC 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/5
//版本：V1.1
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
//********************************************************************************
//修改说明
//V1.1 20140726
//新增:RTC_Get_Week函数,用于根据年月日信息,得到星期信息.
////////////////////////////////////////////////////////////////////////////////// 

	
u8 My_RTC_Init(void);						//RTC初始化
ErrorStatus RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm);			//RTC时间设置
ErrorStatus RTC_Set_Date(u8 year,u8 month,u8 date,u8 week); 		//RTC日期设置
void RTC_Set_AlarmA(u8 week,u8 hour,u8 min,u8 sec);		//设置闹钟时间(按星期闹铃,24小时制)
void RTC_Set_WakeUp(u32 wksel,u16 cnt);					//周期性唤醒定时器设置
int gettimeofday(struct timeval* tp, void* tzp);
uint64_t get_time_msec(void);//获取时间戳
time_t getRTCAsUnixTime(void);
uint64_t getRTCAsUnixTime_m(void);
#endif

















