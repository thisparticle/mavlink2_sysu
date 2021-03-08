#ifndef __SYSU_TEST_MAVLINK_H
#define __SYSU_TEST_MAVLINK_H
#include "mavlink_avoid_errors.h"
#include "mavlink_aes.h"
#include "mavlink_msg_attitude.h"

#include "lcd.h"


// secret_key_ground
static const uint8_t secret_key_ground[32] = {
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9,
    0x42, 0x71, 0xb5, 0xe9
};

 BYTE key[1][32] =
    {
        {0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
    };
    WORD key_schedule[60];
    BYTE iv[1][16] =
    {
        {0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0xff},
    };
    BYTE enc_buf[MAVLINK_MSG_ID_DN_FXSJ_LEN];
		BYTE ciphertext[1][MAVLINK_MSG_ID_DN_FXSJ_LEN];
		BYTE plaintext[1][MAVLINK_MSG_ID_DN_FXSJ_LEN];

		
void mavlink_dn_fxsj_t_plain(mavlink_dn_fxsj_t* dn_fxsj_cipher , mavlink_dn_fxsj_t* dn_fxsj){
		aes_key_setup(key[0], key_schedule, 256);
		memcpy(&ciphertext, dn_fxsj_cipher, MAVLINK_MSG_ID_DN_FXSJ_LEN);
		aes_decrypt_ctr(ciphertext[0], MAVLINK_MSG_ID_DN_FXSJ_LEN, enc_buf, key_schedule, 256, iv[0]);
    memcpy(dn_fxsj, &enc_buf, MAVLINK_MSG_ID_DN_FXSJ_LEN);
//						printf("Got msg DN_FXSJ \n");
//            printf("    HEAD, MSG_ID, UAV_ID, LEN, Checksum:     %s  %d %d %d %d    \n", dn_fxsj.head, dn_fxsj.msg_id, dn_fxsj.uav_id, dn_fxsj.length, dn_fxsj.checksum );
//            printf("    GPS_lat, GPS_lon, GPS_alt:    %d %d %d                      \n", dn_fxsj.GPS_lat, dn_fxsj.GPS_lon, dn_fxsj.GPS_alt );
//            printf("    GPS_Vn, GPS_Ve :    %d %d                                   \n", dn_fxsj.GPS_Vn, dn_fxsj.GPS_Ve );
//            printf("    GPS_num, GPS_time, GPS_sec :    %d %d %d                    \n", dn_fxsj.GPS_num, dn_fxsj.GPS_time, dn_fxsj.GPS_sec );
//            printf("    pos  (NED):     %d %d %d (cm)                               \n", dn_fxsj.x, dn_fxsj.y, dn_fxsj.z );
//            printf("    vel  (NED):     %d %d %d (cm/s)                             \n", dn_fxsj.vx, dn_fxsj.vy, dn_fxsj.vz );
//            printf("    acc  (NED):     %d %d %d (cm/s^2)                           \n", dn_fxsj.ax, dn_fxsj.ay, dn_fxsj.az );
//            printf("    angle     :     %d %d %d (degree)                           \n", dn_fxsj.pitch, dn_fxsj.roll, dn_fxsj.yaw );
//            printf("    acc_vibe, gyro_vibe :    %d %d                              \n", dn_fxsj.acc_vibe, dn_fxsj.gyro_vibe );
//            printf("\n");
}

// process receiving code
void update(void)
{
	mavlink_message_t msg;
  mavlink_status_t status;
	// 	设置签名
	mavlink_signing_t signing;
	mavlink_signing_streams_t signing_streams;
	memset(&signing, 0, sizeof(signing));
	memcpy(signing.secret_key, secret_key_ground, 32);
	memset(&signing_streams, 0, sizeof(signing_streams));
	signing_streams.num_signing_streams = 0;
	uint64_t timestamp_test = getRTCAsUnixTime_m();
	signing.timestamp = timestamp_test;
	status.signing = &signing;
	status.signing_streams  = &signing_streams;
	
	mavlink_dn_fxsj_t dn_fxsj = { 0 };
	mavlink_dn_fxsj_t dn_fxsj_cipher = { 0 };
	uint8_t temp;
    // process received bytes
	int i = 0;
	uint16_t len;
	uint8_t buf[128];
    while(serial_available())
			//while(i<300)
    {
      uint8_t c = serial_read_ch(); 
			temp = c;
			i++;
			//printf(" -%x- ", temp);
        // Try to get a new message
        if (mavlink_parse_char(MAVLINK_COMM_1, c, &msg, &status)) {
            //mavlink_active = true;
            
					  //printf("%c",c);
					  //printf("Received message with ID %d, sequence: %d from component %d of system %d",\
										msg.msgid, msg.seq, msg.compid, msg.sysid);
					//len = mavlink_msg_to_send_buffer(buf, &msg);
					//serial_write_buf(buf, len);
					  //handle_msg(&signing, &signing_streams, &msg);
					
		bool check_signature = mavlink_signature_check(&signing, &signing_streams, &msg);
		if (check_signature)
    {
        printf("\n check_signature pass ! \n");
			mavlink_msg_dn_fxsj_decode(&msg, &dn_fxsj_cipher);
					mavlink_dn_fxsj_t_plain(&dn_fxsj_cipher,&dn_fxsj);
						printf("Got msg DN_FXSJ \n");
            printf("    HEAD, MSG_ID, UAV_ID, LEN, Checksum:     %s  %d %d %d %d    \n", dn_fxsj.head, dn_fxsj.msg_id, dn_fxsj.uav_id, dn_fxsj.length, dn_fxsj.checksum );
            printf("    GPS_lat, GPS_lon, GPS_alt:    %d %d %d                      \n", dn_fxsj.GPS_lat, dn_fxsj.GPS_lon, dn_fxsj.GPS_alt );
            printf("    GPS_Vn, GPS_Ve :    %d %d                                   \n", dn_fxsj.GPS_Vn, dn_fxsj.GPS_Ve );
            printf("    GPS_num, GPS_time, GPS_sec :    %d %d %d                    \n", dn_fxsj.GPS_num, dn_fxsj.GPS_time, dn_fxsj.GPS_sec );
            printf("    pos  (NED):     %d %d %d (cm)                               \n", dn_fxsj.x, dn_fxsj.y, dn_fxsj.z );
            printf("    vel  (NED):     %d %d %d (cm/s)                             \n", dn_fxsj.vx, dn_fxsj.vy, dn_fxsj.vz );
            printf("    acc  (NED):     %d %d %d (cm/s^2)                           \n", dn_fxsj.ax, dn_fxsj.ay, dn_fxsj.az );
            printf("    angle     :     %d %d %d (degree)                           \n", dn_fxsj.pitch, dn_fxsj.roll, dn_fxsj.yaw );
            printf("    acc_vibe, gyro_vibe :    %d %d                              \n", dn_fxsj.acc_vibe, dn_fxsj.gyro_vibe );
            printf("\n");
    }
    else
    {
        printf("\n check_signature not pass ! \n");
    }
						printf("Received message with ID %d, sequence: %d from component %d of system %d",\
										msg.msgid, msg.seq, msg.compid, msg.sysid);
					  //LCD_ShowString(30,180,220,16,16,"mavlink_parse_char PASS!");
					}
//				printf(" +%d ",i);
//				if(i>6) {printf(" +--+ ");}
     }
}



