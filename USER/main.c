#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
//#include "mavlink_avoid_errors.h"

#include "mavlink_usart_fifo.h"
#include "sysu_mavlink.h"
#include "rtc.h"
#include "usmart.h"


#define UART_TX_BUFFER_SIZE        255
#define UART_RX_BUFFER_SIZE        255
#define BUFFER_LENGTH 128
extern fifo_t uart_rx_fifo, uart_tx_fifo;
extern uint8_t uart_tx_buf[UART_TX_BUFFER_SIZE], uart_rx_buf[UART_RX_BUFFER_SIZE];



int main(void)
{ 
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);      //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	
	usmart_dev.init(84); 	//初始化USMART	
	LED_Init();					  //初始化LED
 	LCD_Init();					  //初始化LCD
	My_RTC_Init();		 		//初始化RTC
  //serial_open();
	//RTC_Set_WakeUp(RTC_WakeUpClock_CK_SPRE_16bits,0);		//配置WAKE UP中断,1秒钟中断一次
	
	fifo_init(&uart_tx_fifo, uart_tx_buf, UART_TX_BUFFER_SIZE);	
	fifo_init(&uart_rx_fifo, uart_rx_buf, UART_RX_BUFFER_SIZE);

	int	system_id = 1; // system id
  int	component_id = 1; // component id

	uint8_t buf[BUFFER_LENGTH];
	uint16_t len;
	
	
	mavlink_dn_fxsj_t dn_fxsj_plain = { 0 };
	mavlink_dn_fxsj_t_init(&dn_fxsj_plain);
	//mavlink_dn_fxsj_t dn_fxsj_plain = dn_fxsj_init();
	mavlink_dn_fxsj_t dn_fxsj_cipher = { 0 };
	mavlink_dn_fxsj_t_cipher(&dn_fxsj_plain,&dn_fxsj_cipher);
		
	mavlink_message_t message;
	mavlink_msg_dn_fxsj_encode(system_id, component_id, &message, &dn_fxsj_cipher);
	len = mavlink_msg_to_send_buffer(buf, &message);
	// 	设置签名
	mavlink_signing_t signing;
	mavlink_signing_streams_t signing_streams;
	memset(&signing, 0, sizeof(signing));
	memcpy(signing.secret_key, secret_key_ground, 32);
	memset(&signing_streams, 0, sizeof(signing_streams));
	signing_streams.num_signing_streams = 0;
	

	uint64_t timestamp_test = getRTCAsUnixTime_m();
	signing.timestamp = timestamp_test;

		u8 tbuf[40];
		u8 t=0;
	
	serial_write_buf(buf, len);

while(1) 
	{
//		bool check_signature = mavlink_signature_check(&signing, &signing_streams, &message);
//		if(check_signature){
//			printf("check_signature PASS"); 
//		}else
//		{
//			printf("check_signature Failed"); 
//		}
		
		//serial_write_buf(buf, len);
		while(1)
		{
		update();
		}
	}
}
