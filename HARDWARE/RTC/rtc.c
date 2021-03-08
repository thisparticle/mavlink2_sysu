#include "rtc.h"


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

NVIC_InitTypeDef   NVIC_InitStructure;

//RTCʱ������
//hour,min,sec:Сʱ,����,����
//ampm:@RTC_AM_PM_Definitions  :RTC_H12_AM/RTC_H12_PM
//����ֵ:SUCEE(1),�ɹ�
//       ERROR(0),�����ʼ��ģʽʧ�� 
ErrorStatus RTC_Set_Time(u8 hour,u8 min,u8 sec,u8 ampm)
{
	RTC_TimeTypeDef RTC_TimeTypeInitStructure;
	
	RTC_TimeTypeInitStructure.RTC_Hours=hour;
	RTC_TimeTypeInitStructure.RTC_Minutes=min;
	RTC_TimeTypeInitStructure.RTC_Seconds=sec;
	RTC_TimeTypeInitStructure.RTC_H12=ampm;
	
	return RTC_SetTime(RTC_Format_BIN,&RTC_TimeTypeInitStructure);
	
}
//RTC��������
//year,month,date:��(0~99),��(1~12),��(0~31)
//week:����(1~7,0,�Ƿ�!)
//����ֵ:SUCEE(1),�ɹ�
//       ERROR(0),�����ʼ��ģʽʧ�� 
ErrorStatus RTC_Set_Date(u8 year,u8 month,u8 date,u8 week)
{
	
	RTC_DateTypeDef RTC_DateTypeInitStructure;
	RTC_DateTypeInitStructure.RTC_Date=date;
	RTC_DateTypeInitStructure.RTC_Month=month;
	RTC_DateTypeInitStructure.RTC_WeekDay=week;
	RTC_DateTypeInitStructure.RTC_Year=year;
	return RTC_SetDate(RTC_Format_BIN,&RTC_DateTypeInitStructure);
}

//RTC��ʼ��
//����ֵ:0,��ʼ���ɹ�;
//       1,LSE����ʧ��;
//       2,�����ʼ��ģʽʧ��;
u8 My_RTC_Init(void)
{
	RTC_InitTypeDef RTC_InitStructure;
	u16 retry=0X1FFF; 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);//ʹ��PWRʱ��
	PWR_BackupAccessCmd(ENABLE);	//ʹ�ܺ󱸼Ĵ������� 
	
	if(RTC_ReadBackupRegister(RTC_BKP_DR0)!=0x5050)		//�Ƿ��һ������?
	{
		RCC_LSEConfig(RCC_LSE_ON);//LSE ����    
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)	//���ָ����RCC��־λ�������,�ȴ����پ������
			{
			retry++;
			delay_ms(10);
			}
		if(retry==0)return 1;		//LSE ����ʧ��. 
			
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);		//����RTCʱ��(RTCCLK),ѡ��LSE��ΪRTCʱ��    
		RCC_RTCCLKCmd(ENABLE);	//ʹ��RTCʱ�� 

    //RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//RTC�첽��Ƶϵ��(1~0X7F)
			RTC_InitStructure.RTC_AsynchPrediv = 0x7F;//RTC�첽��Ƶϵ��(1~0X7F)
    RTC_InitStructure.RTC_SynchPrediv  = 0xFF;//RTCͬ����Ƶϵ��(0~7FFF)
		//RTC_InitStructure.RTC_SynchPrediv = 0x7FFF;
    RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;//RTC����Ϊ,24Сʱ��ʽ
    RTC_Init(&RTC_InitStructure);
 
		RTC_Set_Time(10,19,00,RTC_H12_AM);	//����ʱ��
		RTC_Set_Date(20,11,12,4);		//��������
	 
		RTC_WriteBackupRegister(RTC_BKP_DR0,0x5050);	//����Ѿ���ʼ������
	} 
 
	return 0;
}

