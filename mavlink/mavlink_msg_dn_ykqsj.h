#pragma once
// MESSAGE DN_YKQSJ PACKING

#define MAVLINK_MSG_ID_DN_YKQSJ 2


typedef struct __mavlink_dn_ykqsj_t {
 uint16_t length; /*<  uint16_t*/
 char head[3]; /*<  string*/
 uint8_t msg_id; /*<  uint8_t*/
 uint8_t uav_id; /*<  uint8_t*/
 uint8_t checksum; /*<  uint8_t*/
 uint8_t man_pitch; /*<  uint8_t*/
 uint8_t man_roll; /*<  uint8_t*/
 uint8_t man_yaw; /*<  uint8_t*/
 uint8_t man_throttle; /*<  uint8_t*/
 uint8_t real_pitch; /*<  uint8_t*/
 uint8_t real_roll; /*<  uint8_t*/
 uint8_t real_yaw; /*<  uint8_t*/
 uint8_t real_throttle; /*<  uint8_t*/
} mavlink_dn_ykqsj_t;

#define MAVLINK_MSG_ID_DN_YKQSJ_LEN 16
#define MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN 16
#define MAVLINK_MSG_ID_2_LEN 16
#define MAVLINK_MSG_ID_2_MIN_LEN 16

#define MAVLINK_MSG_ID_DN_YKQSJ_CRC 147
#define MAVLINK_MSG_ID_2_CRC 147

