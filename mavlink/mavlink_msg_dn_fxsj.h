#pragma once
// MESSAGE DN_FXSJ PACKING

#define MAVLINK_MSG_ID_DN_FXSJ 1


typedef struct __mavlink_dn_fxsj_t {
 int32_t GPS_lat; /*<  int32_t*/
 int32_t GPS_lon; /*<  int32_t*/
 int32_t GPS_alt; /*<  int32_t*/
 uint32_t GPS_time; /*<  uint32_t*/
 uint16_t length; /*<  uint16_t*/
 int16_t GPS_Vn; /*<  int16_t*/
 int16_t GPS_Ve; /*<  int16_t*/
 uint16_t GPS_sec; /*<  uint16_t*/
 int16_t x; /*<  int16_t*/
 int16_t y; /*<  int16_t*/
 int16_t z; /*<  int16_t*/
 int16_t vx; /*<  int16_t*/
 int16_t vy; /*<  int16_t*/
 int16_t vz; /*<  int16_t*/
 int16_t ax; /*<  int16_t*/
 int16_t ay; /*<  int16_t*/
 int16_t az; /*<  int16_t*/
 int16_t pitch; /*<  int16_t*/
 int16_t roll; /*<  int16_t*/
 int16_t yaw; /*<  int16_t*/
 char head[3]; /*<  string*/
 uint8_t msg_id; /*<  uint8_t*/
 uint8_t uav_id; /*<  uint8_t*/
 uint8_t checksum; /*<  uint8_t*/
 uint8_t GPS_num; /*<  uint8_t*/
 uint8_t acc_vibe; /*<  uint8_t*/
 uint8_t gyro_vibe; /*<  uint8_t*/
} mavlink_dn_fxsj_t;

#define MAVLINK_MSG_ID_DN_FXSJ_LEN 57
#define MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN 57
#define MAVLINK_MSG_ID_1_LEN 57
#define MAVLINK_MSG_ID_1_MIN_LEN 57

#define MAVLINK_MSG_ID_DN_FXSJ_CRC 68
#define MAVLINK_MSG_ID_1_CRC 68

