#include "sys.h"
#include "mavlink_usart_fifo.h"
#define UART_TX_BUFFER_SIZE        255
#define UART_RX_BUFFER_SIZE        255
fifo_t uart_rx_fifo, uart_tx_fifo;
uint8_t uart_tx_buf[UART_TX_BUFFER_SIZE], uart_rx_buf[UART_RX_BUFFER_SIZE];
/** @brief ��FIFO
  * @param fifo ����������
	*        *ch   ����������
	* @return 
	*        ��ȷ��ȡ��1�� �����ݣ�0
  */
uint8_t fifo_read_ch(fifo_t* fifo, uint8_t* ch)
{
	if(fifo->tail == fifo->head) return false;
	*ch = fifo->buf[fifo->tail];  
	
	if(++fifo->tail >= fifo->length) fifo->tail = 0;
  return true;
}
/** @brief дһ�ֽ����ݵ�FIFO
  * @param fifo ��д�뻺����
	*        ch   ��д�������
	* @return 
	*        ��ȷ��1�� ����������0
  */
uint8_t fifo_write_ch(fifo_t* fifo, uint8_t ch)
{
	uint16_t h = fifo->head;
	
	if(++h >= fifo->length) h = 0;
	if(h == fifo->tail) return false;
	
	fifo->buf[fifo->head] = ch;
	fifo->head = h;
  return true;
}
/** @brief ���ػ�����ʣ���ֽڳ���
  * @param fifo 
	* @return 
	*        ʣ��ռ�
  *
  * @note  ʣ���ֽڳ��ȴ��ڵ���2ʱ���ſ�д������
  */
uint16_t fifo_free(fifo_t* fifo)  
{
	uint16_t free;
	
	if(fifo->head >= fifo->tail) free = fifo->tail + (fifo->length - fifo->head);
	else free = fifo->tail - fifo->head;
	
  return free;
}
uint16_t fifo_used(fifo_t* fifo)
{
	uint16_t used;
	
	if(fifo->head >= fifo->tail) used = fifo->head - fifo->tail;
	else used = fifo->head + (fifo->length - fifo->tail);
	
	return used;	
}
/** @brief ��ʼ��������
  * @param *fifo
  *        *buf 
  *        length
  */
void fifo_init(fifo_t* fifo, uint8_t* buf, uint16_t length)  
{
	uint16_t i;
	
	fifo->buf = buf;
	fifo->length = length;
	fifo->head = 0;
	fifo->tail = 0;
	
	for(i=0; i<length; i++) fifo->buf[i] = 0;	
}
/** @brief д���ݵ����ڣ���������
  *        
  * @note ����д�뷢�仺���������������жϣ����жϳ��������Զ�����
  */
uint8_t serial_write_buf(uint8_t* buf, uint16_t length) {
	uint16_t i;
	
	if(length == 0) return false;
  for(i = 0; length > 0; length--, i++)	{
		fifo_write_ch(&uart_tx_fifo, buf[i]);
	}	
  USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
	
	return true;
}
/** @brief �Դ��ڶ����� 
  * @return һ�ֽ�����
  */
uint8_t serial_read_ch(void){
	uint8_t ch;	
	fifo_read_ch(&uart_rx_fifo, &ch);	
	return ch;
}
/** @breif ��ⷢ�仺����ʣ���ֽڳ��� 
  * @return ʣ���ֽڳ���
  */
uint16_t serial_free(void){
	return fifo_free(&uart_tx_fifo);
}
uint16_t serial_available(void){
	return fifo_used(&uart_rx_fifo);
}
void USART1_IRQHandler(void)
{			
  uint8_t c;	
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)//���ݽ����ն�
  {	
		c = USART_ReceiveData(USART1);  
		fifo_write_ch(&uart_rx_fifo, c);		
    //USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
  }
  if(USART_GetITStatus(USART1, USART_IT_TXE) != RESET)//���ݷ����ж�
  {   		
		if(fifo_read_ch(&uart_tx_fifo, &c)) 
			USART_SendData(USART1, c);     
		else 
			USART_SendData(USART1, 0x55);			
    if (fifo_used(&uart_tx_fifo) == 0) // Check if all data is transmitted . if yes disable transmitter UDRE interrupt
    {
      // Disable the EVAL_COM1 Transmit interrupt 
      USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
    }
  }		
}