#define MAVLINK_MSG_DN_YKQSJ_FIELD_HEAD_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_DN_YKQSJ { \
    2, \
    "DN_YKQSJ", \
    13, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 2, offsetof(mavlink_dn_ykqsj_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_dn_ykqsj_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_dn_ykqsj_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_dn_ykqsj_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_dn_ykqsj_t, checksum) }, \
         { "man_pitch", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_dn_ykqsj_t, man_pitch) }, \
         { "man_roll", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_dn_ykqsj_t, man_roll) }, \
         { "man_yaw", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dn_ykqsj_t, man_yaw) }, \
         { "man_throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_dn_ykqsj_t, man_throttle) }, \
         { "real_pitch", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_dn_ykqsj_t, real_pitch) }, \
         { "real_roll", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_dn_ykqsj_t, real_roll) }, \
         { "real_yaw", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_dn_ykqsj_t, real_yaw) }, \
         { "real_throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_dn_ykqsj_t, real_throttle) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_DN_YKQSJ { \
    "DN_YKQSJ", \
    13, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 2, offsetof(mavlink_dn_ykqsj_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_dn_ykqsj_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_dn_ykqsj_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_dn_ykqsj_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 7, offsetof(mavlink_dn_ykqsj_t, checksum) }, \
         { "man_pitch", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_dn_ykqsj_t, man_pitch) }, \
         { "man_roll", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_dn_ykqsj_t, man_roll) }, \
         { "man_yaw", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_dn_ykqsj_t, man_yaw) }, \
         { "man_throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_dn_ykqsj_t, man_throttle) }, \
         { "real_pitch", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_dn_ykqsj_t, real_pitch) }, \
         { "real_roll", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_dn_ykqsj_t, real_roll) }, \
         { "real_yaw", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_dn_ykqsj_t, real_yaw) }, \
         { "real_throttle", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_dn_ykqsj_t, real_throttle) }, \
         } \
}
#endif

/**
 * @brief Pack a dn_ykqsj message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param man_pitch  uint8_t
 * @param man_roll  uint8_t
 * @param man_yaw  uint8_t
 * @param man_throttle  uint8_t
 * @param real_pitch  uint8_t
 * @param real_roll  uint8_t
 * @param real_yaw  uint8_t
 * @param real_throttle  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dn_ykqsj_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, uint8_t man_pitch, uint8_t man_roll, uint8_t man_yaw, uint8_t man_throttle, uint8_t real_pitch, uint8_t real_roll, uint8_t real_yaw, uint8_t real_throttle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_YKQSJ_LEN];
    _mav_put_uint16_t(buf, 0, length);
    _mav_put_uint8_t(buf, 5, msg_id);
    _mav_put_uint8_t(buf, 6, uav_id);
    _mav_put_uint8_t(buf, 7, checksum);
    _mav_put_uint8_t(buf, 8, man_pitch);
    _mav_put_uint8_t(buf, 9, man_roll);
    _mav_put_uint8_t(buf, 10, man_yaw);
    _mav_put_uint8_t(buf, 11, man_throttle);
    _mav_put_uint8_t(buf, 12, real_pitch);
    _mav_put_uint8_t(buf, 13, real_roll);
    _mav_put_uint8_t(buf, 14, real_yaw);
    _mav_put_uint8_t(buf, 15, real_throttle);
    _mav_put_char_array(buf, 2, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DN_YKQSJ_LEN);
#else
    mavlink_dn_ykqsj_t packet;
    packet.length = length;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    packet.man_pitch = man_pitch;
    packet.man_roll = man_roll;
    packet.man_yaw = man_yaw;
    packet.man_throttle = man_throttle;
    packet.real_pitch = real_pitch;
    packet.real_roll = real_roll;
    packet.real_yaw = real_yaw;
    packet.real_throttle = real_throttle;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DN_YKQSJ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DN_YKQSJ;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
}

/**
 * @brief Pack a dn_ykqsj message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param man_pitch  uint8_t
 * @param man_roll  uint8_t
 * @param man_yaw  uint8_t
 * @param man_throttle  uint8_t
 * @param real_pitch  uint8_t
 * @param real_roll  uint8_t
 * @param real_yaw  uint8_t
 * @param real_throttle  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_dn_ykqsj_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *head,uint8_t msg_id,uint8_t uav_id,uint16_t length,uint8_t checksum,uint8_t man_pitch,uint8_t man_roll,uint8_t man_yaw,uint8_t man_throttle,uint8_t real_pitch,uint8_t real_roll,uint8_t real_yaw,uint8_t real_throttle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_YKQSJ_LEN];
    _mav_put_uint16_t(buf, 0, length);
    _mav_put_uint8_t(buf, 5, msg_id);
    _mav_put_uint8_t(buf, 6, uav_id);
    _mav_put_uint8_t(buf, 7, checksum);
    _mav_put_uint8_t(buf, 8, man_pitch);
    _mav_put_uint8_t(buf, 9, man_roll);
    _mav_put_uint8_t(buf, 10, man_yaw);
    _mav_put_uint8_t(buf, 11, man_throttle);
    _mav_put_uint8_t(buf, 12, real_pitch);
    _mav_put_uint8_t(buf, 13, real_roll);
    _mav_put_uint8_t(buf, 14, real_yaw);
    _mav_put_uint8_t(buf, 15, real_throttle);
    _mav_put_char_array(buf, 2, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_DN_YKQSJ_LEN);
#else
    mavlink_dn_ykqsj_t packet;
    packet.length = length;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    packet.man_pitch = man_pitch;
    packet.man_roll = man_roll;
    packet.man_yaw = man_yaw;
    packet.man_throttle = man_throttle;
    packet.real_pitch = real_pitch;
    packet.real_roll = real_roll;
    packet.real_yaw = real_yaw;
    packet.real_throttle = real_throttle;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_DN_YKQSJ_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_DN_YKQSJ;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
}

/**
 * @brief Encode a dn_ykqsj struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param dn_ykqsj C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dn_ykqsj_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_dn_ykqsj_t* dn_ykqsj)
{
    return mavlink_msg_dn_ykqsj_pack(system_id, component_id, msg, dn_ykqsj->head, dn_ykqsj->msg_id, dn_ykqsj->uav_id, dn_ykqsj->length, dn_ykqsj->checksum, dn_ykqsj->man_pitch, dn_ykqsj->man_roll, dn_ykqsj->man_yaw, dn_ykqsj->man_throttle, dn_ykqsj->real_pitch, dn_ykqsj->real_roll, dn_ykqsj->real_yaw, dn_ykqsj->real_throttle);
}

/**
 * @brief Encode a dn_ykqsj struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dn_ykqsj C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_dn_ykqsj_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_dn_ykqsj_t* dn_ykqsj)
{
    return mavlink_msg_dn_ykqsj_pack_chan(system_id, component_id, chan, msg, dn_ykqsj->head, dn_ykqsj->msg_id, dn_ykqsj->uav_id, dn_ykqsj->length, dn_ykqsj->checksum, dn_ykqsj->man_pitch, dn_ykqsj->man_roll, dn_ykqsj->man_yaw, dn_ykqsj->man_throttle, dn_ykqsj->real_pitch, dn_ykqsj->real_roll, dn_ykqsj->real_yaw, dn_ykqsj->real_throttle);
}

/**
 * @brief Send a dn_ykqsj message
 * @param chan MAVLink channel to send the message
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param man_pitch  uint8_t
 * @param man_roll  uint8_t
 * @param man_yaw  uint8_t
 * @param man_throttle  uint8_t
 * @param real_pitch  uint8_t
 * @param real_roll  uint8_t
 * @param real_yaw  uint8_t
 * @param real_throttle  uint8_t
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_dn_ykqsj_send(mavlink_channel_t chan, const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, uint8_t man_pitch, uint8_t man_roll, uint8_t man_yaw, uint8_t man_throttle, uint8_t real_pitch, uint8_t real_roll, uint8_t real_yaw, uint8_t real_throttle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_DN_YKQSJ_LEN];
    _mav_put_uint16_t(buf, 0, length);
    _mav_put_uint8_t(buf, 5, msg_id);
    _mav_put_uint8_t(buf, 6, uav_id);
    _mav_put_uint8_t(buf, 7, checksum);
    _mav_put_uint8_t(buf, 8, man_pitch);
    _mav_put_uint8_t(buf, 9, man_roll);
    _mav_put_uint8_t(buf, 10, man_yaw);
    _mav_put_uint8_t(buf, 11, man_throttle);
    _mav_put_uint8_t(buf, 12, real_pitch);
    _mav_put_uint8_t(buf, 13, real_roll);
    _mav_put_uint8_t(buf, 14, real_yaw);
    _mav_put_uint8_t(buf, 15, real_throttle);
    _mav_put_char_array(buf, 2, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_YKQSJ, buf, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
#else
    mavlink_dn_ykqsj_t packet;
    packet.length = length;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    packet.man_pitch = man_pitch;
    packet.man_roll = man_roll;
    packet.man_yaw = man_yaw;
    packet.man_throttle = man_throttle;
    packet.real_pitch = real_pitch;
    packet.real_roll = real_roll;
    packet.real_yaw = real_yaw;
    packet.real_throttle = real_throttle;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_YKQSJ, (const char *)&packet, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
#endif
}

/**
 * @brief Send a dn_ykqsj message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_dn_ykqsj_send_struct(mavlink_channel_t chan, const mavlink_dn_ykqsj_t* dn_ykqsj)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_dn_ykqsj_send(chan, dn_ykqsj->head, dn_ykqsj->msg_id, dn_ykqsj->uav_id, dn_ykqsj->length, dn_ykqsj->checksum, dn_ykqsj->man_pitch, dn_ykqsj->man_roll, dn_ykqsj->man_yaw, dn_ykqsj->man_throttle, dn_ykqsj->real_pitch, dn_ykqsj->real_roll, dn_ykqsj->real_yaw, dn_ykqsj->real_throttle);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_YKQSJ, (const char *)dn_ykqsj, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
#endif
}

#if MAVLINK_MSG_ID_DN_YKQSJ_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_dn_ykqsj_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, uint8_t man_pitch, uint8_t man_roll, uint8_t man_yaw, uint8_t man_throttle, uint8_t real_pitch, uint8_t real_roll, uint8_t real_yaw, uint8_t real_throttle)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, length);
    _mav_put_uint8_t(buf, 5, msg_id);
    _mav_put_uint8_t(buf, 6, uav_id);
    _mav_put_uint8_t(buf, 7, checksum);
    _mav_put_uint8_t(buf, 8, man_pitch);
    _mav_put_uint8_t(buf, 9, man_roll);
    _mav_put_uint8_t(buf, 10, man_yaw);
    _mav_put_uint8_t(buf, 11, man_throttle);
    _mav_put_uint8_t(buf, 12, real_pitch);
    _mav_put_uint8_t(buf, 13, real_roll);
    _mav_put_uint8_t(buf, 14, real_yaw);
    _mav_put_uint8_t(buf, 15, real_throttle);
    _mav_put_char_array(buf, 2, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_YKQSJ, buf, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
#else
    mavlink_dn_ykqsj_t *packet = (mavlink_dn_ykqsj_t *)msgbuf;
    packet->length = length;
    packet->msg_id = msg_id;
    packet->uav_id = uav_id;
    packet->checksum = checksum;
    packet->man_pitch = man_pitch;
    packet->man_roll = man_roll;
    packet->man_yaw = man_yaw;
    packet->man_throttle = man_throttle;
    packet->real_pitch = real_pitch;
    packet->real_roll = real_roll;
    packet->real_yaw = real_yaw;
    packet->real_throttle = real_throttle;
    mav_array_memcpy(packet->head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_DN_YKQSJ, (const char *)packet, MAVLINK_MSG_ID_DN_YKQSJ_MIN_LEN, MAVLINK_MSG_ID_DN_YKQSJ_LEN, MAVLINK_MSG_ID_DN_YKQSJ_CRC);
#endif
}
#endif

#endif

// MESSAGE DN_YKQSJ UNPACKING


/**
 * @brief Get field head from dn_ykqsj message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_dn_ykqsj_get_head(const mavlink_message_t* msg, char *head)
{
    return _MAV_RETURN_char_array(msg, head, 3,  2);
}

/**
 * @brief Get field msg_id from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_msg_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field uav_id from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_uav_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field length from dn_ykqsj message
 *
 * @return  uint16_t
 */
static inline uint16_t mavlink_msg_dn_ykqsj_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field checksum from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_checksum(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field man_pitch from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_man_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field man_roll from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_man_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field man_yaw from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_man_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field man_throttle from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_man_throttle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field real_pitch from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_real_pitch(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field real_roll from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_real_roll(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field real_yaw from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_real_yaw(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field real_throttle from dn_ykqsj message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_dn_ykqsj_get_real_throttle(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Decode a dn_ykqsj message into a struct
 *
 * @param msg The message to decode
 * @param dn_ykqsj C-struct to decode the message contents into
 */
static inline void mavlink_msg_dn_ykqsj_decode(const mavlink_message_t* msg, mavlink_dn_ykqsj_t* dn_ykqsj)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    dn_ykqsj->length = mavlink_msg_dn_ykqsj_get_length(msg);
    mavlink_msg_dn_ykqsj_get_head(msg, dn_ykqsj->head);
    dn_ykqsj->msg_id = mavlink_msg_dn_ykqsj_get_msg_id(msg);
    dn_ykqsj->uav_id = mavlink_msg_dn_ykqsj_get_uav_id(msg);
    dn_ykqsj->checksum = mavlink_msg_dn_ykqsj_get_checksum(msg);
    dn_ykqsj->man_pitch = mavlink_msg_dn_ykqsj_get_man_pitch(msg);
    dn_ykqsj->man_roll = mavlink_msg_dn_ykqsj_get_man_roll(msg);
    dn_ykqsj->man_yaw = mavlink_msg_dn_ykqsj_get_man_yaw(msg);
    dn_ykqsj->man_throttle = mavlink_msg_dn_ykqsj_get_man_throttle(msg);
    dn_ykqsj->real_pitch = mavlink_msg_dn_ykqsj_get_real_pitch(msg);
    dn_ykqsj->real_roll = mavlink_msg_dn_ykqsj_get_real_roll(msg);
    dn_ykqsj->real_yaw = mavlink_msg_dn_ykqsj_get_real_yaw(msg);
    dn_ykqsj->real_throttle = mavlink_msg_dn_ykqsj_get_real_throttle(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_DN_YKQSJ_LEN? msg->len : MAVLINK_MSG_ID_DN_YKQSJ_LEN;
        memset(dn_ykqsj, 0, MAVLINK_MSG_ID_DN_YKQSJ_LEN);
    memcpy(dn_ykqsj, _MAV_PAYLOAD(msg), len);
#endif
}