//��������ʱ��(����������,24Сʱ��)
//week:���ڼ�(1~7) @ref  RTC_Alarm_Definitions
//hour,min,sec:Сʱ,����,����
void RTC_Set_AlarmA(u8 week,u8 hour,u8 min,u8 sec)
{ 
	EXTI_InitTypeDef   EXTI_InitStructure;
	RTC_AlarmTypeDef RTC_AlarmTypeInitStructure;
	RTC_TimeTypeDef RTC_TimeTypeInitStructure;
	
	RTC_AlarmCmd(RTC_Alarm_A,DISABLE);//�ر�����A 
	
  RTC_TimeTypeInitStructure.RTC_Hours=hour;//Сʱ
	RTC_TimeTypeInitStructure.RTC_Minutes=min;//����
	RTC_TimeTypeInitStructure.RTC_Seconds=sec;//��
	RTC_TimeTypeInitStructure.RTC_H12=RTC_H12_AM;
  
	RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDay=week;//����
	RTC_AlarmTypeInitStructure.RTC_AlarmDateWeekDaySel=RTC_AlarmDateWeekDaySel_WeekDay;//��������
	RTC_AlarmTypeInitStructure.RTC_AlarmMask=RTC_AlarmMask_None;//��ȷƥ�����ڣ�ʱ����
	RTC_AlarmTypeInitStructure.RTC_AlarmTime=RTC_TimeTypeInitStructure;
  RTC_SetAlarm(RTC_Format_BIN,RTC_Alarm_A,&RTC_AlarmTypeInitStructure);
 
	
	RTC_ClearITPendingBit(RTC_IT_ALRA);//���RTC����A�ı�־
  EXTI_ClearITPendingBit(EXTI_Line17);//���LINE17�ϵ��жϱ�־λ 
	
	RTC_ITConfig(RTC_IT_ALRA,ENABLE);//��������A�ж�
	RTC_AlarmCmd(RTC_Alarm_A,ENABLE);//��������A 
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line17;//LINE17
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //�����ش��� 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE17
  EXTI_Init(&EXTI_InitStructure);//����

	NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn; 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//��ռ���ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
}

//�����Ի��Ѷ�ʱ������  
/*wksel:  @ref RTC_Wakeup_Timer_Definitions
#define RTC_WakeUpClock_RTCCLK_Div16        ((uint32_t)0x00000000)
#define RTC_WakeUpClock_RTCCLK_Div8         ((uint32_t)0x00000001)
#define RTC_WakeUpClock_RTCCLK_Div4         ((uint32_t)0x00000002)
#define RTC_WakeUpClock_RTCCLK_Div2         ((uint32_t)0x00000003)
#define RTC_WakeUpClock_CK_SPRE_16bits      ((uint32_t)0x00000004)
#define RTC_WakeUpClock_CK_SPRE_17bits      ((uint32_t)0x00000006)
*/
//cnt:�Զ���װ��ֵ.����0,�����ж�.
void RTC_Set_WakeUp(u32 wksel,u16 cnt)
{ 
	EXTI_InitTypeDef   EXTI_InitStructure;
	
	RTC_WakeUpCmd(DISABLE);//�ر�WAKE UP
	
	RTC_WakeUpClockConfig(wksel);//����ʱ��ѡ��
	
	RTC_SetWakeUpCounter(cnt);//����WAKE UP�Զ���װ�ؼĴ���
	
	
	RTC_ClearITPendingBit(RTC_IT_WUT); //���RTC WAKE UP�ı�־
  EXTI_ClearITPendingBit(EXTI_Line22);//���LINE22�ϵ��жϱ�־λ 
	 
	RTC_ITConfig(RTC_IT_WUT,ENABLE);//����WAKE UP ��ʱ���ж�
	RTC_WakeUpCmd( ENABLE);//����WAKE UP ��ʱ����
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line22;//LINE22
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//�ж��¼�
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising; //�����ش��� 
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;//ʹ��LINE22
  EXTI_Init(&EXTI_InitStructure);//����
 
 
	NVIC_InitStructure.NVIC_IRQChannel = RTC_WKUP_IRQn; 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;//��ռ���ȼ�1
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;//�����ȼ�2
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ���ⲿ�ж�ͨ��
  NVIC_Init(&NVIC_InitStructure);//����
}