#define MAVLINK_MSG_DN_FXSJ_FIELD_HEAD_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DN_FXSJ { \
    1, \
    "DN_FXSJ", \
    27, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 48, offsetof(mavlink_dn_fxsj_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_dn_fxsj_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_dn_fxsj_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_dn_fxsj_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_dn_fxsj_t, checksum) }, \
         { "GPS_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_dn_fxsj_t, GPS_lat) }, \
         { "GPS_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_dn_fxsj_t, GPS_lon) }, \
         { "GPS_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_dn_fxsj_t, GPS_alt) }, \
         { "GPS_Vn", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_dn_fxsj_t, GPS_Vn) }, \
         { "GPS_Ve", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_dn_fxsj_t, GPS_Ve) }, \
         { "GPS_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_dn_fxsj_t, GPS_num) }, \
         { "GPS_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_dn_fxsj_t, GPS_time) }, \
         { "GPS_sec", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_dn_fxsj_t, GPS_sec) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_dn_fxsj_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_dn_fxsj_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_dn_fxsj_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_dn_fxsj_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_dn_fxsj_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_dn_fxsj_t, vz) }, \
         { "ax", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_dn_fxsj_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_dn_fxsj_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_dn_fxsj_t, az) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_dn_fxsj_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_dn_fxsj_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_dn_fxsj_t, yaw) }, \
         { "acc_vibe", NULL, MAVLINK_TYPE_UINT8_T, 0, 55, offsetof(mavlink_dn_fxsj_t, acc_vibe) }, \
         { "gyro_vibe", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_dn_fxsj_t, gyro_vibe) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DN_FXSJ { \
    "DN_FXSJ", \
    27, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 48, offsetof(mavlink_dn_fxsj_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 51, offsetof(mavlink_dn_fxsj_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 52, offsetof(mavlink_dn_fxsj_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_dn_fxsj_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 53, offsetof(mavlink_dn_fxsj_t, checksum) }, \
         { "GPS_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_dn_fxsj_t, GPS_lat) }, \
         { "GPS_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_dn_fxsj_t, GPS_lon) }, \
         { "GPS_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_dn_fxsj_t, GPS_alt) }, \
         { "GPS_Vn", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_dn_fxsj_t, GPS_Vn) }, \
         { "GPS_Ve", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_dn_fxsj_t, GPS_Ve) }, \
         { "GPS_num", NULL, MAVLINK_TYPE_UINT8_T, 0, 54, offsetof(mavlink_dn_fxsj_t, GPS_num) }, \
         { "GPS_time", NULL, MAVLINK_TYPE_UINT32_T, 0, 12, offsetof(mavlink_dn_fxsj_t, GPS_time) }, \
         { "GPS_sec", NULL, MAVLINK_TYPE_UINT16_T, 0, 22, offsetof(mavlink_dn_fxsj_t, GPS_sec) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_dn_fxsj_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_dn_fxsj_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_dn_fxsj_t, z) }, \
         { "vx", NULL, MAVLINK_TYPE_INT16_T, 0, 30, offsetof(mavlink_dn_fxsj_t, vx) }, \
         { "vy", NULL, MAVLINK_TYPE_INT16_T, 0, 32, offsetof(mavlink_dn_fxsj_t, vy) }, \
         { "vz", NULL, MAVLINK_TYPE_INT16_T, 0, 34, offsetof(mavlink_dn_fxsj_t, vz) }, \
         { "ax", NULL, MAVLINK_TYPE_INT16_T, 0, 36, offsetof(mavlink_dn_fxsj_t, ax) }, \
         { "ay", NULL, MAVLINK_TYPE_INT16_T, 0, 38, offsetof(mavlink_dn_fxsj_t, ay) }, \
         { "az", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_dn_fxsj_t, az) }, \
         { "pitch", NULL, MAVLINK_TYPE_INT16_T, 0, 42, offsetof(mavlink_dn_fxsj_t, pitch) }, \
         { "roll", NULL, MAVLINK_TYPE_INT16_T, 0, 44, offsetof(mavlink_dn_fxsj_t, roll) }, \
         { "yaw", NULL, MAVLINK_TYPE_INT16_T, 0, 46, offsetof(mavlink_dn_fxsj_t, yaw) }, \
         { "acc_vibe", NULL, MAVLINK_TYPE_UINT8_T, 0, 55, offsetof(mavlink_dn_fxsj_t, acc_vibe) }, \
         { "gyro_vibe", NULL, MAVLINK_TYPE_UINT8_T, 0, 56, offsetof(mavlink_dn_fxsj_t, gyro_vibe) }, \
         } \
}
#endif

