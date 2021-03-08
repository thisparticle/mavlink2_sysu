#pragma once
// MESSAGE CM_ZDFX PACKING

#define MAVLINK_MSG_ID_CM_ZDFX 10


typedef struct __mavlink_cm_zdfx_t {
 int32_t WP_lat; /*<  int32_t*/
 int32_t WP_lon; /*<  int32_t*/
 uint16_t length; /*<  uint16_t*/
 int16_t WP_alt; /*<  int16_t*/
 char head[3]; /*<  string*/
 uint8_t msg_id; /*<  uint8_t*/
 uint8_t uav_id; /*<  uint8_t*/
 uint8_t checksum; /*<  uint8_t*/
} mavlink_cm_zdfx_t;

#define MAVLINK_MSG_ID_CM_ZDFX_LEN 18
#define MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN 18
#define MAVLINK_MSG_ID_10_LEN 18
#define MAVLINK_MSG_ID_10_MIN_LEN 18

#define MAVLINK_MSG_ID_CM_ZDFX_CRC 152
#define MAVLINK_MSG_ID_10_CRC 152

#define MAVLINK_MSG_CM_ZDFX_FIELD_HEAD_LEN 3

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CM_ZDFX { \
    10, \
    "CM_ZDFX", \
    8, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 12, offsetof(mavlink_cm_zdfx_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_cm_zdfx_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_cm_zdfx_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_cm_zdfx_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_cm_zdfx_t, checksum) }, \
         { "WP_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_cm_zdfx_t, WP_lat) }, \
         { "WP_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_cm_zdfx_t, WP_lon) }, \
         { "WP_alt", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_cm_zdfx_t, WP_alt) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CM_ZDFX { \
    "CM_ZDFX", \
    8, \
    {  { "head", NULL, MAVLINK_TYPE_CHAR, 3, 12, offsetof(mavlink_cm_zdfx_t, head) }, \
         { "msg_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_cm_zdfx_t, msg_id) }, \
         { "uav_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_cm_zdfx_t, uav_id) }, \
         { "length", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_cm_zdfx_t, length) }, \
         { "checksum", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_cm_zdfx_t, checksum) }, \
         { "WP_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_cm_zdfx_t, WP_lat) }, \
         { "WP_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_cm_zdfx_t, WP_lon) }, \
         { "WP_alt", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_cm_zdfx_t, WP_alt) }, \
         } \
}
#endif