bool handle_msg(mavlink_signing_t signing,mavlink_signing_streams_t signing_streams,const mavlink_message_t *msg)
//int handle_msg(const mavlink_message_t *msg)
{
//		mavlink_dn_fxsj_t dn_fxsj_plain  = { 0 };
//    mavlink_msg_dn_fxsj_decode( msg, &dn_fxsj_plain);
//		//mavlink_msg_dn_fxsj_encode(1,1,msg,&dn_fxsj_plain);
//		
//		printf("Got msg DN_FXSJ \n");
//            printf("    magic:          %02X    \n", msg->magic );
//            printf("    len:            %02X    \n", msg->len );
//            printf("    incompat_flags: %02X    \n", msg->incompat_flags );
//            printf("    compat_flags:   %02X    \n", msg->compat_flags );
//            printf("    seq:            %02X    \n", msg->seq );
//            printf("    sysid:          %02X    \n", msg->sysid );
//            printf("    compid:         %02X    \n", msg->compid );
//            printf("    msgid:          %02X    \n", msg->msgid );
//		printf("    ckecksum:       %02X-%02X    \n", msg->ck[0],msg->ck[1] );
//            printf("    link id:        %02X    \n", msg->signature[0] );
//            printf("    time stamp:     %02X-%02X-%02X-%02X-%02X-%02X    \n", msg->signature[1], msg->signature[2], msg->signature[3], msg->signature[4], msg->signature[5], msg->signature[6] );
//            printf("    signature:      %02X-%02X-%02X-%02X-%02X-%02X    \n", msg->signature[7], msg->signature[8], msg->signature[9], msg->signature[10], msg->signature[11], msg->signature[12] );
//            printf("    HEAD, MSG_ID, UAV_ID, LEN, Checksum:     %s  %d %d %d %d    \n", dn_fxsj_plain.head, dn_fxsj_plain.msg_id, dn_fxsj_plain.uav_id, dn_fxsj_plain.length, dn_fxsj_plain.checksum );
//            printf("    GPS_lat, GPS_lon, GPS_alt:    %d %d %d                      \n", dn_fxsj_plain.GPS_lat, dn_fxsj_plain.GPS_lon, dn_fxsj_plain.GPS_alt );
//            printf("    GPS_Vn, GPS_Ve :    %d %d                                   \n", dn_fxsj_plain.GPS_Vn, dn_fxsj_plain.GPS_Ve );
//            printf("    GPS_num, GPS_time, GPS_sec :    %d %d %d                    \n", dn_fxsj_plain.GPS_num, dn_fxsj_plain.GPS_time, dn_fxsj_plain.GPS_sec );
//            printf("    pos  (NED):     %d %d %d (cm)                               \n", dn_fxsj_plain.x, dn_fxsj_plain.y, dn_fxsj_plain.z );
//            printf("    vel  (NED):     %d %d %d (cm/s)                             \n", dn_fxsj_plain.vx, dn_fxsj_plain.vy, dn_fxsj_plain.vz );
//            printf("    acc  (NED):     %d %d %d (cm/s^2)                           \n", dn_fxsj_plain.ax, dn_fxsj_plain.ay, dn_fxsj_plain.az );
//            printf("    angle     :     %d %d %d (degree)                           \n", dn_fxsj_plain.pitch, dn_fxsj_plain.roll, dn_fxsj_plain.yaw );
//            printf("    acc_vibe, gyro_vibe :    %d %d                              \n", dn_fxsj_plain.acc_vibe, dn_fxsj_plain.gyro_vibe );
//            printf("\n");
		
		u8 tbuf[40];
    bool check_signature = mavlink_signature_check(&signing, &signing_streams, msg);
		if (check_signature)
    {
        printf("check_signature pass ! \n");
    }
    else
    {
        printf("check_signature not pass ! \n");
    }
		return check_signature;
}

