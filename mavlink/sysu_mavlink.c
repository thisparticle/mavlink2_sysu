//#include "sysu_mavlink.h"
//#include "mavlink_avoid_errors.h"
//static const uint8_t secret_key_ground[32] = {
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9,
//    0x42, 0x71, 0xb5, 0xe9
//};

//void update(void)
//{
//    // receive new packets
//    mavlink_message_t msg;
//    mavlink_status_t status;
//    status.packet_rx_drop_count = 0;
//    // process received bytes
//    while(serial_available())
//    {
//        uint8_t c = serial_read_ch(); 
//        // Try to get a new message
//        if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
//            //mavlink_active = true;
//            
//					  //printf("%c",c);
//					  //printf("Received message with ID %d, sequence: %d from component %d of system %d",\
//										msg.msgid, msg.seq, msg.compid, msg.sysid);
//					  handleMessage(&msg);
//        }
//    }
//}

//int handle_msg(mavlink_signing_t signing,mavlink_signing_streams_t signing_streams,const mavlink_message_t *msg)
//{
//		//mavlink_dn_fxsj_t dn_fxsj_plain  = { 0 };
//    //mavlink_msg_dn_fxsj_decode( msg, &dn_fxsj_plain);
//            
//		uint8_t t;
//		memset(&signing, 0, sizeof(signing));
//    memcpy(signing.secret_key, secret_key_ground, 32);

//    //??stream???
//    memset(&signing_streams, 0, sizeof(signing_streams));
//    signing_streams.num_signing_streams = 0;
//    uint64_t timestamp_test = get_time_msec();
//    signing.timestamp = timestamp_test; 
//		

//    bool check_signature = mavlink_signature_check(&signing, &signing_streams, msg);

//    if(check_signature)
//    {
//         t=1;
//    }else
//    {
//         t=0;
//    }     
//		return t;
//}