/**
 * @brief Pack a dn_fxsj message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param GPS_lat  int32_t
 * @param GPS_lon  int32_t
 * @param GPS_alt  int32_t
 * @param GPS_Vn  int16_t
 * @param GPS_Ve  int16_t
 * @param GPS_num  uint8_t
 * @param GPS_time  uint32_t
 * @param GPS_sec  uint16_t
 * @param x  int16_t
 * @param y  int16_t
 * @param z  int16_t
 * @param vx  int16_t
 * @param vy  int16_t
 * @param vz  int16_t
 * @param ax  int16_t
 * @param ay  int16_t
 * @param az  int16_t
 * @param pitch  int16_t
 * @param roll  int16_t
 * @param yaw  int16_t
 * @param acc_vibe  uint8_t
 * @param gyro_vibe  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dn_fxsj_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t GPS_lat, int32_t GPS_lon, int32_t GPS_alt, int16_t GPS_Vn, int16_t GPS_Ve, uint8_t GPS_num, uint32_t GPS_time, uint16_t GPS_sec, int16_t x, int16_t y, int16_t z, int16_t vx, int16_t vy, int16_t vz, int16_t ax, int16_t ay, int16_t az, int16_t pitch, int16_t roll, int16_t yaw, uint8_t acc_vibe, uint8_t gyro_vibe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_FXSJ_LEN];
    _mav_put_int32_t(buf, 0, GPS_lat);
    _mav_put_int32_t(buf, 4, GPS_lon);
    _mav_put_int32_t(buf, 8, GPS_alt);
    _mav_put_uint32_t(buf, 12, GPS_time);
    _mav_put_uint16_t(buf, 16, length);
    _mav_put_int16_t(buf, 18, GPS_Vn);
    _mav_put_int16_t(buf, 20, GPS_Ve);
    _mav_put_uint16_t(buf, 22, GPS_sec);
    _mav_put_int16_t(buf, 24, x);
    _mav_put_int16_t(buf, 26, y);
    _mav_put_int16_t(buf, 28, z);
    _mav_put_int16_t(buf, 30, vx);
    _mav_put_int16_t(buf, 32, vy);
    _mav_put_int16_t(buf, 34, vz);
    _mav_put_int16_t(buf, 36, ax);
    _mav_put_int16_t(buf, 38, ay);
    _mav_put_int16_t(buf, 40, az);
    _mav_put_int16_t(buf, 42, pitch);
    _mav_put_int16_t(buf, 44, roll);
    _mav_put_int16_t(buf, 46, yaw);
    _mav_put_uint8_t(buf, 51, msg_id);
    _mav_put_uint8_t(buf, 52, uav_id);
    _mav_put_uint8_t(buf, 53, checksum);
    _mav_put_uint8_t(buf, 54, GPS_num);
    _mav_put_uint8_t(buf, 55, acc_vibe);
    _mav_put_uint8_t(buf, 56, gyro_vibe);
    _mav_put_char_array(buf, 48, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DN_FXSJ_LEN);
#else
    mavlink_dn_fxsj_t packet;
    packet.GPS_lat = GPS_lat;
    packet.GPS_lon = GPS_lon;
    packet.GPS_alt = GPS_alt;
    packet.GPS_time = GPS_time;
    packet.length = length;
    packet.GPS_Vn = GPS_Vn;
    packet.GPS_Ve = GPS_Ve;
    packet.GPS_sec = GPS_sec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
		//printf(" +%x+ ",packet.checksum);
    packet.GPS_num = GPS_num;
    packet.acc_vibe = acc_vibe;
    packet.gyro_vibe = gyro_vibe;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DN_FXSJ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DN_FXSJ;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
}

/**
 * @brief Pack a dn_fxsj message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param GPS_lat  int32_t
 * @param GPS_lon  int32_t
 * @param GPS_alt  int32_t
 * @param GPS_Vn  int16_t
 * @param GPS_Ve  int16_t
 * @param GPS_num  uint8_t
 * @param GPS_time  uint32_t
 * @param GPS_sec  uint16_t
 * @param x  int16_t
 * @param y  int16_t
 * @param z  int16_t
 * @param vx  int16_t
 * @param vy  int16_t
 * @param vz  int16_t
 * @param ax  int16_t
 * @param ay  int16_t
 * @param az  int16_t
 * @param pitch  int16_t
 * @param roll  int16_t
 * @param yaw  int16_t
 * @param acc_vibe  uint8_t
 * @param gyro_vibe  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dn_fxsj_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *head,uint8_t msg_id,uint8_t uav_id,uint16_t length,uint8_t checksum,int32_t GPS_lat,int32_t GPS_lon,int32_t GPS_alt,int16_t GPS_Vn,int16_t GPS_Ve,uint8_t GPS_num,uint32_t GPS_time,uint16_t GPS_sec,int16_t x,int16_t y,int16_t z,int16_t vx,int16_t vy,int16_t vz,int16_t ax,int16_t ay,int16_t az,int16_t pitch,int16_t roll,int16_t yaw,uint8_t acc_vibe,uint8_t gyro_vibe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_FXSJ_LEN];
    _mav_put_int32_t(buf, 0, GPS_lat);
    _mav_put_int32_t(buf, 4, GPS_lon);
    _mav_put_int32_t(buf, 8, GPS_alt);
    _mav_put_uint32_t(buf, 12, GPS_time);
    _mav_put_uint16_t(buf, 16, length);
    _mav_put_int16_t(buf, 18, GPS_Vn);
    _mav_put_int16_t(buf, 20, GPS_Ve);
    _mav_put_uint16_t(buf, 22, GPS_sec);
    _mav_put_int16_t(buf, 24, x);
    _mav_put_int16_t(buf, 26, y);
    _mav_put_int16_t(buf, 28, z);
    _mav_put_int16_t(buf, 30, vx);
    _mav_put_int16_t(buf, 32, vy);
    _mav_put_int16_t(buf, 34, vz);
    _mav_put_int16_t(buf, 36, ax);
    _mav_put_int16_t(buf, 38, ay);
    _mav_put_int16_t(buf, 40, az);
    _mav_put_int16_t(buf, 42, pitch);
    _mav_put_int16_t(buf, 44, roll);
    _mav_put_int16_t(buf, 46, yaw);
    _mav_put_uint8_t(buf, 51, msg_id);
    _mav_put_uint8_t(buf, 52, uav_id);
    _mav_put_uint8_t(buf, 53, checksum);
    _mav_put_uint8_t(buf, 54, GPS_num);
    _mav_put_uint8_t(buf, 55, acc_vibe);
    _mav_put_uint8_t(buf, 56, gyro_vibe);
    _mav_put_char_array(buf, 48, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DN_FXSJ_LEN);
#else
    mavlink_dn_fxsj_t packet;
    packet.GPS_lat = GPS_lat;
    packet.GPS_lon = GPS_lon;
    packet.GPS_alt = GPS_alt;
    packet.GPS_time = GPS_time;
    packet.length = length;
    packet.GPS_Vn = GPS_Vn;
    packet.GPS_Ve = GPS_Ve;
    packet.GPS_sec = GPS_sec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    packet.GPS_num = GPS_num;
    packet.acc_vibe = acc_vibe;
    packet.gyro_vibe = gyro_vibe;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DN_FXSJ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DN_FXSJ;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
}

/**
 * @brief Encode a dn_fxsj struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dn_fxsj C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dn_fxsj_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dn_fxsj_t* dn_fxsj)
{
    return mavlink_msg_dn_fxsj_pack(system_id, component_id, msg, dn_fxsj->head, dn_fxsj->msg_id, dn_fxsj->uav_id, dn_fxsj->length, dn_fxsj->checksum, dn_fxsj->GPS_lat, dn_fxsj->GPS_lon, dn_fxsj->GPS_alt, dn_fxsj->GPS_Vn, dn_fxsj->GPS_Ve, dn_fxsj->GPS_num, dn_fxsj->GPS_time, dn_fxsj->GPS_sec, dn_fxsj->x, dn_fxsj->y, dn_fxsj->z, dn_fxsj->vx, dn_fxsj->vy, dn_fxsj->vz, dn_fxsj->ax, dn_fxsj->ay, dn_fxsj->az, dn_fxsj->pitch, dn_fxsj->roll, dn_fxsj->yaw, dn_fxsj->acc_vibe, dn_fxsj->gyro_vibe);
}

/**
 * @brief Encode a dn_fxsj struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dn_fxsj C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dn_fxsj_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dn_fxsj_t* dn_fxsj)
{
    return mavlink_msg_dn_fxsj_pack_chan(system_id, component_id, chan, msg, dn_fxsj->head, dn_fxsj->msg_id, dn_fxsj->uav_id, dn_fxsj->length, dn_fxsj->checksum, dn_fxsj->GPS_lat, dn_fxsj->GPS_lon, dn_fxsj->GPS_alt, dn_fxsj->GPS_Vn, dn_fxsj->GPS_Ve, dn_fxsj->GPS_num, dn_fxsj->GPS_time, dn_fxsj->GPS_sec, dn_fxsj->x, dn_fxsj->y, dn_fxsj->z, dn_fxsj->vx, dn_fxsj->vy, dn_fxsj->vz, dn_fxsj->ax, dn_fxsj->ay, dn_fxsj->az, dn_fxsj->pitch, dn_fxsj->roll, dn_fxsj->yaw, dn_fxsj->acc_vibe, dn_fxsj->gyro_vibe);
}

/**
 * @brief Send a dn_fxsj message
 * @param chan MAVLink channel to send the message
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param GPS_lat  int32_t
 * @param GPS_lon  int32_t
 * @param GPS_alt  int32_t
 * @param GPS_Vn  int16_t
 * @param GPS_Ve  int16_t
 * @param GPS_num  uint8_t
 * @param GPS_time  uint32_t
 * @param GPS_sec  uint16_t
 * @param x  int16_t
 * @param y  int16_t
 * @param z  int16_t
 * @param vx  int16_t
 * @param vy  int16_t
 * @param vz  int16_t
 * @param ax  int16_t
 * @param ay  int16_t
 * @param az  int16_t
 * @param pitch  int16_t
 * @param roll  int16_t
 * @param yaw  int16_t
 * @param acc_vibe  uint8_t
 * @param gyro_vibe  uint8_t
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dn_fxsj_send(mavlink_channel_t chan, const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t GPS_lat, int32_t GPS_lon, int32_t GPS_alt, int16_t GPS_Vn, int16_t GPS_Ve, uint8_t GPS_num, uint32_t GPS_time, uint16_t GPS_sec, int16_t x, int16_t y, int16_t z, int16_t vx, int16_t vy, int16_t vz, int16_t ax, int16_t ay, int16_t az, int16_t pitch, int16_t roll, int16_t yaw, uint8_t acc_vibe, uint8_t gyro_vibe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_FXSJ_LEN];
    _mav_put_int32_t(buf, 0, GPS_lat);
    _mav_put_int32_t(buf, 4, GPS_lon);
    _mav_put_int32_t(buf, 8, GPS_alt);
    _mav_put_uint32_t(buf, 12, GPS_time);
    _mav_put_uint16_t(buf, 16, length);
    _mav_put_int16_t(buf, 18, GPS_Vn);
    _mav_put_int16_t(buf, 20, GPS_Ve);
    _mav_put_uint16_t(buf, 22, GPS_sec);
    _mav_put_int16_t(buf, 24, x);
    _mav_put_int16_t(buf, 26, y);
    _mav_put_int16_t(buf, 28, z);
    _mav_put_int16_t(buf, 30, vx);
    _mav_put_int16_t(buf, 32, vy);
    _mav_put_int16_t(buf, 34, vz);
    _mav_put_int16_t(buf, 36, ax);
    _mav_put_int16_t(buf, 38, ay);
    _mav_put_int16_t(buf, 40, az);
    _mav_put_int16_t(buf, 42, pitch);
    _mav_put_int16_t(buf, 44, roll);
    _mav_put_int16_t(buf, 46, yaw);
    _mav_put_uint8_t(buf, 51, msg_id);
    _mav_put_uint8_t(buf, 52, uav_id);
    _mav_put_uint8_t(buf, 53, checksum);
    _mav_put_uint8_t(buf, 54, GPS_num);
    _mav_put_uint8_t(buf, 55, acc_vibe);
    _mav_put_uint8_t(buf, 56, gyro_vibe);
    _mav_put_char_array(buf, 48, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_FXSJ, buf, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
#else
    mavlink_dn_fxsj_t packet;
    packet.GPS_lat = GPS_lat;
    packet.GPS_lon = GPS_lon;
    packet.GPS_alt = GPS_alt;
    packet.GPS_time = GPS_time;
    packet.length = length;
    packet.GPS_Vn = GPS_Vn;
    packet.GPS_Ve = GPS_Ve;
    packet.GPS_sec = GPS_sec;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.vx = vx;
    packet.vy = vy;
    packet.vz = vz;
    packet.ax = ax;
    packet.ay = ay;
    packet.az = az;
    packet.pitch = pitch;
    packet.roll = roll;
    packet.yaw = yaw;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    packet.GPS_num = GPS_num;
    packet.acc_vibe = acc_vibe;
    packet.gyro_vibe = gyro_vibe;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_FXSJ, (const char *)&packet, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
#endif
}

/**
 * @brief Send a dn_fxsj message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dn_fxsj_send_struct(mavlink_channel_t chan, const mavlink_dn_fxsj_t* dn_fxsj)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dn_fxsj_send(chan, dn_fxsj->head, dn_fxsj->msg_id, dn_fxsj->uav_id, dn_fxsj->length, dn_fxsj->checksum, dn_fxsj->GPS_lat, dn_fxsj->GPS_lon, dn_fxsj->GPS_alt, dn_fxsj->GPS_Vn, dn_fxsj->GPS_Ve, dn_fxsj->GPS_num, dn_fxsj->GPS_time, dn_fxsj->GPS_sec, dn_fxsj->x, dn_fxsj->y, dn_fxsj->z, dn_fxsj->vx, dn_fxsj->vy, dn_fxsj->vz, dn_fxsj->ax, dn_fxsj->ay, dn_fxsj->az, dn_fxsj->pitch, dn_fxsj->roll, dn_fxsj->yaw, dn_fxsj->acc_vibe, dn_fxsj->gyro_vibe);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_FXSJ, (const char *)dn_fxsj, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
#endif
}

#if MAVLINK_MSG_ID_DN_FXSJ_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dn_fxsj_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t GPS_lat, int32_t GPS_lon, int32_t GPS_alt, int16_t GPS_Vn, int16_t GPS_Ve, uint8_t GPS_num, uint32_t GPS_time, uint16_t GPS_sec, int16_t x, int16_t y, int16_t z, int16_t vx, int16_t vy, int16_t vz, int16_t ax, int16_t ay, int16_t az, int16_t pitch, int16_t roll, int16_t yaw, uint8_t acc_vibe, uint8_t gyro_vibe)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, GPS_lat);
    _mav_put_int32_t(buf, 4, GPS_lon);
    _mav_put_int32_t(buf, 8, GPS_alt);
    _mav_put_uint32_t(buf, 12, GPS_time);
    _mav_put_uint16_t(buf, 16, length);
    _mav_put_int16_t(buf, 18, GPS_Vn);
    _mav_put_int16_t(buf, 20, GPS_Ve);
    _mav_put_uint16_t(buf, 22, GPS_sec);
    _mav_put_int16_t(buf, 24, x);
    _mav_put_int16_t(buf, 26, y);
    _mav_put_int16_t(buf, 28, z);
    _mav_put_int16_t(buf, 30, vx);
    _mav_put_int16_t(buf, 32, vy);
    _mav_put_int16_t(buf, 34, vz);
    _mav_put_int16_t(buf, 36, ax);
    _mav_put_int16_t(buf, 38, ay);
    _mav_put_int16_t(buf, 40, az);
    _mav_put_int16_t(buf, 42, pitch);
    _mav_put_int16_t(buf, 44, roll);
    _mav_put_int16_t(buf, 46, yaw);
    _mav_put_uint8_t(buf, 51, msg_id);
    _mav_put_uint8_t(buf, 52, uav_id);
    _mav_put_uint8_t(buf, 53, checksum);
    _mav_put_uint8_t(buf, 54, GPS_num);
    _mav_put_uint8_t(buf, 55, acc_vibe);
    _mav_put_uint8_t(buf, 56, gyro_vibe);
    _mav_put_char_array(buf, 48, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_FXSJ, buf, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
#else
    mavlink_dn_fxsj_t *packet = (mavlink_dn_fxsj_t *)msgbuf;
    packet->GPS_lat = GPS_lat;
    packet->GPS_lon = GPS_lon;
    packet->GPS_alt = GPS_alt;
    packet->GPS_time = GPS_time;
    packet->length = length;
    packet->GPS_Vn = GPS_Vn;
    packet->GPS_Ve = GPS_Ve;
    packet->GPS_sec = GPS_sec;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->vx = vx;
    packet->vy = vy;
    packet->vz = vz;
    packet->ax = ax;
    packet->ay = ay;
    packet->az = az;
    packet->pitch = pitch;
    packet->roll = roll;
    packet->yaw = yaw;
    packet->msg_id = msg_id;
    packet->uav_id = uav_id;
    packet->checksum = checksum;
    packet->GPS_num = GPS_num;
    packet->acc_vibe = acc_vibe;
    packet->gyro_vibe = gyro_vibe;
    mav_array_memcpy(packet->head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_FXSJ, (const char *)packet, MAVLINK_MSG_ID_DN_FXSJ_MIN_LEN, MAVLINK_MSG_ID_DN_FXSJ_LEN, MAVLINK_MSG_ID_DN_FXSJ_CRC);
#endif
}
#endif

#endif

// MESSAGE DN_FXSJ UNPACKING


/**
 * @brief Get field head from dn_fxsj message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_dn_fxsj_get_head(const mavlink_message_t* msg, char *head)
{
    return _MAV_RETURN_char_array(msg, head, 3,  48);
}

/**
 * @brief Get field msg_id from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_msg_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  51);
}

/**
 * @brief Get field uav_id from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_uav_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  52);
}

/**
 * @brief Get field length from dn_fxsj message
 *
 * @return  uint16_t
 */