void mavlink_dn_fxsj_t_init(mavlink_dn_fxsj_t* dn_fxsj_plain){
	dn_fxsj_plain->head[0] = '$';
  dn_fxsj_plain->head[1] = 'D';
  dn_fxsj_plain->head[2] = 'N';
  dn_fxsj_plain->msg_id = 1;
  dn_fxsj_plain->uav_id = 0;
  dn_fxsj_plain->length = 49 + 8;
  dn_fxsj_plain->checksum = 0.0;
  dn_fxsj_plain->GPS_lat = 1;
  dn_fxsj_plain->GPS_lon = 2;
  dn_fxsj_plain->GPS_alt = 3;
  dn_fxsj_plain->GPS_Vn = 4;
  dn_fxsj_plain->GPS_Ve = 5;
  dn_fxsj_plain->GPS_num = 6;
  dn_fxsj_plain->GPS_time = 7;
  dn_fxsj_plain->GPS_sec = 8;
  dn_fxsj_plain->x = 9;
  dn_fxsj_plain->y = 10;
  dn_fxsj_plain->z = 11;
  dn_fxsj_plain->vx = 12;
  dn_fxsj_plain->vy = 13;
  dn_fxsj_plain->vz = 14;
  dn_fxsj_plain->ax = 15;
  dn_fxsj_plain->ay = 16;
  dn_fxsj_plain->az = 17;
  dn_fxsj_plain->pitch = 18;
  dn_fxsj_plain->roll = 19;
  dn_fxsj_plain->yaw = 20;
  dn_fxsj_plain->acc_vibe = 21;
  dn_fxsj_plain->gyro_vibe = 22;
} 