//RTC�����жϷ�����
void RTC_Alarm_IRQHandler(void)
{    
	if(RTC_GetFlagStatus(RTC_FLAG_ALRAF)==SET)//ALARM A�ж�?
	{
		RTC_ClearFlag(RTC_FLAG_ALRAF);//����жϱ�־
		printf("ALARM A!\r\n");
	}   
	EXTI_ClearITPendingBit(EXTI_Line17);	//����ж���17���жϱ�־ 											 
}

//RTC WAKE UP�жϷ�����
void RTC_WKUP_IRQHandler(void)
{    
	if(RTC_GetFlagStatus(RTC_FLAG_WUTF)==SET)//WK_UP�ж�?
	{ 
		RTC_ClearFlag(RTC_FLAG_WUTF);	//����жϱ�־
		LED1=!LED1; 
	}   
	EXTI_ClearITPendingBit(EXTI_Line22);//����ж���22���жϱ�־ 								
}
 

//char* time_to_timestamp(void)
//{
//	unsigned int timestamp;
//	struct tm stm;
//	char *timestamp_buf;
//	char *buf;
//	timestamp_buf = (char *)mem_malloc(10);
//	buf = (char *)mem_malloc(100);
//	
//	RTC_DateTypeDef RTC_DateStruct;
//	RTC_TimeTypeDef	RTC_TimeStruct;
//	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
//	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
//	
//	stm.tm_year = RTC_DateStruct.RTC_Year + 100;	//RTC_Year rang 0-99,but tm_year since 1900
//	stm.tm_mon	= RTC_DateStruct.RTC_Month-1;		//RTC_Month rang 1-12,but tm_mon rang 0-11
//	stm.tm_mday	= RTC_DateStruct.RTC_Date;			//RTC_Date rang 1-31 and tm_mday rang 1-31
//	stm.tm_hour	= RTC_TimeStruct.RTC_Hours-8;			//RTC_Hours rang 0-23 and tm_hour rang 0-23
//	stm.tm_min	= RTC_TimeStruct.RTC_Minutes;   //RTC_Minutes rang 0-59 and tm_min rang 0-59
//	stm.tm_sec	= RTC_TimeStruct.RTC_Seconds;		
//	sprintf(buf,"\r\nrtc %d-%d-%d  %d.%d.%d\r\n",\
//	RTC_DateStruct.RTC_Year,RTC_DateStruct.RTC_Month,RTC_DateStruct.RTC_Date,\
//	RTC_TimeStruct.RTC_Hours,RTC_TimeStruct.RTC_Minutes,RTC_TimeStruct.RTC_Seconds);
//	USART_COM3_Send_data(buf,strlen(buf));
//	mem_free(buf);
//	sprintf(timestamp_buf,"%u",mktime(&stm));
//	USART_COM3_Send_data(timestamp_buf,strlen(timestamp_buf));
//	return timestamp_buf;
//}

int gettimeofday(struct timeval* tp, void* tzp)
{
	time_t clock;
	struct tm stm;
	
	RTC_DateTypeDef RTC_DateStruct;
	RTC_TimeTypeDef	RTC_TimeStruct;
	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
	
	stm.tm_year = RTC_DateStruct.RTC_Year + 100;	//RTC_Year rang 0-99,but tm_year since 1900
	stm.tm_mon	= RTC_DateStruct.RTC_Month-1;		//RTC_Month rang 1-12,but tm_mon rang 0-11
	stm.tm_mday	= RTC_DateStruct.RTC_Date;			//RTC_Date rang 1-31 and tm_mday rang 1-31
	stm.tm_hour	= RTC_TimeStruct.RTC_Hours-8;			//RTC_Hours rang 0-23 and tm_hour rang 0-23
	stm.tm_min	= RTC_TimeStruct.RTC_Minutes;   //RTC_Minutes rang 0-59 and tm_min rang 0-59
	stm.tm_sec	= RTC_TimeStruct.RTC_Seconds;	
	stm.tm_isdst = -1;
	clock = mktime(&stm);
	tp->tv_sec = clock;
	//tp->tv_usec = wtm.wMilliseconds * 1000;
	//tp->tv_usec = (32767-RTC_GetDivider())*1000/32767;
	//tp->tv_usec = RTC_GetSubSecond()*30.52;
	//tp->tv_usec=(32767-RTC_GetSubSecond())*1000/32767;
	tp->tv_usec = 0;
	return (0);
}


