/** @file
 *  @brief MAVLink comm protocol generated from sysu.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_SYSU_H
#define MAVLINK_SYSU_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_SYSU.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 103, 179, 179, 0, 0, 0}, {1, 68, 57, 57, 0, 0, 0}, {2, 147, 16, 16, 0, 0, 0}, {10, 152, 18, 18, 0, 0, 0}}
#endif

#include "protocol.h"

#define MAVLINK_ENABLED_SYSU

// ENUM DEFINITIONS


/** @brief TO BE ADDED. */
#ifndef HAVE_ENUM_SYSU_STATUS
#define HAVE_ENUM_SYSU_STATUS
typedef enum SYSU_STATUS
{
   GOOD=0, /* development release | */
   VERY_GOOD=1, /* alpha release | */
   VERY_VERY_GOOD=2, /* beta release | */
   BAD=3, /* release candidate | */
   VERY_BAD=4, /* official stable release | */
   SYSU_STATUS_ENUM_END=5, /*  | */
} SYSU_STATUS;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "mavlink_msg_test_types.h"
#include "mavlink_msg_dn_fxsj.h"
#include "mavlink_msg_dn_ykqsj.h"
#include "mavlink_msg_cm_zdfx.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_TEST_TYPES, MAVLINK_MESSAGE_INFO_DN_FXSJ, MAVLINK_MESSAGE_INFO_DN_YKQSJ, MAVLINK_MESSAGE_INFO_CM_ZDFX}
# define MAVLINK_MESSAGE_NAMES {{ "CM_ZDFX", 10 }, { "DN_FXSJ", 1 }, { "DN_YKQSJ", 2 }, { "TEST_TYPES", 0 }}
#if MAVLINK_COMMAND_24BIT
#include "mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_SYSU_H
