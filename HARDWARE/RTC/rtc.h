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
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//RTC ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/5
//�汾��V1.1
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
//********************************************************************************
//�޸�˵��
//V1.1 20140726
//����:RTC_Get_Week����,���ڸ�����������Ϣ,�õ�������Ϣ.
////////////////////////////////////////////////////////////////////////////////// 

	
u8 My_RTC_Init(void);						//RTC��ʼ��
ErrorStatus RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm);			//RTCʱ������
ErrorStatus RTC_Set_Date(u8 year,u8 month,u8 date,u8 week); 		//RTC��������
void RTC_Set_AlarmA(u8 week,u8 hour,u8 min,u8 sec);		//��������ʱ��(����������,24Сʱ��)
void RTC_Set_WakeUp(u32 wksel,u16 cnt);					//�����Ի��Ѷ�ʱ������
int gettimeofday(struct timeval* tp, void* tzp);
uint64_t get_time_msec(void);//��ȡʱ���
time_t getRTCAsUnixTime(void);
uint64_t getRTCAsUnixTime_m(void);
#endif

