void mavlink_dn_fxsj_t_cipher(mavlink_dn_fxsj_t* dn_fxsj_plain , mavlink_dn_fxsj_t* dn_fxsj_cipher){
    aes_key_setup(key[0], key_schedule, 256);
    memcpy(&plaintext, dn_fxsj_plain, MAVLINK_MSG_ID_DN_FXSJ_LEN);
    aes_encrypt_ctr(plaintext[0], MAVLINK_MSG_ID_DN_FXSJ_LEN, enc_buf, key_schedule, 256, iv[0]);
		memcpy(dn_fxsj_cipher, &enc_buf, MAVLINK_MSG_ID_DN_FXSJ_LEN);
	//		printf("Got msg DN_FXSJ \n");
//            printf("    HEAD, MSG_ID, UAV_ID, LEN, Checksum:     %s  %d %d %d %d    \n", dn_fxsj_plain.head, dn_fxsj_plain.msg_id, dn_fxsj_plain.uav_id, dn_fxsj_plain.length, dn_fxsj_plain.checksum );
//            printf("    GPS_lat,  GPS_lon, GPS_alt:    %d %d %d                      \n", dn_fxsj_plain.GPS_lat, dn_fxsj_plain.GPS_lon, dn_fxsj_plain.GPS_alt );
//            printf("    GPS_Vn, GPS_Ve :    %d %d                                   \n", dn_fxsj_plain.GPS_Vn, dn_fxsj_plain.GPS_Ve );
//            printf("    GPS_num, GPS_time, GPS_sec :    %d %d %d                    \n", dn_fxsj_plain.GPS_num, dn_fxsj_plain.GPS_time, dn_fxsj_plain.GPS_sec );
//            printf("    pos  (NED):     %d %d %d (cm)                               \n", dn_fxsj_plain.x, dn_fxsj_plain.y, dn_fxsj_plain.z );
//            printf("    vel  (NED):     %d %d %d (cm/s)                             \n", dn_fxsj_plain.vx, dn_fxsj_plain.vy, dn_fxsj_plain.vz );
//            printf("    acc  (NED):     %d %d %d (cm/s^2)                           \n", dn_fxsj_plain.ax, dn_fxsj_plain.ay, dn_fxsj_plain.az );
//            printf("    angle     :     %d %d %d (degree)                           \n", dn_fxsj_plain.pitch, dn_fxsj_plain.roll, dn_fxsj_plain.yaw );
//            printf("    acc_vibe, gyro_vibe :    %d %d                              \n", dn_fxsj_plain.acc_vibe, dn_fxsj_plain.gyro_vibe );
//            printf("\n");
	//消息明文加密

//		printf("Got msg DN_FXSJ \n");
//            printf("    HEAD, MSG_ID, UAV_ID, LEN, Checksum:     %s  %d %d %d %d    \n", dn_fxsj_cipher.head, dn_fxsj_cipher.msg_id, dn_fxsj_cipher.uav_id, dn_fxsj_cipher.length, dn_fxsj_cipher.checksum );
//            printf("    GPS_lat, GPS_lon, GPS_alt:    %d %d %d                      \n", dn_fxsj_cipher.GPS_lat, dn_fxsj_cipher.GPS_lon, dn_fxsj_cipher.GPS_alt );
//            printf("    GPS_Vn, GPS_Ve :    %d %d                                   \n", dn_fxsj_cipher.GPS_Vn, dn_fxsj_cipher.GPS_Ve );
//            printf("    GPS_num, GPS_time, GPS_sec :    %d %d %d                    \n", dn_fxsj_cipher.GPS_num, dn_fxsj_cipher.GPS_time, dn_fxsj_cipher.GPS_sec );
//            printf("    pos  (NED):     %d %d %d (cm)                               \n", dn_fxsj_cipher.x, dn_fxsj_cipher.y, dn_fxsj_cipher.z );
//            printf("    vel  (NED):     %d %d %d (cm/s)                             \n", dn_fxsj_cipher.vx, dn_fxsj_cipher.vy, dn_fxsj_cipher.vz );
//            printf("    acc  (NED):     %d %d %d (cm/s^2)                           \n", dn_fxsj_cipher.ax, dn_fxsj_cipher.ay, dn_fxsj_cipher.az );
//            printf("    angle     :     %d %d %d (degree)                           \n", dn_fxsj_cipher.pitch, dn_fxsj_cipher.roll, dn_fxsj_cipher.yaw );
//            printf("    acc_vibe, gyro_vibe :    %d %d                              \n", dn_fxsj_cipher.acc_vibe, dn_fxsj_cipher.gyro_vibe );
//            printf("\n");
}

#endif /*__OPENTEL_MAVLINK_H*/   