static inline uint16_t mavlink_msg_dn_fxsj_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field checksum from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_checksum(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  53);
}

/**
 * @brief Get field GPS_lat from dn_fxsj message
 *
 * @return  int32_t
 */
static inline int32_t mavlink_msg_dn_fxsj_get_GPS_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field GPS_lon from dn_fxsj message
 *
 * @return  int32_t
 */
static inline int32_t mavlink_msg_dn_fxsj_get_GPS_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field GPS_alt from dn_fxsj message
 *
 * @return  int32_t
 */
static inline int32_t mavlink_msg_dn_fxsj_get_GPS_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field GPS_Vn from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_GPS_Vn(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field GPS_Ve from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_GPS_Ve(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field GPS_num from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_GPS_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  54);
}

/**
 * @brief Get field GPS_time from dn_fxsj message
 *
 * @return  uint32_t
 */
static inline uint32_t mavlink_msg_dn_fxsj_get_GPS_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field GPS_sec from dn_fxsj message
 *
 * @return  uint16_t
 */
static inline uint16_t mavlink_msg_dn_fxsj_get_GPS_sec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field x from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field y from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field z from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field vx from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_vx(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field vy from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_vy(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field vz from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_vz(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field ax from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_ax(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field ay from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_ay(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field az from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_az(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field pitch from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  42);
}

/**
 * @brief Get field roll from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  44);
}

/**
 * @brief Get field yaw from dn_fxsj message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_dn_fxsj_get_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  46);
}

/**
 * @brief Get field acc_vibe from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_acc_vibe(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  55);
}

/**
 * @brief Get field gyro_vibe from dn_fxsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_fxsj_get_gyro_vibe(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Decode a dn_fxsj message into a struct
 *
 * @param msg The message to decode
 * @param dn_fxsj C-struct to decode the message contents into
 */
static inline void mavlink_msg_dn_fxsj_decode(const mavlink_message_t* msg, mavlink_dn_fxsj_t* dn_fxsj)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dn_fxsj->GPS_lat = mavlink_msg_dn_fxsj_get_GPS_lat(msg);
    dn_fxsj->GPS_lon = mavlink_msg_dn_fxsj_get_GPS_lon(msg);
    dn_fxsj->GPS_alt = mavlink_msg_dn_fxsj_get_GPS_alt(msg);
    dn_fxsj->GPS_time = mavlink_msg_dn_fxsj_get_GPS_time(msg);
    dn_fxsj->length = mavlink_msg_dn_fxsj_get_length(msg);
    dn_fxsj->GPS_Vn = mavlink_msg_dn_fxsj_get_GPS_Vn(msg);
    dn_fxsj->GPS_Ve = mavlink_msg_dn_fxsj_get_GPS_Ve(msg);
    dn_fxsj->GPS_sec = mavlink_msg_dn_fxsj_get_GPS_sec(msg);
    dn_fxsj->x = mavlink_msg_dn_fxsj_get_x(msg);
    dn_fxsj->y = mavlink_msg_dn_fxsj_get_y(msg);
    dn_fxsj->z = mavlink_msg_dn_fxsj_get_z(msg);
    dn_fxsj->vx = mavlink_msg_dn_fxsj_get_vx(msg);
    dn_fxsj->vy = mavlink_msg_dn_fxsj_get_vy(msg);
    dn_fxsj->vz = mavlink_msg_dn_fxsj_get_vz(msg);
    dn_fxsj->ax = mavlink_msg_dn_fxsj_get_ax(msg);
    dn_fxsj->ay = mavlink_msg_dn_fxsj_get_ay(msg);
    dn_fxsj->az = mavlink_msg_dn_fxsj_get_az(msg);
    dn_fxsj->pitch = mavlink_msg_dn_fxsj_get_pitch(msg);
    dn_fxsj->roll = mavlink_msg_dn_fxsj_get_roll(msg);
    dn_fxsj->yaw = mavlink_msg_dn_fxsj_get_yaw(msg);
    mavlink_msg_dn_fxsj_get_head(msg, dn_fxsj->head);
    dn_fxsj->msg_id = mavlink_msg_dn_fxsj_get_msg_id(msg);
    dn_fxsj->uav_id = mavlink_msg_dn_fxsj_get_uav_id(msg);
    dn_fxsj->checksum = mavlink_msg_dn_fxsj_get_checksum(msg);
    dn_fxsj->GPS_num = mavlink_msg_dn_fxsj_get_GPS_num(msg);
    dn_fxsj->acc_vibe = mavlink_msg_dn_fxsj_get_acc_vibe(msg);
    dn_fxsj->gyro_vibe = mavlink_msg_dn_fxsj_get_gyro_vibe(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DN_FXSJ_LEN? msg->len : MAVLINK_MSG_ID_DN_FXSJ_LEN;
        memset(dn_fxsj, 0, MAVLINK_MSG_ID_DN_FXSJ_LEN);
    memcpy(dn_fxsj, _MAV_PAYLOAD(msg), len);
#endif
}
