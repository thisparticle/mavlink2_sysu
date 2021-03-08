/** @file
 *    @brief MAVLink comm protocol testsuite generated from sysu.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef SYSU_TESTSUITE_H
#define SYSU_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_sysu(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_sysu(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_test_types(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TEST_TYPES >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_test_types_t packet_in = {
        93372036854775807ULL,93372036854776311LL,235.0,{ 93372036854777319, 93372036854777320, 93372036854777321 },{ 93372036854778831, 93372036854778832, 93372036854778833 },{ 627.0, 628.0, 629.0 },963502456,963502664,745.0,{ 963503080, 963503081, 963503082 },{ 963503704, 963503705, 963503706 },{ 941.0, 942.0, 943.0 },24723,24827,{ 24931, 24932, 24933 },{ 25243, 25244, 25245 },'E',"FGHIJKLMN",198,9,{ 76, 77, 78 },{ 21, 22, 23 }
    };
    mavlink_test_types_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.u64 = packet_in.u64;
        packet1.s64 = packet_in.s64;
        packet1.d = packet_in.d;
        packet1.u32 = packet_in.u32;
        packet1.s32 = packet_in.s32;
        packet1.f = packet_in.f;
        packet1.u16 = packet_in.u16;
        packet1.s16 = packet_in.s16;
        packet1.c = packet_in.c;
        packet1.u8 = packet_in.u8;
        packet1.s8 = packet_in.s8;
        
        mav_array_memcpy(packet1.u64_array, packet_in.u64_array, sizeof(uint64_t)*3);
        mav_array_memcpy(packet1.s64_array, packet_in.s64_array, sizeof(int64_t)*3);
        mav_array_memcpy(packet1.d_array, packet_in.d_array, sizeof(double)*3);
        mav_array_memcpy(packet1.u32_array, packet_in.u32_array, sizeof(uint32_t)*3);
        mav_array_memcpy(packet1.s32_array, packet_in.s32_array, sizeof(int32_t)*3);
        mav_array_memcpy(packet1.f_array, packet_in.f_array, sizeof(float)*3);
        mav_array_memcpy(packet1.u16_array, packet_in.u16_array, sizeof(uint16_t)*3);
        mav_array_memcpy(packet1.s16_array, packet_in.s16_array, sizeof(int16_t)*3);
        mav_array_memcpy(packet1.s, packet_in.s, sizeof(char)*10);
        mav_array_memcpy(packet1.u8_array, packet_in.u8_array, sizeof(uint8_t)*3);
        mav_array_memcpy(packet1.s8_array, packet_in.s8_array, sizeof(int8_t)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TEST_TYPES_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TEST_TYPES_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_test_types_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_test_types_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_test_types_pack(system_id, component_id, &msg , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
    mavlink_msg_test_types_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_test_types_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
    mavlink_msg_test_types_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_test_types_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_test_types_send(MAVLINK_COMM_1 , packet1.c , packet1.s , packet1.u8 , packet1.u16 , packet1.u32 , packet1.u64 , packet1.s8 , packet1.s16 , packet1.s32 , packet1.s64 , packet1.f , packet1.d , packet1.u8_array , packet1.u16_array , packet1.u32_array , packet1.u64_array , packet1.s8_array , packet1.s16_array , packet1.s32_array , packet1.s64_array , packet1.f_array , packet1.d_array );
    mavlink_msg_test_types_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dn_fxsj(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DN_FXSJ >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dn_fxsj_t packet_in = {
        963497464,963497672,963497880,963498088,18067,18171,18275,18379,18483,18587,18691,18795,18899,19003,19107,19211,19315,19419,19523,19627,"WX",94,161,228,39,106,173
    };
    mavlink_dn_fxsj_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.GPS_lat = packet_in.GPS_lat;
        packet1.GPS_lon = packet_in.GPS_lon;
        packet1.GPS_alt = packet_in.GPS_alt;
        packet1.GPS_time = packet_in.GPS_time;
        packet1.length = packet_in.length;
        packet1.GPS_Vn = packet_in.GPS_Vn;
        packet1.GPS_Ve = packet_in.GPS_Ve;
        packet1.GPS_sec = packet_in.GPS_sec;
        packet1.x = packet_in.x;
        packet1.y = packet_in.y;
        packet1.z = packet_in.z;
        packet1.vx = packet_in.vx;
        packet1.vy = packet_in.vy;
        packet1.vz = packet_in.vz;
        packet1.ax = packet_in.ax;
        packet1.ay = packet_in.ay;
        packet1.az = packet_in.az;
        packet1.pitch = packet_in.pitch;
        packet1.roll = packet_in.roll;
        packet1.yaw = packet_in.yaw;
        packet1.msg_id = packet_in.msg_id;
        packet1.uav_id = packet_in.uav_id;
        packet1.checksum = packet_in.checksum;
        packet1.GPS_num = packet_in.GPS_num;
        packet1.acc_vibe = packet_in.acc_vibe;
        packet1.gyro_vibe = packet_in.gyro_vibe;
        
        mav_array_memcpy(packet1.head, packet_in.head, sizeof(char)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_fxsj_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dn_fxsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_fxsj_pack(system_id, component_id, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.GPS_lat , packet1.GPS_lon , packet1.GPS_alt , packet1.GPS_Vn , packet1.GPS_Ve , packet1.GPS_num , packet1.GPS_time , packet1.GPS_sec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.ax , packet1.ay , packet1.az , packet1.pitch , packet1.roll , packet1.yaw , packet1.acc_vibe , packet1.gyro_vibe );
    mavlink_msg_dn_fxsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_fxsj_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.GPS_lat , packet1.GPS_lon , packet1.GPS_alt , packet1.GPS_Vn , packet1.GPS_Ve , packet1.GPS_num , packet1.GPS_time , packet1.GPS_sec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.ax , packet1.ay , packet1.az , packet1.pitch , packet1.roll , packet1.yaw , packet1.acc_vibe , packet1.gyro_vibe );
    mavlink_msg_dn_fxsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dn_fxsj_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_fxsj_send(MAVLINK_COMM_1 , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.GPS_lat , packet1.GPS_lon , packet1.GPS_alt , packet1.GPS_Vn , packet1.GPS_Ve , packet1.GPS_num , packet1.GPS_time , packet1.GPS_sec , packet1.x , packet1.y , packet1.z , packet1.vx , packet1.vy , packet1.vz , packet1.ax , packet1.ay , packet1.az , packet1.pitch , packet1.roll , packet1.yaw , packet1.acc_vibe , packet1.gyro_vibe );
    mavlink_msg_dn_fxsj_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_dn_ykqsj(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DN_YKQSJ >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_dn_ykqsj_t packet_in = {
        17235,"CD",84,151,218,29,96,163,230,41,108,175,242
    };
    mavlink_dn_ykqsj_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.length = packet_in.length;
        packet1.msg_id = packet_in.msg_id;
        packet1.uav_id = packet_in.uav_id;
        packet1.checksum = packet_in.checksum;
        packet1.man_pitch = packet_in.man_pitch;
        packet1.man_roll = packet_in.man_roll;
        packet1.man_yaw = packet_in.man_yaw;
        packet1.man_throttle = packet_in.man_throttle;
        packet1.real_pitch = packet_in.real_pitch;
        packet1.real_roll = packet_in.real_roll;
        packet1.real_yaw = packet_in.real_yaw;
        packet1.real_throttle = packet_in.real_throttle;
        
        mav_array_memcpy(packet1.head, packet_in.head, sizeof(char)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_ykqsj_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_dn_ykqsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_ykqsj_pack(system_id, component_id, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.man_pitch , packet1.man_roll , packet1.man_yaw , packet1.man_throttle , packet1.real_pitch , packet1.real_roll , packet1.real_yaw , packet1.real_throttle );
    mavlink_msg_dn_ykqsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_ykqsj_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.man_pitch , packet1.man_roll , packet1.man_yaw , packet1.man_throttle , packet1.real_pitch , packet1.real_roll , packet1.real_yaw , packet1.real_throttle );
    mavlink_msg_dn_ykqsj_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_dn_ykqsj_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_dn_ykqsj_send(MAVLINK_COMM_1 , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.man_pitch , packet1.man_roll , packet1.man_yaw , packet1.man_throttle , packet1.real_pitch , packet1.real_roll , packet1.real_yaw , packet1.real_throttle );
    mavlink_msg_dn_ykqsj_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_cm_zdfx(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_CM_ZDFX >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_cm_zdfx_t packet_in = {
        963497464,963497672,17651,17755,"MN",242,53,120
    };
    mavlink_cm_zdfx_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.WP_lat = packet_in.WP_lat;
        packet1.WP_lon = packet_in.WP_lon;
        packet1.length = packet_in.length;
        packet1.WP_alt = packet_in.WP_alt;
        packet1.msg_id = packet_in.msg_id;
        packet1.uav_id = packet_in.uav_id;
        packet1.checksum = packet_in.checksum;
        
        mav_array_memcpy(packet1.head, packet_in.head, sizeof(char)*3);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cm_zdfx_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_cm_zdfx_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cm_zdfx_pack(system_id, component_id, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.WP_lat , packet1.WP_lon , packet1.WP_alt );
    mavlink_msg_cm_zdfx_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cm_zdfx_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.WP_lat , packet1.WP_lon , packet1.WP_alt );
    mavlink_msg_cm_zdfx_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_cm_zdfx_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_cm_zdfx_send(MAVLINK_COMM_1 , packet1.head , packet1.msg_id , packet1.uav_id , packet1.length , packet1.checksum , packet1.WP_lat , packet1.WP_lon , packet1.WP_alt );
    mavlink_msg_cm_zdfx_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sysu(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_test_types(system_id, component_id, last_msg);
    mavlink_test_dn_fxsj(system_id, component_id, last_msg);
    mavlink_test_dn_ykqsj(system_id, component_id, last_msg);
    mavlink_test_cm_zdfx(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SYSU_TESTSUITE_H