/**
 * @brief Pack a cm_zdfx message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param WP_lat  int32_t
 * @param WP_lon  int32_t
 * @param WP_alt  int16_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cm_zdfx_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t WP_lat, int32_t WP_lon, int16_t WP_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CM_ZDFX_LEN];
    _mav_put_int32_t(buf, 0, WP_lat);
    _mav_put_int32_t(buf, 4, WP_lon);
    _mav_put_uint16_t(buf, 8, length);
    _mav_put_int16_t(buf, 10, WP_alt);
    _mav_put_uint8_t(buf, 15, msg_id);
    _mav_put_uint8_t(buf, 16, uav_id);
    _mav_put_uint8_t(buf, 17, checksum);
    _mav_put_char_array(buf, 12, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CM_ZDFX_LEN);
#else
    mavlink_cm_zdfx_t packet;
    packet.WP_lat = WP_lat;
    packet.WP_lon = WP_lon;
    packet.length = length;
    packet.WP_alt = WP_alt;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CM_ZDFX_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CM_ZDFX;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
}

/**
 * @brief Pack a cm_zdfx message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param WP_lat  int32_t
 * @param WP_lon  int32_t
 * @param WP_alt  int16_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cm_zdfx_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *head,uint8_t msg_id,uint8_t uav_id,uint16_t length,uint8_t checksum,int32_t WP_lat,int32_t WP_lon,int16_t WP_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CM_ZDFX_LEN];
    _mav_put_int32_t(buf, 0, WP_lat);
    _mav_put_int32_t(buf, 4, WP_lon);
    _mav_put_uint16_t(buf, 8, length);
    _mav_put_int16_t(buf, 10, WP_alt);
    _mav_put_uint8_t(buf, 15, msg_id);
    _mav_put_uint8_t(buf, 16, uav_id);
    _mav_put_uint8_t(buf, 17, checksum);
    _mav_put_char_array(buf, 12, head, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CM_ZDFX_LEN);
#else
    mavlink_cm_zdfx_t packet;
    packet.WP_lat = WP_lat;
    packet.WP_lon = WP_lon;
    packet.length = length;
    packet.WP_alt = WP_alt;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CM_ZDFX_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_CM_ZDFX;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
}

/**
 * @brief Encode a cm_zdfx struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cm_zdfx C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cm_zdfx_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cm_zdfx_t* cm_zdfx)
{
    return mavlink_msg_cm_zdfx_pack(system_id, component_id, msg, cm_zdfx->head, cm_zdfx->msg_id, cm_zdfx->uav_id, cm_zdfx->length, cm_zdfx->checksum, cm_zdfx->WP_lat, cm_zdfx->WP_lon, cm_zdfx->WP_alt);
}

/**
 * @brief Encode a cm_zdfx struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cm_zdfx C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cm_zdfx_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cm_zdfx_t* cm_zdfx)
{
    return mavlink_msg_cm_zdfx_pack_chan(system_id, component_id, chan, msg, cm_zdfx->head, cm_zdfx->msg_id, cm_zdfx->uav_id, cm_zdfx->length, cm_zdfx->checksum, cm_zdfx->WP_lat, cm_zdfx->WP_lon, cm_zdfx->WP_alt);
}

/**
 * @brief Send a cm_zdfx message
 * @param chan MAVLink channel to send the message
 *
 * @param head  string
 * @param msg_id  uint8_t
 * @param uav_id  uint8_t
 * @param length  uint16_t
 * @param checksum  uint8_t
 * @param WP_lat  int32_t
 * @param WP_lon  int32_t
 * @param WP_alt  int16_t
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cm_zdfx_send(mavlink_channel_t chan, const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t WP_lat, int32_t WP_lon, int16_t WP_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_CM_ZDFX_LEN];
    _mav_put_int32_t(buf, 0, WP_lat);
    _mav_put_int32_t(buf, 4, WP_lon);
    _mav_put_uint16_t(buf, 8, length);
    _mav_put_int16_t(buf, 10, WP_alt);
    _mav_put_uint8_t(buf, 15, msg_id);
    _mav_put_uint8_t(buf, 16, uav_id);
    _mav_put_uint8_t(buf, 17, checksum);
    _mav_put_char_array(buf, 12, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CM_ZDFX, buf, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
#else
    mavlink_cm_zdfx_t packet;
    packet.WP_lat = WP_lat;
    packet.WP_lon = WP_lon;
    packet.length = length;
    packet.WP_alt = WP_alt;
    packet.msg_id = msg_id;
    packet.uav_id = uav_id;
    packet.checksum = checksum;
    mav_array_memcpy(packet.head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CM_ZDFX, (const char *)&packet, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
#endif
}

/**
 * @brief Send a cm_zdfx message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cm_zdfx_send_struct(mavlink_channel_t chan, const mavlink_cm_zdfx_t* cm_zdfx)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cm_zdfx_send(chan, cm_zdfx->head, cm_zdfx->msg_id, cm_zdfx->uav_id, cm_zdfx->length, cm_zdfx->checksum, cm_zdfx->WP_lat, cm_zdfx->WP_lon, cm_zdfx->WP_alt);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CM_ZDFX, (const char *)cm_zdfx, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
#endif
}

#if MAVLINK_MSG_ID_CM_ZDFX_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cm_zdfx_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *head, uint8_t msg_id, uint8_t uav_id, uint16_t length, uint8_t checksum, int32_t WP_lat, int32_t WP_lon, int16_t WP_alt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, WP_lat);
    _mav_put_int32_t(buf, 4, WP_lon);
    _mav_put_uint16_t(buf, 8, length);
    _mav_put_int16_t(buf, 10, WP_alt);
    _mav_put_uint8_t(buf, 15, msg_id);
    _mav_put_uint8_t(buf, 16, uav_id);
    _mav_put_uint8_t(buf, 17, checksum);
    _mav_put_char_array(buf, 12, head, 3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CM_ZDFX, buf, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
#else
    mavlink_cm_zdfx_t *packet = (mavlink_cm_zdfx_t *)msgbuf;
    packet->WP_lat = WP_lat;
    packet->WP_lon = WP_lon;
    packet->length = length;
    packet->WP_alt = WP_alt;
    packet->msg_id = msg_id;
    packet->uav_id = uav_id;
    packet->checksum = checksum;
    mav_array_memcpy(packet->head, head, sizeof(char)*3);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CM_ZDFX, (const char *)packet, MAVLINK_MSG_ID_CM_ZDFX_MIN_LEN, MAVLINK_MSG_ID_CM_ZDFX_LEN, MAVLINK_MSG_ID_CM_ZDFX_CRC);
#endif
}
#endif

#endif

// MESSAGE CM_ZDFX UNPACKING


/**
 * @brief Get field head from cm_zdfx message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_cm_zdfx_get_head(const mavlink_message_t* msg, char *head)
{
    return _MAV_RETURN_char_array(msg, head, 3,  12);
}

/**
 * @brief Get field msg_id from cm_zdfx message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_cm_zdfx_get_msg_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field uav_id from cm_zdfx message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_cm_zdfx_get_uav_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field length from cm_zdfx message
 *
 * @return  uint16_t
 */