uint64_t get_time_msec(void)
{
//	static struct timeval _time_stamp;
//	gettimeofday(&_time_stamp, NULL);
//	return (_time_stamp.tv_sec * 1000000 + _time_stamp.tv_usec) / 1000;
	RTC_DateTypeDef RTC_DateStruct;
	RTC_TimeTypeDef	RTC_TimeStruct;
	RTC_TimeTypeDef* RTC_StampTimeStruct; 
	RTC_DateTypeDef* RTC_StampDateStruct;
	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
	struct tm stm;
	stm.tm_year = RTC_DateStruct.RTC_Year + 100;	//RTC_Year rang 0-99,but tm_year since 1900
	stm.tm_mon	= RTC_DateStruct.RTC_Month-1;		//RTC_Month rang 1-12,but tm_mon rang 0-11
	stm.tm_mday	= RTC_DateStruct.RTC_Date;			//RTC_Date rang 1-31 and tm_mday rang 1-31
	stm.tm_hour	= RTC_TimeStruct.RTC_Hours-8;			//RTC_Hours rang 0-23 and tm_hour rang 0-23
	stm.tm_min	= RTC_TimeStruct.RTC_Minutes;   //RTC_Minutes rang 0-59 and tm_min rang 0-59
	stm.tm_sec	= RTC_TimeStruct.RTC_Seconds;	
	stm.tm_isdst = 0;
	//printf("\r\nrtc %d-%d-%d  %d.%d.%d\r\n",\
	RTC_DateStruct.RTC_Year,RTC_DateStruct.RTC_Month,RTC_DateStruct.RTC_Date,\
	RTC_TimeStruct.RTC_Hours,RTC_TimeStruct.RTC_Minutes,RTC_TimeStruct.RTC_Seconds);
	/* TimeStamp configuration functions ******************************************/
//	RTC_TimeStampCmd(RTC_TimeStampEdge_Rising, ENABLE);
//	RTC_GetTimeStamp(RTC_Format_BIN, RTC_StampTimeStruct, RTC_StampDateStruct);
//	printf("%d ",RTC_StampDateStruct->RTC_WeekDay);
	RTC_TimeStampCmd(RTC_TimeStampEdge_Rising, ENABLE);
	RTC_GetTimeStamp(RTC_Format_BIN, RTC_StampTimeStruct, RTC_StampDateStruct);
	uint64_t ttt = RTC_GetTimeStampSubSecond();
	printf("%llu!",ttt);
	return ttt*1000;
}