static inline uint16_t mavlink_msg_cm_zdfx_get_length(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field checksum from cm_zdfx message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_cm_zdfx_get_checksum(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field WP_lat from cm_zdfx message
 *
 * @return  int32_t
 */
static inline int32_t mavlink_msg_cm_zdfx_get_WP_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field WP_lon from cm_zdfx message
 *
 * @return  int32_t
 */
static inline int32_t mavlink_msg_cm_zdfx_get_WP_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field WP_alt from cm_zdfx message
 *
 * @return  int16_t
 */
static inline int16_t mavlink_msg_cm_zdfx_get_WP_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Decode a cm_zdfx message into a struct
 *
 * @param msg The message to decode
 * @param cm_zdfx C-struct to decode the message contents into
 */
static inline void mavlink_msg_cm_zdfx_decode(const mavlink_message_t* msg, mavlink_cm_zdfx_t* cm_zdfx)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    cm_zdfx->WP_lat = mavlink_msg_cm_zdfx_get_WP_lat(msg);
    cm_zdfx->WP_lon = mavlink_msg_cm_zdfx_get_WP_lon(msg);
    cm_zdfx->length = mavlink_msg_cm_zdfx_get_length(msg);
    cm_zdfx->WP_alt = mavlink_msg_cm_zdfx_get_WP_alt(msg);
    mavlink_msg_cm_zdfx_get_head(msg, cm_zdfx->head);
    cm_zdfx->msg_id = mavlink_msg_cm_zdfx_get_msg_id(msg);
    cm_zdfx->uav_id = mavlink_msg_cm_zdfx_get_uav_id(msg);
    cm_zdfx->checksum = mavlink_msg_cm_zdfx_get_checksum(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CM_ZDFX_LEN? msg->len : MAVLINK_MSG_ID_CM_ZDFX_LEN;
        memset(cm_zdfx, 0, MAVLINK_MSG_ID_CM_ZDFX_LEN);
    memcpy(cm_zdfx, _MAV_PAYLOAD(msg), len);
#endif
}