time_t getRTCAsUnixTime(void) {
	RTC_DateTypeDef RTC_DateStruct;
	RTC_TimeTypeDef	RTC_TimeStruct;
	RTC_TimeTypeDef RTC_StampTimeStruct; 
	RTC_DateTypeDef RTC_StampDateStruct;
	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
	struct tm stm;
	stm.tm_year = RTC_DateStruct.RTC_Year + 100;	//RTC_Year rang 0-99,but tm_year since 1900
	stm.tm_mon	= RTC_DateStruct.RTC_Month-1;		//RTC_Month rang 1-12,but tm_mon rang 0-11
	stm.tm_mday	= RTC_DateStruct.RTC_Date;			//RTC_Date rang 1-31 and tm_mday rang 1-31
	stm.tm_hour	= RTC_TimeStruct.RTC_Hours-8;			//RTC_Hours rang 0-23 and tm_hour rang 0-23
	stm.tm_min	= RTC_TimeStruct.RTC_Minutes;   //RTC_Minutes rang 0-59 and tm_min rang 0-59
	stm.tm_sec	= RTC_TimeStruct.RTC_Seconds;	
	stm.tm_isdst = 0;
	/* TimeStamp configuration functions ******************************************/
	RTC_TimeStampCmd(RTC_TimeStampEdge_Rising, ENABLE);
	RTC_GetTimeStamp(RTC_Format_BIN, &RTC_TimeStruct, &RTC_DateStruct);
	uint32_t timestamp_subsecond = RTC_GetTimeStampSubSecond();
//	uint64_t timestamp = (uint64_t)(((int)timestamp_test)*1000);
//	printf("%llu",timestamp);
	time_t clock = mktime(&stm);
	//printf(" -%d- ",clock);
	//uint64_t timestamp_test = (uint64_t)(((long)clock)*1000);
	//int timestamp_test = ((int)clock)*1000 + (int)timestamp_subsecond;
	//uint64_t timestamp = (uint64_t)timestamp_test;
	//printf(" -%llu- ",timestamp);
	return clock;
	//return mktime(&stm);
	//return timestamp;
}

//time_t getRTCAsUnixTime(void) {
//	RTC_DateTypeDef RTC_DateStruct;
//	RTC_TimeTypeDef	RTC_TimeStruct;
//	RTC_TimeTypeDef RTC_StampTimeStruct; 
//	RTC_DateTypeDef RTC_StampDateStruct;
////	RTC_GetDate(RTC_Format_BIN,&RTC_DateStruct);
////	RTC_GetTime(RTC_Format_BIN,&RTC_TimeStruct);
////	RTC_GetDate(RTC_Format_BIN,RTC_StampDateStruct);
////	RTC_GetTime(RTC_Format_BIN,RTC_StampTimeStruct);
//	/* TimeStamp configuration functions ******************************************/
//	RTC_TimeStampCmd(RTC_TimeStampEdge_Rising, ENABLE);
//	RTC_GetTimeStamp(RTC_Format_BIN, &RTC_StampTimeStruct, &RTC_StampDateStruct);
//	//printf(" %d ",RTC_StampTimeStruct.RTC_Hours);
//	uint32_t timestamp_test = RTC_GetTimeStampSubSecond();
//	uint64_t timestamp = (uint64_t)(((int)timestamp_test)*1000);
//	printf("%llu",timestamp);
//	//return mktime(&stm);
//	return timestamp;
//}

//uint64_t utc; // mS since epoch

//utc = (uint64_t)getRTCAsUnixTime() * 1000;

//void HAL_SYSTICK_Callback(void) {
// other stuff here that has to be done each ms
//++utc;
//}

uint64_t getRTCAsUnixTime_m(void){
	time_t clock = getRTCAsUnixTime();
	
	RTC_TimeTypeDef* RTC_StampTimeStruct; 
	RTC_DateTypeDef* RTC_StampDateStruct;
	RTC_TimeStampCmd(RTC_TimeStampEdge_Rising, ENABLE);
	RTC_GetTimeStamp(RTC_Format_BIN, RTC_StampTimeStruct, RTC_StampDateStruct);
	uint32_t timestamp_subsecond = RTC_GetTimeStampSubSecond();
	
	//uint64_t timestamp = (uint64_t)((int)clock)*1000+(int)timestamp_subsecond;
	uint64_t timestamp = (uint64_t)((int)clock)*10000+((int)timestamp_subsecond)*10;
//	printf(" -%llu- ",(uint64_t)clock);
//	printf(" -%llu- ",(uint64_t)((int)clock)*1000);
//	printf(" -%d- ",timestamp_subsecond);
//	printf(" -%llu- ",(uint64_t)((int)clock)*1000+(int)timestamp_subsecond);
	//printf(" -%llu- ",timestamp);
	return timestamp;
}




